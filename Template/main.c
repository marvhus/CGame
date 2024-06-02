#include "CGame/Core/color.h"
#include "CGame/Entity/entity.h"
#include "CGame/Math/vector2.h"
#include <CGame/Core/engine.h>
#include <CGame/Logger/logger.h>
#include <assert.h>

typedef struct {
    CG_Entities entities;
} Scene_State;

void scene_init(void *state);
void scene_deinit(void *state);
void scene_update(void *state, float delta);
void scene_render(void *state, float delta);

void game_init(CG_Engine *engine)
{
    cg_log_log(CG_LOG_INFO, "Initializing game.");

    engine->window_title = "Template\0";
    engine->window_width = 1280;
    engine->window_height = 720;

    engine->background_color = (CG_Color){.r = 0x18, .g = 0x18, .b = 0x18, .a = 0x18};

    Scene_State *state = malloc(sizeof(Scene_State));
    assert(state && "Buy more ram... faled to allocate scene state");
    cg_core_scene_add((CG_Scene){
        .state  = state,
        .init   = scene_init,
        .deinit = scene_deinit,
        .update = scene_update,
        .render = scene_render,
    });
}

int main(int argc, char **argv)
{
    cg_core_run(game_init);
}

void scene_init(void *_state)
{
    Scene_State *state = (Scene_State *) _state;
    cg_log_log(CG_LOG_INFO, "Initializing scene.");

    cg_entity_add(&state->entities, (CG_Entity){
        .kind = CG_ENTITY_SQUARE,
        .data.color = (CG_Color){.r = 0xFF, .g = 0x00, .b = 0x00, .a = 0xFF},

        .has_gravity = false,

        .position = (CG_Vector2f){.x = 10.0f, .y = 10.0f},
        .velocity = (CG_Vector2f){.x = 100.0f, .y = 100.0f},
        .size     = (CG_Vector2f){.x = 100.0f, .y = 100.0f},
    });
}

void scene_deinit(void *_state)
{
    Scene_State *state = (Scene_State *)_state;
    cg_log_log(CG_LOG_INFO, "Deinitializing scene.");

    cg_entities_clean(&state->entities);
}

void scene_update(void *_state, float delta)
{
    Scene_State *state = (Scene_State *)_state;

    cg_entities_update(state->entities, delta);
}

void scene_render(void *_state, float delta)
{
    Scene_State *state = (Scene_State *)_state;

    cg_entities_render(state->entities);
}
