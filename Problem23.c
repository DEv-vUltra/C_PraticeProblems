#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void func(void) {
    char *p = malloc(10);
    strcpy(p, "Embedded");
    printf("%s", p);
    
}

// void func(void) {
//     const char* src = "Embedded";
//     size_t len = strlen(src) + 1; // cho kí tự NULL
//     char *p = malloc(10);
//     if (p == NULL){
//         perror("malloc");
//         exit(0);
//     }
//     memcpy(p, src, len);
//     printf("%s", p);
// }
// int main(){
//     func();
//     return 0;
// }

/* 
Lỗi 1: việc sử dụng hàm strcpy tiềm ẩn rủi ro bảo mật vì copy từ src tới dest mà không kiểm tra dữ liệu
đầu vào có thể gây tràn bộ đệm, có thể tạo ra lỗi stack smashing detected hoặc segmentation fault
Lỗi 2: sử dụng vùng nhớ nhưng không giải phóng bằng free(), và cấp phát nhiều hơn cần thiết gây tốn bộ nhớ.
*/
