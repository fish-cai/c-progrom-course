#include <stdio.h>
int main(int argc, char const *argv[])
{
    int choice;

    // 菜单循环：do-while 的典型场景——先显示一次，再问要不要继续
    do
    {
        printf("\n===== 菜单 =====\n");
        printf("1. 开始\n");
        printf("2. 设置\n");
        printf("0. 退出\n");
        printf("请选择:");
        scanf("%d", &choice);

        if(choice == 0)
        {
            printf("再见！\n");
        }
        else if(choice == 1)
        {
            printf("开始执行...\n");
        }
        else if(choice == 2)
        {
            printf("进入设置...\n");
        }
        else
        {
            printf("无效选项，请重新选择\n");
        }
    }while(choice != 0);      // 选 0 才退出

    return 0;
}
