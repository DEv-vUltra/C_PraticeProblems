#include <stdio.h>

int main(){
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);

    int LSB = x & (-x);
    int pos = 0;
    while((LSB >>= 1) != 0){
        pos++;
    }
    printf("Vi tri cua LSB: %d\n", pos);
    return 0;
}