#ifndef _MAP_FUNCTIONS_HEADER_

#define _MAP_FUNCTIONS_HEADER_

#include <stdio.h>
#include "character.h"
#include "monsters.h"
#include "monsters_functions.h"
#include "linked_list.h"
#include "keyboard_functions.h"
#include "system_functions.h"
#include "map.h"
#include "map_constants.h"
#include "rng_functions.h"

void
map_map_init(MAP *map_ptr);

void
map_add_character_to_map( CHARACTER *character_struct_ptr, MAP *map_ptr );

void
map_add_monsters_to_map( SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr );

void
map_add_entities_to_map(CHARACTER *character_struct_ptr,SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr);

void
map_print_map(MAP *map_ptr);

void
map_print_map_lim();

int
map_character_update_position(CHARACTER *character_struct_ptr);

void 
map_character_position_map_limit_validation(CHARACTER *character_struct_ptr);

int
map_monster_position_monster_collision_validation(MONSTER* monster_struct_ptr, MAP* map_ptr);

void
map_monster_spawn( SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr);

void
map_monsters_update_position( SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr);

void
map_monsters_position_map_limit_validation( SLL_STRUCT *monster_single_linked_list_head_ptr);

int
map_map_menu(CHARACTER *character_struct_ptr, SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr);


#endif