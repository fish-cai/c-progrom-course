# VS Code + C 语言开发环境搭建（从零到 Hello World）· Mac / Windows 双系统版

> 适用：C语言程序设计课程·单元1「让我们和计算机对话吧！」
> 本文档覆盖 **Mac 版**和 **Windows 版**，全程约 10 分钟，跟着做即可跑通第一个 C 程序。

---

## 目录

1. 总体思路
2. 第一步：安装编译器（Mac 用 Clang / Windows 用 MinGW）
3. 第二步：安装 VS Code
4. 第三步：安装两个关键插件
5. 第四步：打开文件夹工作区
6. 第五步：配置代码提示（IntelliSense）
7. 第六步：编写 hello.c
8. 第七步：编译并运行
9. 代码逐行讲解
10. 新手最容易踩的 5 个坑
11. 验证清单

---

## 一、总体思路

一个 C 程序从写出来到能跑，需要两样东西：

| 需要什么 | 用来干什么                         | 对应工具          |
| -------- | ---------------------------------- | ----------------- |
| 编辑器   | 写代码的地方，有语法高亮和提示     | VS Code           |
| 编译器   | 把代码翻译成计算机能执行的机器指令 | Clang（Mac 自带） |

> **一句话记住**：VS Code 负责「写」，Clang 负责「编译」。两者缺一不可。

> 编译原理补充：C 代码从写出来到跑起来，要经过 4 步——
> **预处理 → 编译 → 汇编 → 链接**。
> 预处理处理 `#include`、`#define`；编译把代码翻译成汇编；汇编翻译成机器码（0101）；链接把 `printf` 等库函数拼进来。Mac 用 `clang`、Windows 用 `gcc`，都是一条命令把四步全做了。

---

## 二、第一步：安装编译器（Mac 用 Clang / Windows 用 MinGW）

C 语言编译器两个系统不一样：

- **Mac** 自带 Clang（通过命令行工具包安装）
- **Windows** 需要自己装 MinGW-w64，它提供 `gcc` 编译器

下面按你的系统选择对应小节操作。

---

### Mac 版：安装 Clang

打开 Mac 的「终端」（Terminal，按 `Command + 空格` 搜索即可），执行：

```bash
xcode-select --install
```

系统会弹出安装提示，点「安装」等待完成即可。

**验证是否装好：**

```bash
clang --version
```

- 能输出版本号 → 说明安装成功，继续下一步。
- 提示 `command not found` → 说明没装成功，重新执行上面的安装命令。

> **讲解：为什么 Mac 只装 Command Line Tools？**
> 很多同学误以为写 C 必须装完整的 Xcode（十几个 G）。其实只需要它的命令行工具包（几百 M），里面就带 Clang 编译器。完全够用，下载快得多。

---

### Windows 版：安装 MinGW-w64（自带 gcc）

Windows 不自带 C 编译器，需要安装 **MinGW-w64**（一个 Windows 上的 C/C++ 编译器套件，提供 `gcc` 命令）。

**方法一（推荐，最简单）：通过 MSYS2 安装**

1. 到官网下载 MSYS2 安装包并安装：

   ```
   https://www.msys2.org
   ```
2. 安装完成后，在「开始菜单」打开 **MSYS2 MINGW64**（注意选 MINGW64 这个，不是 MSYS2 那个）
3. 在弹出的命令行窗口里输入并回车：

   ```bash
   pacman -S mingw-w64-x86_64-gcc
   ```

   提示确认时一路按 `Y` 回车，等待下载安装完成。
4. 关掉这个窗口，重新打开，输入验证：

   ```bash
   gcc --version
   ```

**方法二：安装 TDM-GCC（傻瓜式，适合新手）**

1. 到官网下载 `tdm-gcc` 安装包：

   ```
   https://jmeubank.github.io/tdm-gcc/
   ```
2. 双击安装，一路点「Next」默认安装即可，安装器会自动把它加入系统环境变量。
3. 打开新的「命令提示符」（Win + R 输入 `cmd`），输入验证：

   ```bash
   gcc --version
   ```

**验证是否装好（两种方法通用）：**

```bash
gcc --version
```

- 能输出版本号 → 说明安装成功，继续下一步。
- 提示 `'gcc' 不是内部或外部命令` → 说明没加入环境变量（PATH），去系统设置里把 gcc 的 `bin` 目录加进 PATH，或改用方法二 TDM-GCC。

> **讲解：为什么 Windows 要装 gcc 而不是 clang？**
> Windows 上最主流的开源 C 编译器是 MinGW 提供的 **gcc**，跟 Mac 的 Clang 功能等价，都遵循 C 标准。基础 C 语法两者完全一致，课程里的代码都能跑，不影响学习。
> 装好后，后面编译命令把 Mac 的 `clang` 换成 `gcc` 即可（见第七步）。

