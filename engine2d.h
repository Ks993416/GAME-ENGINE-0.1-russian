// engine2d.h
#ifndef ENGINE2D_H
#define ENGINE2D_H

#ifdef __cplusplus
extern "C" {
#endif

// Экспортируем функции из DLL
#ifdef _WIN32
    #ifdef ENGINE2D_EXPORTS
        #define ENGINE_API __declspec(dllexport)
    #else
        #define ENGINE_API __declspec(dllimport)
    #endif
#else
    #define ENGINE_API
#endif

// Инициализация движка
ENGINE_API int engine_init(int width, int height, const char* title);

// Закрытие движка
ENGINE_API void engine_close();

// Очистка экрана цветом
ENGINE_API void engine_clear(int r, int g, int b);

// Обновление экрана
ENGINE_API void engine_update();

// Проверка закрытия окна
ENGINE_API int engine_should_close();

#ifdef __cplusplus
}
#endif

#endif