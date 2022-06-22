#ifndef _RPGTEXT_CONSTANTS_
#define _RPGTEXT_CONSTANTS_

//-------------------------
//CONSTANTS
//-------------------------

                                //################ Boolean ################//
enum BOOLEAN
{
    FALSE = 0,
    TRUE,
};
                                //################ Keyboard Keys Constants ################//
enum KEYS
{
    ENTER = -5,
    RIGHT,
    LEFT,
    DOWN,
    UP,
};

                                //#################### Menus ####################//
enum MENU_ORDER
{
    IMENU = 0,
    CHARACTER_CREATION_MENU,
    RACE_MENU,
    CLASS_MENU,
    CHARACTER_STATS_MENU,
    GAME,
};

enum IMENU
{
    NEW_GAME = 0,
    LOAD_GAME,
    LEAVE,
};

enum CHARACTER_CREATION_MENU
{
    CHAR_CREATION = 0,
    RETURN_CHARACTER_CREATION_MENU,
};

enum CHARACTER_STATS_MENU
{
    CHARACTER_NAME = 0,
    PRINT_STATS,
    RETURN_CHARACTER_STATS_MENU,
};
                
                                //################ Character Constants ################//
enum RACES
{
    HUMAN = 0,
    ELF,
    GOBLIN,
    DWARF,
    TROLL,
    ORC,
    MINOTAUR,
    GNOME,
    RETURN_RACES,
};

enum CLASSES
{
    WARRIOR = 0,
    PALADIN,
    ARCHER,
    ROGUE,
    PRIEST,
    MAGE,
    NECROMANCER,
    BERSERKER,
    RETURN_CLASSES,
};

enum ATTRIBUTES
{
    STRENGHT = 0,
    CONSTITUITION,
    DEXTERITY,
    INTELLINGENCE,
    WISDOM,
    WILLPOWER,
    PERCEPTION,
    CHARISMA,
    RETURN_ATTRIBUTES,
};
 
                                //################ Itens Constants ################//

enum POTIONS
{
    HEALTH = 0,
    STAMINA,
    MANA,
};

enum WEAPONS
{
    SWORD = 0,
    BOW,
    HAMMER,
    AXE,
    SPEAR,
    SWORD_SHIELD,
    WHIP,
};

enum ARMORS
{
    LIGHT = 0,
};

                                //###################### Attacks ######################//
enum ATTACKS
{
    BASIC_ATTACK = 0,
    STAMINA_ATTACK,
    MANA_ATTACK
};

                                //################ Monsters Numbers ################//
enum MONSTERS
{
    GOBLIN_MONSTER = 0,
    GLASSCANON_GOBLIN,
    DRAGON,
};

                                //#################### Erros ####################//
enum ERRORS
{
    EXIT = -3,
    NOT_ENOUGH_MEMORY,
    UNEXPECTED_ERROR,
};
        
#endif

