#ifndef _FIGHT_FUNCTIONS_HEADER_

#define _FIGHT_FUNCTIONS_HEADER_

//-------------------------
//HEADERS
//-------------------------

#include "linked_list_holder.h"
#include "linked_list.h"
#include "character.h"
#include "monsters.h"
#include "map.h"

#include "rng_functions.h"
#include "character_functions.h"
#include "menu_creation_functions.h"
#include "linked_list_functions.h"
#include "map_functions.h"

#include "fight_constants.h"
#include "character_constants.h"



//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

float 
fight_monsters_base_dmg_calculation(MONSTER *monster_struct_ptr);

float 
fight_character_base_dmg_calculation(CHARACTER *character_struct_ptr);

float 
fight_character_overall_dmg_calculation(CHARACTER *character_struct_ptr);

void
fight_character_death(CHARACTER *character_struct_ptr);

void
fight_character_killed_monsters(CHARACTER *character_struct_ptr, MONSTER *monster_struct_ptr);

void
fight_attack_choise_menu(CHARACTER *character_struct_ptr);

int 
fight_fight_result(CHARACTER *character_struct_ptr,MONSTER *monster_struct_ptr);

int
fight_fight_menu(MAP *map_ptr, CHARACTER *character_struct_ptr, SLL_HOLDER *monsters_holder_ptr, MONSTER *monster_struct_ptr/*, MONSTER *monster_count[]*/);

#endif
