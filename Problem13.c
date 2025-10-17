#include <stdio.h>

int main(){
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);

    int isolate = x & (-x);
    int pos = 0;
    while(isolate > 1){
        isolate >>= 1;
        pos++;
    }
    printf("Bit 1 bi co lap tai vi tri la: %d\n",pos);
    return 0;
}