#include <stdio.h>
int main(int argc, char const *argv[])
{
    int num;
    printf("请输入一个整数:");
    scanf("%d", &num);

    // if-else if 多分支：从上往下判断，命中一个就结束
    if(num > 0){
        printf("正数\n");
    }else if(num < 0){
        printf("负数\n");
    }else{
        printf("零\n");
    }
    return 0;
}
