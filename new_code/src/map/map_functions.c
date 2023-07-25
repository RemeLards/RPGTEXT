#include "map_functions.h"

/************************************
Function : map_map_init
Date : 7/16/2023
Usable? : Yes
Explanation : Iniatializes the game map
*************************************/ 

MAP * 
map_init()
{
    MAP *map_ptr = (MAP *) malloc (sizeof(MAP));

    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++) map_ptr -> map[i][j] = ' ';
    }

    map_ptr -> monster_count = NO_MONSTERS;

    map_ptr -> map_level = TUTORIAL_LEVEL;

    return map_ptr;
}


/************************************
Function : map_add_entities_to_map
Date : 7/16/2023
Usable? : Yes
Explanation : Puts all entities (character,monsters,NPCS,objects,etc.) on the game map, in their's X and Y positions
*************************************/ 

void
map_add_entity_to_map(MAP *map_ptr, int entity_new_x_position, int entity_new_y_position, char entity)
{
    map_ptr -> map[entity_new_y_position][entity_new_x_position] = entity;
}


/************************************
Function : map_remove_entities_from_map
Date : 7/16/2023
Usable? : Yes
Explanation : Removes all entities (character,monsters,NPCS,objects,etc.) on the game map, in their's X and Y positions
*************************************/ 

void
map_remove_entity_from_map(MAP *map_ptr, int entity_old_x_position, int entity_old_y_position)
{
    map_ptr -> map[entity_old_y_position][entity_old_x_position] = ' ';
}


/************************************
Function : map_print_map
Date : 7/16/2023
Usable? : Yes
Explanation : Show (prints) all entities (character,monsters,NPCS,objects,etc.) on the game map, in their's X and Y positions
*************************************/ 

void
map_print_map(MAP *map_ptr)
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


/************************************
Function : map_print_map_lim
Date : 7/16/2023
Usable? : Yes
Explanation : Show (prints) map delimiation, making the map "grid" on the console visible
*************************************/ 

void
map_print_map_lim()
{
    for(int map_lim = 0; map_lim < MAP_SIZE * MAP_HYPHEN_SCALE; map_lim++)printf(" -");
    printf("\n");
}


/************************************
Function : map_character_update_position
Date : 7/16/2023
Usable? : Yes
Explanation : Updates the character position on the map after user press a valid key
*************************************/ 

int
map_character_update_position(CHARACTER *character_struct_ptr, MAP *map_ptr)
{
    int key = keyboard_key_registrations();

    if ( key != ENTER )
    {
        int character_x_old_pos = character_struct_ptr -> character_map_position_struct_ptr -> x_position;
        int character_y_old_pos = character_struct_ptr -> character_map_position_struct_ptr -> y_position;
    
        if ( key == UP ) character_struct_ptr -> character_map_position_struct_ptr -> y_position--;
        if ( key == DOWN ) character_struct_ptr -> character_map_position_struct_ptr -> y_position++;
        if ( key == RIGHT ) character_struct_ptr -> character_map_position_struct_ptr -> x_position++;
        if ( key == LEFT ) character_struct_ptr -> character_map_position_struct_ptr -> x_position--;

        if ( map_entity_map_limit_position_validation(character_struct_ptr -> character_map_position_struct_ptr) == MAP_LIMIT_NOT_REACHED )
        {
            int character_x_new_pos = character_struct_ptr -> character_map_position_struct_ptr -> x_position;
            int character_y_new_pos = character_struct_ptr -> character_map_position_struct_ptr -> y_position;

            if ( map_collision_validation(map_ptr,character_x_new_pos,character_y_new_pos) == COLLISION )
            {
                character_struct_ptr -> character_map_position_struct_ptr -> x_position = character_x_old_pos;
                character_struct_ptr -> character_map_position_struct_ptr -> y_position = character_y_old_pos;
            }
            
            else
            {
                map_remove_entity_from_map(map_ptr,character_x_old_pos,character_y_old_pos);
                map_add_entity_to_map(map_ptr,character_x_new_pos,character_y_new_pos,'C');
            }
        }
    }
    
    return key; // If I want to leave some test
}


/************************************
Function : map_entity_map_limit_position_validation
Date : 7/24/2023
Usable? : Yes
Explanation : Doesnt let entity X and Y positions get out of the map range
*************************************/ 

