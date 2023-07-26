#ifndef _DEBUG_FUNCTIONS_HEADER_

#define _DEBUG_FUNCTIONS_HEADER_

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
debug_map_status_checker( MAP *map_ptr, SLL_HOLDER_STRUCT *monster_holder, CHARACTER *character_ptr );

void
debug_print_monsters_map_pos( SLL_HOLDER_STRUCT *monster_holder );

void 
debug_print_character_map_pos( CHARACTER *character_ptr );

void 
debug_print_entity_map_pos( MAP_POSITION *entity_map_pos );

int
debug_random_character_movement_generator(void);

void
debug_print_movement_done(int key);


#endif