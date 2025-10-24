#include <stdio.h>

struct A {
    char a; // 1
    int b; // 4
    short c; // 2
};
// sizeof(A) là 1 + 4 + 2 + 3 padding giữa + 2 padding cuối = 12 bytes

