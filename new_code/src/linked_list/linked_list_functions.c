#include "linked_list_functions.h"

/************************************
Function : sll_get_data
Date : 7/16/2023
Usable? : Yes
Explanation : Returns Single Linked List Data
*************************************/ 
void*
sll_get_data(SLL_STRUCT *sll)
{
    return sll -> data_ptr;
}

/************************************
Function : sll_get_next_sll_ptr
Date : 7/16/2023
Usable? : Yes
Explanation : Returns Single Linked List Next Single Linked List (AKA Next Node) pointer
*************************************/ 
SLL_STRUCT *
sll_get_next_sll_ptr(SLL_STRUCT *sll)
{
    return sll -> next_sll_struct;
}

/************************************
Function : sll_initialize
Date : 7/16/2023
Usable? : Yes
Explanation : Initializes all pointers inside a Single Linked List as NULL
*************************************/ 
void
sll_initialize(SLL_STRUCT *sll)
{
    sll -> data_ptr = NULL;
    sll -> next_sll_struct = NULL;
}

/************************************
Function : sll_get_tail_sll_ptr
Date : 7/16/2023
Usable? : Yes
Explanation : Returns Single Linked List Last Next Single Linked List pointer that isn't NULL
*************************************/ 
SLL_STRUCT *
sll_get_tail_sll_ptr(SLL_STRUCT *sll)
{
    SLL_STRUCT *sll_copy = NULL;
    for(sll_copy = sll; sll_get_next_sll_ptr(sll_copy) != NULL; sll_copy = sll_get_next_sll_ptr(sll_copy));
    return sll_copy;
}

/************************************
Function : sll_add_new_tail
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts a Single Linked List (Node) on the Tail (Last Single Linked List pointer that isn't NULL)
*************************************/ 
SLL_STRUCT *
sll_add_new_tail(SLL_STRUCT *sll)
{
    SLL_STRUCT *sll_new_tail = (SLL_STRUCT *) malloc (sizeof(SLL_STRUCT));
    sll_initialize(sll_new_tail);

    SLL_STRUCT *sll_old_tail = sll_get_tail_sll_ptr(sll);
    sll_old_tail -> next_sll_struct = sll_new_tail;
        

    return sll_new_tail; 
}

/************************************
Function : sll_add_new_head
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts a new Single Linked List on the Head, doing that, this new SLL becomes the new SLL Head
*************************************/ 
SLL_STRUCT *
sll_add_new_head(SLL_STRUCT *sll)
{
    SLL_STRUCT *sll_new_head = (SLL_STRUCT *) malloc (sizeof(SLL_STRUCT));
    sll_initialize(sll_new_head);
    sll_new_head -> next_sll_struct = sll;

    return sll_new_head;
}

/************************************
Function : sll_free_all
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts a new memory allocated monster struct on the Single Linked List Head, and the new Head points to the old SLL Head
*************************************/ 
void
sll_free_all(SLL_STRUCT* sll)
{
    SLL_STRUCT* next_sll = NULL;

    while ( sll != NULL )
    {
        if (sll_get_data(sll) != NULL) free(sll_get_data(sll)); 

        next_sll = sll_get_next_sll_ptr(sll);

        free(sll);

        sll = next_sll;
    }
}

/************************************
Function : sll_insert_data
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts any data type inside the Single Linked List data_ptr variable
*************************************/ 
void 
sll_insert_data(SLL_STRUCT *sll, void* data)
{
    sll -> data_ptr = data;
}