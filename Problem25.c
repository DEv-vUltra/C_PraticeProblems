#include <stdio.h>

int a = 10; //.data
const int b = 5; //.rodata
static int c = 3;//.data
int func(void) {
    int d = 2; // stack
    return a + b + c + d;
}