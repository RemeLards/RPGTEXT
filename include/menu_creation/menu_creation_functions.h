#ifndef _MENU_CREATION_FUNCTIONS_HEADER_

#define _MENU_CREATION_FUNCTIONS_HEADER_

#include "keyboard_functions.h"
#include "system_functions.h"

#include "keyboard_constants.h"

#include <stdio.h>

void
menu_creation_UI_menu_options_registration(int *option_chosen_ptr, int num_options, int key);

void 
menu_creation_print_menu_options(const char **options_names, int option_chosen,int num_options);

int
menu_creation_menu_option_chosen(const char **options_names, const int num_options, const char *phrase);

int 
menu_creation_confirmation_menu(void);

#endif