#include <stdio.h>


int main(){
    unsigned int x = 5;
    int n = 4;

    x |= (1 << n);
    printf("gia tri sau khi bat bit %d: %u\n", n, x);
    return 0;
}

