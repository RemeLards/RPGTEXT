CC = gcc

KEYBOARD_HEADERS_PATH = ../../include/keyboard

IFLAGS = -I$(KEYBOARD_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

keyboard_functions.o :keyboard_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move keyboard_functions.o ..\..\bin\

clean :
	del *.o
