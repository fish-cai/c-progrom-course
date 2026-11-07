#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, count = 0;

    printf("请输入一个整数:");
    scanf("%d", &n);

    if(n < 0)
    {
        n = -n;        // 负数先转正，位数不受符号影响
    }

    // 任何整数至少有一位（包括 0），所以用 do-while 最合适
    do
    {
        count++;           // 数一位
        n = n / 10;        // 砍掉最后一位
    }while(n != 0);

    printf("这个整数是 %d 位数\n", count);
    return 0;
}
