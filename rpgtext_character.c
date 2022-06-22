//-------------------------
//HEADERS
//-------------------------

#include "rpgtext_character.h"

//-------------------------
//FUNCTIONS
//-------------------------

                                        //------------------------//
                                       //CHARACTER RACE AND CLASS//
                                      //------------------------//

                                        // RACES //

void race_selection(CHARACTER* character,int race)
{
    if(race == HUMAN)
    {
        CHARACTER* human = character;
        human -> base_health = 30;
        human -> base_defense = 30;
        human -> base_stamina = 40;
        human -> base_mana = 10;
        human -> base_attackpower = 1;
        human -> base_attackcritchance = 10;
        human -> base_attackcritdmg = 10;
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
        elf -> base_attackcritchance = 10;
        elf -> base_attackcritdmg = 10;
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
        goblin -> base_attackcritchance = 5;
        goblin -> base_attackcritdmg = 5;
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
        dwarf -> base_attackcritchance = 10;
        dwarf -> base_attackcritdmg = 10;
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
        troll -> base_attackcritchance = 10;
        troll -> base_attackcritdmg = 15;
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
        orc -> base_attackcritchance = 10;
        orc -> base_attackcritdmg = 12;
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
        minotaur -> base_attackcritchance = 11;
        minotaur -> base_attackcritdmg = 11;
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
        gnome  -> base_attackcritchance = 12;
        gnome  -> base_attackcritdmg = 10;
        gnome  -> base_abilitypower = 4;
        gnome  -> base_abilitycritchance = 12;
        gnome  -> base_abilitycritdmg = 10;
        gnome  -> race = GNOME;
    }
}

                                        // CLASSES //

void class_selection(CHARACTER* character,int class)
{
    if(class == WARRIOR)
    {
        CHARACTER* warrior = character;
        warrior -> base_health *= 1.2;
        warrior -> base_defense *= 1.2;
        warrior -> base_stamina *= 1.5;
        warrior -> base_mana *= 1;
        warrior -> base_attackpower *= 1.5;
        warrior -> base_attackcritchance *= 1.1;
        warrior -> base_attackcritdmg *= 1.1;
        warrior -> base_abilitypower *= 1;
        warrior -> base_abilitycritchance *= 1;
        warrior -> base_abilitycritdmg *= 1;
        warrior -> class = WARRIOR;
    }
    if(class == PALADIN)
    {
        CHARACTER* paladin = character;
        paladin -> base_health *= 1;
        paladin -> base_defense *= 1.2;
        paladin -> base_stamina *= 1;
        paladin -> base_mana *= 1.5;
        paladin -> base_attackpower *= 1;
        paladin -> base_attackcritchance *= 1;
        paladin -> base_attackcritdmg *= 1;
        paladin -> base_abilitypower *= 1.5;
        paladin -> base_abilitycritchance *= 1.1;
        paladin -> base_abilitycritdmg *= 1.1;
        paladin -> class = PALADIN;
    }
    if(class == ARCHER)
    {
        CHARACTER* archer = character;
        archer -> base_health *= 1;
        archer -> base_defense *= 1;
        archer -> base_stamina *= 2;
        archer -> base_mana *= 1;
        archer -> base_attackpower *= 2;
        archer -> base_attackcritchance *= 1.2;
        archer -> base_attackcritdmg *= 1.2;
        archer -> base_abilitypower *= 1;
        archer -> base_abilitycritchance *= 1;
        archer -> base_abilitycritdmg *= 1;
        archer -> class = ARCHER;
    }
    if(class == ROGUE)
    {
        CHARACTER* rogue = character;
        rogue -> base_health *= 1.05;
        rogue -> base_defense *= 1;
        rogue -> base_stamina *= 1.5;
        rogue -> base_mana *= 1;
        rogue -> base_attackpower *= 1.8;
        rogue -> base_attackcritchance *= 1.3;
        rogue -> base_attackcritdmg *= 1.3;
        rogue -> base_abilitypower *= 1;
        rogue -> base_abilitycritchance *= 1;
        rogue -> base_abilitycritdmg *= 1;
        rogue -> class = ROGUE;
    }
    if(class == PRIEST)
    {
        CHARACTER* priest = character;
        priest -> base_health *= 1.1;
        priest -> base_defense *= 1;
        priest -> base_stamina *= 1;
        priest -> base_mana *= 2;
        priest -> base_attackpower *= 1;
        priest -> base_attackcritchance *= 1;
        priest -> base_attackcritdmg *= 1;
        priest -> base_abilitypower *= 1.5;
        priest -> base_abilitycritchance *= 1.2;
        priest -> base_abilitycritdmg *= 1.2;
        priest -> class = PRIEST;
    }
    if(class == MAGE)
    {
        CHARACTER* mage = character;
        mage -> base_health *= 1;
        mage -> base_defense *= 1;
        mage -> base_stamina *= 1;
        mage -> base_mana *= 1.8;
        mage -> base_attackpower *= 1;
        mage -> base_attackcritchance *= 1;
        mage -> base_attackcritdmg *= 1;
        mage -> base_abilitypower *= 1.8;
        mage -> base_abilitycritchance *= 1.1;
        mage -> base_abilitycritdmg *= 1.5;
        mage -> class = MAGE;
    }
    if(class == NECROMANCER)
    {
        CHARACTER* necromancer = character;
        necromancer -> base_health *= 1.1;
        necromancer -> base_defense *= 1;
        necromancer -> base_stamina *= 1;
        necromancer -> base_mana *= 3;
        necromancer -> base_attackpower *= 1;
        necromancer -> base_attackcritchance *= 1;
        necromancer -> base_attackcritdmg *= 1;
        necromancer -> base_abilitypower *= 1.5;
        necromancer -> base_abilitycritchance *= 1.5;
        necromancer -> base_abilitycritdmg *= 1.1;
        necromancer -> class = NECROMANCER;  
    }
    if(class == BERSERKER)
    {
        CHARACTER* berserker = character;
        berserker -> base_health *= 1.5;
        berserker -> base_defense *= 1;
        berserker -> base_stamina *= 2;
        berserker -> base_mana *= 1;
        berserker -> base_attackpower *= 1;
        berserker -> base_attackcritchance *= 1;
        berserker -> base_attackcritdmg *= 1;
        berserker -> base_abilitypower *= 1.1;
        berserker -> base_abilitycritchance *= 2;
        berserker -> base_abilitycritdmg *= 1.05;
        berserker -> class = BERSERKER;
    }
}



                                        //-----------//
                                       //SKILLPOINTS//
                                      //-----------//

           
                                // INITIALIZING CHARACTER SKILLPOINTS //

