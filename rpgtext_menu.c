//-------------------------
//HEADERS
//-------------------------

#include "rpgtext_character.h"
#include "rpgtext_menu.h"

//-------------------------
//FUNCTIONS
//-------------------------

//Play
void game(CHARACTER* character)
{
    int options_selection = 0; //Goes from 0 to 3
    char* options_names[] = {"Search Monster","Inventory","Attributes","Return"};
    int sizeofoptions = (sizeof(options_names)/4);
    while(1)
    {
        system("cls");
        menu_print(options_names,options_selection,sizeofoptions);
        game_optionsregistration(&options_selection,sizeofoptions,character, keyregistration());
    }     
}

//Game Mobs
void search_mobs(CHARACTER* character)
{
    int monster_n = rng_generator()%2;
    if(monster_n == GOBLIN_MONSTER)goblin(character);
    if(monster_n == GLASSCANON_GOBLIN)glasscanon_goblin(character);
    //if(monster_n == DRAGON)dragon(character);
    else 
    {
        system("cls");
        printf("No Monster Found\n");
        printf("Press any key to continue");
        getch();
        game(character);
    }
}

//Game Interactions
void fight_menu(CHARACTER* character,MOBS* monster)
{
    int options_selection = 0; //Goes from 0 to 8
    char* options_names[] = {"Basic Attack","Mana Abilities","Stamina Abilties"};
    int sizeofoptions = (sizeof(options_names)/4);
    while(1)
    {
        system("cls");
        menu_print(options_names,options_selection,sizeofoptions);
        fight_menu_optionsregistration(&options_selection,sizeofoptions,character,monster,keyregistration());
    }     
}
void fight(CHARACTER* character,MOBS* monster,int attack_status)
{
    if(attack_status == BASIC_ATTACK)
    {
        //dmg_calculation(character,attack_status) calculates Player Attack
        monster -> health -= dmg_calculation(character,attack_status); //Monster Damage Received
        if(monster -> health > 0)printf("\nMonster Health: %.2f\n", monster -> health);
        getch();

        
        if(monster -> health > 0) //If monster wasn't killed
        {
            //dmg_values_mobs(monster) calculates Monster Attack
            character -> base_health -= dmg_values_mobs(monster);
            printf("\nYOUR Health: %.2f\n", character -> base_health);
            getch();

            if(character -> base_health > 0)//Player isn't dead
            {               
                //Returns to fightmenu
                fight_menu(character,monster);
            }
            else //Player died
            {
                system("cls");
                printf("YOU DIED, DO BETTER NEXT TIME!!!\n");
                printf("Press any key to continue");
                getch(); 
                free(monster);//Freeing monster malloced struct
                free(character -> character_name);
                free(character -> skillpoints_struct);
                free(character);
                imenu(); //Retuns to the initial menu  
            }
        }
        else
        {
            system("cls");
            printf("YOU KILLED THE MONSTER, GOOD JOB!!!!\n");
            printf("Press any key to continue");
            getch();
            
            character -> level_struct -> experience_tracker += monster -> experience_given; //Giving EXP To Player
            printf("\n\nYOU GOT %.0f XP\n",monster -> experience_given);  //Print XP That Player Got 
            character_level(character);         //Calculating If Player Leveled Up

            free(monster);//Freeing monster malloced struct
            game(character);
        }
    } 
}

