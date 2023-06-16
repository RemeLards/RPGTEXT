CC = gcc

OBJECTS = character/character_functions.o fight/fight_functions.o monsters/monsters_functions.o rng/rng_functions.o system/system_functions.o \
keyboard/keyboard_functions.o menu_creation/menu_creation_functions.o main_menu/main_menu_functions.o map/map_functions.o \
linked_list/linked_list_functions.o


IFLAGS = -I../include -I../include/character -I../include/fight -I../include/rng -I../include/monsters \
-I../include/system -I../include/keyboard -I../include/menu_creation -I../include/main_menu -I../include/map \
-I../include/linked_list


CFLAGS = -pedantic -Wall -Wextra -Wwrite-strings -g3

make_directories :
	cd character 			&& $(MAKE)
	cd monsters 			&& $(MAKE)
	cd rng 					&& $(MAKE)
	cd fight 				&& $(MAKE)
	cd system 				&& $(MAKE)
	cd keyboard 			&& $(MAKE)
	cd menu_creation 		&& $(MAKE)
	cd main_menu 			&& $(MAKE)
	cd map 			        && $(MAKE)
	cd linked_list 			&& $(MAKE)
	$(MAKE) teste.exe

teste.exe : teste.c $(OBJECTS)
	$(CC) $^ -o $@ $(IFLAGS) $(CFLAGS)

clean :
	cd character 			&& $(MAKE) clean
	cd monsters 			&& $(MAKE) clean
	cd rng 					&& $(MAKE) clean
	cd fight 				&& $(MAKE) clean
	cd system 				&& $(MAKE) clean
	cd keyboard 			&& $(MAKE) clean
	cd menu_creation 		&& $(MAKE) clean
	cd main_menu 			&& $(MAKE) clean
	cd map 			        && $(MAKE) clean
	cd linked_list 			&& $(MAKE) clean
	del *.o *.txt *.exe
	cls