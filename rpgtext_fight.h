#ifndef _RPGTEXT_FIGHT_
#define _RPGTEXT_FIGHT_
//-------------------------
//HEADERS
//-------------------------
#include "rpgtext_constants.h"
#include "rpgtext_structs.h"
#include "rpgtext_rng.h"
//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

float dmg_calculation(CHARACTER* character, int attack_status);
float dmg_values(CHARACTER* character, int attack_status);
float dmg_values_mobs(MOBS* monster);

#endif
