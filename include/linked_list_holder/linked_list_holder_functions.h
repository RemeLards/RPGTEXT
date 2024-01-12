#ifndef _LINKED_LIST_HOLDER_FUNCTIONS_HEADER_

#define _LINKED_LIST_HOLDER_FUNCTIONS_HEADER_

#include "linked_list_holder.h"
#include "linked_list_functions.h"
#include "linked_list_constants.h"
#include <stdlib.h>

SLL_HOLDER *
sll_holder_initialize( void );

void
sll_holder_destroy( SLL_HOLDER *sll_holder );

void
sll_holder_remove_sll( SLL_HOLDER *sll_holder, void *data );

#endif