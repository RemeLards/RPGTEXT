//-------------------------
//HEADERS
//-------------------------
#include "rpgtext_game.h"

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
            
            character -> character_level -> experience += monster -> experience_given; //Giving EXP To Player
            printf("\n\nYOU GOT %.0f XP\n",monster -> experience_given);  //Print XP That Player Got 
            level_calculation(character);         //Calculating If Player Leveled Up

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
            free(character -> character_level);        //Freeing Character Level Struct
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

//Character Info

                                   // Attribute Menu *MUDAR PARA O JOGO (TIRAR DO MENU DE CRIAÇÃO DE PERSONAGEM)

int attributes_menu(CHARACTER* character)
{
    int options_selection = 0; //Goes from 0 to 8
    char* options_names[] = {"Strenght","Constitution","Dexterity","Intelligence","Wisdom","Willpower","Perception","Charisma","Return"};
    int sizeofoptions = (sizeof(options_names)/4);
    while(1)
    {
        system("cls");
        attributes_menu_print(options_names,options_selection,sizeofoptions,character);
        attributes_optionsregistration(character,&options_selection,sizeofoptions, keyregistration());
    }    
}
void attributes_optionsregistration(CHARACTER* character,int* option, int sizeofoptions,int key)
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
