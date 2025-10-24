#include <stdio.h>

int a; // Các biến a và con trỏ b được cấp phát ở vùng bss
char *b;
const char c[20] = "I am a string"; // biến này được cấp phát ở vùng data


void func(char d, int c_param, char *f){
    int g = 0; // biến được cấp phát trong stack 
    static int h = 2; 
    char *i = NULL;
    i = (char *)malloc(20);
    if(i != NULL){
        free(i);
    }
}
/* Hàm trên hoạt động bằng cách cấp phát cho con trỏ i 20 bytes
nhưng nếu con trỏ trỏ tới ví dụ như const char c[20] thì sẽ được giải phóng

*/






