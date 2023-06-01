CC = gcc

FIGHT_HEADERS_PATH = ../../include/fight
CHARACTER_HEADERS_PATH = ../../include/character
RNG_HEADERS_PATH = ../../include/rng
MONSTERS_HEADERS_PATH = ../../include/monsters
MENU_CREATION_HEADERS_PATH = ../../include/menu_creation
KEYBOARD_HEADERS_PATH = ../../include/keyboard
SYSTEM_HEADERS_PATH = ../../include/system

IFLAGS = -I$(FIGHT_HEADERS_PATH) -I$(CHARACTER_HEADERS_PATH) -I$(RNG_HEADERS_PATH) -I$(MONSTERS_HEADERS_PATH)\
-I$(KEYBOARD_HEADERS_PATH) -I$(MENU_CREATION_HEADERS_PATH) -I$(SYSTEM_HEADERS_PATH)


CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3


fight_functions.o : fight_functions.c 
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move fight_functions.o ..\..\bin\ 

clean :
	del *.o