#include "linked_list_holder_functions.h"

SLL_HOLDER *
sll_holder_initialize(void)
{
    SLL_HOLDER * sll_holder = (SLL_HOLDER *) malloc (sizeof(SLL_HOLDER));
    sll_holder -> head = NULL;
    sll_holder -> tail = NULL;
    sll_holder -> sll_size = EMPTY;
    return sll_holder;
}

void
sll_holder_destroy( SLL_HOLDER *sll_holder )
{
    if ( sll_holder != NULL )
    {
        free(sll_holder);
    }
}

void
sll_holder_remove_sll( SLL_HOLDER *sll_holder, void *data )
{
    if( sll_holder != NULL )
    {
        sll_holder -> head = sll_remove( sll_holder -> head, data );
        sll_holder -> sll_size--;
        sll_holder -> tail = sll_get_tail ( sll_holder -> head );
    }
}

/************************************
Function : sll_holder_add_sll
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts a new memory allocated data on a holder.
*************************************/   

void
sll_holder_add_sll(SLL_HOLDER *sll_holder_ptr, void *data)
{
    if ( sll_holder_ptr -> head != NULL)
    {
        sll_holder_ptr -> tail = sll_add_new_tail(sll_holder_ptr -> tail);

        sll_insert_data(sll_holder_ptr -> tail, data);

        sll_holder_ptr -> sll_size++;
    }

    else 
    {
        sll_holder_ptr -> head = sll_initialize();
        sll_insert_data(sll_holder_ptr -> head, (void *) data);
        sll_holder_ptr -> tail = sll_holder_ptr -> head; // At the start head = tail
        
        sll_holder_ptr -> sll_size++;
    }
}