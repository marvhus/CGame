#include "CGame/Core/cg_core_internal.h"
#include "CGame/Logger/logger.h"
#include <CGame/Core/engine.h>

#include <stdio.h>
#include <stdlib.h>

#include <CGame/Array/dynamic.h>

CG_Scenes cg_core_scenes = {0};
size_t cg_core_scene_index = 0;
// This should start as true since the init function for the scene should run immediatly.
bool cg_core_scene_just_switched = true;

void cg_core_scene_add(CG_Scene scene)
{
    cg_log_log(CG_LOG_INFO, "Appending to scenes");
    CG_DA_APPEND(cg_core_scenes, scene);
}

void cg_core_scene_reserve(size_t count)
{
    cg_log_log(CG_LOG_INFO, "Reserving space for scenes");
    CG_DA_RESIZE(cg_core_scenes, count);
}

int cg_core_scene_set(size_t scene_index)
{
    cg_log_log(CG_LOG_INFO, "Setting current scene");
    // Check if scene index is valid.
    if (scene_index < 0 && scene_index >= cg_core_scenes.capacity)
        return 1;

    cg_core_scene_index = scene_index;
    cg_core_scene_just_switched = true;

    return 0;
}
