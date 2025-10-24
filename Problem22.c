#include <stdio.h>
#include <string.h>


int copy(char *scr, char *dst, unsigned int size) {
    char *s1; // Nên xóa dòng này
    while (size--) {
        *s1++ = *scr++;
        *dst++ = *s1;
        // *dst++ = *scr++; sửa lỗi logic bằng cách xóa 2 dòng trên và đặt lại 2 dòng này
    }
    return 0;
}
/*Lỗi 1: con trỏ không trỏ tới gì cả nên sẽ trỏ tới vùng nhớ không hợp lệ
Lỗi 2: lỗi logic nằm trong đoạn while. Khi gán scr cho s1 và tăng biến thì lúc này s1 sẽ ở vị trí
mới và khi đó dst sẽ trỏ tới sai địa chỉ và bị sai giá trị xuất ra
Lỗi 3: Vì không xác định được kích thước vùng nhớ nguồn và đích nên nếu kích thước của phần src lớn hơn phần 
dst thì sẽ xảy ra lỗi tràn bộ nhớ và gây rò rỉ bộ nhớ 


Đối với lỗi thứ 3 thì nên sử dụng những hàm kiểm soát được dữ liệu đầu vào và an toàn hơn
*/