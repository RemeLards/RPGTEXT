#include "linked_list_holder_functions.h"

SLL_HOLDER_STRUCT *
sll_holder_initialize(void)
{
    SLL_HOLDER_STRUCT * sll_holder = (SLL_HOLDER_STRUCT *) malloc (sizeof(SLL_HOLDER_STRUCT));
    sll_holder -> sll_head = NULL;
    sll_holder -> sll_tail = NULL;
    sll_holder -> sll_size = 0;
    return sll_holder;
}

void
sll_holder_destroy( SLL_HOLDER_STRUCT *sll_holder )
{
    sll_destroy(sll_holder -> sll_head);
    free(sll_holder);
}

void
sll_holder_remove_sll( SLL_HOLDER_STRUCT *sll_holder, void *data )
{
    sll_remove(sll_holder -> sll_head, data);
    sll_holder -> sll_size--;
}