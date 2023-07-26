#ifndef _MAP_MAP_STRUCT_HEADER_

#define _MAP_MAP_STRUCT_HEADER_

#include "map_constants.h"

typedef struct map_struct
{
    char map[MAP_SIZE][MAP_SIZE];
    int resource_count;
    int map_level;

}MAP;


#endif