#include <stdio.h>
int main(int argc, char const *argv[])
{
    int n;
    printf("请输入要输出的斐波那契项数:");
    scanf("%d", &n);

    // 斐波那契：前两项都是 1，从第三项起每项 = 前两项之和
    int a = 1, b = 1;

    for(int i = 1; i <= n; i++)
    {
        printf("%d ", a);      // 输出当前项
        int next = a + b;      // 计算下一项
        a = b;                 // 往后挪一位
        b = next;
    }
    printf("\n");
    return 0;
}
