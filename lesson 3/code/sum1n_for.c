#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n, sum = 0;
    printf("请输入n:");
    scanf("%d", &n);

    // for 版：已知循环次数，最简洁
    // 执行顺序：初始化 i=1 → 判断 i<=n → 循环体 → i++ → 判断...
    for(int i = 1; i <= n; i++)
    {
        sum = sum + i;
    }
    printf("1~%d 的和 = %d\n", n, sum);
    return 0;
}
