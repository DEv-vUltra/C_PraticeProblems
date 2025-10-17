#include <stdio.h>
#include <stdbool.h>


bool is_power2(int n){
    return n != 0 && (!(n & (n - 1)));
}
int main(){
    int x;
    printf("Nhap gia tri: ");
    scanf("%d", &x);
    
    if(is_power2(x)){
        printf("%d la luy thua cua 2\n", x);
    } else printf("%d khong la luy thua cua 2\n", x);
    return 0;
}