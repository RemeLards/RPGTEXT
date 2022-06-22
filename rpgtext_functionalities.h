//How Menus are printed and how Keys are registered, are found here//

#ifndef _RPGTEXT_FUNCTIONALITIES_
#define _RPGTEXT_FUNCTIONALITIES_

//-------------------------
//HEADERS
//-------------------------

/*#include "rpgtext_structs.h"

//Using print_attributes() function, to show character attributes
#include "rpgtext_character.h"*/

#include <stdio.h>
#include "rpgtext_constants.h"

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

                                      // Button Registration

int keyregistration();

                                      //Options Registration

int optionsregistration(int* option, int sizeofoptions, int key);

                                      //Menu Print
void menu_print(char** options_names, int options_selection,int sizeofoptions);

//void attributes_menu_print(char** options_names, int options_selection,int sizeofoptions,CHARACTER* character);

#endif