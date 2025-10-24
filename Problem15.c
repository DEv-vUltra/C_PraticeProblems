#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void myfunction(char *q){
    char *d = (char *)malloc(5); //dòng cần thêm vào
    memcpy(d, "hello", 5);
    printf("%s",d);
    free(d);
}

int main(void){
    char *p;
    myfunction(p);
    
    return 0;
}


// Lỗi nằm ở việc chưa cấp phát bộ nhớ cho con trỏ p và q nên sẽ memcpy sẽ không xác định được vùng nhớ
// lỗi segmentation fault
// 1 trường hợp khác nếu bạn đặt hàm free() ở main sau hàm myfunction(p) thì sẽ gây ra lỗi free 1 vùng nhớ không xác định gây ra core dumped
