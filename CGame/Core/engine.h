#ifndef __H_ENGINE__
#define __H_ENGINE__

#include <CGame/Core/event.h>

#include <stdint.h>

// The engine configuration set by the game.
typedef struct {
    const char *window_title;
    int window_width, window_height;
    uint32_t background_color;

    void (*update_callback)(float);
    void (*render_callback)(float);
    void (*handle_event_callback)(CG_Event);
} CG_Engine;

// Run the game, this will run the game loop, and will block until the game is over.
void cg_core_run(CG_Engine engine);
// This will tell the engine that the current frame will be the last one.
void cg_core_stop(void);

#endif
