# Simple OpenGL Library

SGL is the smallest and simplest OpenGL library. It is a pure C library and provides almost perfect encapsulation of OpenGL. Users only need to focus on the specific drawing logic of OpenGL, without needing to pay attention to the complex initialization content of OpenGL. It can be used like writing a command-line program, where you only need to define three additional functions for the graphical part, which are defined in the same way as the main function.

The function signatures of these three functions are
- `void inital();`
- `void render();`
- `LRESULT CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);`
They are declared in the header file `sgl.h` and they should be implemented in your own code.

# Lanugage
- English
- [简体中文](doc/README_zh-CN.md)
- [繁體中文](doc/README_zh-TW.md)

# Usage
To use SGL, you need to include the header file `sgl.h` in your code and implement the three functions `inital()`, `render()`, and `winProc()`. Here is an example:

1. Include the header file `sgl.h` in your code:
```c
#include "sgl.h"
```

2. Implement the three functions `inital()`, `render()`, and `winProc()`:
```c
#include "sgl.h"

void inital() {
    // Initialize your application here
    // You can use OpenGL functions here
}

void render() {
    // Render the graphics here
    // You can use OpenGL functions here also
}

LRESULT CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    // Handle window messages here
    return DefWindowProc(hwnd, msg, wparam, lparam);
}
```

3. Run function `rungraph()` to start the event loop:
```c
int main() {
    rungraph(50, 50, 800, 600);
    return 0;
}
```

The window is empty now, but you can add graphics to it by implementing the `render()` function. Such as
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
You can see the colorful rectangle in the window.