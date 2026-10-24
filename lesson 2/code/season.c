#include <stdio.h>
int main(int argc, char const *argv[])
{
    int month;
    printf("请输入月份(1-12):");
    scanf("%d", &month);

    // 有意利用 case 穿透：多个 case 执行同一段逻辑
    switch(month){
        case 3:
        case 4:
        case 5:
            printf("春季\n");
            break;
        case 6:
        case 7:
        case 8:
            printf("夏季\n");
            break;
        case 9:
        case 10:
        case 11:
            printf("秋季\n");
            break;
        case 12:
        case 1:
        case 2:
            printf("冬季\n");
            break;
        default:
            printf("月份输入错误\n");
            break;
    }
    return 0;
}
