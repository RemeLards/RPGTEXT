#include <stdio.h>
#include <stdlib.h>

#ifndef _RNG_FUNCTIONS_HEADER
#define _RNG_FUNCTIONS_HEADER

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

//File Functions
int rng_get_seed(); //Getting the seed from .txt
void rng_check_seed_file(); //Checking if "seed.txt" exist
void rng_save_seed(int seed);

//RNG 

int rng_generate_random_number(); //Xorshift algorithm, random number generator
void rng_extend_random_number_group();
int rng_generate_random_positive_number();
int rng_generate_random_sign();

#endif
