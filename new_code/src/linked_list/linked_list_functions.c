#include "linked_list_functions.h"

void*
sll_get_data(SLL_STRUCT* sll)
{
    return sll -> data_ptr;
}

void*
sll_get_next_sll_ptr(SLL_STRUCT* sll)
{
    return sll -> next_sll_struct;
}

void*
sll_initialize(SLL_STRUCT* sll)
{
    sll -> data_ptr = NULL;
    sll -> next_sll_struct = NULL;
}

void*
sll_get_tail_sll_ptr(SLL_STRUCT* sll)
{
    SLL_STRUCT* sll_copy = NULL;
    for(sll_copy = sll; sll_get_next_sll_ptr(sll_copy) != NULL; sll_copy = sll_get_next_sll_ptr(sll_copy));
    return sll_copy;
}