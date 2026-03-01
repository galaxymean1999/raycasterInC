#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define FOV 90*DEG2RAD
#define ANGLE_STEP FOV/SCREEN_WIDTH

#define STEP_LIMIT 400
#define STEP_LENGTH 0.5f

#define TILE_SIZE 32
#define MAP_WIDTH 10
#define MAP_HEIGHT 10

static const char map[] = {
    '#','#','#','#','#','#','#','#','#','#',
    '#',' ',' ',' ',' ',' ',' ','#',' ','#',
    '#',' ','X',' ',' ',' ',' ','#',' ','#',
    '#',' ','X','X','X',' ',' ','#',' ','#',
    '#',' ','X',' ',' ',' ',' ',' ',' ','#',
    '#',' ',' ',' ',' ',' ',' ',' ',' ','#',
    '#',' ',' ',' ','O',' ',' ',' ',' ','#',
    '#',' ',' ',' ','O',' ',' ',' ',' ','#',
    '#',' ',' ',' ','O',' ',' ',' ',' ','#',
    '#','#','#','#','#','#','#','#','#','#',
};