#include <stdio.h>

// Cách 1
// int main(){

//     int x;
//     printf("Nhap x: ");
//     scanf("%d", &x);
//     int msb_pos = -1;
//     for(int i = 31; i >= 0; i--){
//         if((x >> i) & 1){
//             msb_pos = i;
//             break;
//         }
        
//     }
    
//     if(msb_pos == -1){
//         printf("So %d khong co bit 1 nao (x = 0)\n",x);
//     }
//     else printf("Bit MSB cua %d nam o vi tri: %d\n",x , msb_pos);
//     return 0;
// }
// Cách 2: sử dụng while giảm số lần lặp thay vì phải duyệt từ bit thứ 32(log2(n))
int main(){
    int x;
    printf("Nhap x: ");
    scanf("%d", &x);
    int msb_pos = -1;
    while(x > 0){
        x >>= 1;
        msb_pos++;
    }
    printf("MSB = %d\n",msb_pos);
    return 0;
}