#include "map_functions.h"

void
map_print_map(CHARACTER *character_struct_ptr,  MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr)
{
    int char_x_pos = character_struct_ptr -> character_map_position_struct_ptr -> x_position;
    int char_y_pos = character_struct_ptr -> character_map_position_struct_ptr -> y_position;

    for(int map_top_lim = 0; map_top_lim < MAP_SIZE * MAP_HYPHEN_SCALE; map_top_lim++)printf(" -");
    printf("\n");

    for(int map_y_axis = 0; map_y_axis < MAP_SIZE; map_y_axis++)
    {
        printf("| ");
        for(int map_x_axis = 0; map_x_axis < MAP_SIZE; map_x_axis++)
        {
            if(char_x_pos == map_x_axis && char_y_pos == map_y_axis) printf(" C ");
            else printf("   ");
        }
        printf(" |\n");
    }

    for(int map_bottom_lim = 0; map_bottom_lim < MAP_SIZE * MAP_HYPHEN_SCALE ; map_bottom_lim++)printf(" -");
    printf("\n");

}

int
map_character_update_position(CHARACTER *character_struct_ptr)
{
    int key = keyboard_key_registrations();
    if( key == UP ) character_struct_ptr -> character_map_position_struct_ptr -> y_position--;
    if( key == DOWN ) character_struct_ptr -> character_map_position_struct_ptr -> y_position++;
    if( key == RIGHT ) character_struct_ptr -> character_map_position_struct_ptr -> x_position++;
    if( key == LEFT ) character_struct_ptr -> character_map_position_struct_ptr -> x_position--;

    return key; // If I want to leave some test
}

void
map_character_position_validation(CHARACTER *character_struct_ptr)
{
    int char_x_pos = character_struct_ptr -> character_map_position_struct_ptr -> x_position;
    int char_y_pos = character_struct_ptr -> character_map_position_struct_ptr -> y_position;

    if ( char_y_pos > MAP_SIZE-1) character_struct_ptr -> character_map_position_struct_ptr -> y_position --;
    if ( char_y_pos < 0 ) character_struct_ptr -> character_map_position_struct_ptr -> y_position ++;
    if ( char_x_pos > MAP_SIZE-1) character_struct_ptr -> character_map_position_struct_ptr -> x_position --;
    if ( char_x_pos < 0 ) character_struct_ptr -> character_map_position_struct_ptr -> x_position ++;
    
}

void
map_monster_spawn( MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr)
{
    if ( map_ptr -> monster_count < map_ptr -> map_level )
    {
        MONSTER *monster_struct_ptr = monsters_goblin(NORMAL_GOBLIN);
        monster_struct_ptr -> monster_map_position_struct_ptr -> x_position = (rng_generate_random_number() % MAP_SIZE);
        monster_struct_ptr -> monster_map_position_struct_ptr -> y_position = (rng_generate_random_number() % MAP_SIZE);

        monsters_malloc_next_monster_linked_list(monster_linked_list_head_ptr, monster_struct_ptr);
        
        map_ptr -> monster_count++;
    }
}

void
map_monsters_update_position( MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr)
{
    /*for (int i = 0; i < map_ptr -> monster_count; i++)
    {
        monster_struct_ptr_array[i] -> monster_map_position_struct_ptr -> x_position += rng_generate_random_sign() * ( rng_generate_random_number() % MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE ); 
        monster_struct_ptr_array[i] -> monster_map_position_struct_ptr -> y_position += rng_generate_random_sign() * ( rng_generate_random_number() % MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE );
    }*/
}

void
map_monsters_position_validation( MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr)
{
    /*int monster_x_pos = 0;
    int monster_y_pos = 0;

    for(int i = 0; i < map_ptr -> monster_count; i++)
    {
        monster_x_pos = monster_struct_ptr_array[i] -> monster_map_position_struct_ptr -> x_position;
        monster_y_pos = monster_struct_ptr_array[i] -> monster_map_position_struct_ptr -> y_position;

        if ( monster_y_pos > MAP_SIZE-1) monster_struct_ptr_array[i] -> monster_map_position_struct_ptr -> y_position --;
        if ( monster_y_pos < 0 ) monster_struct_ptr_array[i] -> monster_map_position_struct_ptr -> y_position ++;
        if ( monster_x_pos > MAP_SIZE-1) monster_struct_ptr_array[i] -> monster_map_position_struct_ptr -> x_position --;
        if ( monster_x_pos < 0 ) monster_struct_ptr_array[i] -> monster_map_position_struct_ptr -> x_position ++;
    }*/
    
}

/*void
map_increase_monster_array( MONSTERS_LINKED_LIST *monster_linked_list_head_ptr, MAP* map_ptr)
{
    if (map_ptr -> monster_count >= 1)
    {
        MONSTER **monster_struct_ptr_array_increased = (MONSTER **) malloc ( (sizeof(MONSTER*)) * (map_ptr -> monster_count + 1) );
        for(int i = 0; i <= ( map_ptr -> monster_count - 1) ; i++) monster_struct_ptr_array_increased[i] = monster_struct_ptr_array[i];
        free(monster_struct_ptr_array);
        monster_struct_ptr_array = monster_struct_ptr_array_increased;
    }
    else if(map_ptr -> monster_count == 0) monster_struct_ptr_array = (MONSTER **) malloc ( (sizeof(MONSTER*)) );
}*/

int 
map_map_menu(CHARACTER *character_struct_ptr, MONSTER_LINKED_LIST *monster_linked_list_head_ptr, MAP *map_ptr)
{
    map_print_map(character_struct_ptr, monster_linked_list_head_ptr, map_ptr);
    int key = map_character_update_position(character_struct_ptr);
    map_character_position_validation(character_struct_ptr);
    map_monster_spawn(monster_linked_list_head_ptr,map_ptr);
    map_monsters_update_position(monster_linked_list_head_ptr, map_ptr);
    map_monsters_position_validation(monster_linked_list_head_ptr, map_ptr);

    system_clear();

    return key;
}



