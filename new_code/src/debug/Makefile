CC = gcc


CHARACTER_HEADERS_PATH = ../../include/character
MAP_HEADERS_PATH = ../../include/map
MONSTER_HEADERS_PATH = ../../include/monsters
LINKED_LIST_HEADERS_PATH = ../../include/linked_list
LINKED_LIST_HOLDER_HEADERS_PATH = ../../include/linked_list_holder
SYSTEM_HEADERS_PATH = ../../include/system
DEBUG_HEADERS_PATH = ../../include/debug
KEYBOARD_HEADERS_PATH = ../../include/keyboard
RNG_HEADERS_PATH = ../../include/rng

IFLAGS = -I$(CHARACTER_HEADERS_PATH) -I$(MAP_HEADERS_PATH) -I$(MONSTER_HEADERS_PATH) -I$(LINKED_LIST_HEADERS_PATH) \
-I$(LINKED_LIST_HOLDER_HEADERS_PATH) -I$(DEBUG_HEADERS_PATH) -I$(SYSTEM_HEADERS_PATH) -I$(KEYBOARD_HEADERS_PATH) \
-I$(RNG_HEADERS_PATH)


CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3


debug_functions.o : debug_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move character_functions.o ..\..\bin\ 
	

clean :
	del *.o