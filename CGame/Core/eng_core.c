#include <CGame/Core/engine.h>
#include <Raylib/raylib.h>

#include <stdbool.h>
#include <stdint.h>

#include "eng_internal.h"

bool is_running;
Color background_color;

void cg_core_run(CG_Engine engine)
{
    is_running = true;
    background_color = CLITERAL(Color){
        .r = engine.background_color >> (8 * 3) & 0xFF,
        .g = engine.background_color >> (8 * 2) & 0xFF,
        .b = engine.background_color >> (8 * 1) & 0xFF,
        .a = engine.background_color >> (8 * 0) & 0xFF,
    };
    SetTraceLogLevel(LOG_NONE);
    cg_core_window_open(engine.window_title, engine.window_width, engine.window_height);

    while (is_running)
        cg_core_update(engine);

    cg_core_window_close();
}

void cg_core_update(CG_Engine engine)
{
    float delta = 0.0f;
    engine.update_callback(delta);

    BeginDrawing();
        ClearBackground(background_color);

        engine.render_callback(delta);
    EndDrawing();

    if (WindowShouldClose() == true) is_running = false;
}

void cg_core_stop(void)
{
    is_running = false;
}
