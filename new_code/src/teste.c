#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "teste.h"

int 
main(/*int agrc, char *argv[]*/)
{
    CHARACTER *personagem_ptr = (CHARACTER *) malloc (sizeof(CHARACTER));
    personagem_ptr -> character_map_position_struct_ptr = (MAP_POSITION *) malloc (sizeof(MAP_POSITION));

    SLL_STRUCT *monster_single_linked_list = (SLL_STRUCT *) malloc (sizeof(SLL_STRUCT));
    sll_initialize(monster_single_linked_list);

    MAP* map_struct_ptr = (MAP *) malloc (sizeof(MAP));
    map_map_init(map_struct_ptr);


    personagem_ptr -> character_map_position_struct_ptr -> x_position = MAP_SIZE/2;
    personagem_ptr -> character_map_position_struct_ptr -> y_position = MAP_SIZE/2;

    int key = 0;
    system_clear();
    
    while (key != 'Q' && key != 'q')
    {
        key = map_map_menu(personagem_ptr,monster_single_linked_list,map_struct_ptr);
    }
    
    /*personagem_ptr = main_menu();

    if ( personagem_ptr == NULL ) printf("ponteiro nulo LOL");
    else 
    {
        character_print_statistics ( personagem_ptr );
        character_free_all ( personagem_ptr );
    }*/
    
    free(personagem_ptr -> character_map_position_struct_ptr);
    free(personagem_ptr);
    free(map_struct_ptr);
    

    return 0; 
}