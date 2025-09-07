// game.c
#include "engine2d.h"
#include <stdio.h>

int main() {
    if (!engine_init(800, 600, "My 2D Game")) {
        printf("Failed to initialize engine!\n");
        return 1;
    }

    while (!engine_should_close()) {
        engine_clear(30, 30, 100); // Синий фон
        engine_update();
    }

    engine_close();
    return 0;
}