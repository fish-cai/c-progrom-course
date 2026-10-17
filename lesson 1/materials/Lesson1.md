# Lesson1

## 环境

安装文档: environment.md

## Hello world

```c
#include <stdio.h>
int main(int argc, char *argv[]) {
    int sum = 0;
    for(int i = 0;i<=100;i++){
        sum = sum + i;
    }
    printf("%d\n",sum);
}
```

## Sum 1-100

```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sum = 0;
    for(int i = 0;i<=100;i++){
        sum = sum + i;
    }
    printf("%d\n", sum);
}

```

## Sum 1-n

```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sum = 0;
    int i;
    int n;   // 定义变量n，用来接收用户输入

    printf("请输入整数n：");
    scanf("%d", &n);   // 从控制台读取数字存入n，&不能丢！

    for(i = 0; i <= n; i++){
        sum = sum + i;
    }
    printf("%d\n", sum);  // 补上分号
    return 0;
}

```
