#ifndef _KEYBOARD_CONSTANTS_HEADER_

#define _KEYBOARD_CONSTANTS_HEADER_


#ifdef _WIN32
    #define GETCH_ENTER_VALUE 13

#elif _linux_
    // ??????

#endif

enum KEYBOARD_COMMANDS
{
    NULL_KEY = -1,
    UP = 0,
    DOWN,
    LEFT,
    RIGHT,
    ENTER,
};


#endif