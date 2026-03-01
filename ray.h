#include <raylib.h>

typedef struct Ray {
    Vector2 start;
    Vector2 end;
    float length;
    float angle;
} Ray;

Ray castRay(Vector2 start, float angle);