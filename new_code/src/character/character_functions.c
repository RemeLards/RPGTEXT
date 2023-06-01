//-------------------------
//HEADERS
//-------------------------

#include "character_functions.h"

//-------------------------
//FUNCTIONS
//-------------------------

/*************************************
Function : character_race_selection
Date : 5/23/2023
Usable? : Yes
Explanation : Define base character stats from user character's race choice 
*************************************/
void
character_race_selection(CHARACTER *character_struct_ptr,int race)
{
    if(race == HUMAN)
    {
        CHARACTER *human = character_struct_ptr;
        human -> base_health = 30;
        human -> base_defense = 30;
        human -> base_stamina = 40;
        human -> base_mana = 10;
        human -> base_physical_power = 1;
        human -> base_physical_crit_chance = 10;
        human -> base_physical_crit_dmg = 10;
        human -> base_ability_power = 10;
        human -> base_ability_crit_chance = 10;
        human -> base_ability_crit_dmg = 10;
        human -> race = HUMAN;
    }
    if(race == ELF)
    {
        CHARACTER *elf = character_struct_ptr;
        elf -> base_health = 30;
        elf -> base_defense = 10;
        elf -> base_stamina = 20;
        elf -> base_mana = 30;
        elf -> base_physical_power = 1;
        elf -> base_physical_crit_chance = 10;
        elf -> base_physical_crit_dmg = 10;
        elf -> base_ability_power = 10;
        elf -> base_ability_crit_chance = 10;
        elf -> base_ability_crit_dmg = 10;
        elf -> race = ELF;
    }
    if(race == GOBLIN)
    {
        CHARACTER *goblin = character_struct_ptr;
        goblin -> base_health = 70;
        goblin -> base_defense = 5;
        goblin -> base_stamina = 10;
        goblin -> base_mana = 10;
        goblin -> base_physical_power = 0;
        goblin -> base_physical_crit_chance = 5;
        goblin -> base_physical_crit_dmg = 5;
        goblin -> base_ability_power = 5;
        goblin -> base_ability_crit_chance = 5;
        goblin -> base_ability_crit_dmg = 5;
        goblin -> race = GOBLIN;
    }
    if(race == DWARF)
    {
        CHARACTER *dwarf = character_struct_ptr;
        dwarf -> base_health = 40;
        dwarf -> base_defense = 30;
        dwarf -> base_stamina = 20;
        dwarf -> base_mana = 15;
        dwarf -> base_physical_power = 1;
        dwarf -> base_physical_crit_chance = 10;
        dwarf -> base_physical_crit_dmg = 10;
        dwarf -> base_ability_power = 10;
        dwarf -> base_ability_crit_chance = 10;
        dwarf -> base_ability_crit_dmg = 10;
        dwarf -> race = DWARF;
    }
    if(race == TROLL)
    {
        CHARACTER *troll = character_struct_ptr;
        troll -> base_health = 80;
        troll -> base_defense = 30;
        troll -> base_stamina = 40;
        troll -> base_mana = 0;
        troll -> base_physical_power = 5;
        troll -> base_physical_crit_chance = 10;
        troll -> base_physical_crit_dmg = 15;
        troll -> base_ability_power = 1;
        troll -> base_ability_crit_chance = 10;
        troll -> base_ability_crit_dmg = 15;
        troll -> race = TROLL;
    }
    if(race == ORC)
    {
        CHARACTER *orc = character_struct_ptr;
        orc -> base_health = 80;
        orc -> base_defense = 40;
        orc -> base_stamina = 40;
        orc -> base_mana = 0;
        orc -> base_physical_power = 4;
        orc -> base_physical_crit_chance = 10;
        orc -> base_physical_crit_dmg = 12;
        orc -> base_ability_power = 2;
        orc -> base_ability_crit_chance = 10;
        orc -> base_ability_crit_dmg = 12;
        orc -> race = ORC;
    }
    if(race == MINOTAUR)
    {
        CHARACTER *minotaur = character_struct_ptr;
        minotaur -> base_health = 100;
        minotaur -> base_defense = 20;
        minotaur -> base_stamina = 50;
        minotaur -> base_mana = 0;
        minotaur -> base_physical_power = 3;
        minotaur -> base_physical_crit_chance = 11;
        minotaur -> base_physical_crit_dmg = 11;
        minotaur -> base_ability_power = 5;
        minotaur -> base_ability_crit_chance = 11;
        minotaur -> base_ability_crit_dmg = 11;
        minotaur -> race = MINOTAUR;
    }
    if(race == GNOME)
    {
        CHARACTER *gnome = character_struct_ptr;
        gnome  -> base_health = 65;
        gnome  -> base_defense = 15;
        gnome  -> base_stamina = 25;
        gnome  -> base_mana = 15;
        gnome  -> base_physical_power = 1;
        gnome  -> base_physical_crit_chance = 12;
        gnome  -> base_physical_crit_dmg = 10;
        gnome  -> base_ability_power = 4;
        gnome  -> base_ability_crit_chance = 12;
        gnome  -> base_ability_crit_dmg = 10;
        gnome  -> race = GNOME;
    }
}

