🎮 GAME-ENGINE 0.1 (Russian / Русский)
Простой 2D движок на C с DLL-интерфейсом для Windows

https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white
https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white
https://img.shields.io/badge/Open_Source-MIT-green?style=for-the-badge

⚡ Возможности
✅ Создание окон

✅ Очистка экрана цветом

✅ Обработка закрытия окна

✅ Лёгкая интеграция через DLL

🚀 Быстрый старт
Сборка движка
bash
gcc -s -shared -o engine2d.dll engine2d.c -lgdi32 -Wl,--subsystem,windows
Пример использования
c
#include "engine2d.h"

int main() {
    engine_init(800, 600, "Моя Игра!");
    while (!engine_should_close()) {
        engine_clear(30, 30, 100); // Синий фон
        engine_update();
    }
    engine_close();
    return 0;
}
📁 Структура проекта
text
GAME-ENGINE-0.1-russian/
├── engine2d.h     # Заголовочный файл
├── engine2d.c     # Исходный код движка
├── example.c      # Пример игры
└── README.md      # Документация
📜 Лицензия
MIT License — можно использовать свободно, даже в коммерческих проектах!

🤝 Разработка
Приветствуются pull requests! Если хотите добавить фичи — вперёд!

