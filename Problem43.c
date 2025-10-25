#include <stdio.h>

// typedef union {
//     struct {
//         unsigned int EN   : 1;
//         unsigned int MODE : 2;
//         unsigned int RSV  : 1;
//         unsigned int CLK  : 4;
//     } bits;
//     unsigned char reg;
// } CTRL_REG;

// int main(void) {
//     CTRL_REG ctrl = { .reg = 0xB2 };
//     printf("EN=%u, MODE=%u, CLK=%u\n", ctrl.bits.EN, ctrl.bits.MODE, ctrl.bits.CLK);
// }

/*
1. Nó sẽ in ra kết quả là EN = 0, MODE = 1 và CLK = 11 
Với địa chỉ được truyền vào reg thì sẽ ánh xạ của compiler qua bit field của    B          2
                                                                               1011      0010
thì theo như cơ chế Little endian thì sẽ có thứ tự ngược là EN = 0, MODE = 01, CLK = 1011
2. Giải thích tại sao việc truy cập ctrl.bits và ctrl.reg lại ảnh hưởng trực tiếp nhau ?
Bởi vì Union cho phép 2 struct này sử dụng chung 1 vùng nhớ điều này dẫn đến compiler có thể ánh 
xạ từ vùng reg sang vùng bit field 
3. Nếu muốn MODE chiếm bit 4-5 thay vì 1-2, sửa khai báo thế nào ?




*/

typedef union{
    struct {
        unsigned int EN     : 4;
        unsigned int MODE   : 2;
        unsigned int RSV    : 1;
        unsigned int CLK    : 1;
    } bits;
    unsigned char reg;
} CTRL_REG;


int main(void){
    CTRL_REG ctrl = { .reg = 0xB2 };
    printf("EN=%u, MODE=%u, CLK=%u\n", ctrl.bits.EN, ctrl.bits.MODE, ctrl.bits.CLK);
}