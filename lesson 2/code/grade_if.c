#include <stdio.h>
int main(int argc, char const *argv[])
{
    int score;
    printf("请输入分数(0-100):");
    scanf("%d", &score);

    // 范围判断用 if-else if 最合适
    if(score >= 90){
        printf("A\n");
    }else if(score >= 80){
        printf("B\n");
    }else if(score >= 60){
        printf("C\n");
    }else{
        printf("D\n");
    }
    return 0;
}
