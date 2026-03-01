#include "ray.h"
#include "defs.h"
#include <math.h>

MyRay castRay(Vector2 start, float angle) {
    MyRay returnRay;

    returnRay.start = start;
    returnRay.angle = angle;
    returnRay.length = 0;
    returnRay.hit = false;

    Vector2 currentPos = start;

    float stepX = sinf(angle) * STEP_LENGTH;
    float stepY = cosf(angle) * STEP_LENGTH;

    for (int i = 0; i < STEP_LIMIT; i++) {
        currentPos.x += stepX;
        currentPos.y += stepY;

        returnRay.length += STEP_LENGTH;

        if (map[(int)(currentPos.x / TILE_SIZE) + (int)(currentPos.y / TILE_SIZE) * MAP_WIDTH] == '#') {
            returnRay.end = currentPos;
            returnRay.hit = true;
            break;
        }
        else {
            continue;
        }
    }
    
    returnRay.end = currentPos;

    return returnRay;
}