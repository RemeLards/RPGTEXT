#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "teste.h"

int 
main(/*int agrc, char *argv[]*/)
{
    CHARACTER *personagem_ptr = NULL;

    personagem_ptr = main_menu();

    if ( personagem_ptr == NULL ) printf("ponteiro nulo LOL");
    else 
    {
        character_print_statistics ( personagem_ptr );
        character_free_all ( personagem_ptr );
    }
    
    return 0;
}