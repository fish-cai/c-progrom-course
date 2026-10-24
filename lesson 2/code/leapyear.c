#include <stdio.h>
int main(int argc, char const *argv[])
{
    int year;
    printf("请输入年份:");
    scanf("%d", &year);

    // 闰年：能被4整除 且 不能被100整除；或者 能被400整除
    // 用到了取模% 和逻辑与&&、逻辑或||
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        printf("%d 是闰年\n", year);
    }else{
        printf("%d 不是闰年\n", year);
    }
    return 0;
}
