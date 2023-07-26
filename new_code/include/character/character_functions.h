#ifndef _CHARACTER_FUNCTIONS_HEADER_

#define _CHARACTER_FUNCTIONS_HEADER_

//-------------------------
//HEADERS
//-------------------------

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "character_constants.h"
#include "character.h"
#include "system_functions.h"

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

void
character_race_selection(CHARACTER *character_struct_ptr,int race);

void
character_class_selection(CHARACTER *character_ptr,int class);

void
character_init_skillpoints(CHARACTER *character_struct_ptr);

void
character_attributes(CHARACTER *character_struct_ptr, int option, int key);

void
character_attributes_stats_calculation(CHARACTER *character_struct_ptr);

void
character_init_level(CHARACTER *character_ptr);

float
character_exp_to_nextlevel_calculation(CHARACTER *character_struct_ptr);
                                 
void
character_level_calculation(CHARACTER *character_struct_ptr);

void
character_print_statistics(CHARACTER *character_struct_ptr);

void
character_print_attributes(CHARACTER *character_struct_ptr, int index);

void
character_init_all(CHARACTER *character_struct_ptr);

CHARACTER *
character_malloc_all(void);

void 
character_free_all(CHARACTER *character_struct_ptr);

void
character_init_character(CHARACTER *character_struct_ptr);

void
character_init_character_position(CHARACTER *character_struct_ptr);


#endif
