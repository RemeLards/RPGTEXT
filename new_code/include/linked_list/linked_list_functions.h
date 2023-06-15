#ifndef _LINKED_LIST_FUNCTIONS_HEADER_

#define _LINKED_LIST_FUNCTIONS_HEADER_

#include "linked_list.h"
#include <stdlib.h>

void*
sll_get_data(SLL_STRUCT* sll);

void*
sll_get_next_sll_ptr(SLL_STRUCT* sll);

void*
sll_get_tail_sll_ptr(SLL_STRUCT* sll);

void*
sll_initialize(SLL_STRUCT* sll);

#endif