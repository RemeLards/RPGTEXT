#include "map_functions.h"

//#include "debug_functions.h" //Including momentarly to debug, so it wont affect "map_functions.h"
//#include <windows.h> // I will let my program run automatically, but to not stress CPU I will add sleep()
//#define SLEEP_500MS 500

/************************************
Function : map_map_init
Date : 7/16/2023
Usable? : Yes
Explanation : Iniatializes the game map
*************************************/ 

MAP * 
map_init(void)
{
    MAP *map_ptr = (MAP *) malloc (sizeof(MAP));

    for(int i = 0; i < MAP_SIZE; i++)
    {
        for(int j = 0; j < MAP_SIZE; j++) map_ptr -> map[i][j] = ' ';
    }

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
            printf(" %c ", map_ptr -> map[map_y_axis][map_x_axis]);
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
map_print_map_lim(void)
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
    //int key = keyboard_key_registrations();
    int key = debug_random_character_movement_generator();

    if ( key == UP || key == DOWN || key == LEFT || key == RIGHT )
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
map_monster_spawn(SLL_HOLDER *monster_holder_ptr, MAP *map_ptr)
{
    if ( (rng_generate_random_positive_number() % 101) > 90)
    {
        if ( ( monster_holder_ptr -> sll_size ) < ( map_ptr -> map_level ) )
        {
            MONSTER *monster_struct_ptr = monsters_goblin(NORMAL_GOBLIN); //RANDOMIZE MOBS DEPENDING MAP OF THE LEVEL
            monster_struct_ptr -> monster_map_position_struct_ptr -> x_position = ( rng_generate_random_number() % MAP_SIZE );
            monster_struct_ptr -> monster_map_position_struct_ptr -> y_position = ( rng_generate_random_number() % MAP_SIZE );

            int *monster_x_position_ptr = &( monster_struct_ptr -> monster_map_position_struct_ptr -> x_position );
            int *monster_y_position_ptr = &( monster_struct_ptr -> monster_map_position_struct_ptr -> y_position ); 

            while ( map_collision_validation( map_ptr, *(monster_x_position_ptr), *(monster_y_position_ptr) ) == COLLISION )
            {
                *(monster_x_position_ptr) = ( rng_generate_random_number() % MAP_SIZE );
                *(monster_y_position_ptr) = ( rng_generate_random_number() % MAP_SIZE );   
            }
            
            monsters_malloc_next_monster_sll( monster_holder_ptr, monster_struct_ptr );

            map_add_entity_to_map(map_ptr,*(monster_x_position_ptr),*(monster_y_position_ptr), 'M');
        }
    }
}


/************************************
Function : map_monsters_update_position
Date : 7/16/2023
Usable? : Yes
Explanation : Updates the monster position on the map (they move randomly)
*************************************/ 

void
map_monsters_update_position( SLL *monster_single_linked_list_head_ptr, MAP *map_ptr)
{
    SLL *sll_copy = monster_single_linked_list_head_ptr;
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
                    // we need to update the entity position on the map (in this case the monster position) and check collision too.
                    // If both are invalid position and both got corrected, then we dont need to update the entity position on the map
    
                    monster_x_new_position = monster_struct_ptr -> monster_map_position_struct_ptr -> x_position;
                    monster_y_new_position = monster_struct_ptr -> monster_map_position_struct_ptr -> y_position;

                    if ( ( monster_x_new_position != monster_x_old_position ) || ( monster_y_new_position != monster_y_old_position ) )
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
                }
            }
        }
               
        sll_copy = sll_get_next(sll_copy);
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
Date : 7/25/2023
Usable? : No
Explanation : Returns a monster near the player, so the player can fight it.
*************************************/ 

int
map_fight_monster( MAP *map_ptr, CHARACTER *character_struct_ptr, SLL_HOLDER *monsters_holder_ptr)
{
    SLL_HOLDER *near_monsters_holder = NULL;
    MONSTER *monster_chosen = NULL;
    int fight_status = CHARACTER_IS_ALIVE;

    //TRY TO FINISH IT WORKING AND THEN APPLY TO OBJETCS/NPS (TRY TO DO IT IN A GENERAL WAY)
    near_monsters_holder = map_find_monsters_around_character( map_ptr, monsters_holder_ptr, character_struct_ptr );

    if ( near_monsters_holder -> sll_size != EMPTY)
    {
        if( map_map_in_confirmation_menu( map_ptr ) == YES )
        {
            monster_chosen = map_monster_chosen_to_fight( map_ptr, near_monsters_holder );
            fight_status = fight_fight_menu(map_ptr, character_struct_ptr, monsters_holder_ptr, monster_chosen);
        }
    }

    sll_holder_destroy(near_monsters_holder);

    return fight_status;  //coloquei apenas para compilar
}