---

## 三、第二步：安装 VS Code

官网下载 Mac 版并安装：

```
https://code.visualstudio.com
```

- 双击下载的 `.zip` 解压，把 `Visual Studio Code` 拖进「应用程序」文件夹即可。
- 第一次打开若提示「无法打开，因为来自身份不明的开发者」，去「系统设置 → 隐私与安全性」点「仍要打开」即可。

---

## 四、第三步：安装两个关键插件

打开 VS Code，按 `Command + Shift + X` 打开扩展商店，依次搜索并安装：

### 1. 微软官方 C/C++ 插件（必装）

- 搜索：`C/C++`
- 作者：**Microsoft**（蓝底白色 m 图标）

作用：

- 提供代码提示（IntelliSense），输入 `pri` 会自动弹出 `printf`
- 语法高亮、跳转定义、调试支持

> **警告：不要同时装 `clangd` 插件！**
> `clangd` 和微软 C/C++ 是两个不同的「语言服务器」，同时装会冲突，导致代码提示直接失效。

### 2. Code Runner（强烈推荐）

- 搜索：`Code Runner`
- 作者：Jun Han

作用：

- 一键运行代码，点右上角 ▶ 按钮（或快捷键 `Control + Option + N`）直接编译运行并显示结果，不需要手动敲命令。
- 日常快速运行看结果。

> **注意区分：**
>
> - **Code Runner** 只管「一键运行」，不提供代码提示。
> - **C/C++ 插件** 才管「代码提示」。
>   两个都要装，各干各的活。

---

## 五、第四步：打开文件夹工作区（关键一步！）

这一步非常容易踩坑，很多同学只把单个 `.c` 文件拖进 VS Code，导致代码提示失效。

**正确做法：**

1. VS Code 菜单栏 → **文件 → 打开文件夹**
2. 选择一个专门用来放 C 代码的文件夹（比如新建一个 `C语言程` 文件夹）
3. 在左侧资源管理器里新建文件

> **为什么必须打开文件夹？**
> 代码提示（IntelliSense）需要基于「整个工作区」来分析，单独拖一个文件进去没有工作区环境，插件不知道该分析哪些文件、去哪找头文件。所以记住口诀：**先开文件夹，再建 .c 文件**。

---

## 六、第五步：配置代码提示（IntelliSense）

正常情况下，装好 C/C++ 插件 + 打开文件夹后，提示就能用了。如果仍然没有提示，手动配置一次：

1. 按 `Command + Shift + P` 打开命令面板

2. 输入并选择：`C/C++: Edit Configurations (UI)`

3. 在弹出的界面填写：

   **Mac 专用：**

   - **Compiler path**：`/usr/bin/clang`
   - **C standard**：`c17`
   - **IntelliSense mode**：`macos-clang-arm64`（M 系列芯片 Mac）或 `macos-clang-x64`（Intel Mac）

   **Windows 专用（装的是 MinGW/gcc）：**

   - **Compiler path**：填你的 gcc 路径，通常是 `C:\msys64\mingw64\bin\gcc.exe`（MSYS2 默认）或 `C:\TDM-GCC-64\bin\gcc.exe`（TDM-GCC 默认）
   - **C standard**：`c17`
   - **IntelliSense mode**：`windows-gcc-x64`

保存后，会在当前文件夹自动生成 `.vscode/c_cpp_properties.json` 配置文件，内容类似：

```json
{
    "configurations": [
        {
            "name": "Mac",
            "includePath": ["${workspaceFolder}/**"],
            "defines": [],
            "macFrameworkPath": [
                "/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library/Frameworks"
            ],
            "compilerPath": "/usr/bin/clang",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "macos-clang-arm64"
        }
    ],
    "version": 4
}
```

**如果你在 Windows（装的是 MinGW/gcc），JSON 对应改成这样：**

```json
{
    "configurations": [
        {
            "name": "Windows",
            "includePath": ["${workspaceFolder}/**"],
            "defines": [],
            "compilerPath": "C:\\msys64\\mingw64\\bin\\gcc.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "windows-gcc-x64"
        }
    ],
    "version": 4
}
```

> 注意：Windows 没有 `macFrameworkPath` 那一项（那是 Mac 专属），不要照抄。`compilerPath` 里的反斜杠要写成 `\\`（双反斜杠，JSON 转义）。

**提示失效时的急救办法：**
按 `Command + Shift + P` → 输入 `C/C++: Reset IntelliSense Database` → 重置后重启 VS Code。

