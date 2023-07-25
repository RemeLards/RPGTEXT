CC = gcc

LINKED_LIST_HEADERS_PATH = ../../include/linked_list
LINKED_LIST_HOLDER_HEADERS_PATH = ../../include/linked_list_holder

IFLAGS = -I$(LINKED_LIST_HEADERS_PATH) -I$(LINKED_LIST_HOLDER_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

linked_list_holder_functions.o : linked_list_holder_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)

clean :
	del *.o