#include "ray.h"
#include "defs.h"
#include <math.h>

MyRay castRay(Vector2 start, float angle, int maxSteps) {
    MyRay returnRay;

    returnRay.start = start;
    returnRay.angle = angle;
    returnRay.length = 0;
    returnRay.hit = false;

    Vector2 currentPos = start;

    float stepX = sinf(angle) * STEP_LENGTH;
    float stepY = cosf(angle) * STEP_LENGTH;

    for (int i = 0; i < maxSteps; i++) {
        currentPos.x += stepX;
        currentPos.y += stepY;

        returnRay.length += STEP_LENGTH;

        if (map[(int)(currentPos.x / TILE_SIZE) + (int)(currentPos.y / TILE_SIZE) * MAP_WIDTH] != ' ') {
            returnRay.wallTypeHit = map[(int)(currentPos.x / TILE_SIZE) + (int)(currentPos.y / TILE_SIZE) * MAP_WIDTH];

            returnRay.end = currentPos;
            returnRay.hit = true;
            break;
        }
        else {
            returnRay.wallTypeHit = ' ';

            continue;
        }
    }

    returnRay.correctedLength = returnRay.length;

    returnRay.end = currentPos;

    if (returnRay.hit) {
        /*if (((int)returnRay.end.x % TILE_SIZE > TILE_SIZE - 1 || (int)returnRay.end.x % TILE_SIZE < 1) && 
            ((int)returnRay.end.y % TILE_SIZE > TILE_SIZE - 1 || (int)returnRay.end.y % TILE_SIZE < 1)) {
            returnRay.wallPart = CORNER_WALL;
        }*/
        if ((int)returnRay.end.x % TILE_SIZE < TILE_SIZE - 1 && (int)returnRay.end.x % TILE_SIZE > 1) {
            returnRay.wallPart = HORIZONTAL_WALL;
        }
        else if ((int)returnRay.end.y % TILE_SIZE < TILE_SIZE - 1 && (int)returnRay.end.y % TILE_SIZE > 1) {
            returnRay.wallPart = VERTICAL_WALL;
        }
    }

    return returnRay;
}