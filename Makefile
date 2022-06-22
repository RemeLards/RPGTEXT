
output: rpgtext_character.o rpgtext_fight.o rpgtext_functionalities.o rpgtext_game.o rpgtext_menu.o rpgtext_monsters.o rpgtext_rng.o rpgtext_strings.o rpgtext.o
	gcc rpgtext_character.o rpgtext_fight.o rpgtext_functionalities.o rpgtext_game.o rpgtext_menu.o rpgtext_monsters.o rpgtext_rng.o rpgtext_strings.o rpgtext.o -o rpgtext.exe


rpgtext_character.o: rpgtext_character.c rpgtext_character.h
	gcc -c rpgtext_character.c

rpgtext_fight.o: rpgtext_fight.c rpgtext_fight.h
	gcc -c rpgtext_fight.c

rpgtext_functionalities.o: rpgtext_functionalities.c rpgtext_functionalities.h
	gcc -c rpgtext_functionalities.c

rpgtext_game.o: rpgtext_game.c rpgtext_game.h
	gcc -c rpgtext_game.c

rpgtext_menu.o: rpgtext_menu.c rpgtext_menu.h
	gcc -c rpgtext_menu.c

rpgtext_monsters.o: rpgtext_monsters.c rpgtext_monsters.h
	gcc -c rpgtext_monsters.c

rpgtext_rng.o: rpgtext_rng.c rpgtext_rng.h
	gcc -c rpgtext_rng.c

rpgtext_strings.o: rpgtext_strings.c rpgtext_strings.h
	gcc -c rpgtext_strings.c

