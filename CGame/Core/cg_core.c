#include <CGame/Core/engine.h>
#include <Raylib/raylib.h>

#include <stdbool.h>
#include <stdint.h>

#include "cg_core_internal.h"

bool is_running;
Color background_color;

void cg_core_run(void (*init_callback)(CG_Engine *))
{
    is_running = true;
    SetTraceLogLevel(LOG_ERROR);

    CG_Engine engine = {0};
    init_callback(&engine);

    {
        CG_Scene current = cg_core_scenes.data[cg_core_scene_index];
        current.init(current.state);
    }

    cg_core_window_open(engine.window_title, engine.window_width, engine.window_height);

    while (is_running)
        cg_core_update(engine);

    cg_core_window_close();

    {
        CG_Scene current = cg_core_scenes.data[cg_core_scene_index];
        current.deinit(current.state);
    }
}

void cg_core_update(CG_Engine engine)
{
    // @TODO: implement some actual delta time stuff.
    float delta = 0.0f;

    CG_Scene current = cg_core_scenes.data[cg_core_scene_index];

    if (cg_core_scene_just_switched) {
        CG_Scene prev = cg_core_scenes.data[cg_core_scene_index_prev];
        prev.deinit(prev.state);
        current.init(current.state);

        cg_core_scene_just_switched = false;
        cg_core_scene_index_prev = cg_core_scene_index;
    }

    current.update(current.state, delta);

    BeginDrawing();
        ClearBackground((Color){
            .r = engine.background_color.r,
            .g = engine.background_color.g,
            .b = engine.background_color.b,
            .a = engine.background_color.a
        });

        current.render(current.state, delta);
    EndDrawing();

    if (WindowShouldClose() == true) is_running = false;
}

void cg_core_stop(void)
{
    is_running = false;
}
