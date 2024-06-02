#ifndef __H_CG_MATH_VECTOR2__
#define __H_CG_MATH_VECTOR2__

// === Float Vector2 ===

typedef struct {
    float x, y;
} CG_Vector2f;

// Basic math operations on verctors.

CG_Vector2f cg_math_vector2f_add(CG_Vector2f a, CG_Vector2f b);
CG_Vector2f cg_math_vector2f_sub(CG_Vector2f a, CG_Vector2f b);
CG_Vector2f cg_math_vector2f_mul(CG_Vector2f a, CG_Vector2f b);
CG_Vector2f cg_math_vector2f_div(CG_Vector2f a, CG_Vector2f b);

// More advanced vector stuff.

CG_Vector2f cg_math_vector2f_scale(CG_Vector2f a, float scalar);
float cg_math_vector2f_magnitude(CG_Vector2f a);
float cg_math_vector2f_dot(CG_Vector2f a, CG_Vector2f b);

#endif
