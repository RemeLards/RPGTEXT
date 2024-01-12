#ifndef _MAP_FUNCTIONS_HEADER_

#define _MAP_FUNCTIONS_HEADER_

#include <stdio.h>
#include <math.h>

#include "character.h"
#include "monsters.h"
#include "map.h"
#include "linked_list.h"
#include "linked_list_holder.h"

#include "keyboard_functions.h"
#include "system_functions.h"
#include "rng_functions.h"
#include "monsters_functions.h"
#include "menu_creation_functions.h"
#include "linked_list_functions.h"
#include "linked_list_holder_functions.h"
#include "fight_functions.h"

#include "map_constants.h"
#include "debug_functions.h"
#include "fight_constants.h"

MAP *
map_init(void);

void
map_print_map(MAP *map);

void
map_print_map_lim(void);

int
map_character_update_position(CHARACTER *character_struct_ptr,MAP *map_ptr);

void
map_monsters_update_position( SLL *monster_single_linked_list_head_ptr, MAP *map_ptr);

void
map_monster_spawn(SLL_HOLDER *monster_holder_ptr, MAP *map_ptr);

void
map_add_entity_to_map(MAP *map_ptr, int entity_x_position, int entity_y_position, char entity);

void
map_remove_entity_from_map(MAP *map_ptr, int entity_old_x_position, int entity_old_y_position);

int
map_entity_map_limit_position_validation(MAP_POSITION *entity_map_position_struct_ptr);

int
map_collision_validation(MAP *map_ptr, int x_coordinate, int y_coordinate);

int
map_fight_monster( MAP *map_ptr, CHARACTER *character_struct_ptr, SLL_HOLDER *monsters_holder_ptr );

MONSTER *
map_monster_chosen_to_fight( MAP *map_ptr, SLL_HOLDER *near_monster_holder);

SLL_HOLDER *
map_find_monsters_around_character( MAP *map_ptr, SLL_HOLDER *monsters_holder_ptr, CHARACTER *character_struct_ptr);

MONSTER *
map_find_monster_by_coordinates( SLL_HOLDER *monsters_holder_ptr, int monster_x, int monster_y );

void
map_show_chosen_monster_on_map(MAP *map_ptr, SLL_HOLDER *near_monster_holder, int monster_chosen);

int
map_map_in_menu_option_chosen(const char **options_names, const int num_options, const char *phrase, MAP *map);

int 
map_map_in_confirmation_menu(MAP* map);

int
map_map_menu(CHARACTER *character_struct_ptr, SLL_HOLDER *monster_holder_ptr, MAP *map_ptr);


#endif