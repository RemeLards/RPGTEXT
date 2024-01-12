#ifndef _CHARACTER_CHARACTER_STRUCT_HEADER_

#define _CHARACTER_CHARACTER_STRUCT_HEADER_

#include "character_skillpoints.h"
#include "character_backpack.h"
#include "character_level.h"
#include "map_position.h"


typedef struct character_struct //Implemented
{
    char *character_name;
    float base_health;
    float base_defense;
    float base_stamina;
    float base_mana;
    float base_physical_power;
    float base_physical_crit_chance;
    float base_physical_crit_dmg;
    float base_ability_power;
    float base_ability_crit_chance;
    float base_ability_crit_dmg;
    int attack_type;
    int ability_type;
    int race;
    int class;
    //char* abilities;
    SKILLPOINTS *skillpoints_struct_ptr;
    BACKPACK *backpack_struct_ptr;
    LEVEL *level_struct_ptr;
    MAP_POSITION *character_map_position_struct_ptr;
    
}CHARACTER;

#endif