//Game Registrations
void game_optionsregistration(int* option,int sizeofoptions, CHARACTER* character,int key)
{
    if(key == UP)*option -= 1;    //If User Press Up Arrow
    if(key == DOWN)*option += 1;  //If User Press Lower Arrow
    if(key == ENTER)
    {
        if(*option == 0)search_mobs(character);          //Search a Monster
        //if(*option == 1)inventory();                  //Character Inventory
        //if(*option == 2)attributes_ingame();         //Return to last menu option;
        if(*option == 3)
        {
            free(character -> level_struct);        //Freeing Level Dtruct
            free(character -> character_name);     //Freeing Character Name
            character_stats_menu(character);
        }
        
    }
    if(*option < 0)*option = sizeofoptions-1; //If options selection becomes negative
    if(*option >= sizeofoptions)*option = 0; //If options selection becomes higher than the quantity of options in the "imenu"    
}
void fight_menu_optionsregistration(int* option,int sizeofoptions, CHARACTER* character,MOBS* monster, int key)
{
    if(key == UP)*option -= 1;    //If User Press Up Arrow
    if(key == DOWN)*option += 1;  //If User Press Lower Arrow
    if(key == ENTER)
    {
        if(*option == 0)fight(character,monster,BASIC_ATTACK); //Basic Attack      
        //if(*option == 1)fight(character,monster,STAMINA_ATTACK); //Mana Attack
        //if(*option == 2)fight(character,monster,MANA_ATTACK); //Stamina Attack
        
    }
    if(*option < 0)*option = sizeofoptions-1; //If options selection becomes negative
    if(*option >= sizeofoptions)*option = 0; //If options selection becomes higher than the quantity of options in the "imenu" 
}

