#ifndef _RPGTEXT_STRUCTS_
#define _RPGTEXT_STRUCTS_

//-------------------------
//STRUCTS
//-------------------------

                                              //-----------------//
                                             //CHARACTER STRUCTS//
                                            //-----------------//

                                            //LEVEL//
typedef struct character_level //Implemented
{
    int level;
    float experience;  
}CHAR_LEVEL;

         
                                            //BACKPACK//
typedef struct character_backpack //Not implemented
{
    int health_potion;
    int stamina_potion;
    int mana_potion;
    
    //Test Later
    char* helmet;
    char* chestplate;
    char* boots;
    char* gloves;
    char* legs;
    char* weapon;
}BACKPACK;

                                            
                                            //SKILLPOINTS//
typedef struct character_skillpoints //Implemented
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

                                            //CHARACTER//

typedef struct character_struct //Implemented
{
    char* character_name;
    float base_health;
    float base_defense;
    float base_stamina;
    float base_mana;
    float base_attackpower;
    float base_attackcritchance;
    float base_attackcritdmg;
    float base_abilitypower;
    float base_abilitycritchance;
    float base_abilitycritdmg;
    int race;
    int class;
    //char* abilities;
    SKILLPOINTS* skillpoints_struct;
    BACKPACK* backpack_struct;
    CHAR_LEVEL* character_level;

}CHARACTER;


                                              //---------------//
                                             //MONTERS STRUCTS//
                                            //---------------//

typedef struct monsters_struct //Implemented
{
    float health;
    float defense;
    float stamina;
    float mana;
    float attackpower;
    float abilitypower;
    float experience_given;
}MOBS;

                                              //--------------//
                                             //WEAPONS STRUCT//
                                            //--------------//
typedef struct weapons_struct
{
    int type;
    int level;
    float damage;

}WEAPONS;

#endif
