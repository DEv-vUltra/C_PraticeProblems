#include <stdio.h>

int main(){
    int x = 5; // 000101
    int n = 1;

    x ^= (1 << n);

    printf("Gia tri sau khi dao bit %d: %d\n", n, x);
    return 0;
}