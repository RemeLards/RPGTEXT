#ifndef _LINKED_LIST_STRUCT_HOLDER_HEADER_

#define _LINKED_LIST_STRUCT_HOLDER_HEADER_

#include "linked_list.h"

typedef struct single_linked_list_holder_struct
{
    SLL_STRUCT *sll_head;
    SLL_STRUCT *sll_tail;
    int sll_size;
    
}SLL_HOLDER_STRUCT;

#endif
