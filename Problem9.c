#include <stdio.h>


int main(){
    int a, b;
    printf("Nhap 2 so nguyen duong: ");
    scanf("%d", &a);
    scanf("%d", &b);

    if((a ^ b) == 0) printf("2 so nay bang nhau\n");
    else printf("2 so nay khong bang nhau\n");
    return 0;    
}