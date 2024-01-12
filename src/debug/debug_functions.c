#include "debug_functions.h"

#define NUMBER_OF_POSSIBLE_MOVEMENTS 4 // W (UP), S (DOWN), A (LEFT), D (RIGHT)

void
debug_map_status_checker( MAP *map_ptr, SLL_HOLDER *monster_holder, CHARACTER *character_ptr )
{
    int monsters_alive = monster_holder -> sll_size;
    int monster_on_map = 0;
    int character_on_map = 0;

    for ( int y = 0; y < MAP_SIZE; y++ )
    {
        for ( int x = 0; x < MAP_SIZE; x++)
        {
            if ( map_ptr -> map[y][x] == 'M') monster_on_map++;
            else if ( map_ptr -> map[y][x] == 'C') character_on_map++;
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
debug_print_monsters_map_pos( SLL_HOLDER *monster_holder )
{
    SLL *head_copy = monster_holder -> head;
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
        head_copy = sll_get_next(head_copy);
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

int
debug_all_monsters_around_char(CHARACTER *character_struct_ptr, SLL_HOLDER *near_monsters_holder)
{
    SLL *monster_head_copy = near_monsters_holder -> head;
    MONSTER *monster = NULL;
    
    int char_x = character_struct_ptr -> character_map_position_struct_ptr -> x_position;
    int char_y = character_struct_ptr -> character_map_position_struct_ptr -> y_position;
    int error_counter = 0;

    while ( monster_head_copy != NULL )
    {
        monster = (MONSTER *) sll_get_data( monster_head_copy );
        error_counter = debug_monster_around_char(monster,char_x,char_y, error_counter);
        monster_head_copy = sll_get_next(monster_head_copy);
    }

    return error_counter;
}

int
debug_monster_around_char(MONSTER *monster, int char_x, int char_y, int error_counter)
{
    int monster_x =  monster -> monster_map_position_struct_ptr -> x_position;
    int monster_y =  monster -> monster_map_position_struct_ptr -> y_position;

    if( sqrt( pow( char_x - monster_x, 2) + pow( char_y - monster_y, 2) ) > 2 )
    {
        printf("Monster is too far away to be selected, logic is wrong\n\n");
        printf("Monsters Distance %lf\n\n", sqrt( pow( char_x - monster_x, 2) + pow( char_y - monster_y, 2) ));
        printf("Monster x : %d , Monster y : %d\n\n", monster_x, monster_y );
        error_counter++;
        getch();
    }

    return error_counter;
}

int 
debug_max_monster_around_char(MAP *map_ptr, SLL_HOLDER *monsters_holder, CHARACTER *character_struct_ptr, int max_monsters_counter)
{
    SLL_HOLDER *near_monsters_holder = map_find_monsters_around_character(map_ptr, monsters_holder, character_struct_ptr);

    if ( ( near_monsters_holder -> sll_size ) > max_monsters_counter ) max_monsters_counter = ( near_monsters_holder -> sll_size );

    printf("max monsters around character : %d\n\n", max_monsters_counter);

    sll_holder_destroy(near_monsters_holder);

    return max_monsters_counter;

}