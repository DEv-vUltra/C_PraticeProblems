#include <stdio.h>

char *getString(void) {
    char str[] = "hello"; // -> static char str[] = "hello" đưa nó vào vùng dữ liệu tĩnh thì sẽ còn tồn tại sau khi hàm kết thúc
    return str;
}
int main(void) {
    char *s = getString();
    printf("%s\n", s);
}

/*Lỗi nằm ở việc khi mà viết hàm getString trả về 1 con trỏ tới mảng cục bộ là str thì khi
khai báo trong hàm main 1 biến con trỏ thì hàm getString sẽ không thể trả về vì mảng cục bộ str
nằm trong stack và bị hủy sau khi hàm kết thúc nên con trỏ trả về trỏ tới vùng nhớ không còn hợp lệ
dẫn tới segmentation fault
*/

/*
Cách 2: 
char *getString(void){
    char *str = (char *)malloc(6);
    strcpy(str, "Hello")
    return str;
}
int main(void){
    char *s = getString();
    printf("%s", s);
    free(s);
}

*/