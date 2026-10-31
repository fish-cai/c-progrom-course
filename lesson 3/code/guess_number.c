#include <stdio.h>
int main(int argc, char const *argv[])
{
    int target = 42;    // 预设答案
    int guess, count = 0;

    printf("=== 猜数字游戏 ===\n");
    printf("我心里想了一个 1~100 的数，猜猜是几？\n");

    while(1)            // 死循环，靠 break 退出
    {
        printf("请输入你猜的数:");
        scanf("%d", &guess);
        count++;

        if(guess == target)
        {
            printf("恭喜你猜对了！共猜了 %d 次\n", count);
            break;      // 猜对了，跳出循环
        }
        else if(guess > target)
        {
            printf("大了！再小一点\n");
        }
        else
        {
            printf("小了！再大一点\n");
        }
    }
    return 0;
}
