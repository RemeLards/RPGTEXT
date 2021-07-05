//-------------------------
//HEADERS
//-------------------------

#include "rpgtext_character.h"
#include "rpgtext_menu.h"

//-------------------------
//FUNCTIONS
//-------------------------

    //Character Race/Class/Stats
void race_creation(int race,CHARACTER* character)
{
    if(race == HUMAN)
    {
        CHARACTER* human = character;
        human -> base_health = 30;
        human -> base_defense = 30;
        human -> base_stamina = 40;
        human -> base_mana = 10;
        human -> base_attackpower = 1;
        human -> base_critchance = 10;
        human -> base_critdmg = 10;
        human -> base_abilitypower = 10;
        human -> base_abilitycritchance = 10;
        human -> base_abilitycritdmg = 10;
        human -> race = HUMAN;
    }
    if(race == ELF)
    {
        CHARACTER* elf = character;
        elf -> base_health = 30;
        elf -> base_defense = 10;
        elf -> base_stamina = 20;
        elf -> base_mana = 30;
        elf -> base_attackpower = 1;
        elf -> base_critchance = 10;
        elf -> base_critdmg = 10;
        elf -> base_abilitypower = 10;
        elf -> base_abilitycritchance = 10;
        elf -> base_abilitycritdmg = 10;
        elf -> race = ELF;
    }
    if(race == GOBLIN)
    {
        CHARACTER* goblin = character;
        goblin -> base_health = 70;
        goblin -> base_defense = 5;
        goblin -> base_stamina = 10;
        goblin -> base_mana = 10;
        goblin -> base_attackpower = 0;
        goblin -> base_critchance = 5;
        goblin -> base_critdmg = 5;
        goblin -> base_abilitypower = 5;
        goblin -> base_abilitycritchance = 5;
        goblin -> base_abilitycritdmg = 5;
        goblin -> race = GOBLIN;
    }
    if(race == DWARF)
    {
        CHARACTER* dwarf = character;
        dwarf -> base_health = 40;
        dwarf -> base_defense = 30;
        dwarf -> base_stamina = 20;
        dwarf -> base_mana = 15;
        dwarf -> base_attackpower = 1;
        dwarf -> base_critchance = 10;
        dwarf -> base_critdmg = 10;
        dwarf -> base_abilitypower = 10;
        dwarf -> base_abilitycritchance = 10;
        dwarf -> base_abilitycritdmg = 10;
        dwarf -> race = DWARF;
    }
    if(race == TROLL)
    {
        CHARACTER* troll = character;
        troll -> base_health = 80;
        troll -> base_defense = 30;
        troll -> base_stamina = 40;
        troll -> base_mana = 0;
        troll -> base_attackpower = 5;
        troll -> base_critchance = 10;
        troll -> base_critdmg = 15;
        troll -> base_abilitypower = 1;
        troll -> base_abilitycritchance = 10;
        troll -> base_abilitycritdmg = 15;
        troll -> race = TROLL;
    }
    if(race == ORC)
    {
        CHARACTER* orc = character;
        orc -> base_health = 80;
        orc -> base_defense = 40;
        orc -> base_stamina = 40;
        orc -> base_mana = 0;
        orc -> base_attackpower = 4;
        orc -> base_critchance = 10;
        orc -> base_critdmg = 12;
        orc -> base_abilitypower = 2;
        orc -> base_abilitycritchance = 10;
        orc -> base_abilitycritdmg = 12;
        orc -> race = ORC;
    }
    if(race == MINOTAUR)
    {
        CHARACTER* minotaur = character;
        minotaur -> base_health = 100;
        minotaur -> base_defense = 20;
        minotaur -> base_stamina = 50;
        minotaur -> base_mana = 0;
        minotaur -> base_attackpower = 3;
        minotaur -> base_critchance = 11;
        minotaur -> base_critdmg = 11;
        minotaur -> base_abilitypower = 5;
        minotaur -> base_abilitycritchance = 11;
        minotaur -> base_abilitycritdmg = 11;
        minotaur -> race = MINOTAUR;
    }
    if(race == GNOME)
    {
        CHARACTER* gnome = character;
        gnome  -> base_health = 65;
        gnome  -> base_defense = 15;
        gnome  -> base_stamina = 25;
        gnome  -> base_mana = 15;
        gnome  -> base_attackpower = 1;
        gnome  -> base_critchance = 12;
        gnome  -> base_critdmg = 10;
        gnome  -> base_abilitypower = 4;
        gnome  -> base_abilitycritchance = 12;
        gnome  -> base_abilitycritdmg = 10;
        gnome  -> race = GNOME;
    }
    if(race == RETURN_MENU)
    {
        free(character -> skillpoints_struct);//Freeing Malloced "skillpoints_struct" struct
        free(character);//Freeing Malloced "character" struct, because we'll return to the initial menu AKA "imenu()"
        character_creation_menu(); //Return to the last menu
    }
}
void initialize_attributes(CHARACTER* character)
{
    character -> skillpoints_struct -> skillpoints = 0;
    character -> skillpoints_struct -> strenght  = 0;
    character -> skillpoints_struct -> constituition = 0;
    character -> skillpoints_struct -> dexterity = 0;
    character -> skillpoints_struct -> intelligence = 0;
    character -> skillpoints_struct -> wisdom = 0;
    character -> skillpoints_struct -> willpower = 0;
    character -> skillpoints_struct -> perception = 0;
    character -> skillpoints_struct -> charisma = 0;
}
void character_basestats(CHARACTER* character,int characterclass)
{
    if(characterclass == WARRIOR)
    {
        character ->base_health *= 1.2;
        character ->base_defense *= 1.2;
        character ->base_stamina *= 1.5;
        character ->base_mana *= 1;
        character ->base_attackpower *= 1.5;
        character ->base_critchance *= 1.1;
        character ->base_critdmg *= 1.1;
        character ->base_abilitypower *= 1;
        character ->base_abilitycritchance *= 1;
        character ->base_abilitycritdmg *= 1;
        character ->characterclass = WARRIOR;
    }
    if(characterclass == PALADIN)
    {
        character ->base_health *= 1;
        character ->base_defense *= 1.2;
        character ->base_stamina *= 1;
        character ->base_mana *= 1.5;
        character ->base_attackpower *= 1;
        character ->base_critchance *= 1;
        character ->base_critdmg *= 1;
        character ->base_abilitypower *= 1.5;
        character ->base_abilitycritchance *= 1.1;
        character ->base_abilitycritdmg *= 1.1;
        character ->characterclass = PALADIN;
    }
    if(characterclass == ARCHER)
    {
        character ->base_health *= 1;
        character ->base_defense *= 1;
        character ->base_stamina *= 2;
        character ->base_mana *= 1;
        character ->base_attackpower *= 2;
        character ->base_critchance *= 1.2;
        character ->base_critdmg *= 1.2;
        character ->base_abilitypower *= 1;
        character ->base_abilitycritchance *= 1;
        character ->base_abilitycritdmg *= 1;
        character ->characterclass = ARCHER;
    }
    if(characterclass == ROGUE)
    {
        character ->base_health *= 1.05;
        character ->base_defense *= 1;
        character ->base_stamina *= 1.5;
        character ->base_mana *= 1;
        character ->base_attackpower *= 1.8;
        character ->base_critchance *= 1.3;
        character ->base_critdmg *= 1.3;
        character ->base_abilitypower *= 1;
        character ->base_abilitycritchance *= 1;
        character ->base_abilitycritdmg *= 1;
        character ->characterclass = ROGUE;
    }
    if(characterclass == PRIEST)
    {
        character ->base_health *= 1.1;
        character ->base_defense *= 1;
        character ->base_stamina *= 1;
        character ->base_mana *= 2;
        character ->base_attackpower *= 1;
        character ->base_critchance *= 1;
        character ->base_critdmg *= 1;
        character ->base_abilitypower *= 1.5;
        character ->base_abilitycritchance *= 1.2;
        character ->base_abilitycritdmg *= 1.2;
        character ->characterclass = PRIEST;
    }
    if(characterclass == MAGE)
    {
        character ->base_health *= 1;
        character ->base_defense *= 1;
        character ->base_stamina *= 1;
        character ->base_mana *= 1.8;
        character ->base_attackpower *= 1;
        character ->base_critchance *= 1;
        character ->base_critdmg *= 1;
        character ->base_abilitypower *= 1.8;
        character ->base_abilitycritchance *= 1.1;
        character ->base_abilitycritdmg *= 1.5;
        character ->characterclass = MAGE;
    }
    if(characterclass == NECROMANCER)
    {
        character ->base_health *= 1.1;
        character ->base_defense *= 1;
        character ->base_stamina *= 1;
        character ->base_mana *= 3;
        character ->base_attackpower *= 1;
        character ->base_critchance *= 1;
        character ->base_critdmg *= 1;
        character ->base_abilitypower *= 1.5;
        character ->base_abilitycritchance *= 1.5;
        character ->base_abilitycritdmg *= 1.1;
        character ->characterclass = NECROMANCER;  
    }
    if(characterclass == BERSERKER)
    {
        character ->base_health *= 1.5;
        character ->base_defense *= 1;
        character ->base_stamina *= 2;
        character ->base_mana *= 1;
        character ->base_attackpower *= 1;
        character ->base_critchance *= 1;
        character ->base_critdmg *= 1;
        character ->base_abilitypower *= 1.1;
        character ->base_abilitycritchance *= 2;
        character ->base_abilitycritdmg *= 1.05;
        character ->characterclass = BERSERKER;
    }
    if(characterclass == RETURN_RACES)
    {
        race_creation_menu();//Return to last menu option
    }
}
void character_name_creation(CHARACTER* character)
{
    char* Character_name_confirmed;  //Points to a malloced string
    int character_registered = 1;   //confirmation of the character name "1" to "no" and "0" to "yes"
    while(character_registered != 0)
    {
        system("cls");

        char Character_name[31];//Character Name
        printf("\nCharacter Name: ");
        fflush(stdin);//Cleaning Keyboard Buffer
        fgets(Character_name,31, stdin);//Gets Character Name
            
        if(Character_name[strlen(Character_name)-1] == '\n')Character_name[strlen(Character_name)-1] = '\0';//Erasing the "\n" character in the end of fgets(), if it gets into the string
        Character_name_confirmed  = remove_spaces(Character_name);//If there's more than 1 space between chars, this function removes it and returns a malloced pointer that points towards a string
        
        int options_selection = 0; //Goes from 0 to 1
        char* options_names[] = {"Yes","No"}; // Options Names
        int sizeofoptions = (sizeof(options_names)/4);

        while(1)
        {
            system("cls");
            printf("Are you sure about your character name |%s| ?\n\n", Character_name_confirmed);
            menu_print(options_names,options_selection,sizeofoptions);
            int key = yes_no_optionsregistration(&options_selection, sizeofoptions,keyregistration());
            if(key == 0){character_registered = 0; break;}
            if(key == 1){character_registered = 1; free(Character_name_confirmed); break;}
        }
    }
    character -> character_name = Character_name_confirmed;//"character_name" points to the malloced string that "Character_name_confirmed" points too
    character -> level_struct = (CHAR_LEVEL*)malloc(sizeof(CHAR_LEVEL));
    level_initialization(character);
    game(character); 
}

    //Skillpoints and Attributes

