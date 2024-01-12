CC = gcc

CHARACTER_HEADERS_PATH = ../../include/character
MAP_HEADERS_PATH = ../../include/map
KEYBOARD_HEADERS_PATH = ../../include/keyboard
SYSTEM_HEADERS_PATH = ../../include/system
MONSTER_HEADERS_PATH = ../../include/monsters
LINKED_LIST_HEADERS_PATH = ../../include/linked_list
RNG_HEADERS_PATH = ../../include/rng
LINKED_LIST_HOLDER_HEADERS_PATH = ../../include/linked_list_holder
MENU_CREATION_HEADERS_PATH = ../../include/menu_creation
FIGHT_HEADERS_PATH = ../../include/fight

DEBUG_HEADERS_PATH = ../../include/debug #momentarly to debug

IFLAGS = -I$(CHARACTER_HEADERS_PATH) -I$(MAP_HEADERS_PATH) -I$(KEYBOARD_HEADERS_PATH) -I$(SYSTEM_HEADERS_PATH)\
-I$(MONSTER_HEADERS_PATH) -I$(LINKED_LIST_HEADERS_PATH) -I$(RNG_HEADERS_PATH) -I$(LINKED_LIST_HOLDER_HEADERS_PATH)\
-I$(MENU_CREATION_HEADERS_PATH) -I$(FIGHT_HEADERS_PATH)\
-I$(DEBUG_HEADERS_PATH)


CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3


map_functions.o : map_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move character_functions.o ..\..\bin\ 
	

clean :
	del *.o