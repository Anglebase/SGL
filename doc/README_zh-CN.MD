# 简单OpenGL库

SGL是最小最简单的 OpenGL 库。它是一个纯 C 库，几乎完美地封装了OpenGL。用户只需关注 OpenGL 的具体绘图逻辑，而无需关注 OpenGL 复杂的初始化内容。它可以像编写命令行程序一样使用，您只需要为图形部分定义三个附加函数，这些函数的定义方式与主函数的定义方式相同。

这三个函数的函数签名是
- `void inital();`
- `void render();`
- `LRESULT CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);`

它们在头文件`sgl.h`中声明，需要在您自己的代码中实现。

# 语言
- [English](../README.md)
- 简体中文
- [繁體中文](README_zh-TW.md)

# 使用方法
要使用SGL，您需要在代码中包含头文件`SGL.h`，并实现三个函数`inital()`、`render()`和`winProc()'。以下是一个示例：

1. 在你的代码中包含头文件`sgl.h`：
```c
#include "sgl.h"
```

2. 实现三个函数`inital()`、`render()`和`winProc()'：
```c
#include "sgl.h"

void inital() {
    // 初始化你的应用
    // 你可以在这里使用OpenGL函数
}

void render() {
    // 渲染图形
    // 你也可以在这里使用OpenGL函数
}

LRESULT CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    // 处理窗口事件
    return DefWindowProc(hwnd, msg, wparam, lparam);
}
```

3. 运行函数`rungraph()`启动事件循环：
```c
int main() {
    rungraph(50, 50, 800, 600);
    return 0;
}
```

现在窗口是空的，但你可以通过实现`render()`函数来添加图形。比如：
```c
void render() {
    glClearColor(0.3f, 0.4f, 0.5f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex2f(-0.5f, 0.5f);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    glEnd();
}
```
你可以在窗口中看到一个彩色的矩形。