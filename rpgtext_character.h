#ifndef _RPGTEXT_CHARACTER_
#define _RPGTEXT_CHARACTER_

//-------------------------
//HEADERS
//-------------------------

#include <stdio.h>
#include <stdlib.h>
#include "rpgtext_constants.h"
#include "rpgtext_structs.h"

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------


                                        //------------------------//
                                       //CHARACTER RACE AND CLASS//
                                      //------------------------//

// RACES //

void race_selection(CHARACTER* character,int race);

// CLASSES //

void class_selection(CHARACTER* character,int class);

                                        //----------//
                                       //ATTRIBUTES//
                                      //----------//

// INITIALIZING CHARACTER ATTRIBUTES/SKILLPOINTS //

void init_skillpoints(CHARACTER* character);

// ATTRIBUTES/SKILLPOINTS ADDITION/REMOVAL //

void attributes(CHARACTER* character, int option, int key);

// ****CHECK THIS LATER**** //
// ATTRIBUTES/SKILLPOINTS CALCULATION //

void attributes_stats_calculation(CHARACTER* character);

                                        //--------//
                                       //LEVELING//
                                      //--------//

// INITIALIZING CHARACTER ATTRIBUTES/SKILLPOINTS //

void init_level(CHARACTER* character);

// CALCULATION OF EXPERIENCE NEEDED TO NEXT LEVEL //

float exp_to_nextlevel_calculation(CHARACTER* character);

// LEVEL CALCULATION //
                                      
void level_calculation(CHARACTER* character);

                                        //--------------------------//
                                       //ATTRIBUTES AND STATS PRINT//
                                      //--------------------------//

// CHARACTER STATS //

void print_stats(CHARACTER* character, int race, int class);

// CHARACER ATTRIBUTES //

void print_attributes(CHARACTER* character, int index);

#endif
