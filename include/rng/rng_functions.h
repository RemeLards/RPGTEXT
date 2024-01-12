#include <stdio.h>
#include <stdlib.h>

#ifndef _RNG_FUNCTIONS_HEADER
#define _RNG_FUNCTIONS_HEADER

//-------------------------
//FUNCTIONS PROTOTYPES
//-------------------------

//File Functions
int rng_get_seed(void); //Getting the seed from .txt
void rng_check_seed_file(void); //Checking if "seed.txt" exist
void rng_save_seed(int seed);

//RNG 

int rng_generate_random_number(void); //Xorshift algorithm, random number generator
void rng_extend_random_number_group(void);
int rng_generate_random_positive_number(void);
int rng_generate_random_sign(void);

#endif
