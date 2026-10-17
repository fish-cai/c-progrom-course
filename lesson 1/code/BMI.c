#include <stdio.h>

int main(int argc, char const *argv[])
{
    double height,weight,BMI;
    scanf("%lf %lf", &height,&weight);
    BMI = weight/(height * height);
    if(BMI <= 18.4){
        printf("偏瘦");
    }else if(BMI >= 18.5 && BMI <= 23.9){
        printf("正常");
    }else if(BMI >= 24 && BMI <= 27.9){
        printf("过重");
    }else{
        printf("肥胖");
    }
}
