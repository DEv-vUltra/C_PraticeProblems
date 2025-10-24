#include <stdio.h>


union Data {
    int i; //4  alignment: 4
    char c[4]; //4 
};

struct Test {
    char flag; //1
    union Data data; //4
};

// size of struct Test is: 1 + 4 + 3 padding = 8 byte