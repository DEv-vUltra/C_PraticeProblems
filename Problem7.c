#include <stdio.h>

int main(){
    int x;
    printf("Nhap gia tri nguyen duong (x > 0): ");
    scanf("%d", &x);

    if(x & 1 != 0) printf("%d la so le\n",x);
    else printf("%d la so chan\n",x);
    return 0;
}