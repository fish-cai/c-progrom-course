#include <stdio.h>
int main(int argc, char const *argv[])
{
    int score, level;
    printf("请输入分数(0-100):");
    scanf("%d", &score);

    // 先除以10，把连续分数变成离散的档位，才能用 switch
    level = score / 10;
    switch(level){
        case 10:          // 100分 和 90-99 一起，case 穿透
        case 9:
            printf("A\n");
            break;
        case 8:
            printf("B\n");
            break;
        case 7:           // 70-79 和 60-69 一起
        case 6:
            printf("C\n");
            break;
        default:          // 0-59 分
            printf("D\n");
            break;
    }
    return 0;
}
