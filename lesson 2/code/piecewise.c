#include <stdio.h>
int main(int argc, char const *argv[])
{
    double x, y;
    printf("请输入x:");
    scanf("%lf", &x);

    // 分段函数：y = x+1 (x<=0)；y = x*x (0<x<=2)；y = x-1 (x>2)
    if(x <= 0){
        y = x + 1;
    }else if(x <= 2){
        y = x * x;
    }else{
        y = x - 1;
    }
    printf("y = %.2f\n", y);
    return 0;
}
