// engine2d.c
#define ENGINE2D_EXPORTS
#include "engine2d.h"
#include <windows.h>

static HWND window;
static HDC hdc;
static int should_close = 0;

// Добавим структуру для хранения контекста рисования
typedef struct {
    HBRUSH brush;
    HPEN pen;
} GraphicsContext;

static GraphicsContext gc;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_PAINT:
            // Перерисовываем окно при необходимости
            PAINTSTRUCT ps;
            BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
            break;
        case WM_CLOSE:
            should_close = 1;
            break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

ENGINE_API int engine_init(int width, int height, const char* title) {
    HINSTANCE hInstance = GetModuleHandle(NULL);
    WNDCLASS wc = {0};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = "Engine2DClass";
    RegisterClass(&wc);

    window = CreateWindow("Engine2DClass", title, WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT, CW_USEDEFAULT, width, height,
                          NULL, NULL, hInstance, NULL);
    if (!window) return 0;

    ShowWindow(window, SW_SHOW);
    hdc = GetDC(window); // Получаем контекст устройства для рисования

    // Инициализируем кисть и перо
    gc.brush = CreateSolidBrush(RGB(0, 0, 0));
    gc.pen = CreatePen(PS_SOLID, 1, RGB(255, 255, 255));
    return 1;
}

ENGINE_API void engine_close() {
    // Удаляем GDI-объекты
    DeleteObject(gc.brush);
    DeleteObject(gc.pen);
    ReleaseDC(window, hdc);
    DestroyWindow(window);
}

ENGINE_API void engine_clear(int r, int g, int b) {
    // Создаём кисть с нужным цветом
    HBRUSH clear_brush = CreateSolidBrush(RGB(r, g, b));
    RECT rect;
    GetClientRect(window, &rect);

    // Заливаем всё окно цветом
    FillRect(hdc, &rect, clear_brush);
    DeleteObject(clear_brush);
}

ENGINE_API void engine_update() {
    // Обработка сообщений Windows
    MSG msg;
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

ENGINE_API int engine_should_close() {
    return should_close;
}