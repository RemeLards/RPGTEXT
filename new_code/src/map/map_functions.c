#include "map_functions.h"

//TODO (USEI UM MACETE RUIM, MELHORAR)

void 
map_map_init(MAP *map_ptr)
{
    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++) map_ptr -> map[i][j] = ' ';
    }

    map_ptr -> monster_count = NO_MONSTERS;

    map_ptr -> map_level = TUTORIAL_LEVEL;
}

void
map_add_character_to_map( CHARACTER *character_struct_ptr, MAP *map_ptr )
{
    int char_x_pos = character_struct_ptr -> character_map_position_struct_ptr -> x_position;
    int char_y_pos = character_struct_ptr -> character_map_position_struct_ptr -> y_position;
    map_ptr -> map[char_y_pos][char_x_pos] = 'C';
}

void
map_add_monsters_to_map( SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr )
{
    SLL_STRUCT *sll_monster_copy = monster_single_linked_list_head_ptr;
    MONSTER *monster_struct_ptr;
    int monster_x_pos = 0;
    int monster_y_pos = 0;

    while (sll_monster_copy != NULL )
    {
        if (sll_get_data(sll_monster_copy) != NULL )
        {
            monster_struct_ptr = (MONSTER *) sll_get_data(sll_monster_copy);
            monster_x_pos = monster_struct_ptr -> monster_map_position_struct_ptr -> x_position;
            monster_y_pos = monster_struct_ptr -> monster_map_position_struct_ptr -> y_position;

            map_ptr -> map[monster_y_pos][monster_x_pos] = 'M';
        }

        sll_monster_copy = sll_get_next_sll_ptr(sll_monster_copy);
    }
}

void
map_add_entities_to_map(CHARACTER *character_struct_ptr,SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr)
{
    map_add_character_to_map( character_struct_ptr, map_ptr );

    map_add_monsters_to_map( monster_single_linked_list_head_ptr, map_ptr );
}

void
map_print_map(MAP *map_ptr )
{

    map_print_map_lim();

    for(int map_y_axis = 0; map_y_axis < MAP_SIZE; map_y_axis++)
    {
        printf("| ");

        for(int map_x_axis = 0; map_x_axis < MAP_SIZE; map_x_axis++)
        {
            printf(" %c ",map_ptr -> map[map_y_axis][map_x_axis]);
        }
        
        printf(" |");
        printf("\n");
    }

    map_print_map_lim();

}

void
map_print_map_lim()
{
    for(int map_lim = 0; map_lim < MAP_SIZE * MAP_HYPHEN_SCALE; map_lim++)printf(" -");
    printf("\n");
}

int
map_character_update_position(CHARACTER *character_struct_ptr )
{
    int key = keyboard_key_registrations();
    if( key == UP ) character_struct_ptr -> character_map_position_struct_ptr -> y_position--;
    if( key == DOWN ) character_struct_ptr -> character_map_position_struct_ptr -> y_position++;
    if( key == RIGHT ) character_struct_ptr -> character_map_position_struct_ptr -> x_position++;
    if( key == LEFT ) character_struct_ptr -> character_map_position_struct_ptr -> x_position--;

    return key; // If I want to leave some test
}

void
map_character_position_map_limit_validation(CHARACTER *character_struct_ptr )
{
    int char_x_pos = character_struct_ptr -> character_map_position_struct_ptr -> x_position;
    int char_y_pos = character_struct_ptr -> character_map_position_struct_ptr -> y_position;

    if ( char_y_pos > MAP_SIZE-1) character_struct_ptr -> character_map_position_struct_ptr -> y_position --;
    if ( char_y_pos < 0 ) character_struct_ptr -> character_map_position_struct_ptr -> y_position ++;
    if ( char_x_pos > MAP_SIZE-1) character_struct_ptr -> character_map_position_struct_ptr -> x_position --;
    if ( char_x_pos < 0 ) character_struct_ptr -> character_map_position_struct_ptr -> x_position ++;
    
}