/*************************************
Function : character_class_selection
Date : 5/23/2023
Usable? : Yes
Explanation : Scale base character stats from user character's class choice 
*************************************/
void
character_class_selection(CHARACTER *character_struct_ptr,int class)
{
    if(class == WARRIOR)
    {
        CHARACTER *warrior = character_struct_ptr;
        warrior -> base_health *= 1.2;
        warrior -> base_defense *= 1.2;
        warrior -> base_stamina *= 1.5;
        warrior -> base_mana *= 1;
        warrior -> base_physical_power *= 1.5;
        warrior -> base_physical_crit_chance *= 1.1;
        warrior -> base_physical_crit_dmg *= 1.1;
        warrior -> base_ability_power *= 1;
        warrior -> base_ability_crit_chance *= 1;
        warrior -> base_ability_crit_dmg *= 1;
        warrior -> class = WARRIOR;
    }
    if(class == PALADIN)
    {
        CHARACTER *paladin = character_struct_ptr;
        paladin -> base_health *= 1;
        paladin -> base_defense *= 1.2;
        paladin -> base_stamina *= 1;
        paladin -> base_mana *= 1.5;
        paladin -> base_physical_power *= 1;
        paladin -> base_physical_crit_chance *= 1;
        paladin -> base_physical_crit_dmg *= 1;
        paladin -> base_ability_power *= 1.5;
        paladin -> base_ability_crit_chance *= 1.1;
        paladin -> base_ability_crit_dmg *= 1.1;
        paladin -> class = PALADIN;
    }
    if(class == ARCHER)
    {
        CHARACTER *archer = character_struct_ptr;
        archer -> base_health *= 1;
        archer -> base_defense *= 1;
        archer -> base_stamina *= 2;
        archer -> base_mana *= 1;
        archer -> base_physical_power *= 2;
        archer -> base_physical_crit_chance *= 1.2;
        archer -> base_physical_crit_dmg *= 1.2;
        archer -> base_ability_power *= 1;
        archer -> base_ability_crit_chance *= 1;
        archer -> base_ability_crit_dmg *= 1;
        archer -> class = ARCHER;
    }
    if(class == ROGUE)
    {
        CHARACTER *rogue = character_struct_ptr;
        rogue -> base_health *= 1.05;
        rogue -> base_defense *= 1;
        rogue -> base_stamina *= 1.5;
        rogue -> base_mana *= 1;
        rogue -> base_physical_power *= 1.8;
        rogue -> base_physical_crit_chance *= 1.3;
        rogue -> base_physical_crit_dmg *= 1.3;
        rogue -> base_ability_power *= 1;
        rogue -> base_ability_crit_chance *= 1;
        rogue -> base_ability_crit_dmg *= 1;
        rogue -> class = ROGUE;
    }
    if(class == PRIEST)
    {
        CHARACTER *priest = character_struct_ptr;
        priest -> base_health *= 1.1;
        priest -> base_defense *= 1;
        priest -> base_stamina *= 1;
        priest -> base_mana *= 2;
        priest -> base_physical_power *= 1;
        priest -> base_physical_crit_chance *= 1;
        priest -> base_physical_crit_dmg *= 1;
        priest -> base_ability_power *= 1.5;
        priest -> base_ability_crit_chance *= 1.2;
        priest -> base_ability_crit_dmg *= 1.2;
        priest -> class = PRIEST;
    }
    if(class == MAGE)
    {
        CHARACTER *mage = character_struct_ptr;
        mage -> base_health *= 1;
        mage -> base_defense *= 1;
        mage -> base_stamina *= 1;
        mage -> base_mana *= 1.8;
        mage -> base_physical_power *= 1;
        mage -> base_physical_crit_chance *= 1;
        mage -> base_physical_crit_dmg *= 1;
        mage -> base_ability_power *= 1.8;
        mage -> base_ability_crit_chance *= 1.1;
        mage -> base_ability_crit_dmg *= 1.5;
        mage -> class = MAGE;
    }
    if(class == NECROMANCER)
    {
        CHARACTER *necromancer = character_struct_ptr;
        necromancer -> base_health *= 1.1;
        necromancer -> base_defense *= 1;
        necromancer -> base_stamina *= 1;
        necromancer -> base_mana *= 3;
        necromancer -> base_physical_power *= 1;
        necromancer -> base_physical_crit_chance *= 1;
        necromancer -> base_physical_crit_dmg *= 1;
        necromancer -> base_ability_power *= 1.5;
        necromancer -> base_ability_crit_chance *= 1.5;
        necromancer -> base_ability_crit_dmg *= 1.1;
        necromancer -> class = NECROMANCER;  
    }
    if(class == BERSERKER)
    {
        CHARACTER *berserker = character_struct_ptr;
        berserker -> base_health *= 1.5;
        berserker -> base_defense *= 1;
        berserker -> base_stamina *= 2;
        berserker -> base_mana *= 1;
        berserker -> base_physical_power *= 1;
        berserker -> base_physical_crit_chance *= 1;
        berserker -> base_physical_crit_dmg *= 1;
        berserker -> base_ability_power *= 1.1;
        berserker -> base_ability_crit_chance *= 2;
        berserker -> base_ability_crit_dmg *= 1.05;
        berserker -> class = BERSERKER;
    }
}


