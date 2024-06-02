#include <CGame/Math/vector2.h>
#include <math.h>

// === Float Vector2 ===

// Basic math operations on verctors.

CG_Vector2f cg_math_vector2f_add(CG_Vector2f a, CG_Vector2f b)
{
    return (CG_Vector2f){
        .x = a.x + b.x,
        .y = a.y + b.y,
    };
}
CG_Vector2f cg_math_vector2f_sub(CG_Vector2f a, CG_Vector2f b)
{
    return (CG_Vector2f){
        .x = a.x - b.x,
        .y = a.y - b.y,
    };
}
CG_Vector2f cg_math_vector2f_mul(CG_Vector2f a, CG_Vector2f b)
{
    return (CG_Vector2f){
        .x = a.x * b.x,
        .y = a.y * b.y,
    };
}
CG_Vector2f cg_math_vector2f_div(CG_Vector2f a, CG_Vector2f b)
{
    return (CG_Vector2f){
        .x = a.x / b.x,
        .y = a.y / b.y,
    };
}

// More advanced vector stuff.

CG_Vector2f cg_math_vector2f_scale(CG_Vector2f a, float scalar)
{
    return (CG_Vector2f){
        .x = a.x * scalar,
        .y = a.y * scalar,
    };
}
float cg_math_vector2f_magnitude(CG_Vector2f a)
{
    return sqrtf((a.x * a.x) + (a.y * a.y));
}
float cg_math_vector2f_dot(CG_Vector2f a, CG_Vector2f b)
{
    return (a.x * b.x) + (a.y * b.y);
}
