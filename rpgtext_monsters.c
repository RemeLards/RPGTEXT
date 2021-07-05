#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "rpgtext_structs.h"
#include "rpgtext_monsters.h"
#include "rpgtext_menu.h"

void goblin(CHARACTER* character)
{
    system("cls");
    printf("\nYOU FOUND A GOLBIN!!!\n");
    printf("Press any key to continue");
    getch();

    MOBS* goblin = (MOBS*)malloc(sizeof(MOBS));
    goblin -> health = 15;
    goblin -> defense = 1;
    goblin -> attackpower = 0;
    goblin -> abilitypower = 1;
    goblin -> mana = 0;
    goblin -> stamina = 0;
    goblin -> experience_given = 501;
    fight_menu(character,goblin);
}

void glasscanon_goblin(CHARACTER* character)
{
    system("cls");
    printf("\nYOU FOUND A GLASS GOLBIN!!!\n");
    printf("Press any key to continue");
    getch();

    MOBS* glasscanon_goblin = (MOBS*)malloc(sizeof(MOBS));
    glasscanon_goblin -> health = 1;
    glasscanon_goblin -> defense = 1;
    glasscanon_goblin -> attackpower = 1000000;
    glasscanon_goblin -> abilitypower = 1;
    glasscanon_goblin -> mana = 0;
    glasscanon_goblin -> stamina = 0;
    glasscanon_goblin -> experience_given = 501;
    fight_menu(character,glasscanon_goblin);
}


