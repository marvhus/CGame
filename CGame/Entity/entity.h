#ifndef __H_CG_ENTITY__
#define __H_CG_ENTITY__

#include <CGame/Core/color.h>
#include <CGame/Math/vector2.h>

#include <stdlib.h>
#include <stdbool.h>

typedef enum {
    CG_ENTITY_SQUARE,
} CG_Entity_Kind;

typedef struct {
    CG_Entity_Kind kind;

    // @TODO: add textures.
    union {
        CG_Color color;
    } data;

    // @TODO: implement gravity and physics.
    bool has_gravity;

    CG_Vector2f position;
    CG_Vector2f velocity;
    CG_Vector2f size;
} CG_Entity;

typedef struct {
    CG_Entity *data;
    size_t count;
    size_t capacity;
} CG_Entities;

// Add a given entity to the given dynamic array of entities.
void cg_entity_add(CG_Entities *entities, CG_Entity entity);
// Reserve a given amount of space in the given dynamic array so you won't have unecesary allocations.
void cg_entities_reserve(CG_Entities *entities, size_t count);
// Remove all the entities in the given dynamic array of entities.
void cg_entities_clean(CG_Entities *entities);

// Update the position of the entities based on their current velocity.
void cg_entities_update(CG_Entities entities, float delta);
// Render the entities
void cg_entities_render(CG_Entities entities);

#endif
