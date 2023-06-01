#ifndef _MAIN_MENU_FUNCTIONS_HEADER_

#define _MAIN_MENU_FUNCTIONS_HEADER_

#include <stdlib.h>
#include "menu_creation_functions.h"
#include "main_menu_constants.h"
#include "character.h"
#include "character_functions.h"


int main_menu_start_menu();

//char* main_menu_load_game_menu()

int main_menu_create_character_menu();

int main_menu_race_selection_menu();

int main_menu_class_selection_menu();

char* main_menu_character_name_creation();

CHARACTER * main_menu();


#endif