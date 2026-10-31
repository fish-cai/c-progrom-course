#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, sum = 0;
    int i = 1;

    printf("请输入n:");
    scanf("%d", &n);

    // while 版：先判断后执行
    while(i <= n)
    {
        sum = sum + i;
        i++;            // 关键：让 i 趋向 n+1，否则死循环
    }
    printf("1~%d 的和 = %d\n", n, sum);
    return 0;
}
