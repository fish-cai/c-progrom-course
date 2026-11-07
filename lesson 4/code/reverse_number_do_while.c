#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, rev = 0;

    printf("请输入一个整数:");
    scanf("%d", &n);

    // 数字反转：每次取最后一位，拼到结果末尾
    // 12345 -> 5 -> 54 -> 543 -> 5432 -> 54321
    do
    {
        rev = rev * 10 + n % 10;   // 取出最后一位接到 rev 末尾
        n = n / 10;                // 砍掉最后一位
    }while(n != 0);

    printf("反转后 = %d\n", rev);
    return 0;
}
