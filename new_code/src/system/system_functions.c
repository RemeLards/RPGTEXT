#include "system_functions.h"

void system_clear()
{
    #ifdef _WIN32
        system("cls");
    
    #elif _linux_
        system("clear");
    
    #endif
}