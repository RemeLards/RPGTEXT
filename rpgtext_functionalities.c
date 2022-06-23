//-------------------------
//HEADERS
//-------------------------
#include "rpgtext_functionalities.h"

//-------------------------
//FUNCTIONS
//-------------------------

                                      // Button Registration

int keyregistration()//Gets keyboard input
{
    int key = 0;    
    int c; //Just need 2 ints in the vector
    
    //fix getch() non existence

    c = getch();//Key input 
    
    if(c != 13)
    {

        if(c == 'W' || c == 'w'){key = UP;return key;}//Up Arrow Value
        if(c == 'S' || c == 's'){key = DOWN;return key;} //Lower Arrow Value
        if(c == 'A' || c == 'a'){key = LEFT;return key;} //Left Arrow Value
        if(c == 'D' || c == 'd'){key = RIGHT;return key;} //Right Arrow Value
    }
    else
    {
        key = ENTER;
        return key;
    }

    return 0;
}

                                     //Options Registration

int optionsregistration(int* option, int sizeofoptions, int key)
{
    if(key == UP)*option -= 1;    //If User Press Up Arrow
    if(key == DOWN)*option += 1;  //If User Press Lower Arrow
    if(key == ENTER)return *option;
    if(*option < 0)*option = sizeofoptions-1; //If options selection becomes negative
    if(*option >= sizeofoptions)*option = 0; //If options selection becomes higher than the quantity of options in the "imenu"
    
    return sizeofoptions;
}
                                      
                                      //Menus Print Functions
                                    
void menu_print(char** options_names, int options_selection,int sizeofoptions)//Prints the menu of the respective function
{
    for(int i = 0; i < sizeofoptions; i++)
    {
        if(i == options_selection)printf("--------\n");
        printf("|%s\n", options_names[i]);
        if(i == options_selection)printf("--------\n");
    }
}

/*void attributes_menu_print(char** options_names, int options_selection,int sizeofoptions,CHARACTER* character)
{
    printf("SKILLPOINTS LEFT %d\n\n",character -> skillpoints_struct -> skillpoints);
    for(int i = 0; i < sizeofoptions; i++)
    {
        if(i == options_selection)printf("--------\n");
        if(i != sizeofoptions-1)
        {
            printf("|%s : ", options_names[i]);
            print_attributes(character,i);
            printf("\n");
        }
        else printf("|%s \n", options_names[i]);
        if(i == options_selection)printf("--------\n");
    }    
}*/