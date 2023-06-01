#include "keyboard_functions.h"

int keyboard_key_registrations()
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