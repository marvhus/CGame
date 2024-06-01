#ifndef __H_ENG_INTERNAL__
#define __H_ENG_INTERNAL__

#include <Engine/engine.h>
#include <Raylib/raylib.h>

#include <stdbool.h>

extern bool is_running;
extern Color background_color;

void eng_window_open(const char *title, int width, int height);
void eng_window_close(void);

void eng_update(Engine engine);

#endif
