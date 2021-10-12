#include "../h/tty.h"

volatile uint16_t* vga_buffer = (uint16_t*)0xB8000;

const int VGA_COLS = 80;
const int VGA_ROWS = 25;

int t_col = 0;
int t_row = 0;

uint8_t t_color = 31;

void t_init(){
    for (int col = 0; col < VGA_COLS; col++){
        for (int row = 0; row < VGA_ROWS; row++){
            size_t index = (VGA_COLS * row) + col;
            vga_buffer[index] = ((uint16_t)t_color << 8) | ' ';
        }
    }
}

void t_putch(char c){
    switch(c){
        case '\n': {
            t_col = 0;
            t_row++;
            break;
        }

        default: {
            size_t index = (VGA_COLS * t_row) + t_col;
            vga_buffer[index] = ((uint16_t)t_color << 8) | c;
            t_col++;
            break;
        }

        if (t_col >= VGA_COLS){
            t_col = 0;
            t_row++;
        }
        
        if (t_row >= VGA_ROWS){
            t_col = 0;
            t_row = 0;
        }
    }
}

void t_print(const char* str){
    for (size_t i = 0; str[i] != '\0'; i++){
        t_putch(str[i]);
    }
}

void t_putuint(int i){
    unsigned int n, d = 1000000000;
    char str[255];
    unsigned int dec_index = 0;

    while ((i/d == 0) && (d >= 10)){
        d /= 10;
    }
    n = i;
    while (d >= 10){
        str[dec_index++] = ((char)((int)'0' +n/d));
        n = n % d;
        d /= 10;
    }
    str[dec_index++] = ((char)((int)'0' +n));
    str[dec_index] = 0;
    t_print(str);
}

void t_putint(int i){
    if (i >= 0){
        t_putuint(i);
    } else {
        t_putch('-');
        t_putuint(-i);
    }
}