//-------------------------
//Headers
//-------------------------

#include "rpgtext_rng.h"

//-------------------------
//Functions
//-------------------------

//File Functions
int get_seed()//Getting the seed from .txt
{
    FILE* file;
    file = fopen("rpgdmg_rng.txt", "r");
    char c_seed[12];
    fgets(c_seed, 12 ,file);
    int seed = atoi(c_seed);
    fclose(file);
    return seed;
}
void check_seed_file()//Checking if "seed.txt" exist
{
    FILE* file;
    file = fopen("rpgdmg_rng.txt", "r");

    if(file == NULL)//If "seed.txt" doesnt exist
    {
        fclose(file);
        file = fopen("rpgdmg_rng.txt", "w");
        fprintf(file,"%d\n", 1234);//1234 is the default seed
        fclose(file);
    }

    //If seed.txt exist
    fclose(file);
}
void save_seed(int seed)//Savind the seed in .txt
{
    FILE* file;
    file = fopen("rpgdmg_rng.txt", "w");
    fprintf(file,"%d\n", seed);
    fclose(file);
}

//RNG 
int rng_generator()//Xorshift algorithm
{
    int n = get_seed(); // "Seed"
	n ^= n << 13; // << shifts bits to the left "x << y" = x* (2^y)
	n ^= n >> 17; // >> shifts bits to the right "x >> y" = x/(2^y)
	n ^= n << 5;
    if(n < 0) n = n*-1; 
    save_seed(n);
	return n;
}
void break_rngloop()
{
    int seed = get_seed(); 
    seed += 2;
    save_seed(seed);
}
