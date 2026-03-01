#include <raylib.h>
#include <math.h>
#include "defs.h"

#include "ray.h"

float currentAngle = 0;

Vector2 playerPos = {50, 50};

void drawRays() {
    int x = 0;

    for (float angle = currentAngle - FOV / 2; angle < currentAngle + FOV / 2; angle += ANGLE_STEP) {
        MyRay *ray = MemAlloc(sizeof(MyRay));
        *ray = castRay(playerPos, angle, STEP_LIMIT);

        ray->correctedLength = ray->length * sin(90*DEG2RAD - angle + currentAngle);
        
        if (ray->hit) {
            int columnHeight = (int)(SCREEN_HEIGHT / ray->correctedLength * (TILE_SIZE / 2));

            int columnY = (int)(SCREEN_HEIGHT / 2 - columnHeight / 2);

            Color columnColor = RAYWHITE;

            /*if (((int)ray->end.x % TILE_SIZE > TILE_SIZE -2 || (int)ray->end.x % TILE_SIZE < 2) && 
            ((int)ray->end.y % TILE_SIZE > TILE_SIZE -2 || (int)ray->end.y % TILE_SIZE < 2)) {
                columnColor = GRAY;
            }*/

            switch (ray->wallTypeHit) {
                case 'X':
                    columnColor = (Color){255, 0, 0, 255};
                break;
                case '#':
                    columnColor = (Color){0, 255, 0, 255};
                break;
                case 'O':
                    columnColor = (Color){0, 0, 255, 255};
                break;
            }
            
            if (ray->wallPart == VERTICAL_WALL) {
                columnColor.r = (int)((float)columnColor.r * 0.5f);
                columnColor.g = (int)((float)columnColor.g * 0.5f);
                columnColor.b = (int)((float)columnColor.b * 0.5f);
            }

            DrawRectangle(x, columnY, 1, columnHeight, columnColor);
        }

        MemFree(ray);
        x++;
    }
}

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RAYCASTER");

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_A)) {
            currentAngle -= 1*DEG2RAD;
        }
        else if (IsKeyDown(KEY_D)) {
            currentAngle += 1*DEG2RAD;
        }

        if (IsKeyDown(KEY_W)) {
            MyRay *ray = MemAlloc(sizeof(MyRay));
            *ray = castRay(playerPos, currentAngle, 10);
            
            if (ray->hit == false) {
                playerPos.x += sinf(currentAngle);
                playerPos.y += cosf(currentAngle);
            }

            MemFree(ray);
        }
        else if (IsKeyDown(KEY_S)) {
            MyRay *ray = MemAlloc(sizeof(MyRay));
            *ray = castRay(playerPos, currentAngle - 180*DEG2RAD, 10);
            
            if (ray->hit == false) {
                playerPos.x -= sinf(currentAngle);
                playerPos.y -= cosf(currentAngle);
            }

            MemFree(ray);
        }

        BeginDrawing();
        
        ClearBackground(BLACK);

        drawRays();

        EndDrawing();
    }
}