#include <raylib.h>

#define HORIZONTAL_WALL 'h'
#define VERTICAL_WALL 'v'
#define CORNER_WALL 'c'

struct CastableRay {
    Vector2 start;
    Vector2 end;
    
    float length;
    float correctedLength;
    float angle;

    char wallTypeHit;
    char wallPart;

    bool hit;
};

typedef struct CastableRay MyRay;

MyRay castRay(Vector2 start, float angle, int maxSteps);