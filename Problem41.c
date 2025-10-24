#include <stdio.h>
struct Packet {
    unsigned char header; //1
    union {
        struct {
            unsigned int id   : 4;
            unsigned int type : 3;
            unsigned int err  : 1;
        } bits; // 4
        unsigned char raw;
    } data;
};


int main(){
    struct Packet P;
    P.data.raw = 0xAB;
    printf("id = %u, type = %u, err = %u", P.data.bits.id, P.data.bits.type, P.data.bits.err);
    return 0;
}
/*
1.size of (struct Packet) là 8 bytes
2.Hàm size of không phải luôn bằng 2 mà nó trả về kích thước tính bằng byte của một biến
hoặc một kiểu dữ liệu
3.Nếu gán data.raw = 0xAB, giá trị của id, type, err lần lượt là 11, 2 và 1 vì A    B
                                                                              1010 1011
thì id lấy từ 1011, type là 010 và id là 1
*/