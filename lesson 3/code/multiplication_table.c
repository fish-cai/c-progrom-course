#include <stdio.h>
int main(int argc, char const *argv[])
{
    // 九九乘法表：外层控制行，内层控制列
    for(int i = 1; i <= 9; i++)        // 第 i 行
    {
        for(int j = 1; j <= i; j++)    // 第 i 行有 i 列
        {
            printf("%d×%d=%d\t", j, i, i * j);
        }
        printf("\n");                   // 一行结束换行
    }
    return 0;
}
