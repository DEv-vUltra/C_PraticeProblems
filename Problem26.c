#include <stdio.h>

void recursion(int x) {
    int a[100];
    // if(x < 100){}
    recursion(x + 1);
}
/* Đoạn mã này đệ quy mà không có điều kiện dừng. Điều này dẫn đến các stack frame cứ chồng
chất lên nhau từ đó tạo ra lỗi stack overflow
*/