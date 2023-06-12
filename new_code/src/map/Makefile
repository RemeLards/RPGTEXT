CC = gcc

CHARACTER_HEADERS_PATH = ../../include/character
MAP_HEADERS_PATH = ../../include/map
KEYBOARD_HEADERS_PATH = ../../include/keyboard
SYSTEM_HEADERS_PATH = ../../include/system

IFLAGS = -I$(CHARACTER_HEADERS_PATH) -I$(MAP_HEADERS_PATH) -I$(KEYBOARD_HEADERS_PATH) -I$(SYSTEM_HEADERS_PATH)\


CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3


map_functions.o : map_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move character_functions.o ..\..\bin\ 
	

clean :
	del *.o