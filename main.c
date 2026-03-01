#include <raylib.h>
#include "defs.h"

#include "ray.h"

float currentAngle = 0;

void DrawRays() {
    for (float angle = currentAngle - FOV / 2; angle < currentAngle + FOV / 2; angle += ANGLE_STEP) {
        MyRay *ray = MemAlloc(sizeof(MyRay));

        MemFree(ray);
    }
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RAYCASTER");

    while (!WindowShouldClose()) {

        BeginDrawing();
        
        ClearBackground(BLACK);

        EndDrawing();
    }
}