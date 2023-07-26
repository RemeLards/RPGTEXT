//-------------------------
//HEADERS
//-------------------------

#include "main_menu_functions.h"

//-------------------------
//Defines
//-------------------------


//-------------------------
//Functions
//-------------------------

/************************************
Function : main_menu_start_menu
Date : 7/16/2023
Usable? : Yes
Explanation : Creates the start menu of the game
*************************************/ 

int 
main_menu_start_menu(void)
{
    const char *options_names[] = {"New Game","Load Game","Quit Game"};
    const int num_options = 3;

    return menu_creation_menu_option_chosen(options_names, num_options); 
}


/************************************
Function : main_menu_load_game_menu
Date : 7/16/2023
Usable? : Yes
Explanation : Loads a user saved game
*************************************/

/*TODO
//char* 
main_menu_load_game_menu()
//{   
    // Gets all files in the "<SAVED_WORLD_DIRECTORY>"
    // const char *options_names[] = {..., N_SAVED_WORLD};
    // const int num_options = N;
    // int option_chosen = menu_creation_menu_option_chosen(options_names, num_options);

    //return  options_name[option_chosen];
}*/ 


/************************************
Function : main_menu_create_character_menu
Date : 7/16/2023
Usable? : Yes
Explanation : Creates the character creation menu, where you choose Class, Race and Name (need to work on it) of a character
*************************************/ 

int 
main_menu_create_character_menu(void)
{
    const char *options_names[] = {"Select Race","Select Class","Start Game","Return"};
    const int num_options = 4;

    return menu_creation_menu_option_chosen(options_names, num_options);
}


/************************************
Function : main_menu_race_selection_menu
Date : 7/16/2023
Usable? : Yes
Explanation : Creates the race creation menu, where you choose a character Race
*************************************/ 

int 
main_menu_race_selection_menu(void)
{
    const char *options_names[] = {"Human", "Elf","Goblin","Dwarf","Troll","Orc","Minotaur","Gnome"};
    const int num_options = 8;

    return menu_creation_menu_option_chosen(options_names, num_options);  
}


/************************************
Function : main_menu_class_selection_menu
Date : 7/16/2023
Usable? : Yes
Explanation : Creates the class creation menu, where you choose a character Class
*************************************/ 

int 
main_menu_class_selection_menu(void)
{
    const char *options_names[] = {"Warrior","Paladin","Archer","Rogue","Priest","Mage","Necromancer","Berserker"};
    const int num_options = 8;

    return menu_creation_menu_option_chosen(options_names, num_options);  
}


// Main Menu Logic
/************************************
Function : main_menu
Date : 7/16/2023
Usable? : Yes
Explanation : Contains the main menu logic of the game, and after player quit, start a new game or load a new game, it returns a CHARACTER struct
pointer, if its NULL the player exit the game, else it started or loaded a game.
*************************************/ 

CHARACTER * 
main_menu(void)
{
    CHARACTER *character_struct_ptr = NULL;
    int race = NONE_RACE;
    int class = NONE_CLASS;
    int option = NONE_MAIN_MENU_OPTION;
    
    while ( ( option != QUIT_GAME ) && ( option != START_NEW_GAME ) && ( option != START_LOADED_GAME )  )
    {
        option = main_menu_start_menu();

        if ( option == 0 ) option = NEW_GAME;
        else if ( option == 1 ) option = LOAD_GAME;
        else if ( option == 2 ) option = QUIT_GAME;
    

        if ( option == NEW_GAME )
        {

            while ( ( option != RETURN_CREATE_CHARACTER ) && ( option != START_NEW_GAME ) )
            {
                option = main_menu_create_character_menu();

                if ( option == 0 ) option = RACE_CREATE_CHARACTER;
                else if ( option == 1 ) option = CLASS_CREATE_CHARACTER;
                else if ( option == 2 ) option = START_NEW_GAME;
                else if ( option == 3 ) option = RETURN_CREATE_CHARACTER; 

                if ( option == RACE_CREATE_CHARACTER ) race = main_menu_race_selection_menu();                 
                if ( option == CLASS_CREATE_CHARACTER ) class = main_menu_class_selection_menu();

                if ( ( option == START_NEW_GAME && race == NONE_RACE ) || ( option == START_NEW_GAME && class == NONE_CLASS ) )
                {
                    if ( race == NONE_RACE && class == NONE_CLASS ) printf("Select a Race and Class before playing\n");

                    if ( race != NONE_RACE && class == NONE_CLASS ) printf("Select a Class before playing\n");

                    if ( race == NONE_RACE && class != NONE_CLASS ) printf("Select a Race before playing\n");
                
                    printf("Press Enter To Continue!");
                    getchar();
                    system_clear();

                    option = NONE_MAIN_MENU_OPTION;

                }

            }

            if ( option == RETURN_CREATE_CHARACTER)
            {
                race = NONE_RACE;
                class = NONE_CLASS;
            }
        }
        
        if ( option == LOAD_GAME )
        {
            // TODO
            // Read Save File, Malloc CHARACTER ptr, and grab values
            // char *save_file_option = char* main_menu_load_game_menu();
            // if ( save_file_option == "Return") option = NONE_MAIN_MENU_OPTION (Exemplo em alto nivel)
            // else option = START_LOADED_GAME; 
        }
    }

    if ( option == START_LOADED_GAME || option == START_NEW_GAME )
    {

        character_struct_ptr = character_malloc_all();

        if( option == START_NEW_GAME )
        {
            character_init_all(character_struct_ptr);
            character_struct_ptr -> race = race;
            character_struct_ptr -> class = class;
            character_race_selection(character_struct_ptr,race);
            character_class_selection(character_struct_ptr, class);
        }
        
    }
    
    return character_struct_ptr;
}