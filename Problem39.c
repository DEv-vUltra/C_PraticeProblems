#include <stdio.h>

struct Flags {
    unsigned int a : 1;
    unsigned int b : 3;
    unsigned int c : 4;
};

// sizeof(struct Flags) là: 4 bytes vì nó cùng kiểu dữ liệu unsigned int