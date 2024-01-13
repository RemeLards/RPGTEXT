#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "teste.h"

int 
main(/*int agrc, char *argv[]*/)
{
    CHARACTER *personagem_ptr = character_malloc_all();
    character_init_all(personagem_ptr);
    character_class_selection(personagem_ptr,WARRIOR);
    character_race_selection(personagem_ptr,HUMAN);

    SLL_HOLDER* monster_holder_ptr = sll_holder_initialize();

    MAP* map_struct_ptr = map_init();

    map_struct_ptr -> map_level = 3; //TESTING IF MOBS WILL WORK

    personagem_ptr -> character_map_position_struct_ptr -> x_position = MAP_SIZE/2;
    personagem_ptr -> character_map_position_struct_ptr -> y_position = MAP_SIZE/2;
    
    map_struct_ptr -> map[personagem_ptr -> character_map_position_struct_ptr -> y_position]
                         [personagem_ptr -> character_map_position_struct_ptr -> x_position] = 'C';
    
    int key = 0;
    
    system_clear();

    map_print_map( map_struct_ptr );

    while (key != 'Q' && key != 'q')
    {
        key = map_map_menu( personagem_ptr,monster_holder_ptr,map_struct_ptr);
        //debug_map_status_checker( map_struct_ptr, monster_holder_ptr, personagem_ptr);
        //max_monsters_counter = debug_max_monster_around_char( map_struct_ptr, monster_holder_ptr, personagem_ptr, max_monsters_counter);
        debug_monster_num_map ( map_struct_ptr );
        debug_monster_num_sll_holder ( monster_holder_ptr );
    }
    
    character_free_all(personagem_ptr);
    free(map_struct_ptr);
    printf("\n monsters ammount = %d \n",monster_holder_ptr -> sll_size);
    sll_holder_destroy(monster_holder_ptr);
    printf("\n monster holder destroyed \n");
    getch();

    /*CHARACTER *character = main_menu();

    character_free_all(character);
    */
    return 0; 
}