void
map_monster_spawn( SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr )
{
    if ( map_ptr -> monster_count < map_ptr -> map_level )
    {
        MONSTER *monster_struct_ptr = monsters_goblin(NORMAL_GOBLIN); //RANDOMIZE MOBS DEPENDING MAP OF THE LEVEL
        monster_struct_ptr -> monster_map_position_struct_ptr -> x_position = (rng_generate_random_number() % MAP_SIZE);
        monster_struct_ptr -> monster_map_position_struct_ptr -> y_position = (rng_generate_random_number() % MAP_SIZE);

        while ( map_monster_position_monster_collision_validation(monster_struct_ptr, map_ptr) == MONSTER_COLLISION)
        {
            monster_struct_ptr -> monster_map_position_struct_ptr -> x_position = (rng_generate_random_number() % MAP_SIZE);
            monster_struct_ptr -> monster_map_position_struct_ptr -> y_position = (rng_generate_random_number() % MAP_SIZE);   
        }

        monsters_malloc_next_monster_single_linked_list(monster_single_linked_list_head_ptr, monster_struct_ptr);
        
        map_ptr -> monster_count++;
    }
}

void
map_monsters_update_position( SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr )
{
    SLL_STRUCT *sll_copy = NULL;
    MONSTER *monster_struct_ptr = NULL;
    
    for (sll_copy = monster_single_linked_list_head_ptr; sll_get_data(sll_copy) != NULL; sll_copy = sll_get_next_sll_ptr(sll_copy) )
    {
        monster_struct_ptr = (MONSTER *) sll_get_data(sll_copy);
        monster_struct_ptr -> monster_map_position_struct_ptr -> x_position += rng_generate_random_sign() * ( rng_generate_random_number() % MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE ); 
        monster_struct_ptr -> monster_map_position_struct_ptr -> y_position += rng_generate_random_sign() * ( rng_generate_random_number() % MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE );
        
        while ( map_monster_position_monster_collision_validation( monster_struct_ptr, map_ptr) == MONSTER_COLLISION)
        {
            monster_struct_ptr -> monster_map_position_struct_ptr -> x_position += rng_generate_random_sign() * ( rng_generate_random_number() % MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE ); 
            monster_struct_ptr -> monster_map_position_struct_ptr -> y_position += rng_generate_random_sign() * ( rng_generate_random_number() % MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE ); 
        }

        if (sll_copy -> data_ptr == NULL) break;
    }
}

//SEE IF I CAN DO BETTER
void
map_monsters_position_map_limit_validation( SLL_STRUCT *monster_single_linked_list_head_ptr )
{
    SLL_STRUCT *sll_monster_copy = monster_single_linked_list_head_ptr;
    MONSTER *monster_struct_ptr = NULL;
    int monster_x_pos = 0;
    int monster_y_pos = 0;
    
    while (sll_monster_copy != NULL )
    {
        if( sll_get_data(sll_monster_copy) != NULL)
        {
            monster_struct_ptr = (MONSTER *) sll_get_data(sll_monster_copy);
            monster_x_pos = monster_struct_ptr -> monster_map_position_struct_ptr -> x_position;
            monster_y_pos = monster_struct_ptr -> monster_map_position_struct_ptr -> y_position;

            if ( monster_y_pos > MAP_SIZE-1) monster_struct_ptr-> monster_map_position_struct_ptr -> y_position --;
            if ( monster_y_pos < 0 ) monster_struct_ptr -> monster_map_position_struct_ptr -> y_position ++;
            if ( monster_x_pos > MAP_SIZE-1) monster_struct_ptr -> monster_map_position_struct_ptr -> x_position --;
            if ( monster_x_pos < 0 ) monster_struct_ptr -> monster_map_position_struct_ptr -> x_position ++;
        }

        sll_monster_copy = sll_get_next_sll_ptr(sll_monster_copy);
    } 
}

int
map_monster_position_monster_collision_validation(MONSTER* monster_struct_ptr, MAP* map_ptr)
{
    int monster_x_pos = monster_struct_ptr -> monster_map_position_struct_ptr -> x_position;
    int monster_y_pos = monster_struct_ptr -> monster_map_position_struct_ptr -> y_position;
    
    if( map_ptr -> map[monster_y_pos][monster_x_pos] != ' ') return MONSTER_COLLISION;

    return NO_MONSTER_COLLISION;
}

//TODO
int 
map_map_menu(CHARACTER *character_struct_ptr, SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr )
{

    map_add_entities_to_map(character_struct_ptr, monster_single_linked_list_head_ptr, map_ptr);

    map_print_map(map_ptr);
    
    int key = map_character_update_position(character_struct_ptr);
    
    map_character_position_map_limit_validation(character_struct_ptr);
    
    map_monster_spawn(monster_single_linked_list_head_ptr,map_ptr);
   
    map_monsters_update_position(monster_single_linked_list_head_ptr, map_ptr);
    
    map_monsters_position_map_limit_validation(monster_single_linked_list_head_ptr);

    system_clear();

    return key;
}



