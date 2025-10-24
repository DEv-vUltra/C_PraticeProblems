#include <stdio.h>

union Data {
    struct {
        unsigned int flag  : 3;
        unsigned int mode  : 5;
        unsigned int value : 8;
    } info;
    unsigned short raw;
};
int main(void) {

    union Data d;
    d.raw = 0xABCD;
    printf("flag=%u, mode=%u, value=%u\n", d.info.flag, d.info.mode, d.info.value);
}

/*
1. Giá trị flag, mode, value (trong hệ thống little endian) là 
    + flag = 5
    + mode = 25
    + value = 171
Tại sao lại có các giá trị này:
    Khi ta gán giá trị raw vào union thì nó sẽ ánh xạ bit field lúc này
    nó sẽ dịch địa chỉ 0xABCD theo hệ thập lục phân thành A    B    C    D
                                                          ↓    ↓    ↓    ↓
                                                        1010  1011 1100 1101
    Đối với flag thì nó sẽ lấy bit từ 0 đến 2: 101 = 5 theo hệ thập phân
    Đối với mode thì nó sẽ lấy bit từ 3 đến 7: 11001 = 25 
    Đối với value thì nó sẽ lấy bit từ 8 đến 15: 1010 1011 = 171
    Bởi vì là little endian nên máy tính sẽ hiểu thứ tự là CD AB nên nó sẽ như này:
    Bit index:  [15] [14] [13] [12] [11] [10] [9] [8] [7] [6] [5] [4] [3] [2] [1] [0]
    Value bit:   1    0    1    0    1    0    1   1   1   1   0   0   1   1   0   1
2. Giá trị thay đổi trên big endian là vì máy tính sẽ hiểu theo thứ tự bit 0 quan trọng nhất cho
đến bit 15 là bit ít quan trọng nhất (ngược lại với little endian).
3. Compiler ánh xạ bit-field.
Các bit-field trong 1 struct được đặt theo thứ tự khai báo, nhưng thứ tự của bit trong vùng nhớ ảo
lại do compiler quyết định
Có 2 kiểu là 
+Little endian ứng với bit thấp nhất trong vùng nhớ
+Big endian ứng với bit cao nhất trong vùng nhớ
*/