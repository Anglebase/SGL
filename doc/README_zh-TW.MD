# 簡單OpenGL庫

SGL是最小最簡單的 OpenGL 庫。它是一個純 C 庫，幾乎完美地封裝了OpenGL。用戶只需關注 OpenGL 的具體繪圖邏輯，而無需關注 OpenGL 複雜的初始化內容。它可以像編寫命令行程序一樣使用，您只需要爲圖形部分定義三個附加函數，這些函數的定義方式與主函數的定義方式相同。

這三個函數的函數簽名是
- `void inital();`
- `void render();`
- `LRESULT CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);`

它們在頭文件`sgl.h`中聲明，需要在您自己的代碼中實現。

# 語言
- [English](../README.md)
- [简体中文](README_zh-CN.md)
- 繁體中文

# 使用方法
要使用SGL，您需要在代碼中包含頭文件`SGL.h`，並實現三個函數`inital()`、`render()`和`winProc()'。以下是一個示例：

1. 在你的代碼中包含頭文件`sgl.h`：
```c
#include "sgl.h"
```

2. 實現三個函數`inital()`、`render()`和`winProc()'：
```c
#include "sgl.h"

void inital() {
    // 初始化你的應用
    // 你可以在這裏使用OpenGL函數
}

void render() {
    // 渲染圖形
    // 你也可以在這裏使用OpenGL函數
}

LRESULT CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    // 處理窗口事件
    return DefWindowProc(hwnd, msg, wparam, lparam);
}
```

3. 運行函數`rungraph()`啓動事件循環：
```c
int main() {
    rungraph(50, 50, 800, 600);
    return 0;
}
```

現在窗口是空的，但你可以通過實現`render()`函數來添加圖形。比如：
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
你可以在窗口中看到一個彩色的矩形。