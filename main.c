#include <raylib.h>
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(void) {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "RAYCASTER");

    while (!WindowShouldClose()) {

        BeginDrawing();
        
        ClearBackground(BLACK);

        EndDrawing();
    }
}