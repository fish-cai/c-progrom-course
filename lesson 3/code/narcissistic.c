#include <stdio.h>
int main(int argc, char const *argv[])
{
    // 水仙花数：三位数中，各位数字立方和等于自身
    // 如 153 = 1³ + 5³ + 3³ = 1 + 125 + 27 = 153
    printf("所有水仙花数：\n");

    for(int n = 100; n <= 999; n++)
    {
        int a = n / 100;          // 百位
        int b = n / 10 % 10;      // 十位
        int c = n % 10;           // 个位

        if(a*a*a + b*b*b + c*c*c == n)
        {
            printf("%d = %d³ + %d³ + %d³\n", n, a, b, c);
        }
    }
    return 0;
}
