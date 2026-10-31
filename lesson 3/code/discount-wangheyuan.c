#include<stdio.h>

int main()
{
    int num;//num为数量 
    float yuanjia=0,zhekou=0,pay=0;
    //yuanjia是商品原价
    // zhekou是折扣，pay是应付价格，即折扣*原价 

    printf("请输入购物数量与总金额：");
    scanf("%d%f",&num,&yuanjia);//输入两个数给两个变量 

    if(num>=10 && yuanjia>=10000 )//两个条件同时满足：数量≥10 并且 总额≥10000
    {
        zhekou= yuanjia * 0.1 ; //折扣额 = 原价 × 10%
        pay= yuanjia - zhekou ;      //应付金额 = 原价 - 折扣额
        printf("\n折扣额是：%.2f\n应付金额是：%.2f\n",zhekou,pay);
    }
    else  printf("\n不符合优惠要求！\n");
}