int
map_entity_map_limit_position_validation(MAP_POSITION *entity_map_position_struct_ptr)
{
    int entity_x_position = entity_map_position_struct_ptr -> x_position;
    int entity_y_position = entity_map_position_struct_ptr -> y_position;

    if ( entity_y_position > MAP_SIZE-1) entity_map_position_struct_ptr -> y_position --;
    if ( entity_y_position < 0 ) entity_map_position_struct_ptr -> y_position ++;
    if ( entity_x_position > MAP_SIZE-1) entity_map_position_struct_ptr -> x_position --;
    if ( entity_x_position < 0 ) entity_map_position_struct_ptr -> x_position ++;

    if ( (entity_x_position == entity_map_position_struct_ptr -> x_position) && (entity_y_position == entity_map_position_struct_ptr -> y_position) ) return MAP_LIMIT_NOT_REACHED;

    return MAP_LIMIT_REACHED;
    
}


/************************************
Function : map_monster_spawn
Date : 7/16/2023
Usable? : Yes
Explanation : Spawn monsters dinamically on random valid positions (SPAWNING ONLY GLOBINS)
*************************************/ 

void
map_monster_spawn(SLL_HOLDER_STRUCT *monster_holder_ptr, MAP *map_ptr)
{
    if ( map_ptr -> monster_count < map_ptr -> map_level )
    {
        MONSTER *monster_struct_ptr = monsters_goblin(NORMAL_GOBLIN); //RANDOMIZE MOBS DEPENDING MAP OF THE LEVEL
        monster_struct_ptr -> monster_map_position_struct_ptr -> x_position = (rng_generate_random_number() % MAP_SIZE);
        monster_struct_ptr -> monster_map_position_struct_ptr -> y_position = (rng_generate_random_number() % MAP_SIZE);

        int *monster_x_position_ptr = &(monster_struct_ptr -> monster_map_position_struct_ptr -> x_position);
        int *monster_y_position_ptr = &(monster_struct_ptr -> monster_map_position_struct_ptr -> y_position); 

        while ( map_collision_validation(map_ptr, *(monster_x_position_ptr), *(monster_y_position_ptr) ) == COLLISION)
        {
            *(monster_x_position_ptr) = (rng_generate_random_number() % MAP_SIZE);
            *(monster_y_position_ptr) = (rng_generate_random_number() % MAP_SIZE);   
        }

        monsters_malloc_next_monster_single_linked_list(monster_holder_ptr, monster_struct_ptr);

        map_add_entity_to_map(map_ptr,*(monster_x_position_ptr),*(monster_y_position_ptr), 'M');
        
        map_ptr -> monster_count++;
    }
}


/************************************
Function : map_monsters_update_position
Date : 7/16/2023
Usable? : Yes
Explanation : Updates the monster position on the map (they move randomly)
*************************************/ 

void
map_monsters_update_position( SLL_STRUCT *monster_single_linked_list_head_ptr, MAP *map_ptr)
{
    SLL_STRUCT *sll_copy = monster_single_linked_list_head_ptr;
    MONSTER *monster_struct_ptr = NULL;
    
    int monster_x_old_position = 0;
    int monster_y_old_position = 0;

    int random_monster_x_movement = 0;
    int random_monster_y_movement = 0;

    int monster_x_new_position = 0;
    int monster_y_new_position = 0;

    while ( sll_copy != NULL )
    {

        if ( sll_get_data(sll_copy) != NULL )
        {
            monster_struct_ptr = (MONSTER * ) sll_get_data(sll_copy);

            random_monster_x_movement = rng_generate_random_sign() * ( rng_generate_random_number() % MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE );
            random_monster_y_movement = rng_generate_random_sign() * ( rng_generate_random_number() % MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE );

            monster_x_old_position = monster_struct_ptr -> monster_map_position_struct_ptr -> x_position;
            monster_y_old_position = monster_struct_ptr -> monster_map_position_struct_ptr -> y_position;
            
            monster_struct_ptr -> monster_map_position_struct_ptr -> x_position = monster_x_old_position + random_monster_x_movement;
            monster_struct_ptr -> monster_map_position_struct_ptr -> y_position = monster_y_old_position + random_monster_y_movement;

            monster_x_new_position = monster_struct_ptr -> monster_map_position_struct_ptr -> x_position;
            monster_y_new_position = monster_struct_ptr -> monster_map_position_struct_ptr -> y_position;

            if( ( monster_x_new_position != monster_x_old_position ) || ( monster_y_new_position != monster_y_old_position ) ) 
            {

                if ( map_entity_map_limit_position_validation(monster_struct_ptr -> monster_map_position_struct_ptr) == MAP_LIMIT_NOT_REACHED )
                {

                    if ( map_collision_validation(map_ptr, monster_x_new_position, monster_y_new_position) == COLLISION )
                    {
                        monster_struct_ptr -> monster_map_position_struct_ptr -> x_position = monster_x_old_position;
                        monster_struct_ptr -> monster_map_position_struct_ptr -> y_position = monster_y_old_position;
                    }

                    else
                    {
                        map_remove_entity_from_map(map_ptr,monster_x_old_position,monster_y_old_position);
                        map_add_entity_to_map(map_ptr,monster_x_new_position,monster_y_new_position,'M');
                    }
                }

                else 
                {
                    // Even though "map_entity_map_limit_position_validation" corrects the position if its beyond map limit,
                    // if atleast one of coordinates (x or y) is valid (and so didn't need correction)
                    // we need to update the entity position on the map (in this case the monster position).
                    // If both are invalid position and both got corrected, then we dont need to update the entity position on the map
    
                    monster_x_new_position = monster_struct_ptr -> monster_map_position_struct_ptr -> x_position;
                    monster_y_new_position = monster_struct_ptr -> monster_map_position_struct_ptr -> y_position;

                    if ( ( monster_x_new_position != monster_x_old_position ) || ( monster_y_new_position != monster_y_old_position ) )
                    {
                        map_remove_entity_from_map(map_ptr,monster_x_old_position,monster_y_old_position);
                        map_add_entity_to_map(map_ptr,monster_x_new_position,monster_y_new_position,'M');
                    }
                }
            }
        }
               
        sll_copy = sll_get_next_sll_ptr(sll_copy);
    }

}


