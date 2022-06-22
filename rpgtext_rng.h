#include <stdio.h>
#include <stdlib.h>

#ifndef _RPGTEXT_RNG_
#define _RPGTEXT_RNG_

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

//File Functions
int get_seed();//Getting the seed from .txt
void check_seed_file();//Checking if "seed.txt" exist
void save_seed(int seed);

//RNG 
int rng_generator();//Xorshift algorithm
void break_rngloop();

#endif
