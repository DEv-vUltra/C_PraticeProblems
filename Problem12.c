#include <stdio.h>

int main(){
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    
    x = x & (x - 1);

    printf("In ra so sau khi tat bit 1 o ngoai cung ben phai: %d\n",x);
    return 0;
}