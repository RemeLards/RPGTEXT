CC = gcc

RNG_HEADERS_PATH = ../../include/rng

IFLAGS = -I$(RNG_HEADERS_PATH)

CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

rng_functions.o : rng_functions.c
	$(CC) $< -c $(IFLAGS) $(CFLAGS)
#	move rng_functions.o ..\..\bin\

clean :
	del *.o
