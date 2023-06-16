CC = gcc

MONSTERS_HEADERS_PATH = ../../include/monsters
MAP_HEADERS_PATH = ../../include/map
LINKED_LIST_HEADERS_PATH = ../../include/linked_list

IFLAGS = -I$(MONSTERS_HEADERS_PATH) -I$(MAP_HEADERS_PATH) -I$(LINKED_LIST_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

monsters_functions.o : monsters_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move monsters_functions.o ..\..\bin\

clean :
	del *.o