// Screen/Button Registration in Initial Menus
int keyregistration()//Gets keyboard input
{
    int key = 0;    
    int i = 0,c; //Just need 2 ints in the vector
    
    int arrowkeyregistration_vector[2]; //Arrow registration Vector
    
    int vectorpos = 0; //Arrow Vector Position
    
    c = getch();//Key input
    
    if(c != 13)
    {
        while(i < 2)
        {
            if(i == 0)arrowkeyregistration_vector[vectorpos] = c; //Gets a Char
            else arrowkeyregistration_vector[vectorpos] = getch();//Gets the second char if any Arrow Button gets pressed
            if(i >= 1) //Checking The Arrows Input (Arrows Input Gives 2 Values), OBS: Ó =224, so people can move that way too
            {
                if(arrowkeyregistration_vector[vectorpos] == 72 && arrowkeyregistration_vector[vectorpos-1] == 224){key = UP;return key;}//Up Arrow Value
                if(arrowkeyregistration_vector[vectorpos] == 80 && arrowkeyregistration_vector[vectorpos-1] == 224){key = DOWN;return key;} //Lower Arrow Value
                if(arrowkeyregistration_vector[vectorpos] == 75 && arrowkeyregistration_vector[vectorpos-1] == 224){key = LEFT;return key;} //Left Arrow Value
                if(arrowkeyregistration_vector[vectorpos] == 77 && arrowkeyregistration_vector[vectorpos-1] == 224){key = RIGHT;return key;} //Right Arrow Value
            }
            vectorpos = ++i;
        }
    }
    else
    {
        key = ENTER;
        return key;
    } 
}
void imenu_optionsregistration(int* option, int sizeofoptions, int key)
{
    if(key == UP)*option -= 1;    //If User Press Up Arrow
    if(key == DOWN)*option += 1;  //If User Press Lower Arrow
    if(key == ENTER)
    {
        if(*option == 0)character_creation_menu();//Race option;
        if(*option == 2)exit(0);//Return to last menu option;
        
    }
    if(*option < 0)*option = sizeofoptions-1; //If options selection becomes negative
    if(*option >= sizeofoptions)*option = 0; //If options selection becomes higher than the quantity of options in the "imenu"
}
void character_creation_optionsregistration(int* option, int sizeofoptions, int key)//Options functionality
{
    if(key == UP)*option -= 1;    //If User Press Up Arrow
    if(key == DOWN)*option += 1;  //If User Press Lower Arrow
    if(key == ENTER)
    {
        if(*option == 0)race_creation_menu();//Race option;
        if(*option == 1)imenu();//Return to last menu option;
        
    }
    if(*option < 0)*option = sizeofoptions-1; //If options selection becomes negative
    if(*option >= sizeofoptions)*option = 0; //If options selection becomes higher than the quantity of options in the "imenu"

}
void race_optionsregistration(int* race, int sizeofoptions, CHARACTER* character, int key)//
{
    if(key == UP)*race -= 1;    //If User Press Up Arrow
    if(key == DOWN)*race += 1;  //If User Press Lower Arrow
    if(key == ENTER)
    {
        race_creation(*race,character);//All Options Are in character creation
        if(*race != RETURN_MENU)class_selection_menu(character);//There's a Return Option Inside "race_creation"
    }
    if(*race < 0)*race = sizeofoptions-1; //If options selection becomes negative
    if(*race >= sizeofoptions)*race = 0; //If options selection becomes higher than the quantity of options in the "imenu"

}
void class_optionsregistration(int* characterclass, int sizeofoptions,CHARACTER* character, int key)
{    
    if(key == UP)*characterclass -= 1;    //If User Press Up Arrow
    if(key == DOWN)*characterclass += 1;  //If User Press Lower Arrow
    if(key == ENTER)
    {
        character_basestats(character,*characterclass);//Character stats option when choosing a class;
        if(*characterclass != RETURN_RACES)character_stats_menu(character);
    }
    if(*characterclass < 0)*characterclass = sizeofoptions-1; //If options selection becomes negative
    if(*characterclass >= sizeofoptions)*characterclass = 0; //If options selection becomes higher than the quantity of options in the "imenu"

}
void character_stats_optionsregistration(int* option, int sizeofoptions,CHARACTER* character, int key)
{
    if(key == UP)*option -= 1;    //If User Press Up Arrow
    if(key == DOWN)*option += 1;  //If User Press Lower Arrow
    if(key == ENTER)
    {
        if(*option == 0)character_name_creation(character);//Character name creation
        if(*option == 1)print_stats(character,character->race,character->characterclass);//Print Status
        if(*option == 2)attributes_menu(character);//Print Menu
        if(*option == 3)
        {
            race_creation(character->race,character);//Removing Character Class Initial Stats
            class_selection_menu(character);//Return to last menu option
        }
    }
    if(*option < 0)*option = sizeofoptions-1; //If options selection becomes negative
    if(*option >= sizeofoptions)*option = 0; //If options selection becomes higher than the quantity of options in the "imenu"
   
}
void attributes_optionsregistration(int* option, int sizeofoptions,CHARACTER* character, int key)
{
    if(key == UP)*option -= 1;    //If User Press Up Arrow
    if(key == DOWN)*option += 1;  //If User Press Lower Arrow
    
    if(key == LEFT)//Removes 1 skillpoint
    {
        attributes(character, *option, key); //Removes 1 skillpoint in the attribute, and gets 1 skillpoint back
    }
    if(key == RIGHT && character -> skillpoints_struct -> skillpoints > 0)//Adds 1 skillpoint if skillpoints != 0
    {
        character -> skillpoints_struct -> skillpoints -= 1; //Spend 1 skillpont
        attributes(character, *option, key); //Adds 1 skillpoint in the attribute
    }

    if(key == ENTER && *option == RETURN_ATTRIBUTES)
    {
        attributes_stats_calculation(character);
    }
    
    if(*option < 0)*option = sizeofoptions-1; //If options selection becomes negative
    if(*option >= sizeofoptions)*option = 0; //If options selection becomes higher than the quantity of options in the "imenu"
    if(character -> skillpoints_struct -> skillpoints < 0)
    {
        character -> skillpoints_struct -> skillpoints = 0;
        printf("\nNO SKILLPOINTS LEFT\n");
        getch();
    }
    if(character -> skillpoints_struct -> skillpoints > 300){character -> skillpoints_struct -> skillpoints = 0;printf("\nDONT TRY TO CHEAT DUDE, THAT'S HORRIBLE\n");}
}
int yes_no_optionsregistration(int* option, int sizeofoptions,int key)
{
    if(key == UP)*option -= 1;    //If User Press Up Arrow
    if(key == DOWN)*option += 1;  //If User Press Lower Arrow
    if(key == ENTER)
    {
        if(*option == 0)return 0; //Yes Option;       
        if(*option == 1)return 1; //No Option;
        
    }
    if(*option < 0)*option = sizeofoptions-1; //If options selection becomes negative
    if(*option >= sizeofoptions)*option = 0; //If options selection becomes higher than the quantity of options in the "imenu" 
    return 2;//Keeps in the loop
}

