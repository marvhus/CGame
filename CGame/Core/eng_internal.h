#ifndef __H_ENG_INTERNAL__
#define __H_ENG_INTERNAL__

#include <CGame/Core/engine.h>
#include <Raylib/raylib.h>

#include <stdbool.h>

extern bool is_running;
extern Color background_color;

// Open a window with the given title and dimensions.
void cg_core_window_open(const char *title, int width, int height);
// Close the current window.
void cg_core_window_close(void);
// Will be run on each frame and will handle calling the user callbacks, etc.
void cg_core_update(CG_Engine engine);

#endif
