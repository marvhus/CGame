#include "CGame/Logger/logger.h"
#include "CGame/Math/vector2.h"
#include <CGame/Entity/entity.h>
#include <CGame/Array/dynamic.h>
#include <stdlib.h>

#include <thirdparty/Raylib/raylib.h>

void cg_entity_add(CG_Entities *entities, CG_Entity entity)
{
    CG_DA_APPEND(entities, entity);
}
void cg_entities_reserve(CG_Entities *entities, size_t count)
{
    CG_DA_RESIZE(entities, count);
}
void cg_entities_clean(CG_Entities *entities)
{
    CG_DA_CLEAN(entities);
}

void cg_entities_update(CG_Entities entities, float delta)
{
    for (size_t i = 0; i < entities.count; ++i)
    {
        CG_Entity *entity = entities.data + i;
        entity->position = cg_math_vector2f_add(entity->position,
                                                cg_math_vector2f_scale(entity->velocity, delta));
    }
}
void cg_entities_render(CG_Entities entities)
{
    for (size_t i = 0; i < entities.count; ++i)
    {
        CG_Entity entity = entities.data[i];
        switch (entity.kind) {
            case CG_ENTITY_SQUARE: {
                DrawRectangleV(
                    (Vector2){
                        .x = entity.position.x,
                        .y = entity.position.y
                    },
                    (Vector2){
                        .x = entity.size.x,
                        .y = entity.size.y
                    },
                    (Color){
                        .r = entity.data.color.r,
                        .g = entity.data.color.g,
                        .b = entity.data.color.b, .a = entity.data.color.a
                    }
                );
            } break;
            default:
                cg_log_log(CG_LOG_WARNING, "Encountered unsupported entity kind for rendering.");
        }
    }
}