//Menu Prints
void menu_print(char** options_names, int options_selection,int sizeofoptions)//Prints the menu of the respective function
{
    for(int i = 0; i < sizeofoptions; i++)
    {
        if(i == options_selection)printf("--------\n");
        printf("|%s\n", options_names[i]);
        if(i == options_selection)printf("--------\n");
    }
}
void attributes_menu_print(char** options_names, int options_selection,int sizeofoptions,CHARACTER* character)
{
    printf("SKILLPOINTS LEFT %d\n\n",character -> skillpoints_struct -> skillpoints);
    for(int i = 0; i < sizeofoptions; i++)
    {
        if(i == options_selection)printf("--------\n");
        if(i != sizeofoptions-1)
        {
            printf("|%s : ", options_names[i]);
            print_attributes(character,i);
            printf("\n");
        }
        else printf("|%s \n", options_names[i]);
        if(i == options_selection)printf("--------\n");
    }    
}

// Initial Menus
void imenu()
{
    int options_selection = 0; //Goes from 0 to 1
    char* options_names[] = {"New Game","Load Game","Leave"}; // Options Names
    int sizeofoptions = (sizeof(options_names)/4);
    while(1)
    {
        system("cls");
        menu_print(options_names,options_selection,sizeofoptions);
        imenu_optionsregistration(&options_selection, sizeofoptions,keyregistration());
    }
}
void character_creation_menu()
{
    int options_selection = 0; //Goes from 0 to 1
    char* options_names[] = {"Character Creation","Return"}; // Options Names
    int sizeofoptions = (sizeof(options_names)/4);
    while(1)
    {
        system("cls");
        menu_print(options_names,options_selection,sizeofoptions);
        character_creation_optionsregistration(&options_selection, sizeofoptions, keyregistration());
    }   
}
void race_creation_menu()//Character Creation Menu
{
    CHARACTER* character = (CHARACTER*)malloc(sizeof(CHARACTER));
    character -> skillpoints_struct = (SKILLPOINTS*)malloc(sizeof(SKILLPOINTS));
    initialize_attributes(character);

    int options_selection = 0; //Goes from 0 to 8
    char* options_names[] = {"Human","Elf","Goblin","Dwarf","Troll","Orc","Minotaur","Gnome","Return"}; // Options Names
    int sizeofoptions = (sizeof(options_names)/4);
    while(1)
    {
        system("cls");
        menu_print(options_names,options_selection,sizeofoptions);
        race_optionsregistration(&options_selection,sizeofoptions,character, keyregistration());
    }    
}
void class_selection_menu(CHARACTER* character)
{
    int options_selection = 0; //Goes from 0 to 8
    char* options_names[] = {"Warrior","Paladin","Archer","Rogue","Priest","Mage","Necromancer","Berserker","Return"}; // Options Names
    int sizeofoptions = (sizeof(options_names)/4);
    while(1)
    {
        system("cls");
        menu_print(options_names,options_selection,sizeofoptions);
        class_optionsregistration(&options_selection,sizeofoptions,character, keyregistration());
    }    
}
void character_stats_menu(CHARACTER* character)
{
    int options_selection = 0; //Goes from 0 to 8
    char* options_names[] = {"Character Name","Show Stats","Attributes","Return"}; // Options Names
    int sizeofoptions = (sizeof(options_names)/4);
    while(1)
    {
        system("cls");
        menu_print(options_names,options_selection,sizeofoptions);
        character_stats_optionsregistration(&options_selection,sizeofoptions,character, keyregistration());
    }    
}
void attributes_menu(CHARACTER* character)
{
    int options_selection = 0; //Goes from 0 to 8
    char* options_names[] = {"Strenght","Constitution","Dexterity","Intelligence","Wisdom","Willpower","Perception","Charisma","Return"};
    int sizeofoptions = (sizeof(options_names)/4);
    while(1)
    {
        system("cls");
        attributes_menu_print(options_names,options_selection,sizeofoptions,character);
        attributes_optionsregistration(&options_selection,sizeofoptions,character, keyregistration());
    }    
}