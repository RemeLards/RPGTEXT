#ifndef _RPGTEXT_MENU_
#define _RPGTEXT_MENU_
//-------------------------
//HEADERS
//-------------------------

#include "rpgtext_character.h"
#include "rpgtext_strings.h"
#include "rpgtext_functionalities.h"
#include "rpgtext_game.h"

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

                                    //------------------------//
                                    //         MENUS          //
                                    //------------------------//
                                    
                                    // Initial Menu

int imenu();
                                    // Character Creation Menu

int character_creation_menu();

                                    // Race Selection Menu

int race_selection_menu();

                                    // Class Selection Menu

int class_selection_menu();

                                    // Character Stats Menu

int character_stats_menu();

                                    // Character Creation Menu

char* character_name_creation();

#endif
