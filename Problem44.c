#include <stdio.h>

union Frame {
    struct {
        unsigned short len  : 10;
        unsigned short type : 3;
        unsigned short crc  : 3;
    } info; // 2

    struct {
        unsigned char low;
        unsigned char high;
    } bytes; // 1
};

/*
1.size of (union Frame) là 2 bytes
2. Nếu bytes.low = 0xAA và bytes.high = 0xBB, giá trị của info.len, info.type, info.crc là gì ?
Với 0xBB theo hệ thập lục phân sẽ là 1011 1011 (BB)
Với 0xAA theo hệ thập lục phân sẽ là 1010 1010 (AA)
Thì lúc này sẽ được sắp xếp là BBAA
    1011           1011           1010        1010
15 14 13 12     11 10 9 8       7 6 5 4      3 2 1 0
Đối với 10 bit đầu sẽ là : 1110101010 = 938 ứng với len
Đối với 3 bit giữa sẽ là : 110 = 6 ứng với type
Đối với 3 bit cuối sẽ là : 101 = 5 ứng với crc
3. Giải thích tại sao giá trị có thể khác nhau giữa compiler (GCC và ARMCC)
Tại vì compiler được quy định bởi hệ điều hành thì lúc đó việc sử dụng little endian và big
endian còn tùy thuộc vào kiến trúc vi xử lí và của máy tính

*/

int main(void){
    union Frame Fr;
    Fr.bytes.high = 0xBB;
    Fr.bytes.low = 0xAA;
    printf("len = %u, type = %u, crc = %u", Fr.info.len, Fr.info.type, Fr.info.crc);
    return 0;
}