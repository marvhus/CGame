#ifndef __H_ENGINE__
#define __H_ENGINE__

#include "CGame/Core/color.h"
#include <CGame/Core/event.h>

#include <stdint.h>
#include <stdlib.h>

// The scene related data.
typedef struct {
    void *state;

    void (*init  )(void *);
    void (*update)(void *, float);
    void (*render)(void *, float);
    void (*event )(void *, CG_Event);
} CG_Scene;

// The engine configuration set by the game.
typedef struct {
    const char *window_title;
    int window_width, window_height;
    CG_Color background_color;
} CG_Engine;

// Run the game, this will run the game loop, and will block until the game is over.
void cg_core_run(void (*init_callback)(CG_Engine *));
// This will tell the engine that the current frame will be the last one.
void cg_core_stop(void);

// Add a given scene to the internal array of scenes.
void cg_core_scene_add(CG_Scene scene);
// Reserve a given amount of space for scenes so you won't have unecesary allocations.
void cg_core_scene_reserve(size_t count);
// Set the current scene. Returns 0 if successful.
int cg_core_scene_set(size_t scene_index);

#endif
