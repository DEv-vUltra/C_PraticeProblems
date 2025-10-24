#include <stdio.h>

int a = 5; //.data
int d; //bss
char b[6] = "hello"; //.data
const int c = 4; // .rodata

void myfunction(void)
{
    static int g = 5; // .data (có thời gian sống toàn cục, lưu trong vùng tĩnh)
    const int h = 6; // stack 
    char i; // stack
}