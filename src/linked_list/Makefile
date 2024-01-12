CC = gcc

LINKED_LIST_HEADERS_PATH = ../../include/linked_list

IFLAGS = -I$(LINKED_LIST_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

linked_list_functions.o : linked_list_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)

clean :
	del *.o