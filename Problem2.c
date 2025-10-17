#include <stdio.h>


int main(){
    int x = 5; // 0000101
    int n = 2;

    x &= ~(1 << n);

    printf("Gia tri sau khi tat bit %d: %d\n", n, x);
    return 0;
}