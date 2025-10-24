#include <stdio.h>


void main(void) {
    char array[20];
    for (int i = 0; i < 20; i++) {
        array[i] = i;
    }

    int *p = (int *)array;
    p++;
    p++;
    printf("Value at p: 0x%x\n", *p);
}
/* 
array là mảng char, việc gán i (kiểu int) cho array[i] hợp lệ nhưng có thể gây mất dữ liệu nếu vượt quá phạm vi của char.
Con trỏ p ép kiểu sang int* nên khi p++ thì nhảy 4 byte/lần. 
Việc in *p sẽ đọc 4 byte liên tiếp trong mảng char, giá trị in ra phụ thuộc vào endianness, nhưng không gây lỗi cú pháp.
*/

