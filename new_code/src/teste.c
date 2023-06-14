#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "teste.h"

int 
main(/*int agrc, char *argv[]*/)
{
    CHARACTER *personagem_ptr = (CHARACTER *) malloc (sizeof(CHARACTER));
    personagem_ptr -> character_map_position_struct_ptr = (MAP_POSITION *) malloc (sizeof(MAP_POSITION));

    personagem_ptr -> character_map_position_struct_ptr -> x_position = MAP_SIZE/2;
    personagem_ptr -> character_map_position_struct_ptr -> y_position = MAP_SIZE/2;

    int key = 0;
    system_clear();
    while (key != 'Q' && key != 'q')
    {
        key = map_map_menu(personagem_ptr,);
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

    return 0; 
}