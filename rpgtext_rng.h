#include <stdio.h>
#include <stdlib.h>

#ifndef _RPGTEXT_RNG_
#define _RPGTEXT_RNG_
int getting_seed();//Getting the seed from .txt
void checking_seed_file();//Checking if "seed.txt" exist
void saving_seed(int seed);
int rng_generator();//Xorshift algorithm
void break_rngloop();

#endif