#include <stdio.h>


struct
{
    int a; // = 4
    char b; // = 1
} ab;
// sizeof(ab) là 4 + 1 + 3 padding = 8
#pragma pack(push, 1)
struct
{
    char a;
    int b;  
} ba;
// int main(){
//     printf("size of ab: %ld\n", sizeof(ab));
//     printf("size of ba: %ld\n", sizeof(ba));
//     return 0;
// }

#pragma pack(pop)

// sizeof(ba) là 1 + 4 + 0 padding = 5
// kích thước của 1 struct = tổng kích thước của các thành viên +  padding giữa các thành viên +  padding cuối 