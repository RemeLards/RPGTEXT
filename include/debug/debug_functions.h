#ifndef _DEBUG_FUNCTIONS_HEADER_

#define _DEBUG_FUNCTIONS_HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#include "map.h"
#include "linked_list_holder.h"
#include "monsters.h"
#include "character.h"

#include "map_constants.h"
#include "keyboard_constants.h"

#include "linked_list_functions.h"
#include "system_functions.h"
#include "map_functions.h"

void
debug_map_status_checker( MAP *map_ptr, SLL_HOLDER *monster_holder, CHARACTER *character_ptr );

void
debug_print_monsters_map_pos( SLL_HOLDER *monster_holder );

void 
debug_print_character_map_pos( CHARACTER *character_ptr );

void 
debug_print_entity_map_pos( MAP_POSITION *entity_map_pos );

int
debug_random_character_movement_generator( void );

void
debug_print_movement_done( int key );

int
debug_all_monsters_around_char( CHARACTER *character_struct_ptr, SLL_HOLDER *near_monsters_holder );

int
debug_monster_around_char( MONSTER *monster, int char_x, int char_y, int error_counter );

int 
debug_max_monster_around_char( MAP *map_ptr, SLL_HOLDER *monsters_holder, CHARACTER *character_struct_ptr, int max_monsters_counter );

void
debug_monster_num_map( MAP *map_ptr );

void
debug_monster_num_sll_holder( SLL_HOLDER *monsters_holder );

void
debug_monster_sll_holder_equal_monster_map_num ( MAP *map_ptr, SLL_HOLDER *monsters_holder );


#endif