void attributes(CHARACTER* character, int option, int key)
{
    if(key == LEFT)// Removing 1 skillpoint
    {
        if(option == STRENGHT)
        {
            if(character -> skillpoints_struct -> strenght > 0)
            {
                character -> skillpoints_struct -> skillpoints += 1;  //Gets 1 skillpoint back
                character -> skillpoints_struct -> strenght-= 1;//Just remove a skillpoint if its value before its higher than 0
            }
        }
        if(option == CONSTITUITION)
        {
            if(character -> skillpoints_struct -> constituition > 0)
            {
                character -> skillpoints_struct -> skillpoints += 1;  //Gets 1 skillpoint back
                character -> skillpoints_struct -> constituition-= 1;//Just remove a skillpoint if its value before its higher than 0
            }
        }
        if(option == DEXTERITY)
        {
            if(character -> skillpoints_struct -> dexterity > 0)
            {
                character -> skillpoints_struct -> skillpoints += 1;  //Gets 1 skillpoint back
                character -> skillpoints_struct -> dexterity-= 1;    //Just remove a skillpoint if its value before its higher than 0
            }   
        }
        if(option == INTELLINGENCE)
        {
            if(character -> skillpoints_struct -> intelligence > 0)
            {
                character -> skillpoints_struct -> skillpoints += 1;  //Gets 1 skillpoint back
                character -> skillpoints_struct -> intelligence-= 1; //Just remove a skillpoint if its value before its higher than 0
            }
        }
        if(option == WISDOM)
        {
            if(character -> skillpoints_struct -> wisdom > 0)
            {
                character -> skillpoints_struct -> skillpoints += 1;  //Gets 1 skillpoint back
                character -> skillpoints_struct -> wisdom-= 1;       //Just remove a skillpoint if its value before its higher than 0
            }
        }
        if(option == WILLPOWER)
        {
            if(character -> skillpoints_struct -> willpower > 0)
            {
                character -> skillpoints_struct -> skillpoints += 1;  //Gets 1 skillpoint back
                character -> skillpoints_struct -> willpower-= 1;    //Just remove a skillpoint if its value before its higher than 0
            }
        }
        if(option == PERCEPTION)
        {
            if(character -> skillpoints_struct -> perception > 0)
            {
                character -> skillpoints_struct -> skillpoints += 1;  //Gets 1 skillpoint back
                character -> skillpoints_struct -> perception-= 1;   //Just remove a skillpoint if its value before its higher than 0
            }
        }
        if(option == CHARISMA)
        {
            if(character -> skillpoints_struct -> charisma > 0)
            {
                character -> skillpoints_struct -> skillpoints += 1;  //Gets 1 skillpoint back
                character -> skillpoints_struct -> charisma-= 1;      //Just remove a skillpoint if its value before its higher than 0
            }
        }
    }
    if(key == RIGHT)// Adds 1 skillpoint
    {
        if(option == STRENGHT)
        {
            character -> skillpoints_struct -> strenght+= 1;
        }
        if(option == CONSTITUITION)
        {
            character -> skillpoints_struct -> constituition+= 1;
        }
        if(option == DEXTERITY)
        {
            character -> skillpoints_struct -> dexterity+= 1;
        }
        if(option == INTELLINGENCE)
        {
            character -> skillpoints_struct -> intelligence+= 1;
        }
        if(option == WISDOM)
        {
            character -> skillpoints_struct -> wisdom+= 1;
        }
        if(option == WILLPOWER)
        {
            character -> skillpoints_struct -> willpower+= 1;
        }
        if(option == PERCEPTION)
        {
            character -> skillpoints_struct -> perception+= 1;
        }
        if(option == CHARISMA)
        {
            character -> skillpoints_struct -> charisma+= 1;
        }
    }
}
void attributes_stats_calculation(CHARACTER* character)
{
    //"CHARISMA" and "PERCEPTION" dont affect any stat yet
    race_creation(character -> race, character);//Reseting base stats to add the attributes and Mallocing "race" char again
    if(character -> characterclass == WARRIOR)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> characterclass == PALADIN)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> characterclass == ARCHER)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> characterclass == ROGUE)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> characterclass == PRIEST)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> characterclass == MAGE)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> characterclass == NECROMANCER)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> characterclass == BERSERKER)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    character_basestats(character,character -> characterclass);//Multiply the final stats depending of the character class and Malloc "character_class" again
    character_stats_menu(character);//Returning to the "character_stats" menu
}

    //Level