/************************************
Function : map_collision_validation
Date : 7/16/2023
Usable? : Yes
Explanation : Doesnt let entities collide with each other (need to make characters work with this)
*************************************/ 

int
map_collision_validation(MAP* map_ptr, int x_coordinate, int y_coordinate)
{    
    if( map_ptr -> map[y_coordinate][x_coordinate] != ' ' ) return COLLISION;

    return NO_COLLISION;
}


/************************************
Function : map_fightable_monsters
Date : 7/16/2023
Usable? : No
Explanation : Returns a SLL containing all monsters near the player, so the player can fight them
*************************************/ 

SLL_STRUCT *
map_fightable_monsters(SLL_STRUCT *monster_single_linked_list_head_ptr, CHARACTER *character_struct_ptr)
{
    SLL_STRUCT *sll_copy = monster_single_linked_list_head_ptr;
    SLL_STRUCT *sll_fightable_monsters = NULL;
    MONSTER *monster_struct_ptr = NULL;
    int monster_character_x_difference = 0;
    int monster_character_y_difference = 0;

    while ( sll_copy != NULL )
    {
        if ( sll_get_data(sll_copy) != NULL )
        {
            monster_struct_ptr = (MONSTER *) sll_get_data(sll_copy);

            monster_character_x_difference = (monster_struct_ptr -> monster_map_position_struct_ptr -> x_position) - (character_struct_ptr -> character_map_position_struct_ptr -> x_position);
            monster_character_y_difference = (monster_struct_ptr -> monster_map_position_struct_ptr -> y_position) - (character_struct_ptr -> character_map_position_struct_ptr -> y_position);

            if ( pow(monster_character_x_difference,2) + pow(monster_character_y_difference,2) <= pow(MAX_MONSTER_WALKABLE_DISTANCE_AT_ONCE,2))
            {
                if( sll_fightable_monsters == NULL) sll_insert_data(sll_fightable_monsters, monster_struct_ptr);
                
                else
                {
                    sll_add_new_head(sll_fightable_monsters);
                    sll_insert_data(sll_fightable_monsters, monster_struct_ptr);
                }
            }
            
        }

        sll_copy = sll_get_next_sll_ptr(sll_copy);
    }

    return sll_fightable_monsters;
}


/************************************
Function : map_map_menu
Date : 7/16/2023
Usable? : Yes
Explanation : Contains the Logic of the map menu, in other words, makes the map work (put the functions in a correct order)
*************************************/ 

int 
map_map_menu(CHARACTER *character_struct_ptr,SLL_HOLDER_STRUCT* monster_holder_ptr,MAP *map_ptr)
{
    //map_add_entities_to_map(character_struct_ptr, monster_holder_ptr -> sll_head, map_ptr);

    map_print_map(map_ptr);

    //map_remove_entities_from_map(character_struct_ptr, monster_holder_ptr -> sll_head, map_ptr);
    
    int key = map_character_update_position(character_struct_ptr, map_ptr);
    
    //map_character_position_map_limit_validation(character_struct_ptr);

    map_monsters_update_position(monster_holder_ptr -> sll_head, map_ptr);

    //map_monsters_position_map_limit_validation(monster_holder_ptr -> sll_head);
    
    map_monster_spawn(monster_holder_ptr,map_ptr);
    
    //map_monsters_update_position(monster_holder_ptr -> sll_head, map_ptr);

    system_clear();

    return key;
}



