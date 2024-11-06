// This is a header-only C library for creating an OpenGL window and rendering graphics.
// It is based on the Windows API and uses the OpenGL library provided by the system.
// This file is released under the MIT license(See it at the end of this file).
#ifndef _EGL_H_
#define _EGL_H_

#ifndef UNICODE
#define UNICODE
#endif
#ifndef _UNICODE
#define _UNICODE
#endif

#define GLE_VERSION_X "0"   // major version number
#define GLE_VERSION_Y "1"   // minor version number
#define GLE_VERSION_Z "0"   // revision number
#define GLE_VERSION_STRING GLE_VERSION_X "." GLE_VERSION_Y "." GLE_VERSION_Z // complete version number

#include<Windows.h>
 // It needs OpenGL!
#include<GL/GL.h>

// This preprocessor code is used to configure the depentdent environment of this library.
// If you define The macro 'NOWARN', it will not show any warning messages
// when you are not using Visual Studio.
// If you define the macro 'RELEASE', it will add the necessary linker options
// to create a release version (without the console window) of your program.
#ifdef _MSC_VER
#   pragma comment(lib,"opengl32.lib")
#   pragma comment(lib,"gdi32.lib")
#   ifdef RELEASE
#       pragma comment(linker,"/ENTRY:mainCRTStartup")
#       pragma comment(linker,"/SUBSYSTEM:WINDOWS")
#   endif
#else   // such as MinGW or Clang.
#   ifndef NOWARN
#       warning "You may need to add '-lopengl32 -lgdi32' to your linker options because you are not using Visual Studio"
#       ifdef RELEASE
#           warning "You may need to add '-mwindows' to your compiler options because you are not using Visual Studio"
#       endif
#   endif
#endif

static BOOL _registerWindowClass(WNDPROC WinProc) {
    WNDCLASSEX wc = { 0 };
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = WinProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wc.lpszClassName = L"GLEAppWindowClass";
    if (!RegisterClassEx(&wc)) {
        return FALSE;
    }
    return TRUE;
}

static HWND _createWindow(int x, int y, int width, int height) {
    return CreateWindowEx(
        0,
        L"GLEAppWindowClass",
        L"GLE " GLE_VERSION_STRING,
        WS_OVERLAPPEDWINDOW,
        x, y, width, height,
        NULL,
        NULL,
        GetModuleHandle(NULL),
        NULL
    );
}

// This function is called only once after the environment is set up.
// This function must be defined by the user.
void inital();
// This function is called in the every cycle of the event loop.
// This function must be defined by the user.
void render();
// This function is called if a message is received.
// This function must be defined by the user.
LRESULT CALLBACK winProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

// This function will enter the event loop and start the rendering process.
// It will return TRUE if the program is normal, or FALSE if the program is terminated.
// The x, y, width, and height parameters are the position and size of the window.
static BOOL rungraph(int x, int y, int width, int height) {
    _registerWindowClass(&winProc);
    HWND hWnd = _createWindow(x, y, width, height);
    if (!hWnd)
        return FALSE;
    // create the OpenGL context
    PIXELFORMATDESCRIPTOR pfd = {};
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    HDC hDC = GetDC(hWnd);
    int pixelFormat = ChoosePixelFormat(hDC, &pfd);
    if (!pixelFormat) {
        ReleaseDC(hWnd, hDC);
        return FALSE;
    }
    if (!SetPixelFormat(hDC, pixelFormat, &pfd)) {
        ReleaseDC(hWnd, hDC);
        return FALSE;
    }
    HGLRC hRC = wglCreateContext(hDC);
    if (!hRC)
        return FALSE;
    if (!wglMakeCurrent(hDC, hRC))
        return FALSE;
    wglMakeCurrent(hDC, hRC);
    inital();
    // show window
    ShowWindow(hWnd, SW_SHOW);
    UpdateWindow(hWnd);
    // enter the event loop
    MSG msg;
    while (1) {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT)
                break;
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        render();
        SwapBuffers(hDC);   // double buffering
    }
    return TRUE;
}

#endif

/*
MIT License

Copyright (c) 2024 Weiyi Anglebase

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/