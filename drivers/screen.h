#ifndef SCREEN_H
#define SCREEN_H

#include "../utils/data_types.h"

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

//Video defintions
#define BUFFER_ADDR 0xb8000
#define NUM_ROWS 25
#define NUM_COLS 80
#define PORT_QUERY 0x03d4
#define PORT_DATA 0x03d5

void print_at_k(char* str, int row, int col, u8 bg_col, u8 fg_col);
void print_k(char* str, u8 bg_col, u8 fg_col);
void clear_screen_k();

#endif