#ifndef _LINKED_LIST_FUNCTIONS_HEADER_

#define _LINKED_LIST_FUNCTIONS_HEADER_

#include "linked_list.h"
#include "linked_list_constants.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void *
sll_get_data( SLL *sll );

SLL *
sll_get_next( SLL *sll );

SLL *
sll_get_tail( SLL *sll );

SLL *
sll_initialize( void );

SLL *
sll_add_new_tail( SLL *sll );

SLL *
sll_add_new_head( SLL *head );

void
sll_destroy( SLL *head );

void 
sll_insert_data( SLL *sll, void* data );

SLL *
sll_remove( SLL *head , void *data );

#endif