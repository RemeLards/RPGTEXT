#ifndef _MENU_CREATION_FUNCTIONS_HEADER_

#define _MENU_CREATION_FUNCTIONS_HEADER_

#include "keyboard_constants.h"
#include "keyboard_functions.h"
#include "system_functions.h"

#include <stdio.h>

void
menu_creation_UI_menu_options_registration(int *option_chosen_ptr, int num_of_options, int key);

void 
menu_creation_print_menu_options(const char **options_names, int option_chosen,int num_of_options);

int
menu_creation_menu_option_chosen(const char **options_names, const int num_options);

#endif