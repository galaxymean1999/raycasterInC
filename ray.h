#include <raylib.h>

struct CastableRay {
    Vector2 start;
    Vector2 end;
    
    float length;
    float angle;

    bool hit;
};

typedef struct CastableRay MyRay;

MyRay castRay(Vector2 start, float angle);