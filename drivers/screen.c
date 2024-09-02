#define VIDEO_ADDRESS 0xb8000;
#define NUM_ROWS 25
#define NUM_COLS 80

//Color definitions
#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHT_GREY 7
#define DARK_GREY 8
#define LIGHT_BLUE 9
#define LIGHT_GREEN 10
#define LIGHT_CYAN 11
#define LIGHT_RED 12
#define LIGHT_MAGENTA 13
#define LIGHT_BROWN 14
#define WHITE 15

//Keeping a track of the cursor
unsigned int cursor_row = 0;
unsigned int cursor_col = 0;

//Defining buffer
char* buffer = (char*) VIDEO_ADDRESS;

void write_char_to_cursor(int row, int col, unsigned char c, unsigned char bg_col, unsigned char fg_col) {
    if (row < 0 || row >= NUM_ROWS || col < 0 || col >= NUM_COLS) return;
    
    int idx = (row*NUM_COLS + col)*2;
    *(buffer + idx) = c;
    *(buffer + idx + 1) = ((bg_col & 0x0f) << 4) | (fg_col & 0x0f);
}
void main() {
    write_char_to_cursor(1, -100, 'O', RED, WHITE);
}