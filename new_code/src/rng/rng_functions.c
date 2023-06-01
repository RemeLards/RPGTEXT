//-------------------------
//Headers
//-------------------------

#include "rng_functions.h"

//-------------------------
//Functions
//-------------------------


/************************************
Function : rng_get_seed
Date : 5/24/2023
Usable? : Yes
Explanation : gets a number from "rng.txt" to use as a Pseudo Random Number Generator "seed".
*************************************/
int
rng_get_seed()//Getting the seed from .txt
{
    FILE* file_ptr;
    file_ptr = fopen("rng.txt", "r");
    char c_seed[12];
    fgets(c_seed, 12 ,file_ptr);
    int seed = atoi(c_seed);
    fclose(file_ptr);
    return seed;
}

/************************************
Function : rng_check_seed_file
Date : 5/24/2023
Usable? : Yes
Explanation : checks if "rng.txt" exists, if it doesn't, this function puts a default "seed".
*************************************/
void
rng_check_seed_file()//Checking if "seed.txt" exist
{
    FILE *file_ptr;
    file_ptr = fopen("rng.txt", "r");

    if(file_ptr == NULL)//If "rng.txt" doesnt exist
    {
        fclose(file_ptr);
        file_ptr = fopen("rng.txt", "w");
        fprintf(file_ptr,"%d\n", 1234);//1234 is the default seed
        fclose(file_ptr);
    }

    //If seed.txt exist
    fclose(file_ptr);
}

/************************************
Function : rng_save_seed
Date : 5/24/2023
Usable? : Yes
Explanation : save the "seed" number in a file called "rng.txt"
*************************************/
void
rng_save_seed(int seed)//Savind the seed in .txt
{
    FILE *file_ptr;
    file_ptr = fopen("rng.txt", "w");
    fprintf(file_ptr,"%d\n", seed);
    fclose(file_ptr);
}

/************************************
Function : rng_generate_random_number
Date : 5/24/2023
Usable? : Yes
Explanation : This is an algorithm to generate a Random Number Generator (need to see how it works later) 
*************************************/
//RNG 
int
rng_generate_random_number()//Xorshift algorithm
{
    int n = rng_get_seed(); // "Seed"
	n ^= n << 13; // << shifts bits to the left "x << y" = x * (2^y)
	n ^= n >> 17; // >> shifts bits to the right "x >> y" = x / (2^y)
	n ^= n << 5; //
    if(n < 0) n = n*-1; 
    rng_save_seed(n);
	return n;
}

/************************************
Function : rng_extend_random_number_group
Date : 5/24/2023
Usable? : Yes
Explanation : After a Big quantity of numbers, a number can create the start "seed" number again, so we get stuck in a loop.
This loop can be small or big, this functions tries to get this loop as big as possible (need to see if it works)
*************************************/
void
rng_extend_random_number_group()
{
    int seed = rng_get_seed(); 
    seed += 2;
    rng_save_seed(seed);
}
