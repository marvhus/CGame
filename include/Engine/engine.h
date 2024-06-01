#ifndef __H_ENGINE__
#define __H_ENGINE__

#include <Engine/event.h>

#include <stdint.h>

typedef struct {
    const char *window_title;
    int window_width, window_height;
    uint32_t background_color;

    void (*update_callback)(float);
    void (*render_callback)(float);
    void (*handle_event_callback)(Event);
} Engine;

void eng_start(Engine engine);
void eng_stop(void);

#endif
