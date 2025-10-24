#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void demo_dangling_pointer() {
    printf("=== Demo Dangling Pointer ===\n");

    int *p = malloc(sizeof(int));
    *p = 42;
    printf("Before free: *p = %d\n", *p);

    free(p);     // Giải phóng vùng nhớ
    // p giờ trở thành con trỏ treo (dangling)
    
    printf("After free, accessing *p...\n");
    printf("*p = %d\n", *p); // ❌ Lỗi: truy cập vùng nhớ đã free
}

void demo_heap_corruption() {
    printf("\n=== Demo Heap Corruption ===\n");

    char *buf = malloc(8);
    strcpy(buf, "ABCDEFG");  // OK, "ABCDEFG" (8 bytes bao gồm '\0')
    printf("buf = %s\n", buf);

    // Ghi đè vượt quá vùng nhớ được cấp phát
    // -> gây hỏng heap
    strcpy(buf, "ABCDEFGHIJK"); // ❌ Quá giới hạn (11 + 1 bytes > 8)
    printf("After overflow: buf = %s\n", buf);

    free(buf);
}

int main() {
    demo_dangling_pointer();
    demo_heap_corruption();
    return 0;
}
/* Heap corruption có thể do nhiều nguyên nhân gây ra ngoài việc 
gây ra bởi các lỗi như ghi đè vùng nhớ cấp phát hay dùng bộ nhớ sau
khi đã free thì còn
1.Double free (Giải phóng hai lần)

#include <stdlib.h>

int main() {
    int *p = (int *)malloc(10 * sizeof(int));
    free(p);
    free(p);  // lỗi: double free -> corrupt heap metadata
    return 0;
}

2.Ghi vào vùng nhớ chưa được cấp phát (Uninitialized / Invalid pointer write)

int *p = (int *)malloc(4);
int *q = p + 10;   // vượt vùng nhớ
*q = 5;            // ghi ra ngoài heap

3.Giải phóng con trỏ không hợp lệ (Free invalid pointer)

#include <stdlib.h>

int main() {
    int a;
    free(&a);   // lỗi: a nằm trên stack, không phải heap
    return 0;
}

4.Sử dụng bộ nhớ sau khi realloc thay đổi địa chỉ

#include <stdlib.h>
#include <string.h>

int main() {
    char *p = (char *)malloc(5);
    strcpy(p, "Hi");
    char *q = realloc(p, 10);  // có thể di chuyển vùng nhớ
    p[0] = 'X';   // p có thể không còn hợp lệ
    free(q);
    return 0;
}

5.Viết sai kích thước hoặc sai kiểu dữ liệu khi dùng memcpy, memmove, v.v
#include <string.h>
#include <stdlib.h>

int main() {
    int *arr = (int *)malloc(3 * sizeof(int));
    int src[5] = {1,2,3,4,5};
    memcpy(arr, src, 5 * sizeof(int));  // copy quá 2 phần tử -> overflow
    free(arr);
    return 0;
}



*/
