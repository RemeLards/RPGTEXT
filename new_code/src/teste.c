#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "teste.h"

int 
main(/*int agrc, char *argv[]*/)
{
    CHARACTER *personagem_ptr = character_malloc_all();

    SLL_HOLDER_STRUCT* monster_holder_ptr = sll_holder_initialize();

    MAP* map_struct_ptr = map_init();

    map_struct_ptr -> map_level = 5; //TESTING IF MOBS WILL WORK

    personagem_ptr -> character_map_position_struct_ptr -> x_position = MAP_SIZE/2;
    personagem_ptr -> character_map_position_struct_ptr -> y_position = MAP_SIZE/2;
    
    map_struct_ptr -> map[personagem_ptr -> character_map_position_struct_ptr -> y_position][personagem_ptr -> character_map_position_struct_ptr -> x_position] = 'C';

    //printf("numero aleatorio teste : %d\n",rng_generate_random_number());
    //printf("numero aleatorio teste : %d\n",rng_generate_random_number());
    //printf("numero aleatorio teste : %d\n",rng_generate_random_number());
    //getchar();
    int key = 0;
    system_clear();
    
    while (key != 'Q' && key != 'q')
    {
        //implementar os "hoaders"
        key = map_map_menu(personagem_ptr,monster_holder_ptr,map_struct_ptr);
    }
    
    /*personagem_ptr = main_menu();

    if ( personagem_ptr == NULL ) printf("ponteiro nulo LOL");
    else 
    {
        character_print_statistics ( personagem_ptr );
        character_free_all ( personagem_ptr );
    }*/
    
    character_free_all(personagem_ptr);
    free(map_struct_ptr);
    printf("\n monsters ammount = %d \n",monster_holder_ptr -> sll_size);
    sll_holder_destroy(monster_holder_ptr);
    printf("\n monster holder destroyed \n");
    getch();
    

    return 0; 
}