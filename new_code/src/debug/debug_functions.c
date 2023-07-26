#include "debug_functions.h"

#define NUMBER_OF_POSSIBLE_MOVEMENTS 4 // W (UP), S (DOWN), A (LEFT), D (RIGHT)

void
debug_map_status_checker( MAP *map_ptr, SLL_HOLDER_STRUCT *monster_holder, CHARACTER *character_ptr )
{
    int monsters_alive = monster_holder -> sll_size;
    int monster_on_map = 0;
    int character_on_map = 0;

    for ( int y = 0; y < MAP_SIZE; y++ )
    {
        for ( int x = 0; x < MAP_SIZE; x++)
        {
            if ( map_ptr -> map[y][x] == 'M') monster_on_map++;
            if ( map_ptr -> map[y][x] == 'C') character_on_map++;
        }
    }


    if ( (monsters_alive != monster_on_map) || (character_on_map != 1 ) ) /*Currently on single player, there's one character*/
    {
        printf("\n");

        map_print_map( map_ptr );

        printf("\n monsters alive = %d \n", monsters_alive);
        printf("\n monster on map= %d \n", monster_on_map);

        debug_print_monsters_map_pos( monster_holder );
        debug_print_character_map_pos( character_ptr );
        
        getch();
        system_clear();
    }
}

void
debug_print_monsters_map_pos( SLL_HOLDER_STRUCT *monster_holder )
{
    SLL_STRUCT *head_copy = monster_holder -> sll_head;
    MONSTER *monster = NULL;
    int monster_number = 0;

    while ( head_copy != NULL )
    {
        if ( sll_get_data(head_copy) != NULL )
        {
            monster =  (MONSTER *) sll_get_data(head_copy);

            printf("\n Monster Number %d:\n", ++monster_number);
            debug_print_entity_map_pos( monster -> monster_map_position_struct_ptr);
        }
        head_copy = sll_get_next_sll_ptr(head_copy);
    }
}

void 
debug_print_character_map_pos( CHARACTER *character_ptr )
{
    printf("\n Character :\n");
    debug_print_entity_map_pos(character_ptr -> character_map_position_struct_ptr );
}

void 
debug_print_entity_map_pos( MAP_POSITION *entity_map_pos)
{
    printf("\n x position = %d \n", entity_map_pos -> x_position);
    printf("\n y position  = %d \n", entity_map_pos -> y_position);
    printf("\n\n");
}

int
debug_random_character_movement_generator(void)
{
    int psudo_rng = rng_generate_random_positive_number();
    
    int random_movement = psudo_rng % NUMBER_OF_POSSIBLE_MOVEMENTS;
    
    return random_movement;
}

void
debug_print_movement_done(int key)
{
    if ( key == UP) printf ("\n MOVEMENT : UP \n");
    else if ( key == DOWN) printf ("\n MOVEMENT : DOWN \n");
    else if ( key == LEFT) printf ("\n MOVEMENT : LEFT \n");
    else if ( key == RIGHT) printf ("\n MOVEMENT : RIGHT \n");
    else printf("\n KEY VALUE =  %d\n",key);

}