#include "sgl.h"

LRESULT CALLBACK winProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    case WM_ERASEBKGND:
        return TRUE;
    case WM_SIZING:
    case WM_SIZE:
        glViewport(0, 0, LOWORD(lParam), HIWORD(lParam));
        return TRUE;
    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
}