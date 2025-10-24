#include <stdio.h>


void counter(void) {
    static int count = 0;
    count++;
    printf("%d ", count);
}

int main(void) {
    for (int i = 0; i < 3; i++)
        counter();
    return 0;
}
/* Kết quả in ra là 1 2 3
-Nếu bỏ từ khóa static đi thì kết quả sẽ khác vì lúc này biến count được lưu trong stack và sẽ 
kết thúc khi hàm kết thúc nên nó sẽ không trả về kết quả được
-Biến count được lưu ở vùng nhớ tĩnh (.bss)
*/