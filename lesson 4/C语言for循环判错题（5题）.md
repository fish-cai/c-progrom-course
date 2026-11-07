# C语言 for 循环判错题（5 题）

> 定位：第三课 for 循环复习 / 第四课课前热身
> 适用教材：赵彦《C语言程序设计（第二版）》
> 建议用时：15 分钟　·　建议每题 3 分钟
> 要求：指出每段代码的**错误位置**、**错误类型（语法错误 / 用法错误）**，并写出**修改后的代码**

---

## 第 1 题

```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int sum = 0;
    for(int i = 0, i <= 10, i++)
    {
        sum = sum + i;
    }
    printf("%d\n", sum);
    return 0;
}
```

**要求：** 这段代码能否通过编译？如果不能，错在哪里？请改写正确。

---

## 第 2 题

```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    int i, sum = 0;
    for(i = 1; i <= 5; i++);
    {
        sum = sum + i;
    }
    printf("%d\n", sum);
    return 0;
}
```

**要求：** 这段代码能编译，但运行结果是错的。指出错误位置，说明程序实际做了什么，并改正。
（提示：正确的运行结果应该是 1+2+3+4+5 = 15）

---

## 第 3 题

```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    for(int i = 1; i <= 10; i--)
    {
        printf("%d ", i);
    }
    return 0;
}
```

**要求：** 这段代码能编译，但运行不正常。指出问题，说明运行现象，并改正。

---

## 第 4 题

```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    // 要求：输出 1~10 每个数的平方
    for(int i = 1; i < 10; i++)
    {
        printf("%d ", i * i);
    }
    return 0;
}
```

**要求：** 这段代码能编译、能运行，但没完成题目要求。指出问题（属于语法错误还是用法错误），并改正。

---

## 第 5 题

```c
#include <stdio.h>
int main(int argc, char const *argv[])
{
    for(int i = 0; i = 10; i++)
    {
        printf("%d ", i);
    }
    return 0;
}
```

**要求：** 这段代码能编译，但运行不正常。指出错误位置，说明原因，并改正。
（提示：想让 i 从 0 走到 10）

---

## 提交要求

| 题号 | 错误位置（第几部分） | 错误类型 | 修改后的代码 |
| --- | --- | --- | --- |
| 1 | | | |
| 2 | | | |
| 3 | | | |
| 4 | | | |
| 5 | | | |

> 判错题的顺序：先看**能不能编译**（语法），再看**跑出来的结果对不对**（用法）。
