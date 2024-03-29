#ifndef _CHARACTER_CONSTANTS_HEADER_

#define _CHARACTER_CONSTANTS_HEADER_


enum
CHARACTER_RACES
{
    NONE_RACE = -1,
    HUMAN,
    ELF,
    GOBLIN,
    DWARF,
    TROLL,
    ORC,
    MINOTAUR,
    GNOME,
    RETURN_RACES,
};

enum
CHARACTER_CLASSES
{
    NONE_CLASS = -1,
    WARRIOR,
    PALADIN,
    ARCHER,
    ROGUE,
    PRIEST,
    MAGE,
    NECROMANCER,
    BERSERKER,
    RETURN_CLASSES,
};

enum
CHARACTER_ATTRIBUTES
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

enum
CHARACTER_ATTACK_TYPE
{
    NONE_ATTACK_TYPE = -1,
    PHYSICAL_ATTACK,
    ABILITY_ATTACK,
};

enum
CHARACTER_ABILITY_TYPE
{
    NONE_ABILITY_TYPE = -1,
    MANA_ABILITY,
    STAMINA_ABILITY,
};

#endif