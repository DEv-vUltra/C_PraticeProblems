#include <stdio.h>

union Config {
    struct {
        unsigned int enable : 1;
        unsigned int speed  : 2;
        unsigned int mode   : 3;
    } normal;

    struct {
        unsigned int secure : 1;
        unsigned int key    : 7;
    } security;
};

/*
1.size of (union Config) là 4 
2. Cả 2 struct đều có cùng kiểu vùng nhớ vì các thành viên bên trong cả 2 struct là unsigned int
3. Nếu gán security.key = 0x7F, giá trị Normal.mode sẽ bị ghi đè lên vì cả 2 struct đều cùng chung
vùng nhớ và security key chiếm 7 bit (1 đến 7) còn normal mode là 3 (2 đến 5) -> ghi đè

*/