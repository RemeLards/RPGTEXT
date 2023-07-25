#include "system_functions.h"

/************************************
Function : system_clear
Date : 7/16/2023
Usable? : Yes
Explanation : Uses the correct terminal OS command to clear all the terminal text (Example of use : faking a clear screen to the user )
*************************************/ 

void system_clear()
{
    #ifdef _WIN32
        system("cls");
    
    #elif _linux_
        system("clear");
    
    #endif
}