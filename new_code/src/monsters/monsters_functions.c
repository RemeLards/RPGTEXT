#include "monsters_functions.h"


/*********************************
IDEA : Create a int named "type", and assign constants values to it to represent monster variations.
and depending of the monster variations, we assign different/other values to the struct, making easier
to create more monsters, and the code gets a better organization.

If we introduce graphics, it wouldn't matter because each monster needs a new model, but the code gets easier to work with.
**********************************/

/************************************
Function : monsters_goblin
Date : 5/24/2023
Usable? : Yes
Explanation : Creates a goblin struct to represent a monster, or in order words creates a goblin monster and it's variations.
*************************************/              
MONSTER *
monsters_goblin(int goblin_type) 
{
    MONSTER *goblin_monster_ptr = (MONSTER *)malloc(sizeof(MONSTER));

    //CHANGE THIS AFTER TEST
    goblin_monster_ptr -> monster_map_position_struct_ptr = (MAP_POSITION *) malloc(sizeof(MAP_POSITION));

    if (goblin_type == NORMAL_GOBLIN)
    {  
        /*
        system("cls");
        printf("\nYOU FOUND A GOLBIN!!!\n");
        printf("Press ENTER to continue");
        getchar();*/

        goblin_monster_ptr -> health = 30;
        goblin_monster_ptr -> defense = 1;
        goblin_monster_ptr -> physical_power = 0;
        goblin_monster_ptr -> ability_power = 1;
        goblin_monster_ptr -> mana = 0;
        goblin_monster_ptr -> stamina = 0;
        goblin_monster_ptr -> experience_given = 501;
        goblin_monster_ptr -> monster_type = NORMAL_GOBLIN;
        goblin_monster_ptr -> monster_status = MONSTER_ALIVE;
    
    }

    if (goblin_type == GLASSCANON_GOBLIN)
    {
        /*
        system("cls");
        printf("\nYOU FOUND A GLASS GOLBIN!!!\n");
        printf("Press ENTER to continue");
        getchar();
        */

        goblin_monster_ptr -> health = 1;
        goblin_monster_ptr -> defense = 1;
        goblin_monster_ptr -> physical_power = 1000000;
        goblin_monster_ptr -> ability_power = 1;
        goblin_monster_ptr -> mana = 0;
        goblin_monster_ptr -> stamina = 0;
        goblin_monster_ptr -> experience_given = 501;
        goblin_monster_ptr -> monster_type = GLASSCANON_GOBLIN;
        goblin_monster_ptr -> monster_status = MONSTER_ALIVE;   
    }
    
    return goblin_monster_ptr;
}

/************************************
Function : monsters_malloc_next_monster_single_linked_list
Date : 7/16/2023
Usable? : Yes
Explanation : Inserts a new memory allocated monster struct on the Monster Single Linked List Head, and the new Head points to the old SLL Head
*************************************/   

void
monsters_malloc_next_monster_single_linked_list(SLL_HOLDER_STRUCT *monster_holder_ptr, MONSTER *monster_struct_ptr)
{
    if ( monster_holder_ptr -> sll_head != NULL)
    {
        monster_holder_ptr -> sll_tail = sll_add_new_tail(monster_holder_ptr -> sll_tail);

        sll_insert_data(monster_holder_ptr -> sll_tail, (void *) monster_struct_ptr);

        monster_holder_ptr -> sll_size++;
    }

    else 
    {
        monster_holder_ptr -> sll_head = sll_initialize();
        sll_insert_data(monster_holder_ptr -> sll_head, (void *) monster_struct_ptr);
        monster_holder_ptr -> sll_tail = monster_holder_ptr -> sll_head; // At the start head = tail
        
        monster_holder_ptr -> sll_size++;
    }
}



