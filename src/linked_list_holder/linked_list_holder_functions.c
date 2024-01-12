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
        sll_holder -> head = sll_remove(sll_holder -> head, data);
        sll_holder -> sll_size--;
    }
}