#ifndef _MONSTERS_MONSTERS_LINKED_LIST_STRUCT_HEADER_

#define _MONSTERS_MONSTERS_LINKED_LIST_STRUCT_HEADER_

#include "monsters.h"

typedef struct monsters_linked_list_struct
{
    MONSTER *monster_struct_ptr;
    MONSTER_LINKED_LIST *next_monster;

}MONSTER_LINKED_LIST;


#endif