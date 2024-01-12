CC = gcc

MENU_CREATION_HEADERS_PATH = ../../include/menu_creation
KEYBOARD_HEADERS_PATH = ../../include/keyboard
SYSTEM_HEADERS_PATH = ../../include/system

IFLAGS = -I$(MENU_CREATION_HEADERS_PATH) -I$(KEYBOARD_HEADERS_PATH) -I$(SYSTEM_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

menu_creation_functions.o : menu_creation_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move menu_creation_functions.o ..\..\bin\

clean :
	del *.o
