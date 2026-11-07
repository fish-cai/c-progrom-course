#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, sum = 0;
    int i = 0;

    printf("请输入n:");
    scanf("%d", &n);

    // 与第三课 for、while 的求和对照：三种循环结果一致，只是选型不同
    // do-while：先执行一次，再判断
    do
    {
        sum = sum + i;
        i++;
    }while(i <= n);

    printf("0~%d 的和 = %d\n", n, sum);
    return 0;
}
