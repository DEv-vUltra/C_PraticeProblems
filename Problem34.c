#include <stdio.h>

#pragma pack(push, 1)
struct B {
    char a; //1
    int b;  //4
    short c; //2
};
#pragma pack(pop)
/* lệnh pragma cho phép căn chỉnh padding. Đối với pragma pack(push,1)
thì các thành viên sẽ được sắp xếp nhau có thể -> padding = 0. Tức là 4 + 2 + 1 = 7
Nếu với pragma pack(push,2) thì sẽ được căn chỉnh theo bội số của 2 byte tức là 1 + 1 padding
+ 4 + 2 = 8;
*/ 


int main(){
    printf("size of A: %ld\n", sizeof(struct B));
    return 0;
}