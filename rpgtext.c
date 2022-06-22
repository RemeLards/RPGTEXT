//-------------------------
//HEADERS
//-------------------------

#include "rpgtext_menu.h"
#include "rpgtext_rng.h"

//-------------------------
//PROGRAM
//-------------------------
int main(int argc, char* argv[])
{
    CHARACTER* character;
    int menu_pos = IMENU;
    check_seed_file();
    
    while(menu_pos != EXIT)
    {
        if(menu_pos == IMENU)
        {
            int option = imenu(); //Enters "Initial Menu"
    
            if(option == UNEXPECTED_ERROR) menu_pos = EXIT; //If the while loop inside "Initial Menu" breaks, an error occurred

            if(option == NEW_GAME) menu_pos++; //If the user choose the "New Game" option, the "Character Creation Menu" is loaded

            if(option == LOAD_GAME);
                /*Load Game Function Here */
                /*menu_pos value that break while loop*/

            if(option == LEAVE) menu_pos = EXIT; //If the use choose to close the game
            
        }
        
        if(menu_pos == CHARACTER_CREATION_MENU)
        {
            int option = character_creation_menu(); //Enters "Character Creation Menu"

            if(option == UNEXPECTED_ERROR) menu_pos = EXIT; //If the while loop inside "Character Creation Menu" breaks , an error occurred 

            if(option == CHAR_CREATION) menu_pos++; //If the user choose the "Create Character" option, the "Race Menu" is loaded
                    
            if(option == RETURN_CHARACTER_CREATION_MENU) menu_pos--; //If the user choose the "Return" option, the "Initial Menu" is loaded    
        }

        if(menu_pos == RACE_MENU)
        { 
            character = (CHARACTER*)malloc(sizeof(CHARACTER));

            if(character == NULL) //If it couldn't malloc
            {
                printf("\nNot Enough Memory for %d bytes, Press Any Key To Close The Program \n",sizeof(CHARACTER));
                getchar();//fix getch() non existence
                menu_pos = EXIT;
            }
            
            else
            {
                int race = race_selection_menu(); //Enters "Race Selection Menu"

                if(race >= HUMAN) //If it didnt return any error, apply a race stat
                {
                    if(race != RETURN_RACES)//If user didnt return to "Character Creation Menu" 
                    {
                        race_selection(character,race);
                        menu_pos++;
                    }
                    else
                    {
                        free(character);
                        menu_pos--;
                    }
                }
            
                else // race = UNEXPECTED_ERROR
                {
                    free(character);
                    menu_pos = EXIT;
                }
            }
           
        }

        if(menu_pos == CLASS_MENU)
        {
            int class = class_selection_menu();//Enters "Class Selection Menu"

            if(class >= WARRIOR) //If it didnt return any error, apply a class stat multiplier
            {
                if(class != RETURN_CLASSES)//If user didnt return to "Race Selection Menu" 
                {
                    class_selection(character,class);
                    menu_pos++;
                }
                else
                {
                    free(character);
                    menu_pos--;
                }
            }
           
            else //class = UNEXPECTED_ERROR
            {
                free(character);
                menu_pos = EXIT;
            }       

        }

        if(menu_pos == CHARACTER_STATS_MENU)
        {
            int option = character_stats_menu();

            if(option == CHARACTER_NAME)
            {
                menu_pos++;
                character -> character_name = character_name_creation(character); //Gets character name
                if(character -> character_name == NULL ) // If it's NULL 
                {
                    free(character);
                    menu_pos = EXIT;
                }
            }
            
            if(option == PRINT_STATS)
            {
                print_stats(character,character->race,character->class);//Print Status
                //It will return to the same menu_pos, since just stats are beeing printed
            }

            if(option == RETURN_CHARACTER_STATS_MENU)
            {
                
                menu_pos--;
                race_selection(character,character->race);//Removing Character Class Multiplier and Returning to CLASS_MENU 
            }

            if(option == UNEXPECTED_ERROR) //If the "while" break  
            {
                menu_pos = EXIT;
                free(character);
            }
        }

        if(menu_pos == GAME)//Game Loop
        {
            character -> character_level = (CHAR_LEVEL*)malloc(sizeof(CHAR_LEVEL));

            if(character -> character_level == NULL)
            {
                printf("\n Not Enough Memory for %d bytes, Press Any Key To Close The Program \n",sizeof(CHAR_LEVEL));
                free(character -> character_name);
                free(character);
                getchar();//fix getch() non existence
                menu_pos = EXIT;
            }
            else init_level(character);

            character -> skillpoints_struct = (SKILLPOINTS*)malloc(sizeof(SKILLPOINTS));
            if(character -> skillpoints_struct == NULL)
            {
                printf("\nNot Enough Memory for %d bytes, Press Any Key To Close The Program \n",sizeof(SKILLPOINTS));
                free(character -> character_name);
                free(character -> character_level);
                free(character);
                getchar();//fix getch() non existence
                menu_pos = EXIT;;
            }
            else init_skillpoints(character);

            printf("character name: %s\n", character -> character_name);
            printf("character level: %d\n", character -> character_level -> level);
            printf("character exp: %.2f\n", character -> character_level -> experience);
            printf("character strenght level: %d\n", character -> skillpoints_struct -> strenght);
            getchar();//fix getch() non existence
            
            //game(character);
            //Add some options later
            break;
        }
    }

}

//gcc rpgtext_character.c rpgtext_fight.c rpgtext_functionalities.c rpgtext_game.c rpgtext_menu.c rpgtext_monsters.c rpgtext_rng.c rpgtext_strings.c rpgtext.c -o rpgtext
//gcc rpgtext_character.c rpgtext_functionalities.c rpgtext_menu.c rpgtext_rng.c rpgtext_strings.c rpgtext.c -o rpgtext
