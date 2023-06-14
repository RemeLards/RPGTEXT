#ifndef _MAP_MAP_STRUCT_HEADER_

#define _MAP_MAP_STRUCT_HEADER_

#include "map_constants.h"

typedef struct map_struct
{
    char map_size[MAP_SIZE][MAP_SIZE];
    int monster_count;
    int map_level;

}MAP;


#endif