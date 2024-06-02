#include <CGame/Core/engine.h>
#include <CGame/Core/event.h>
#include <CGame/Logger/logger.h>

typedef struct {
    int number;
} Scene_State;

void scene_init(void *state);
void scene_deinit(void *state);
void scene_update(void *state, float delta);
void scene_render(void *state, float delta);
void scene_event(void *state, CG_Event event);

void game_init(CG_Engine *engine)
{
    cg_log_log(CG_LOG_INFO, "Initializing game.");

    engine->window_title = "Template\0";
    engine->window_width = 1280;
    engine->window_height = 720;

    engine->background_color = (CG_Color){.r = 0x18, .g = 0x18, .b = 0x18, .a = 0x18};

    Scene_State *state = malloc(sizeof(Scene_State));
    cg_core_scene_add((CG_Scene){
        .state  = state,
        .init   = scene_init,
        .deinit = scene_deinit,
        .update = scene_update,
        .render = scene_render,
        .event  = scene_event,
    });
}

int main(int argc, char **argv)
{
    cg_core_run(game_init);
}

void scene_init(void *_state)
{
    CG_Scene *scene = (CG_Scene *)_state;
    (void)scene;

    cg_log_log(CG_LOG_INFO, "Initializing scene.");
}

void scene_deinit(void *_state)
{
    CG_Scene *scene = (CG_Scene *)_state;
    (void)scene;

    cg_log_log(CG_LOG_INFO, "Deinitializing scene.");
}

void scene_update(void *_state, float delta)
{
    CG_Scene *scene = (CG_Scene *)_state;
    (void)scene;
}

void scene_render(void *_state, float delta)
{
    CG_Scene *scene = (CG_Scene *)_state;
    (void)scene;
}

void scene_event(void *_state, CG_Event event)
{
    CG_Scene *scene = (CG_Scene *)_state;
    (void)scene;
}
