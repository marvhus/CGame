#ifndef __H_ENG_INTERNAL__
#define __H_ENG_INTERNAL__

#include <stdbool.h>

#include "engine.h"
#include "Thirdparty/raylib.h"

extern bool is_running;
extern Color background_color;

void eng_window_open(const char *title, int width, int height);
void eng_window_close();

void eng_update(Engine engine);

#endif
