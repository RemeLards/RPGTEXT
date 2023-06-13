CC = gcc

MONSTERS_HEADERS_PATH = ../../include/monsters
MAP_HEADERS_PATH = ../../include/map

IFLAGS = -I$(MONSTERS_HEADERS_PATH) -I$(MAP_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

monsters_functions.o : monsters_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move monsters_functions.o ..\..\bin\

clean :
	del *.o