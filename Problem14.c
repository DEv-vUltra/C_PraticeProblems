#include <stdio.h>


int main(){
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);

    if((x & 0x7) == 0) printf("So %d la boi cua 8\n", x);
    else printf("So %d khong phai la boi cua 8\n", x);
    return 0;
}