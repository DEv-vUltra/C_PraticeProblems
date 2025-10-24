#include <stdio.h>

void myfunction(){
    char *q;
    for(int i = 0; i < 1000; i++){
        q = (char *)malloc(8);
        if (q != NULL){
            memcpy(q, "hello", 6);
            // free(q); Cách sửa
        }
    }
}

/*Nếu với RAM 2KB thì với mỗi 1 lần lặp là cấp phát 8 byte thì sau 250 vòng lặp thì sẽ
hết RAM và bị lỗi out of memory và malloc sẽ trả về NULL
Ngoài ra vì không có free() nên giá trị sẽ bị ghi đè và con trỏ ở vùng đã bị ghi đè sẽ bị mất
để thay thế cho con trỏ khác. Điều này dẫn đến rò rỉ bộ nhớ (Memory Leak)
Mà "hello" chỉ ứng với 6 byte và nằm trong vùng (.rodata) mà lại cấp phát tận 8 byte nên sẽ bị dư 2 byte
*/