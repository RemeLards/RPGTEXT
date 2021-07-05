#ifndef _RPGTEXT_CONSTANTS_
#define _RPGTEXT_CONSTANTS_

//-------------------------
//CONSTANTS
//-------------------------

//Input Constants
enum KEYS//Register Keys
{
    ENTER = -5,
    RIGHT,
    LEFT,
    DOWN,
    UP,
};

//Character Constants
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
    RETURN_MENU,
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
    RETURN_RACES,
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

//Itens Constants

//Potions
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

//Attacks
enum ATTACKS
{
    BASIC_ATTACK = 0,
    STAMINA_ATTACK,
    MANA_ATTACK
};

//Monsters Numbers
enum MONSTERS
{
    GOBLIN_MONSTER = 0,
    GLASSCANON_GOBLIN,
    DRAGON,
};


#endif

