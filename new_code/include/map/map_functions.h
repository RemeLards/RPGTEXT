#ifndef _MAP_FUNCTIONS_HEADER_

#define _MAP_FUNCTIONS_HEADER_

#include <stdio.h>
#include "character.h"
#include "monsters.h"
#include "monsters_functions.h"
#include "linked_list.h"
#include "linked_list_holder.h"
#include "keyboard_functions.h"
#include "system_functions.h"
#include "map.h"
#include "map_constants.h"
#include "rng_functions.h"
#include <math.h>

MAP *
map_init(void);

void
map_print_map(MAP *map_ptr);

void
map_print_map_lim(void);

int
map_character_update_position(CHARACTER *character_struct_ptr,MAP *map_ptr);

void
map_monsters_update_position( SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr);

void
map_monster_spawn(SLL_HOLDER_STRUCT *monster_holder_ptr, MAP *map_ptr);

void
map_add_entity_to_map(MAP *map_ptr, int entity_x_position, int entity_y_position, char entity);

void
map_remove_entity_from_map(MAP *map_ptr, int entity_old_x_position, int entity_old_y_position);

int
map_entity_map_limit_position_validation(MAP_POSITION *entity_map_position_struct_ptr);

int
map_collision_validation(MAP *map_ptr, int x_coordinate, int y_coordinate);

SLL_STRUCT *
map_fightable_monsters(MAP *map_ptr, CHARACTER *character_struct_ptr);

int
map_map_menu(CHARACTER *character_struct_ptr, SLL_HOLDER_STRUCT *monster_holder_ptr, MAP *map_ptr);


#endif