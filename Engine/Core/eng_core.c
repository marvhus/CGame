#include <Engine/Core/engine.h>
#include <Raylib/raylib.h>

#include <stdbool.h>
#include <stdint.h>

#include "eng_internal.h"

bool is_running;
Color background_color;

void eng_start(Engine engine)
{
    is_running = true;
    background_color = CLITERAL(Color){
        .r = engine.background_color >> (8 * 3) & 0xFF,
        .g = engine.background_color >> (8 * 2) & 0xFF,
        .b = engine.background_color >> (8 * 1) & 0xFF,
        .a = engine.background_color >> (8 * 0) & 0xFF,
    };
    eng_window_open(engine.window_title, engine.window_width, engine.window_height);

    while (is_running)
        eng_update(engine);

    eng_window_close();
}

void eng_update(Engine engine)
{
    float delta = 0.0f;
    engine.update_callback(delta);

    BeginDrawing();
        ClearBackground(background_color);

        engine.render_callback(delta);
    EndDrawing();

    if (WindowShouldClose() == true) is_running = false;
}

void eng_stop(void)
{
    is_running = false;
}
