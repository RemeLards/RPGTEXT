CC = gcc

FIGHT_HEADERS_PATH = ../../include/fight
CHARACTER_HEADERS_PATH = ../../include/character
RNG_HEADERS_PATH = ../../include/rng
MONSTERS_HEADERS_PATH = ../../include/monsters
MENU_CREATION_HEADERS_PATH = ../../include/menu_creation
KEYBOARD_HEADERS_PATH = ../../include/keyboard
SYSTEM_HEADERS_PATH = ../../include/system
MAP_HEADERS_PATH = ../../include/map
LINKED_LIST_HOLDER_HEADERS_PATH = ../../include/linked_list_holder
LINKED_LIST_HEADERS_PATH = ../../include/linked_list
DEBUG_HEADERS_PATH = ../../include/debug


IFLAGS = -I$(FIGHT_HEADERS_PATH) -I$(CHARACTER_HEADERS_PATH) -I$(RNG_HEADERS_PATH) -I$(MONSTERS_HEADERS_PATH)\
-I$(KEYBOARD_HEADERS_PATH) -I$(MENU_CREATION_HEADERS_PATH) -I$(SYSTEM_HEADERS_PATH) -I$(MAP_HEADERS_PATH)\
-I$(LINKED_LIST_HOLDER_HEADERS_PATH) -I$(LINKED_LIST_HEADERS_PATH)\
-I$(DEBUG_HEADERS_PATH)\


CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3


fight_functions.o : fight_functions.c 
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move fight_functions.o ..\..\bin\ 

clean :
	del *.o