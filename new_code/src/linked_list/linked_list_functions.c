#include "linked_list_functions.h"

/************************************
Function : sll_get_data
Date : 7/16/2023
Usable? : Yes
Explanation : Returns Single Linked List Data
*************************************/ 
void*
sll_get_data( SLL_STRUCT *sll )
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
sll_get_next_sll_ptr( SLL_STRUCT *sll )
{
    return sll -> next_sll_struct;
}

/************************************
Function : sll_initialize
Date : 7/16/2023
Usable? : Yes
Explanation : Initializes all pointers inside a Single Linked List as NULL
*************************************/ 
SLL_STRUCT *
sll_initialize( void )
{
    SLL_STRUCT *sll = (SLL_STRUCT *) malloc (sizeof(SLL_STRUCT));
    sll -> data_ptr = NULL;
    sll -> next_sll_struct = NULL;
    return sll;
}

/************************************
Function : sll_get_tail_sll_ptr
Date : 7/16/2023
Usable? : Yes
Explanation : Returns Single Linked List Last Next Single Linked List pointer that isn't NULL
*************************************/ 
SLL_STRUCT *
sll_get_tail_sll_ptr( SLL_STRUCT *sll )
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
sll_add_new_tail( SLL_STRUCT *sll )
{
    SLL_STRUCT *sll_new_tail = sll_initialize();

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
sll_add_new_head( SLL_STRUCT *sll_head )
{
    SLL_STRUCT *sll_new_head = sll_initialize();
    sll_new_head -> next_sll_struct = sll_head;

    return sll_new_head;
}

/************************************
Function : sll_free_all
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts a new memory allocated monster struct on the Single Linked List Head, and the new Head points to the old SLL Head
*************************************/ 
void
sll_destroy( SLL_STRUCT* sll_head )
{
    SLL_STRUCT* next_sll = NULL;

    while ( sll_head != NULL )
    {
        if (sll_get_data(sll_head) != NULL) free(sll_get_data(sll_head)); 

        next_sll = sll_get_next_sll_ptr(sll_head);

        free(sll_head);

        sll_head = next_sll;
    }
}

/************************************
Function : sll_insert_data
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts any data type inside the Single Linked List data_ptr variable
*************************************/ 
void 
sll_insert_data( SLL_STRUCT *sll, void* data )
{
    sll -> data_ptr = data;
}

/************************************
Function : sll_remove
Date : 7/25/2023
Usable? : Yes
Explanation : Removes a Single Linked List (Node) from the sequence, when passing a respective data
*************************************/ 
SLL_STRUCT *
sll_remove( SLL_STRUCT *sll_head , void *data )
{
    SLL_STRUCT *sll_copy = NULL;
    SLL_STRUCT *sll_next = NULL;
    SLL_STRUCT *sll_to_be_removed = NULL;

    if ( sll_head -> data_ptr == data ) // We need to change head ptr
    {
        sll_to_be_removed = sll_head;
        
        sll_next = sll_get_next_sll_ptr( sll_to_be_removed );

        if ( sll_to_be_removed -> data_ptr != NULL) free( sll_to_be_removed -> data_ptr );
        if ( sll_to_be_removed != NULL) free( sll_to_be_removed );

        sll_head = sll_next;

    }

    else // We don't need to change head ptr
    {
        for ( sll_copy = sll_head; sll_get_data( sll_get_next_sll_ptr( sll_copy ) ) != data; sll_copy = sll_get_next_sll_ptr(sll_copy) );

        sll_to_be_removed = sll_get_next_sll_ptr( sll_copy ) ;

        sll_next = sll_get_next_sll_ptr( sll_to_be_removed );

        if ( sll_to_be_removed -> data_ptr != NULL ) free( sll_to_be_removed -> data_ptr );
        if ( sll_to_be_removed != NULL ) free( sll_to_be_removed );

        sll_copy -> next_sll_struct = sll_next;
    }

    return sll_head;
}


