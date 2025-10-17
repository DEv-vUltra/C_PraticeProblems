#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int a = 5;
    int b = 1;
    swap(&a,&b);
    printf("Gia tri sau khi da hoan doi giua a = 5 va b = 1 la a = %d va b = %d\n",a,b);
    return 0;
}