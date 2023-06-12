#include "map_functions.h"

void
map_print_map(CHARACTER *character_struct_ptr/*, MAP *map_ptr*/)
{
    int char_x_pos = character_struct_ptr -> character_position_struct_ptr -> x_position;
    int char_y_pos = character_struct_ptr -> character_position_struct_ptr -> y_position;

    for(int map_top_lim = 0; map_top_lim < MAP_SIZE * 1.6 ; map_top_lim++)printf(" -");
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

    for(int map_floor_lim = 0; map_floor_lim < MAP_SIZE * 1.6 ; map_floor_lim++)printf(" -");
    printf("\n");

}

int
map_character_update_position(CHARACTER *character_struct_ptr)
{
    int key = keyboard_key_registrations();
    if( key == UP ) character_struct_ptr -> character_position_struct_ptr -> y_position--;
    if( key == DOWN ) character_struct_ptr -> character_position_struct_ptr -> y_position++;
    if( key == RIGHT ) character_struct_ptr -> character_position_struct_ptr -> x_position++;
    if( key == LEFT ) character_struct_ptr -> character_position_struct_ptr -> x_position--;

    return key; // If I want to leave some test
}

void
map_character_position_validation(CHARACTER *character_struct_ptr)
{
    int char_x_pos = character_struct_ptr -> character_position_struct_ptr -> x_position;
    int char_y_pos = character_struct_ptr -> character_position_struct_ptr -> y_position;

    if ( char_y_pos > MAP_SIZE-1) character_struct_ptr -> character_position_struct_ptr -> y_position --;
    if ( char_y_pos < 0 ) character_struct_ptr -> character_position_struct_ptr -> y_position ++;
    if ( char_x_pos > MAP_SIZE-1) character_struct_ptr -> character_position_struct_ptr -> x_position --;
    if ( char_x_pos < 0 ) character_struct_ptr -> character_position_struct_ptr -> x_position ++;
    
}

int map_map_menu(CHARACTER *character_struct_ptr /*, MAP *map_ptr*/)
{
    map_print_map(character_struct_ptr);
    int key = map_character_update_position(character_struct_ptr);
    map_character_position_validation(character_struct_ptr);
    system_clear();

    return key;
}

