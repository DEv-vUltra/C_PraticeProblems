#include <stdio.h>

int main(){
    int x = 5; // 000101
    int n = 1;

    if(((x >> n) & 1) == 1) printf("Bat\n");
    else printf("Tat\n");
    return 0;
}