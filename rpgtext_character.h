//-------------------------
//HEADERS
//-------------------------
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "rpgtext_constants.h"
#include "rpgtext_structs.h"
#include "rpgtext_strings.h"
#include "rpgtext_monsters.h"
#include "rpgtext_fight.h"

#ifndef _RPGTEXT_CHARACTER_
#define _RPGTEXT_CHARACTER_
//-------------------------
//FUNCTIONS
//-------------------------

    //Character Race/Class/Stats
void race_creation(int race,CHARACTER* character);
void character_basestats(CHARACTER* character,int characterclass);
void initialize_attributes(CHARACTER* character);
void character_name_creation(CHARACTER* character);

    //Skillpoints and Attributes
void attributes(CHARACTER* character, int option, int key);
void attributes_stats_calculation(CHARACTER* character);

    //Level
void level_initialization(CHARACTER* character);
float level_calculation(CHARACTER* character);
void character_level(CHARACTER* character); 

//Character Prints
void print_stats(CHARACTER* character, int race, int characterclass);
void print_attributes(CHARACTER* character, int index);

#endif