#include "menu_creation_functions.h"

void 
menu_creation_UI_menu_options_registration(int *option_chosen_ptr, int num_of_options, int key)
{
    if (key == UP) *option_chosen_ptr -= 1;

    if (key == DOWN) *option_chosen_ptr += 1; 

    if (*option_chosen_ptr < 0) *option_chosen_ptr = num_of_options-1;

    if (*option_chosen_ptr >= num_of_options) *option_chosen_ptr = 0; 
}

void 
menu_creation_print_menu_options(const char **options_names, int option_chosen,int num_of_options)//Prints the menu of the respective function
{
    for(int i = 0; i < num_of_options; i++)
    {
        if(i == option_chosen)printf("--------\n");
        printf("|%s\n", options_names[i]);
        if(i == option_chosen)printf("--------\n");
    }
}

int
menu_creation_menu_option_chosen(const char **options_names, const int num_options)
{
    int option_chosen = 0;
    int key = NULL_KEY;
    
    while(key != ENTER)
    {
        system_clear();
        menu_creation_print_menu_options(options_names,option_chosen,num_options);
        key = keyboard_key_registrations();
        menu_creation_UI_menu_options_registration(&option_chosen,num_options,key);
    }
    
    return option_chosen;
}