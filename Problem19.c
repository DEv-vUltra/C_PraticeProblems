#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void myfunction(char *q) {
    q = (char *)malloc(8);
    if (q) {
        memcpy(q, "hello", 6);
        printf("%s", q); // Cách để in ra hello
        // free(q); dòng cần thêm vào
    }
}

void main(void) {
    char *p = NULL;
    myfunction(p);
}
/* hàm void myfunction có 1 vấn đề là chưa free() sau khi sử dụng  */
