#include <stdio.h>
union data {
    int a;
    char b;
} ab;

ab;a = 64;
ab;a = 2500; // 0x09C4