/************************************
Function : map_find_monsters_around_character
Date : 1/9/2024
Usable? : Yes
Explanation : Finds monster around the player (3x3 square, without counting the middle, because the player is on the middle).
*************************************/

SLL_HOLDER *
map_find_monsters_around_character( MAP *map_ptr, SLL_HOLDER *monsters_holder_ptr, CHARACTER *character_struct_ptr )
{
    SLL_HOLDER *near_monters_holder = sll_holder_initialize();
    MONSTER *monster = NULL;

    int char_x = character_struct_ptr -> character_map_position_struct_ptr -> x_position;
    int char_y = character_struct_ptr -> character_map_position_struct_ptr -> y_position;
    int y = 0;
    int x = 0;

    for (y = char_y - 1; y < MAP_SIZE && y <=  ( char_y + 1 ); y++ )
    {
        //if the player stays on the bottom of the map, the "Y" goes from MAP_SIZE-1 to MAP_SIZE+1, 
        //but maximum matrix index is MAP_SIZE (for loop already takes care of it!).
        //if the player stays on the top of the map, the "Y" goes from -1 to 1, but negative index aren't usable.

        if ( y < 0 ) y++; 

        for (x = char_x - 1; x < MAP_SIZE && x <= ( char_x + 1 ); x++ )
        {
            //if the player stays on the right corner of the map, the "X" goes from MAP_SIZE-1 to MAP_SIZE+1, but maximum matrix index is MAP_SIZE.
            //if the player stays on the left corner of the map, the "X"  goes from -1 to 1, but negative index aren't usable.

            if ( x < 0  || ( (x == char_x) && (y == char_y) ) ) x++; //we dont need to check if theres a monster on the char position.
            
            if ( map_ptr -> map[y][x] == 'M' )
            {
                if ( near_monters_holder -> head == NULL)
                {
                    monster = map_find_monster_by_coordinates( monsters_holder_ptr, x, y );
                    
                    if( monster != NULL )
                    {
                        near_monters_holder -> head = sll_initialize();
                        sll_insert_data( near_monters_holder -> head, (void *) monster );

                        near_monters_holder -> tail = near_monters_holder -> head;
                        near_monters_holder -> sll_size++;   
                    }
                }

                else
                {
                    monster = map_find_monster_by_coordinates( monsters_holder_ptr, x, y );

                    if( monster != NULL )
                    {
                        near_monters_holder -> tail -> next = sll_initialize();
                        near_monters_holder -> tail = near_monters_holder -> tail -> next;
                        
                        sll_insert_data( near_monters_holder -> tail, (void *) monster ); 

                        near_monters_holder -> sll_size++;
                    }
                }

            }
        }
    }

//    if ( debug_all_monsters_around_char( character_struct_ptr, near_monters_holder ) )
//    {
//        printf("char_x : %d , max x value %d\n\n",char_x,x);
//        printf("char_y : %d , max y value %d\n\n",char_y,y);
//        getch();
//    }

    return near_monters_holder;
}


/************************************
Function : map_find_monster_by_coordinates
Date : 1/9/2024
Usable? : Yes
Explanation : Returns a monster if there's any in the coords given, else returns NULL.
*************************************/ 

MONSTER *
map_find_monster_by_coordinates( SLL_HOLDER *monsters_holder_ptr, int monster_x, int monster_y )
{
    MONSTER *monster = NULL;
    SLL *head_copy = monsters_holder_ptr -> head;
    int monster_x_position = 0;
    int monster_y_position = 0;  

    while ( head_copy != NULL )
    {
        if ( sll_get_data ( head_copy ) != NULL )
        {
            monster = (MONSTER *) sll_get_data ( head_copy );
            monster_x_position = monster -> monster_map_position_struct_ptr -> x_position;
            monster_y_position = monster -> monster_map_position_struct_ptr -> y_position;

            if ( monster_x_position == monster_x && monster_y_position == monster_y ) break;
            else
            {
                monster = NULL;
                head_copy = sll_get_next( head_copy );
            }
        }
    }
    
    return monster; 
}


