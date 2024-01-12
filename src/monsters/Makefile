CC = gcc

MONSTERS_HEADERS_PATH = ../../include/monsters
MAP_HEADERS_PATH = ../../include/map
LINKED_LIST_HEADERS_PATH = ../../include/linked_list
LINKED_LIST_HOLDER_HEADERS_PATH = ../../include/linked_list_holder

IFLAGS = -I$(MONSTERS_HEADERS_PATH) -I$(MAP_HEADERS_PATH) -I$(LINKED_LIST_HEADERS_PATH) -I$(LINKED_LIST_HOLDER_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

monsters_functions.o : monsters_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)

clean :
	del *.o