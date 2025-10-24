#include <stdio.h>

void test(void) {
    char *str = "Hello"; // đổi str lại thành mảng 
    str[0] = 'h';
}
/*Đoạn mã này không hợp lệ vì con trỏ này trỏ tới 1 chuỗi được lưu trong .rodata mà ở dòng
thứ 2 thì lại sử dụng con trỏ như 1 mảng để gán tới kí tự 'h' vào*/