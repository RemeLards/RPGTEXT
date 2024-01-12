CC = gcc

CHARACTER_HEADERS_PATH = ../../include/character
MAIN_MENU_HEADERS_PATH = ../../include/main_menu
MENU_CREATION_HEADERS_PATH = ../../include/menu_creation
KEYBOARD_HEADERS_PATH = ../../include/keyboard
SYSTEM_HEADERS_PATH = ../../include/system
MAP_HEADERS_PATH = ../../include/map

IFLAGS = -I$(CHARACTER_HEADERS_PATH) -I$(MAIN_MENU_HEADERS_PATH) -I$(MENU_CREATION_HEADERS_PATH) -I$(KEYBOARD_HEADERS_PATH) -I$(SYSTEM_HEADERS_PATH)\
-I$(MAP_HEADERS_PATH)


CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3


main_menu_functions.o : main_menu_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move character_functions.o ..\..\bin\ 
	

clean :
	del *.o