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

#ifndef _RPGTEXT_MENU_
#define _RPGTEXT_MENU_
//-------------------------
//FUNCTIONS
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

// Screen/Button Registration
int keyregistration();

//Initial Menus of Character Creation
void imenu_optionsregistration(int* options_selection, int sizeofoptions, int key);
void character_creation_optionsregistration(int* options_selection, int sizeofoptions, int key);
void race_optionsregistration(int* race, int sizeofoptions, CHARACTER* character, int key);
void class_optionsregistration(int* characterclass, int sizeofoptions, CHARACTER* character,int key);
void character_stats_optionsregistration(int* option, int sizeofoptions, CHARACTER* character, int key);
void attributes_optionsregistration(int* option, int sizeofoptions, CHARACTER* character, int key);
int yes_no_optionsregistration(int* option, int sizeofoptions, int key);

//Menu Prints
void menu_print(char** options_names, int options_selection,int sizeofoptions);
void attributes_menu_print(char** options_names, int options_selection,int sizeofoptions,CHARACTER* character);

//Initial Menus
void imenu();
void character_creation_menu();
void race_creation_menu();
void class_selection_menu(CHARACTER* character);
void character_stats_menu(CHARACTER* character);
void attributes_menu(CHARACTER* character);

#endif
