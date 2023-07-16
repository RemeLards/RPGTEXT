#ifndef _MAP_CONSTANTS_HEADER_

#define _MAP_CONSTANTS_HEADER_

#define MAP_SIZE 10
#define MAP_HYPHEN_SCALE 1.6
#define MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE 2
#define NO_MONSTERS 0

enum MAP_COLLISION
{
    NO_COLLISION = 0,
    COLLISION,
};

enum MAP_LEVELS
{
    TUTORIAL_LEVEL = 0,
    FOREST_LEVEL,
};

#endif