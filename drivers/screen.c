#include "port_io.h"
#include "screen.h"
#include "../utils/mem_copy.h"
#include "../utils/data_types.h"

int get_cursor();
void update_cursor(int cursor_offset);
int get_row(int cursor_offset);
int get_col(int cursor_offset);
void print_char(u8 c, int row, int col, u8 bg_col, u8 fg_col);
int handle_scroll(int cursor_offset);

/* Public kernel functions 
    - These functions have the "_k" suffix in their names
*/
void print_at_k(char* str, int row, int col, u8 bg_col, u8 fg_col) {
    
    if (row >= NUM_ROWS || col >= NUM_COLS) {
        char* error_msg = "ERROR";
        print_at_k(error_msg, NUM_ROWS-1, 0, WHITE, RED);
        return;
    }

    int idx = 0;
    while (str[idx] != 0) {
        print_char(str[idx], row, col, bg_col, fg_col);
        
        int cursor_offset = get_cursor();
        row = get_row(cursor_offset);
        col = get_col(cursor_offset);

        idx++;
    }
}

void print_k(char* str, u8 bg_col, u8 fg_col) {
    print_at_k(str, -1, -1, bg_col, fg_col);
}

void clear_screen_k() {
    for (int i=0; i<NUM_ROWS; i++) {
        for (int j=0; j<NUM_COLS; j++) {
            
            int offset = 2*(i*NUM_COLS + j);

            *((char*) BUFFER_ADDR + offset) = ' ';
            *((char*) BUFFER_ADDR + offset + 1) = ((BLACK << 4) & 0xf0) | (WHITE & 0xf);
        }
    }

    update_cursor(0);
}

//Private kernel functions 


//Getting cursor position
int get_cursor() {
    
    //Query cursor high byte and store it
    port_byte_out(PORT_QUERY, 14);
    u8 cursor_high_byte = port_byte_in(PORT_DATA);

    //Query cursor low byte and store it 
    port_byte_out(PORT_QUERY, 15);
    u8 cursor_low_byte = port_byte_in(PORT_DATA);

    //Compute cursor offset from BUFFER_ADDR
    int cursor_offset = ((cursor_high_byte << 8) | cursor_low_byte)*2;
    return cursor_offset;
}

void update_cursor(int cursor_offset) {
    cursor_offset /= 2;
    u8 cursor_high_byte = cursor_offset >> 8;
    u8 cursor_low_byte = cursor_offset & 0x00ff;

    //Update high byte
    port_byte_out(PORT_QUERY, 14);
    port_byte_out(PORT_DATA, cursor_high_byte);

    //Update low byte
    port_byte_out(PORT_QUERY, 15);
    port_byte_out(PORT_DATA, cursor_low_byte);
}

int get_row(int cursor_offset) {
    int num_chars_printed = cursor_offset / 2;
    return num_chars_printed / NUM_COLS;
}

int get_col(int cursor_offset) {
    int num_chars_printed = cursor_offset / 2;
    return num_chars_printed % NUM_COLS;
}

void print_char(u8 c, int row, int col, u8 bg_col, u8 fg_col) {
    int cursor_offset;
    if (row < 0 || col < 0 || row >= NUM_ROWS || col >= NUM_COLS) {
        cursor_offset = get_cursor();
    }
    else {
        cursor_offset = 2*((row * NUM_COLS) + col);
    }

    cursor_offset = handle_scroll(cursor_offset);

    //Special characters
    int curr_row = get_row(cursor_offset);
    int curr_col = get_col(cursor_offset);
    if (c == '\n') {
        cursor_offset = 2*((curr_row+1)*NUM_COLS);
    }
    else if (c == '\t') { 
        if (curr_col < NUM_COLS - 4) {   //One tab = 4 spaces
            cursor_offset = 2*(curr_row*NUM_COLS + curr_col + 4) ;
        }
        else {
            cursor_offset = 2*((curr_row+1)*NUM_COLS);
        }
    }
    else {
        //Write char to correct position in buffer
        *((char*) BUFFER_ADDR + cursor_offset) = c;
        *((char*) BUFFER_ADDR + cursor_offset + 1) = ((bg_col << 4) & 0xf0) | (fg_col & 0xf);
        cursor_offset += 2;
    }

    //Update cursor position
    update_cursor(cursor_offset);
}

int handle_scroll(int cursor_offset) {

    if (cursor_offset < 2*NUM_COLS*NUM_ROWS) {
        return cursor_offset;
    }

    //Transfer data from row[1] - row[n-1] to row[0] - row[n-2]
    char* source = (char*) BUFFER_ADDR + (2*NUM_COLS);
    char* dest = (char*) BUFFER_ADDR;
    int num_bytes = 2*NUM_COLS*(NUM_ROWS - 1); 
    mem_copy(source, dest, num_bytes);

    //Clear last row
    int last_row_offset = 2*(NUM_ROWS-1)*(NUM_COLS);
    for (int i=0; i<2*NUM_COLS; i++) {
        *((char*) BUFFER_ADDR + last_row_offset + i) = 0;
    }

    //cursor_offset should go back a row
    return cursor_offset - 2*NUM_COLS;
}