/*************************************
Function : character_init_skillpoints
Date : 5/23/2023
Usable? : Yes
Explanation : initialize SKILLPOINTS struct variables
*************************************/
void
character_init_skillpoints(CHARACTER *character_struct_ptr)
{
    character_struct_ptr -> skillpoints_struct_ptr -> skillpoints = 0;
    character_struct_ptr -> skillpoints_struct_ptr -> strenght  = 0;
    character_struct_ptr -> skillpoints_struct_ptr -> constituition = 0;
    character_struct_ptr -> skillpoints_struct_ptr -> dexterity = 0;
    character_struct_ptr -> skillpoints_struct_ptr -> intelligence = 0;
    character_struct_ptr -> skillpoints_struct_ptr -> wisdom = 0;
    character_struct_ptr -> skillpoints_struct_ptr -> willpower = 0;
    character_struct_ptr -> skillpoints_struct_ptr -> perception = 0;
    character_struct_ptr -> skillpoints_struct_ptr -> charisma = 0;
}


                                // ATTRIBUTES/SKILLPOINTS ADDITION/REMOVAL // ------ REMOVED TEMPORALY

/*
void
attributes(CHARACTER* character, int option, int key)
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

*/
                                 // ****CHECK THIS LATER**** //
                                // ATTRIBUTES/SKILLPOINTS CALCULATION //

/*void attributes_stats_calculation(CHARACTER* character)
{
    //"CHARISMA" and "PERCEPTION" dont affect any stat yet
    race_selection(character,character -> race);//Reseting base stats to add the attributes
    //Change this later
    if(character -> class == WARRIOR)
    {
        character -> base_physical_power +=  character -> skillpoints_struct -> strenght;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_ability_power+=  character -> skillpoints_struct -> wisdom;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == PALADIN)
    {
        character -> base_physical_power +=  character -> skillpoints_struct -> strenght;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_ability_power+=  character -> skillpoints_struct -> wisdom;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == ARCHER)
    {
        character -> base_physical_power +=  character -> skillpoints_struct -> strenght;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_ability_power+=  character -> skillpoints_struct -> wisdom;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == ROGUE)
    {
        character -> base_physical_power +=  character -> skillpoints_struct -> strenght;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_ability_power+=  character -> skillpoints_struct -> wisdom;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == PRIEST)
    {
        character -> base_physical_power +=  character -> skillpoints_struct -> strenght;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_ability_power+=  character -> skillpoints_struct -> wisdom;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == MAGE)
    {
        character -> base_physical_power +=  character -> skillpoints_struct -> strenght;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_ability_power+=  character -> skillpoints_struct -> wisdom;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == NECROMANCER)
    {
        character -> base_physical_power +=  character -> skillpoints_struct -> strenght;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_ability_power+=  character -> skillpoints_struct -> wisdom;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == BERSERKER)
    {
        character -> base_physical_power +=  character -> skillpoints_struct -> strenght;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_ability_power+=  character -> skillpoints_struct -> wisdom;
        character -> base_ability_crit_dmg +=  character -> skillpoints_struct -> willpower;
    }
    class_selection(character,character -> class);//Multiply the final stats depending of the character class
    character_stats_menu(character);//Returning to the "character_stats" menu
}*/


