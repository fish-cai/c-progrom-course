#include <stdio.h>
int main(int argc, char const *argv[])
{
    int score;

    // 输入校验：不合格就重新输入，直到合法为止
    // 用 do-while 只需写一次 scanf；用 while 就得在循环外先写一遍
    do
    {
        printf("请输入 0~100 的分数:");
        scanf("%d", &score);

        if(score < 0 || score > 100)
        {
            printf("输入不合法，请重新输入！\n");
        }
    }while(score < 0 || score > 100);

    printf("你输入的分数是 %d\n", score);
    return 0;
}
