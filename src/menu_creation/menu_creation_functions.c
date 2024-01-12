#include "menu_creation_functions.h"

/************************************
Function : menu_creation_UI_menu_options_registration
Date : 7/16/2023
Usable? : Yes
Explanation : Registers valid key inputs on the menu created, so you can select a given option
*************************************/ 

void 
menu_creation_UI_menu_options_registration(int *option_chosen_ptr, int num_options, int key)
{
    if (key == UP) *option_chosen_ptr -= 1;

    if (key == DOWN) *option_chosen_ptr += 1; 

    if (*option_chosen_ptr < 0) *option_chosen_ptr = num_options-1;

    if (*option_chosen_ptr >= num_options) *option_chosen_ptr = 0; 
}


/************************************
Function : menu_creation_print_menu_options
Date : 7/16/2023
Usable? : Yes
Explanation : Show (prints) all the created menu options
*************************************/ 

void 
menu_creation_print_menu_options(const char **options_names, int option_chosen,int num_options)//Prints the menu of the respective function
{
    for(int i = 0; i < num_options; i++)
    {
        if(i == option_chosen)printf("--------\n");
        printf("|%s\n", options_names[i]);
        if(i == option_chosen)printf("--------\n");
    }
}


/************************************
Function : menu_creation_menu_option_chosen
Date : 7/16/2023
Usable? : Yes
Explanation : Contains all the logic to make any menu work, in the end returns the option choosen by the user
*************************************/ 

int
menu_creation_menu_option_chosen(const char **options_names, const int num_options, const char *phrase)
{
    int option_chosen = 0;
    int key = NULL_KEY;
    
    while(key != ENTER)
    {
        system_clear();
        if(phrase != NULL)printf("%s\n\n",phrase);
        menu_creation_print_menu_options(options_names, option_chosen, num_options);
        key = keyboard_key_registrations();
        menu_creation_UI_menu_options_registration(&option_chosen, num_options, key);
    }
    
    return option_chosen;
}

/************************************
Function : menu_creation_confirmation_menu
Date : 1/11/2023
Usable? : Yes
Explanation : Used for user confirmation
*************************************/ 

int 
menu_creation_confirmation_menu(void)
{
    const char *options_names[] = {"Yes","No"};
    const char *phrase = "Wanna fight a monster?";
    int num_options = 2;
    return menu_creation_menu_option_chosen(options_names,num_options,phrase);
}