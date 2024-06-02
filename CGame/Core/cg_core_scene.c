#include "CGame/Core/cg_core_internal.h"
#include <CGame/Core/engine.h>

#include <stdlib.h>

#include <CGame/Array/dynamic.h>

CG_Scenes cg_core_scenes = {0};
size_t cg_core_scene_index = 0;
size_t cg_core_scene_index_prev = 0;
bool cg_core_scene_just_switched = false;

void cg_core_scene_add(CG_Scene scene)
{
    CG_DA_APPEND(&cg_core_scenes, scene);
}
void cg_core_scenes_reserve(size_t count)
{
    CG_DA_RESIZE(&cg_core_scenes, count);
}
void cg_core_scenes_clean(void)
{
    CG_DA_CLEAN(&cg_core_scenes);
}
int cg_core_scene_set(size_t scene_index)
{
    // Check if scene index is valid.
    if (scene_index < 0 && scene_index >= cg_core_scenes.capacity)
        return 1;

    cg_core_scene_index = scene_index;
    cg_core_scene_just_switched = true;

    return 0;
}
