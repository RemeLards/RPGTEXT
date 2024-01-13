#include "linked_list_functions.h"

/************************************
Function : sll_get_data
Date : 7/16/2023
Usable? : Yes
Explanation : Returns Single Linked List Data
*************************************/ 
void*
sll_get_data( SLL *sll )
{
    if ( sll != NULL ) return sll -> data_ptr;
    return NULL;
}

/************************************
Function : sll_get_next
Date : 7/16/2023
Usable? : Yes
Explanation : Returns Single Linked List Next Single Linked List (AKA Next Node) pointer
*************************************/ 
SLL *
sll_get_next( SLL *sll )
{
    if ( sll != NULL ) return sll -> next;
    return NULL;
}

/************************************
Function : sll_initialize
Date : 7/16/2023
Usable? : Yes
Explanation : Initializes all pointers inside a Single Linked List as NULL
*************************************/ 
SLL *
sll_initialize( void )
{
    SLL *sll = (SLL *) malloc( sizeof(SLL) );
    sll -> data_ptr = NULL;
    sll -> next = NULL;
    return sll;
}

/************************************
Function : sll_get_tail
Date : 7/16/2023
Usable? : Yes
Explanation : Returns Single Linked List Last Next Single Linked List pointer that isn't NULL
*************************************/ 
SLL *
sll_get_tail( SLL *sll )
{
    SLL *sll_copy = NULL;
    for(sll_copy = sll; sll_get_next(sll_copy) != NULL; sll_copy = sll_get_next(sll_copy));
    return sll_copy;
}

/************************************
Function : sll_add_new_tail
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts a Single Linked List (Node) on the Tail (Last Single Linked List pointer that isn't NULL)
*************************************/ 
SLL *
sll_add_new_tail( SLL *sll )
{
    SLL *sll_new_tail  = NULL;

    if ( sll != NULL )
    {
        sll_new_tail = sll_initialize();

        SLL *sll_old_tail = sll_get_tail( sll );

        if ( sll_old_tail != NULL ) sll_old_tail -> next = sll_new_tail;
    }

    return sll_new_tail; 
}

/************************************
Function : sll_add_new_head
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts a new Single Linked List on the Head, doing that, this new SLL becomes the new SLL Head
*************************************/ 
SLL *
sll_add_new_head( SLL *sll_head )
{
    SLL *sll_new_head = sll_initialize();
    
    sll_new_head -> next = sll_head;

    return sll_new_head;
}

/************************************
Function : sll_destroy
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts a new memory allocated monster struct on the Single Linked List Head, and the new Head points to the old SLL Head
*************************************/ 
void
sll_destroy( SLL* sll_head )
{
    SLL* next_sll = NULL;

    while ( sll_head != NULL )
    {
        if (sll_get_data(sll_head) != NULL) free(sll_get_data(sll_head)); 

        next_sll = sll_get_next(sll_head);

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
sll_insert_data( SLL *sll, void* data )
{
    if(sll != NULL) sll -> data_ptr = data;
}

/************************************
Function : sll_remove
Date : 7/25/2023
Usable? : Yes
Explanation : Removes a Single Linked List (Node) from the sequence, when passing a respective data
*************************************/ 
SLL *
sll_remove( SLL *sll_head , void *data )
{
    SLL *sll_copy = NULL;
    SLL *sll_next = NULL;
    SLL *sll_to_be_removed = NULL;

    if ( sll_head -> data_ptr == data ) // We need to change head ptr
    {
        sll_to_be_removed = sll_head;
        
        sll_next = sll_get_next( sll_to_be_removed );

        if ( sll_to_be_removed -> data_ptr != NULL) free( sll_to_be_removed -> data_ptr );
        if ( sll_to_be_removed != NULL) free( sll_to_be_removed );

        sll_head = sll_next;

    }

    else // We don't need to change head ptr
    {
        for ( sll_copy = sll_head; sll_get_data( sll_get_next( sll_copy ) ) != data; sll_copy = sll_get_next(sll_copy) );

        sll_to_be_removed = sll_get_next( sll_copy ) ;

        sll_next = sll_get_next( sll_to_be_removed );

        if ( sll_to_be_removed -> data_ptr != NULL ) free( sll_to_be_removed -> data_ptr );
        if ( sll_to_be_removed != NULL ) free( sll_to_be_removed );

        sll_copy -> next = sll_next;
    }

    return sll_head;
}


