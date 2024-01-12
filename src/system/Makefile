CC = gcc

SYSTEM_HEADERS_PATH = ../../include/system

IFLAGS = -I$(SYSTEM_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

system_functions.o : system_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move system_functions.o ..\..\bin\

clean :
	del *.o
