#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sum = 0;

    // for 循环：初始化 i=1 → 判断 i<=100 → 循环体 → i++ → 判断...
    // 已知循环次数时，for 最清晰
    for(int i = 1; i <= 100; i++)
    {
        sum = sum + i;
    }
    printf("1~100 的和 = %d\n", sum);
    return 0;
}