void level_initialization(CHARACTER* character)
{
    character -> level_struct -> character_level = 1;
    character -> level_struct -> experience_tracker = 0;
}    
float level_calculation(CHARACTER* character)
{
    float experience_needed = 500;
    for(int i = 1; i < character -> level_struct -> character_level; i++)
    {
        experience_needed *= 1.05;
    }
    experience_needed *= character -> level_struct -> character_level;
    return experience_needed;
}
void character_level(CHARACTER* character)
{
    if(character -> level_struct -> experience_tracker >= level_calculation(character))
    {
        character -> level_struct -> experience_tracker -= level_calculation(character);   
        character -> level_struct -> character_level += 1;
        printf("\nCONGRATS YOU LEVELED UP, NOW YOU ARE LEVEL %d\n",character -> level_struct -> character_level);
    }
    printf("\nYOU HAVE %.0f EXPERIENCE, AND YOU NEED %.0f EXPERIENCE FOR THE NEXT LEVEL",character -> level_struct -> experience_tracker,level_calculation(character) - character -> level_struct -> experience_tracker);
    getch();
}

    //Character Prints
void print_stats(CHARACTER* character, int race, int characterclass)
{
    char* RACES_STR[] = {"HUMAN", "ELF","GOBLIN","DWARF","TROLL","ORC","MINOTAUR","GNOME","RETURN_MENU"};
    char* CLASSES_STR[] = {"WARRIOR","PALADIN","ARCHER","ROGUE","PRIEST","MAGE","NECROMANCER","BERSERKER","RETURN_RACES"};
    system("cls");
    printf("RACE: %s\n",RACES_STR[character->race]);
    printf("CLASS: %s\n",CLASSES_STR[character->characterclass]);
    printf("BASE HEALTH: %.2f\n",character ->base_health);
    printf("BASE DEFENSE: %.2f\n",character ->base_defense);
    printf("BASE MANA: %.2f\n",character ->base_mana);
    printf("BASE STAMINA: %.2f\n",character ->base_stamina);
    printf("BASE ATTACK POWER: %.2f\n",character ->base_attackpower);
    printf("BASE CRIT CHANCE: %.2f\n",character ->base_critchance);
    printf("BASE CRIT DAMAGE: %.2f\n",character ->base_critdmg);
    printf("BASE ABILITY POWER: %.2f\n",character ->base_abilitypower);
    printf("BASE ABILITY CRIT CHANCE: %.2f\n",character ->base_abilitycritchance);
    printf("BASE ABILITY CRIT DMG: %.2f\n\n",character ->base_abilitycritdmg);

    printf("PRESS ENTER TO RETURN");

    while(1)
    {
        if(keyregistration() == ENTER)break;
    }
}
void print_attributes(CHARACTER* character, int index)
{
    if(index == STRENGHT)printf("%d",character -> skillpoints_struct -> strenght);
    if(index == CONSTITUITION)printf("%d",character -> skillpoints_struct -> constituition);
    if(index == DEXTERITY)printf("%d",character -> skillpoints_struct -> dexterity);
    if(index == INTELLINGENCE)printf("%d",character -> skillpoints_struct -> intelligence);
    if(index == WISDOM)printf("%d",character -> skillpoints_struct -> wisdom);
    if(index == WILLPOWER)printf("%d",character -> skillpoints_struct -> willpower);
    if(index == PERCEPTION)printf("%d",character -> skillpoints_struct -> perception);
    if(index == CHARISMA)printf("%d",character -> skillpoints_struct -> charisma);
}