---

## 七、第六步：编写 hello.c

在打开的文件夹里新建文件，**必须命名为 `hello.c`**：

```c
#include <stdio.h>

int main(void)
{
    printf("Hello, World!\n");
    return 0;
}
```

> **注意：文件后缀必须是 `.c`！**
>
> - `.c` = C 语言文件
> - `.cpp` = C++ 语言文件
>   如果保存成 `.txt`，编译器不认识，直接报错。

---

## 八、第七步：编译并运行

### 方法一：Code Runner 一键运行（推荐日常用）

点右上角 ▶ 按钮（或按 `Control + Option + N`），下方终端直接输出结果。

### 方法二：终端手动编译

**Mac 版（用 Clang）：**

```bash
clang hello.c -o hello
./hello
```

- `clang hello.c`：编译 hello.c
- `-o hello`：把生成的可执行文件命名为 `hello`
- `./hello`：运行这个程序（`./` 表示当前目录）

**Windows 版（用 MinGW 的 gcc）：**

在「命令提示符」（cmd）或 VS Code 的终端里：

```bash
gcc hello.c -o hello.exe
hello.exe
```

- `gcc hello.c`：编译 hello.c（注意是 `gcc` 不是 `clang`）
- `-o hello.exe`：把生成的可执行文件命名为 `hello.exe`
- `hello.exe`：直接输入文件名运行（Windows 不要求 `./` 前缀）

运行后终端输出（两个系统都一样）：

```
Hello, World!
```

> **讲解：这条命令在干嘛？**
> `clang hello.c -o hello`（Mac）或 `gcc hello.c -o hello.exe`（Windows）都是一行做完预处理、编译、汇编、链接四步，把 C 代码变成可执行文件；
> 然后运行这个程序，`printf` 才会在屏幕上打印文字。

---

## 九、代码逐行讲解

```c
#include <stdio.h>          // ① 预处理指令：引入标准输入输出库，printf 在这里
int main(void)              // ② 主函数：程序唯一入口，从这一行开始执行
{                           // ③ 函数体开始
    printf("Hello, World!\n"); // ④ 打印文字，\n 是换行
    return 0;               // ⑤ 返回 0，告诉操作系统程序正常结束
}                           // ⑥ 函数体结束
```

| 行                   | 作用       | 讲解要点                                                            |
| -------------------- | ---------- | ------------------------------------------------------------------- |
| `#include <stdio.h>` | 引入头文件 | 不是普通语句，是给**预处理器**看的，编译前把 stdio.h 内容插进来     |
| `int main(void)`     | 主函数入口 | `int` 表示函数最后要返回整数，`void` 表示不接收参数                 |
| `printf("...\n");`   | 打印输出   | `\n` 是换行符，等于按回车；字符串用**双引号**                       |
| `return 0;`          | 返回状态码 | 0 表示正常结束，非 0 表示出错；这是给操作系统看的，不会打印在屏幕上 |

> **return 0 小知识**：`main` 是特殊函数，如果末尾不写 `return 0;`，C 标准会自动帮你补上。但规范代码建议显式写上。

---

## 十、新手最容易踩的 5 个坑

1. **用了中文分号、中文引号**

   - C 只认英文半角符号。报错第一件事：检查输入法是不是切到英文了。

2. **忘写 `#include <stdio.h>`**

   - `printf` 在这个头文件里，不写它编译器找不到这个函数，直接报错。

3. **文件保存成 `.txt`**

   - 必须 `.c` 后缀，否则编译器不把它当 C 代码。

4. **拼写错误**

   - `mian` 写成 `main`、`print` 写成 `printf`——编译器不帮你猜，仔细核对。

5. **把 C++ 代码当成 C 来编译**

   - 如果你写了 `#include <iostream>`、`std::cout`，那是 **C++ 语法**，C 语言不认识。
   - 正确做法：C++ 代码存成 `.cpp` 文件，用 `clang++` 编译；C 代码存成 `.c` 文件，用 `clang` 编译。

---

## 十一、验证清单

做完以上步骤，逐项确认：

- [ ] 编译器装好（Mac：`clang --version`；Windows：`gcc --version` 能输出版本号）
- [ ] VS Code 已安装，C/C++ 插件已装
- [ ] 已「打开文件夹」工作区，而不是只拖单个文件
- [ ] `hello.c` 文件已创建，后缀是 `.c`
- [ ] 输入 `pri` 能弹出 `printf` 提示（IntelliSense 生效）
- [ ] 运行后终端输出 `Hello, World!`

全部打勾，你的第一个 C 程序就跑通了，可以正式开始学 C 了。
