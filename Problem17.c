#include <stdio.h>


void main(void){
    char a[4] = "foo"; 
    char *b = "bar"; 
}
/* a là 1 mảng cục bộ được cấp phát trên stack 
Chuỗi "foo" được copy từ vùng read only vào mảng a trên stack
b là 1 con trỏ cục bộ được cấp phát trên stack nhưng nó chỉ trỏ tới vùng nhớ read only data của "bar"(.rodata)
a là 1 mảng thực sự chứa dữ liệu nên có thể thay đổi nội dung của a, còn b vì chưa được cấp phát
đúng nghĩa nên nếu cố gắng thay đổi dữ liệu thì sẽ gây ra segmentation fault
*/

