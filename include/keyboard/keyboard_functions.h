#ifndef _KEYBOARD_FUNCTIONS_HEADER_

#define _KEYBOARD_FUNCTIONS_HEADER_

#include "keyboard_constants.h"

#ifdef _WIN32
    #include <conio.h>

#elif _linux_
    //#include ????

#endif

int keyboard_key_registrations(void);


#endif