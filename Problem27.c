#include <stdio.h>


int main(void) {
    int a = 0x12345678; // local var cấp trong stack có thể r/w
    char *p = (char *)&a; // được quyền ghi vì là vùng nhớ hợp lệ 
    p[0] = 0xAA; // dòng này ghi vào byte thấp nhất
    printf("a = 0x%x\n", a);
}
/* Đoạn mã này là hợp lệ nhưng cần lưu ý rằng đối với máy của tôi là ARM thì có kiến trúc
là little endian tức là máy tính sẽ hiểu theo thứ tự ngược lại (78 56 43 12) thay vì là (12 34 56 78) như
big endian và vì nó ghi vào byte thấp nhất là 0 nên sẽ là (AA 56 43 12) từ đó in ra a là 0x123456aa
Giống hiện tượng UNIX nhưng bị hiểu thành NUXI

*/