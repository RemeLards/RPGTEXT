#ifndef _MONSTERS_FUNCTIONS_HEADER_

#define _MONSTERS_FUNCTIONS_HEADER_

#include "monsters.h"
#include "monsters_constants.h"
#include "monsters_linked_list.h"
#include "linked_list_functions.h"
#include <stdlib.h>

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

MONSTER * 
monsters_goblin(int goblin_type);

void
monsters_malloc_next_monster_single_linked_list(SLL_STRUCT *monster_single_linked_list_head_ptr, MONSTER *monster_struct_ptr);

#endif