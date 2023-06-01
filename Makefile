CC=gcc
CFLAGS = -Wall
OBJECTS = rpgtext_character.o rpgtext_functionalities.o rpgtext_menu.o rpgtext_rng.o rpgtext_strings.o rpgtext.o
BINARY = rpgtext.exe

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^

%.o: %.c %.h
	$(CC) -c $<

clean:
	del *.o rpgtext.exe rpgdmg_rng.txt
