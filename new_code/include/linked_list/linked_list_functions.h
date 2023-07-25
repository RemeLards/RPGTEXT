#ifndef _LINKED_LIST_FUNCTIONS_HEADER_

#define _LINKED_LIST_FUNCTIONS_HEADER_

#include "linked_list.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void *
sll_get_data(SLL_STRUCT* sll);

SLL_STRUCT *
sll_get_next_sll_ptr(SLL_STRUCT* sll);

SLL_STRUCT *
sll_get_tail_sll_ptr(SLL_STRUCT* sll);

SLL_STRUCT *
sll_initialize();

SLL_STRUCT *
sll_add_new_tail(SLL_STRUCT* sll);

SLL_STRUCT *
sll_add_new_head(SLL_STRUCT *sll_head);

void
sll_destroy(SLL_STRUCT *sll_head);

void 
sll_insert_data(SLL_STRUCT *sll, void* data);

#endif