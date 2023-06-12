#ifndef _MAP_FUNCTIONS_HEADER_

#define _MAP_FUNCTIONS_HEADER_

#include <stdio.h>
#include "character.h"
//#include "monsters.h"
#include "keyboard_functions.h"
#include "system_functions.h"
#include "map.h"

void
map_print_map(CHARACTER *character_struct_ptr/*, MAP *map_ptr*/);

int
map_character_update_position(CHARACTER *character_struct_ptr);

void 
map_character_position_validation(CHARACTER *character_struct_ptr);

int
map_map_menu(CHARACTER *character_struct_ptr/*, MAP *map_ptr*/);

#endif