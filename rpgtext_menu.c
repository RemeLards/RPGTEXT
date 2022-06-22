//-------------------------
//HEADERS
//-------------------------
#include "rpgtext_menu.h"

//-------------------------
//FUNCTIONS
//-------------------------
                                    //------------------------//
                                    //         MENUS          //
                                    //------------------------//
                                    
                                    // Initial Menu

int imenu()
{
    int option = NEW_GAME; //Goes from 0 to 2
    char* options_names[] = {"New Game","Load Game","Leave"}; // Options Names
    int sizeofoptions = sizeof(options_names)/ sizeof(char*);
    int value;
    
    while(TRUE)
    {
        system("cls"); //Updates UI
        menu_print(options_names,option,sizeofoptions);
        value = optionsregistration(&option, sizeofoptions,keyregistration()); 
        if(value >= NEW_GAME && value <= LEAVE) return option;
    }
    
    printf("\nUnexpected Error, Press Enter To Close The Program\n");
    getchar();//fix getch() non existence

    return UNEXPECTED_ERROR;
}

                                    // Character Creation Menu

int character_creation_menu()
{
    int option = CHAR_CREATION; //Goes from 0 to 1
    char* options_names[] = {"Character Creation","Return"}; // Options Names
    int sizeofoptions = sizeof(options_names)/ sizeof(char*);
    int value;

    while(TRUE)
    {
        system("cls"); //Updates UI
        menu_print(options_names,option,sizeofoptions);
        value = optionsregistration(&option, sizeofoptions, keyregistration());
        if(value >= CHAR_CREATION && value <= RETURN_CHARACTER_CREATION_MENU) return option;
    }

    printf("\nUnexpected Error, Press Enter To Close The Program\n");
    getchar();//fix getch() non existence

    return UNEXPECTED_ERROR;   
}

                                    // Race Selection Menu

int race_selection_menu()
{
    int race = HUMAN; //Goes from 0 to 8
    char* race_names[] = {"Human","Elf","Goblin","Dwarf","Troll","Orc","Minotaur","Gnome","Return"}; // Options Names
    int sizeofoptions = sizeof(race_names)/ sizeof(char*);
    int value;

    while(TRUE)
    {
        system("cls"); //Updates UI
        menu_print(race_names,race,sizeofoptions);
        value = optionsregistration(&race,sizeofoptions,keyregistration());
        if(value >= HUMAN && value <= RETURN_RACES) return race;
    }
    
    printf("\nUnexpected Error, Press Enter To Close The Program\n");
    getchar();//fix getch() non existence
    
    return UNEXPECTED_ERROR;
}

                                    // Class Selection Menu

int class_selection_menu()
{
    int class = WARRIOR; //Goes from 0 to 8
    char* class_names[] = {"Warrior","Paladin","Archer","Rogue","Priest","Mage","Necromancer","Berserker","Return"}; // Options Names
    int sizeofoptions = sizeof(class_names)/ sizeof(char*);
    int value;

    while(TRUE)
    {
        system("cls"); //Updates UI
        menu_print(class_names,class,sizeofoptions);
        value = optionsregistration(&class,sizeofoptions,keyregistration()); 
        if(value >= WARRIOR && value <= RETURN_CLASSES) return class;
    }

    printf("\nUnexpected Error, Press Enter To Close The Program\n");
    getchar();//fix getch() non existence

    return UNEXPECTED_ERROR;    
}

                                    // Character Stats Menu

int character_stats_menu()
{
    int option = CHARACTER_NAME; //Goes from 0 to 8
    char* options_names[] = {"Character Name","Show Stats","Return"}; // Options Names
    int sizeofoptions = sizeof(options_names)/ sizeof(char*);
    int value;

    while(TRUE)
    {
        system("cls"); //Updates UI
        menu_print(options_names,option,sizeofoptions);
        value = optionsregistration(&option,sizeofoptions,keyregistration());
        if(value >= CHARACTER_NAME && value <= RETURN_CHARACTER_STATS_MENU) return option;
    }

    printf("\nUnexpected Error, Press Enter To Close The Program\n");
    getchar();//fix getch() non existence

    return UNEXPECTED_ERROR;
}

                                    // Character Creation Menu

char* character_name_creation()
{
    char* Character_name_confirmed;  //Points to a malloced string
    int MAX_CHAR = 31; // Max number of chars
    
    int character_registered = FALSE;
    while(character_registered != TRUE)
    {
        system("cls"); //Updates UI

        char Character_name[MAX_CHAR]; //Character Name
        printf("\nCharacter Name: ");
        fflush(stdin); //Cleaning Keyboard Buffer
        fgets(Character_name, MAX_CHAR , stdin); //Gets Character Name
            
        if(Character_name[strlen(Character_name)-1] == '\n')Character_name[strlen(Character_name)-1] = '\0';//Erasing the "\n" character in the end of fgets(), if it gets into the string
        Character_name_confirmed = remove_spaces(Character_name);//If there's more than 1 space between chars, this function removes it and returns a malloced pointer that points towards a string
        
        if ( Character_name_confirmed == NULL)
        {
            printf("\n Not Enough Memory for the Character Name, Press Any Key To Close The Program \n");
            getchar();//fix getch() non existence
            return Character_name_confirmed;
        }

        while(TRUE)
        {
            int options_selection = FALSE; //Goes from 0 to 1
            char* options_names[] = {"No","Yes"}; // Options Names
            int sizeofoptions = sizeof(options_names)/ sizeof(char*);

            system("cls");
            printf("Are you sure about your character name |%s| ?\n\n", Character_name_confirmed);
            menu_print(options_names,options_selection,sizeofoptions);
            int option = optionsregistration(&options_selection, sizeofoptions,keyregistration());
            if( (character_registered = option) == TRUE){break;}
            if( (character_registered = option) == FALSE){free(Character_name_confirmed); break;}
        }
    }


    return Character_name_confirmed;
}