/*************************************
Function : character_init_level
Date : 5/24/2023
Usable? : Yes
Explanation : initialize CHAR_LEVEL struct variables
*************************************/
void
character_init_level(CHARACTER *character_struct_ptr)
{
    character_struct_ptr -> level_struct_ptr -> level = 1;
    character_struct_ptr -> level_struct_ptr -> experience = 0;
}

/*************************************
Function : character_exp_to_next_level_calculation
Date : 5/24/2023
Usable? : Yes
Explanation : Calculates experience (EXP) required for the character to reach next level, 
*************************************/

float
character_exp_to_next_level_calculation(CHARACTER *character_struct_ptr)
{
    float experience_needed = 500;

    for(int i = 1; i < character_struct_ptr -> level_struct_ptr -> level; i++) experience_needed *= 1.05;
    
    return experience_needed;
}                                

/*************************************
Function : character_level_calculation
Date : 5/24/2023
Usable? : Yes
Explanation : Calculates if a character leveled up (reached the ammount of experience required to level up).
If the ammount of experience exceed the requirement of the level, this function carries over the remaining experience
that exceeded the level exp requirement.
*************************************/
void
character_level_calculation(CHARACTER *character_struct_ptr)
{
    if(character_struct_ptr -> level_struct_ptr -> experience >= character_exp_to_next_level_calculation(character_struct_ptr))
    {
        character_struct_ptr -> level_struct_ptr -> experience -= character_exp_to_next_level_calculation(character_struct_ptr);   
        character_struct_ptr -> level_struct_ptr -> level++;
        printf("\nCONGRATS YOU LEVELED UP, NOW YOU ARE LEVEL %d\n",character_struct_ptr -> level_struct_ptr -> level);
    }
    printf("\nYOU HAVE %.0f EXPERIENCE, AND YOU NEED %.0f EXPERIENCE FOR THE NEXT LEVEL",
    character_struct_ptr -> level_struct_ptr -> experience,
    character_exp_to_next_level_calculation(character_struct_ptr) - character_struct_ptr -> level_struct_ptr -> experience);
    
    printf("\nPress Enter To Continue\n");
    getchar();
}
                               
/************************************
Function : character_print_statistics
Date : 5/24/2023
Usable? : Yes
Explanation : Prints character statistics, like physical power number, quantity of mana, critical chance percentage, etc.
*************************************/
void
character_print_statistics(CHARACTER *character_struct_ptr)
{
    const char *races_names[] = {"Human", "Elf","Goblin","Dwarf","Troll","Orc","Minotaur","Gnome"};
    const char *classes_names[] = {"Warrior","Paladin","Archer","Rogue","Priest","Mage","Necromancer","Berserker"};
    system_clear();
    printf("RACE: %s\n",races_names[character_struct_ptr -> race]);
    printf("CLASS: %s\n",classes_names[character_struct_ptr -> class]);
    printf("BASE HEALTH: %.2f\n",character_struct_ptr -> base_health);
    printf("BASE DEFENSE: %.2f\n",character_struct_ptr -> base_defense);
    printf("BASE MANA: %.2f\n",character_struct_ptr -> base_mana);
    printf("BASE STAMINA: %.2f\n",character_struct_ptr -> base_stamina);
    printf("BASE physical POWER: %.2f\n",character_struct_ptr -> base_physical_power);
    printf("BASE CRIT CHANCE: %.2f\n",character_struct_ptr -> base_physical_crit_chance);
    printf("BASE CRIT DAMAGE: %.2f\n",character_struct_ptr -> base_physical_crit_dmg);
    printf("BASE ABILITY POWER: %.2f\n",character_struct_ptr -> base_ability_power);
    printf("BASE ABILITY CRIT CHANCE: %.2f\n",character_struct_ptr -> base_ability_crit_chance);
    printf("BASE ABILITY CRIT DMG: %.2f\n\n",character_struct_ptr -> base_ability_crit_dmg);

    printf("PRESS ANY KEY TO RETURN");

    getch();
}

