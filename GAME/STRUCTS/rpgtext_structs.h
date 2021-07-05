#ifndef _RPGTEXT_STRUCTS_
#define _RPGTEXT_STRUCTS_

//-------------------------
//STRUCTS
//-------------------------

//Character

typedef struct level_character //Implemented
{
    int character_level;
    float experience_tracker;  
}CHAR_LEVEL;

//Current Attributes {"Strenght","Constitution","Dexterity","Intelligence","Wisdom","Willpower","Perception","Charisma"}
typedef struct backpack_character //Ideia of a backpack, Not implemented yet
{
    int health_potion;
    int stamina_potion;
    int mana_potion;
    
    //Test Later
    int helmet;
    int chestplate;
    int boots;
    int gloves;
    int legs;
    int weapon;
}BACKPACK;

typedef struct skillpoints_character //Implemented
{
    int skillpoints;
    
    //All Attributes
    int strenght;
    int constituition;
    int dexterity;
    int intelligence;
    int wisdom;
    int willpower;
    int perception;
    int charisma;
}SKILLPOINTS;

typedef struct character_struct //Implemented
{
    char* character_name;
    float base_health;
    float base_defense;
    float base_stamina;
    float base_mana;
    float base_attackpower;
    float base_critchance;
    float base_critdmg;
    float base_abilitypower;
    float base_abilitycritchance;
    float base_abilitycritdmg;
    int   race;
    int   characterclass;
    //char* abilities;
    SKILLPOINTS* skillpoints_struct;
    BACKPACK* backpack_struct;
    CHAR_LEVEL* level_struct;

}CHARACTER;


//Monsters

typedef struct monster_struct //Implemented
{
    
    float health;
    float defense;
    float stamina;
    float mana;
    float attackpower;
    float abilitypower;
    float experience_given;
}MOBS;

#endif