/************************************
Function : map_monster_chosen_to_fight
Date : 1/9/2024
Usable? : Yes
Explanation : Returns a monster chosen for a fight.
*************************************/ 

MONSTER *
map_monster_chosen_to_fight( MAP *map_ptr, SLL_HOLDER *near_monster_holder)
{
    int monster_chosen = 0;
    int key = NULL_KEY;
    SLL *monster_head_copy = NULL;
    
    while(key != ENTER)
    {
        system_clear();
        map_show_chosen_monster_on_map( map_ptr, near_monster_holder, monster_chosen );
        key = keyboard_key_registrations();
        menu_creation_UI_menu_options_registration( &monster_chosen, near_monster_holder -> sll_size, key );
    }

    monster_head_copy = near_monster_holder -> head;
    for ( int monster_number = 0; monster_number != monster_chosen; monster_number++ ) monster_head_copy = sll_get_next(monster_head_copy);

    return (MONSTER *) sll_get_data(monster_head_copy);
}


/************************************
Function : map_show_chosen_monster_on_map
Date : 1/9/2024
Usable? : Yes
Explanation : Changes the monster symbol if it's selected, and print the map again.
*************************************/ 

void
map_show_chosen_monster_on_map(MAP *map_ptr, SLL_HOLDER *near_monster_holder, int monster_chosen)
{
    SLL *monster_head_copy = near_monster_holder -> head;
    MONSTER *monster = NULL;
    int monster_x = 0;
    int monster_y = 0;

    for ( int monster_number = 0; monster_number != monster_chosen; monster_number++ ) monster_head_copy = sll_get_next(monster_head_copy);
 
    monster = (MONSTER *) sll_get_data(monster_head_copy);
    monster_x = monster -> monster_map_position_struct_ptr -> x_position;
    monster_y = monster -> monster_map_position_struct_ptr -> y_position;
    
    map_ptr -> map[monster_y][monster_x] = '@';
    map_print_map( map_ptr );
    printf("W - Next Monster\n\n");
    printf("S - Previous Monster\n\n");
    printf("Enter - Confirm Monster\n\n");
    map_ptr -> map[monster_y][monster_x] = 'M';
}

/************************************
Function : map_map_in_menu_option_chosen
Date : 1/11/2023
Usable? : Yes
Explanation : Contains all the logic to make any menu work with the map, in the end returns the option choosen by the user
*************************************/ 

int
map_map_in_menu_option_chosen(const char **options_names, const int num_options, const char *phrase, MAP *map)
{
    int option_chosen = 0;
    int key = NULL_KEY;
    
    while(key != ENTER)
    {
        system_clear();
        map_print_map(map);
        if(phrase != NULL)printf("%s\n\n",phrase);
        menu_creation_print_menu_options(options_names, option_chosen, num_options);
        key = keyboard_key_registrations();
        menu_creation_UI_menu_options_registration(&option_chosen, num_options, key);
    }
    
    return option_chosen;
}

/************************************
Function : menu_creation_confirmation_menu
Date : 1/11/2023
Usable? : Yes
Explanation : Used for user confirmation while the map is shown.
*************************************/ 

int 
map_map_in_confirmation_menu(MAP* map)
{
    const char *options_names[] = {"Yes","No"};
    const char *phrase = "Wanna fight a monster?";
    int num_options = 2;
    return map_map_in_menu_option_chosen(options_names,num_options,phrase,map);
}

/************************************
Function : map_map_menu
Date : 7/16/2023
Usable? : Yes
Explanation : Contains the Logic of the map menu, in other words, makes the map work (put the functions in a correct order)
*************************************/ 

int 
map_map_menu(CHARACTER *character_struct_ptr, SLL_HOLDER* monster_holder_ptr, MAP *map_ptr)
{   
    int key = map_character_update_position(character_struct_ptr, map_ptr);
    
    map_monsters_update_position(monster_holder_ptr -> head, map_ptr);
    
    map_monster_spawn(monster_holder_ptr, map_ptr);

    system_clear();

    map_print_map( map_ptr );

    if ( map_fight_monster(map_ptr, character_struct_ptr, monster_holder_ptr) != CHARACTER_IS_ALIVE ) key = 'Q'; //Faz alguma coisa kk

    return key;
}



