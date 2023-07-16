#ifndef _MONSTERS_MONSTERS_STRUCT_HEADER_

#define _MONSTERS_MONSTERS_STRUCT_HEADER_

#include "map_position.h"

typedef struct monster_struct
{
    float health;
    float defense;
    float stamina;
    float mana;
    float physical_power;
    float ability_power;
    float experience_given;
    int monster_type;
    int monster_status;
    MAP_POSITION *monster_map_position_struct_ptr;

}MONSTER;

#endif
