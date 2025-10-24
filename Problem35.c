#include <stdio.h>

struct Inner {
    char c; // 1
    int d; // 4
};

struct Outer {
    int a; // 4
    struct Inner in;
    char e[3]; // 3
};
// sizeof (struct outer) là: 16 bytes
