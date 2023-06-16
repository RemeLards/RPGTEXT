#ifndef _LINKED_LIST_STRUCT_HEADER_

#define _LINKED_LIST_STRUCT_HEADER_

typedef struct single_linked_list_struct
{
    void *data_ptr;
    struct single_linked_list_struct *next_sll_struct;

}SLL_STRUCT;



#endif