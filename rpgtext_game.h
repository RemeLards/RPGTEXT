#ifndef _RPGTEXT_GAME_
#define _RPGTEXT_GAME_

//------------------------
//HEADERS
//-------------------------
#include "rpgtext_functionalities.h"
#include "rpgtext_monsters.h"
#include "rpgtext_fight.h"

//If player dies, returns to initial menu in the fight() function
#include "rpgtext_menu.h"

//If player gets XP
#include "rpgtext_character.h"

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

//Play
void game(CHARACTER* character);

//Game Mobs
void search_mobs(CHARACTER* character);

//Game Interactions
void fight_menu(CHARACTER* character,MOBS* monster);
void fight(CHARACTER* character,MOBS* monster,int attack_status);

//Game Registrations
void game_optionsregistration(int* option,int sizeofoptions, CHARACTER* character,int key);
void fight_menu_optionsregistration(int* option,int sizeofoptions, CHARACTER* character,MOBS* monster, int key);

//Char Infos

int attributes_menu(CHARACTER* character);
void attributes_optionsregistration(CHARACTER* character,int* option, int sizeofoptions,int key);

#endif