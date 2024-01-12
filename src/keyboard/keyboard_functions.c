#include "keyboard_functions.h"

/************************************
Function : keyboard_key_registrations
Date : 7/16/2023
Usable? : Yes
Explanation : Controls how key registration works depending of the OS used.
*************************************/   

int keyboard_key_registrations(void)
{
    int key = 0;

    #ifdef _WIN32
        
        key = getch();//Key input 
    
        if ( key != GETCH_ENTER_VALUE )
        {

            if ( key == 'W' || key == 'w' ) key = UP;
            if ( key == 'S' || key == 's' ) key = DOWN;
            if ( key == 'A' || key == 'a' ) key = LEFT;
            if ( key == 'D' || key == 'd' ) key = RIGHT;
        }
        else key = ENTER;
    
        return key;

    #elif _linux_
        // ???
    #endif

    return key;
}