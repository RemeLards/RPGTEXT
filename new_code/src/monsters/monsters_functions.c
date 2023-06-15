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
    }
    
    return goblin_monster_ptr;
}

void
monsters_malloc_next_monster_single_linked_list(SLL_STRUCT *monster_single_linked_list_head_ptr, MONSTER *monster_struct_ptr)
{
    if ( monster_single_linked_list_head_ptr -> data_ptr != NULL)
    {
        SLL_STRUCT *monster_sll_tail = sll_get_tail_sll_ptr(monster_single_linked_list_head_ptr);
        
        monster_sll_tail -> next_sll_struct = (SLL_STRUCT *) malloc (sizeof(SLL_STRUCT));
        
        sll_initialize( monster_sll_tail -> next_sll_struct ); 
        
        monster_sll_tail -> next_sll_struct -> data_ptr = (void *) monster_struct_ptr;
    }

    else monster_single_linked_list_head_ptr -> data_ptr =  (void *) monster_struct_ptr;
}