/************************************
Function :character_ print_attributes
Date : 5/24/2023
Usable? : Yes
Explanation : Prints character attributes statistics, strenght number, wisdow number, etc.
*************************************/                                     
void
character_print_attributes(CHARACTER *character_struct_ptr, int index)
{
    if(index == STRENGHT)printf("%d",character_struct_ptr -> skillpoints_struct_ptr -> strenght);
    if(index == CONSTITUITION)printf("%d",character_struct_ptr -> skillpoints_struct_ptr -> constituition);
    if(index == DEXTERITY)printf("%d",character_struct_ptr -> skillpoints_struct_ptr -> dexterity);
    if(index == INTELLINGENCE)printf("%d",character_struct_ptr -> skillpoints_struct_ptr -> intelligence);
    if(index == WISDOM)printf("%d",character_struct_ptr -> skillpoints_struct_ptr -> wisdom);
    if(index == WILLPOWER)printf("%d",character_struct_ptr -> skillpoints_struct_ptr -> willpower);
    if(index == PERCEPTION)printf("%d",character_struct_ptr -> skillpoints_struct_ptr -> perception);
    if(index == CHARISMA)printf("%d",character_struct_ptr -> skillpoints_struct_ptr -> charisma);
}

/************************************
Function :character_init_all
Date : 5/28/2023
Usable? : Yes
Explanation : Initializes all character variables using all other " character_init_<struct_name> " functions
*************************************/      
void
character_init_all(CHARACTER *character_struct_ptr)
{
    character_init(character_struct_ptr);
    character_init_level(character_struct_ptr);
    character_init_skillpoints(character_struct_ptr);
    //character_init_backpack(character);
}

/************************************
Function :character_malloc_all
Date : 5/28/2023
Usable? : Yes
Explanation : Memory allocates all structs pointers related to the character (including it's own struct), and retuns a usable CHARACTER pointer type
*************************************/   

CHARACTER *
character_malloc_all()
{
    CHARACTER *character_struct_ptr = (CHARACTER *) malloc (sizeof(CHARACTER));
    character_struct_ptr -> level_struct_ptr = (LEVEL *) malloc (sizeof(LEVEL));
    character_struct_ptr -> skillpoints_struct_ptr = (SKILLPOINTS *) malloc (sizeof(SKILLPOINTS));
    //character_struct_ptr -> backpack_struct = (BACKPACK *) malloc (sizeof(BACKPACK));
    
    return character_struct_ptr;
}

/************************************
Function :character_free_all
Date : 5/28/2023
Usable? : Yes
Explanation : Frees all memory allocated to all structs pointers related to the character (including it's own struct)
*************************************/   

void
character_free_all(CHARACTER *character_struct_ptr)
{
    free(character_struct_ptr -> level_struct_ptr); 
    free(character_struct_ptr -> skillpoints_struct_ptr);
    //free(character_struct_ptr -> backpack_struct);
    free(character_struct_ptr);
}

void
character_init(CHARACTER *character_struct_ptr)
{
    character_struct_ptr -> character_name = NULL;
    character_struct_ptr -> base_health = 0.0;
    character_struct_ptr -> base_defense = 0.0;
    character_struct_ptr -> base_stamina = 0.0;
    character_struct_ptr -> base_mana = 0.0;
    character_struct_ptr -> base_physical_power = 0.0;
    character_struct_ptr -> base_physical_crit_chance = 0.0;
    character_struct_ptr -> base_physical_crit_dmg = 0.0;
    character_struct_ptr -> base_ability_power = 0.0;
    character_struct_ptr -> base_ability_crit_chance = 0.0;
    character_struct_ptr -> base_ability_crit_dmg = 0.0;
    character_struct_ptr -> attack_type = NONE_ATTACK_TYPE;
    character_struct_ptr -> ability_type = NONE_ABILITY_TYPE;
    character_struct_ptr -> race = NONE_RACE;
    character_struct_ptr -> class = NONE_CLASS;
}

                                      