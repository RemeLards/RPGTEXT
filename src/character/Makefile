CC = gcc

CHARACTER_HEADERS_PATH = ../../include/character
SYSTEM_HEADERS_PATH = ../../include/system
MAP_HEADERS_PATH = ../../include/map

IFLAGS = -I$(CHARACTER_HEADERS_PATH) -I$(SYSTEM_HEADERS_PATH) -I$(MAP_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

character_functions.o : character_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move character_functions.o ..\..\bin\ 
	

clean :
	del *.o
