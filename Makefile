
output: rpgtext_character.o rpgtext_functionalities.o rpgtext_menu.o rpgtext_rng.o rpgtext_strings.o rpgtext.o
	gcc rpgtext_character.o rpgtext_functionalities.o rpgtext_menu.o rpgtext_rng.o rpgtext_strings.o rpgtext.o -o rpgtext.exe


rpgtext_character.o: rpgtext_character.c rpgtext_character.h
	gcc -c rpgtext_character.c

rpgtext_functionalities.o: rpgtext_functionalities.c rpgtext_functionalities.h
	gcc -c rpgtext_functionalities.c

rpgtext_menu.o: rpgtext_menu.c rpgtext_menu.h
	gcc -c rpgtext_menu.c

rpgtext_rng.o: rpgtext_rng.c rpgtext_rng.h
	gcc -c rpgtext_rng.c

rpgtext_strings.o: rpgtext_strings.c rpgtext_strings.h
	gcc -c rpgtext_strings.c

clean:
	rm *.o rpgtext.exe

