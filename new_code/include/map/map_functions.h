#ifndef _MAP_FUNCTIONS_HEADER_

#define _MAP_FUNCTIONS_HEADER_

#include <stdio.h>
#include "character.h"
#include "monsters.h"
#include "monsters_functions.h"
#include "monsters_linked_list.h"
#include "keyboard_functions.h"
#include "system_functions.h"
#include "map.h"
#include "rng_functions.h"

void
map_print_map(CHARACTER *character_struct_ptr,  MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr);

int
map_character_update_position(CHARACTER *character_struct_ptr);

void 
map_character_position_validation(CHARACTER *character_struct_ptr);

void
map_monster_spawn( MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr);

void
map_monsters_update_position( MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr);

void
map_monsters_position_validation( MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr);

int
map_map_menu(CHARACTER *character_struct_ptr, MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr);



#endif