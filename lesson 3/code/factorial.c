#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    long long result = 1;   // 阶乘增长快，用 long long 防溢出

    printf("请输入n:");
    scanf("%d", &n);

    // 累乘器：初始值为 1（不是 0！）
    for(int i = 1; i <= n; i++)
    {
        result = result * i;
    }
    printf("%d! = %lld\n", n, result);
    return 0;
}