void init_skillpoints(CHARACTER* character)
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


                                // ATTRIBUTES/SKILLPOINTS ADDITION/REMOVAL //

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


                                 // ****CHECK THIS LATER**** //
                                // ATTRIBUTES/SKILLPOINTS CALCULATION //

/*void attributes_stats_calculation(CHARACTER* character)
{
    //"CHARISMA" and "PERCEPTION" dont affect any stat yet
    race_selection(character,character -> race);//Reseting base stats to add the attributes
    //Change this later
    if(character -> class == WARRIOR)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == PALADIN)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == ARCHER)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == ROGUE)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == PRIEST)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == MAGE)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == NECROMANCER)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    if(character -> class == BERSERKER)
    {
        character -> base_attackpower +=  character -> skillpoints_struct -> strenght;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> constituition;
        character -> base_stamina +=  character -> skillpoints_struct -> dexterity;
        character -> base_mana +=  character -> skillpoints_struct -> intelligence;
        character -> base_abilitypower+=  character -> skillpoints_struct -> wisdom;
        character -> base_abilitycritdmg +=  character -> skillpoints_struct -> willpower;
    }
    class_selection(character,character -> class);//Multiply the final stats depending of the character class
    character_stats_menu(character);//Returning to the "character_stats" menu
}*/





                                        //--------//
                                       //LEVELING//
                                      //--------//

                     
                            // INITIALIZING CHARACTER ATTRIBUTES/SKILLPOINTS //

void init_level(CHARACTER* character)
{
    character -> character_level -> level = 1;
    character -> character_level -> experience = 0;
}

                            // CALCULATION OF EXPERIENCE NEEDED TO NEXT LEVEL //

float exp_to_nextlevel_calculation(CHARACTER* character)
{
    float experience_needed = 500;
    for(int i = 1; i < character -> character_level -> level; i++)
    {
        experience_needed *= 1.05;
    }
    experience_needed *= character -> character_level -> level;
    return experience_needed;
}

                                        // LEVEL CALCULATION //                                    

void level_calculation(CHARACTER* character)
{
    if(character -> character_level -> experience >= exp_to_nextlevel_calculation(character))
    {
        character -> character_level -> experience -= exp_to_nextlevel_calculation(character);   
        character -> character_level -> level++;
        printf("\nCONGRATS YOU LEVELED UP, NOW YOU ARE LEVEL %d\n",character -> character_level -> level);
    }
    printf("\nYOU HAVE %.0f EXPERIENCE, AND YOU NEED %.0f EXPERIENCE FOR THE NEXT LEVEL",character -> character_level -> experience,exp_to_nextlevel_calculation(character) - character -> character_level -> experience);
    printf("\nPRESS ENTER TO RETURN\n");
    
    getchar(); //fix getch() non existence
}




                                        //-----------//
                                       //STATS PRINT//
                                      //-----------//


                                        // CHARACTER STATS //

void print_stats(CHARACTER* character, int race, int class)
{
    char* RACES_STR[] = {"HUMAN", "ELF","GOBLIN","DWARF","TROLL","ORC","MINOTAUR","GNOME","RETURN_MENU"};
    char* CLASSES_STR[] = {"WARRIOR","PALADIN","ARCHER","ROGUE","PRIEST","MAGE","NECROMANCER","BERSERKER","RETURN_RACES"};
    system("cls");
    printf("RACE: %s\n",RACES_STR[character->race]);
    printf("CLASS: %s\n",CLASSES_STR[character->class]);
    printf("BASE HEALTH: %.2f\n",character ->base_health);
    printf("BASE DEFENSE: %.2f\n",character ->base_defense);
    printf("BASE MANA: %.2f\n",character ->base_mana);
    printf("BASE STAMINA: %.2f\n",character ->base_stamina);
    printf("BASE ATTACK POWER: %.2f\n",character ->base_attackpower);
    printf("BASE CRIT CHANCE: %.2f\n",character ->base_attackcritchance);
    printf("BASE CRIT DAMAGE: %.2f\n",character ->base_attackcritdmg);
    printf("BASE ABILITY POWER: %.2f\n",character ->base_abilitypower);
    printf("BASE ABILITY CRIT CHANCE: %.2f\n",character ->base_abilitycritchance);
    printf("BASE ABILITY CRIT DMG: %.2f\n",character ->base_abilitycritdmg);

    printf("\nPRESS ENTER TO RETURN\n");

    getchar(); //fix getch() non existence
}

                                        // CHARACER ATTRIBUTES //
                                        
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




                                        //---------//
                                       //INVENTORY//
                                      //---------//
                                      