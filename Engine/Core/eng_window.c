#ifndef __H_ENG_WINDOW__
#define __H_ENG_WINDOW__

#include <Raylib/raylib.h>

#include "eng_internal.h"

void eng_window_open(const char *title, int width, int height)
{
    InitWindow(width, height, title);
    SetTargetFPS(60);
}

void eng_window_close(void)
{
    CloseWindow();
}

#endif
