#ifndef _MONSTERS_FUNCTIONS_HEADER_

#define _MONSTERS_FUNCTIONS_HEADER_

#include "monsters.h"
#include "monsters_constants.h"
#include "linked_list_functions.h"
#include "linked_list_holder.h"
#include <stdlib.h>

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

MONSTER * 
monsters_goblin(int goblin_type);

void
monsters_malloc_next_monster_single_linked_list(SLL_HOLDER_STRUCT *monster_holder_ptr, MONSTER *monster_struct_ptr);

#endif