#include <stdio.h>

int main(void) {
    register int x = 5;
    printf("%d\n", x);
    printf("%p\n", &x);
    return 0;
}
/* 
Lỗi: không thể lấy địa chỉ của biến khai báo với 'register'.
Nguyên nhân: biến 'x' có thể được lưu trong thanh ghi CPU,
nên không có địa chỉ bộ nhớ hợp lệ để truy cập bằng &x.
*/
