#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define FOV 90*DEG2RAD
#define ANGLE_STEP FOV/SCREEN_WIDTH

#define STEP_LIMIT 200
#define STEP_LENGTH 1.0f

#define TILE_SIZE 64
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

static const char map[] = {
    '#','#','#','#','#','#','#','#','#','#',
    '#',' ',' ',' ',' ',' ',' ','#',' ','#',
    '#',' ','#',' ',' ',' ',' ','#',' ','#',
    '#',' ','#','#','#',' ',' ','#',' ','#',
    '#',' ','#',' ',' ',' ',' ',' ',' ','#',
    '#',' ',' ',' ',' ',' ',' ',' ',' ','#',
    '#',' ',' ',' ','#',' ',' ',' ',' ','#',
    '#',' ',' ',' ','#',' ',' ',' ',' ','#',
    '#',' ',' ',' ','#',' ',' ',' ',' ','#',
    '#','#','#','#','#','#','#','#','#','#',
};