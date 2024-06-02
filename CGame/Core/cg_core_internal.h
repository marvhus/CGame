#ifndef __H_ENG_INTERNAL__
#define __H_ENG_INTERNAL__

#include <CGame/Core/engine.h>
#include <Raylib/raylib.h>

#include <stdbool.h>
#include <stdlib.h>

extern bool is_running;
extern Color background_color;

// Open a window with the given title and dimensions.
void cg_core_window_open(const char *title, int width, int height);
// Close the current window.
void cg_core_window_close(void);
// Will be run on each frame and will handle calling the user callbacks, etc.
void cg_core_update(CG_Engine engine);

// Data structure for dynamic list of scenes.
typedef struct {
    CG_Scene *data;
    size_t count;
    size_t capacity;
} CG_Scenes;

extern CG_Scenes cg_core_scenes;
extern size_t cg_core_scene_index;
extern size_t cg_core_scene_index_prev;
extern bool cg_core_scene_just_switched;

#endif
