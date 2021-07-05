//-------------------------
//HEADERS
//-------------------------
#include "rpgtext_fight.h"
#include <conio.h>

//-------------------------
//Functions
//-------------------------

float dmg_values_mobs(MOBS* monster)
{
    printf("\nTHE MONSTER HITTED YOU!!!\n");
    int roll = rng_generator() % 101;
    float pure_attackpower = monster -> attackpower;

    if(roll <= 10)pure_attackpower *= 0.9;
    if(roll > 10 &&  roll <= 20)pure_attackpower *= 0.92;
    if(roll > 20 &&  roll <= 30)pure_attackpower *= 0.94;
    if(roll > 30 &&  roll <= 40)pure_attackpower *= 0.96;
    if(roll > 40 &&  roll <= 50)pure_attackpower *= 0.98;
    if(roll > 50 &&  roll <= 60)pure_attackpower *= 1;
    if(roll > 60 &&  roll <= 70)pure_attackpower *= 1.02;
    if(roll > 70 &&  roll <= 80)pure_attackpower *= 1.04;
    if(roll > 80 &&  roll <= 90)pure_attackpower *= 1.06;
    if(roll > 90 &&  roll <= 100)pure_attackpower *= 1.1;
    printf("DAMAGE RECEIVE: %.2f\n",pure_attackpower);
    return pure_attackpower;

    /*if (attack_status == MANA_ATTACK)
    {
        if(roll <= 1000)monster -> attackpower *= 1;
        if(roll > 1000 &&  roll <= 2000)monster -> attackpower *= 1.02;
        if(roll > 2000 &&  roll <= 3000)monster -> attackpower *= 1.04;
        if(roll > 3000 &&  roll <= 4000)monster -> attackpower *= 1.06;
        if(roll > 4000 &&  roll <= 5000)monster -> attackpower *= 1.08;
        if(roll > 5000 &&  roll <= 6000)monster -> attackpower *= 1.1;
        if(roll > 6000 &&  roll <= 7000)monster -> attackpower *= 1.12;
        if(roll > 7000 &&  roll <= 8000)monster -> attackpower *= 1.14;
        if(roll > 8000 &&  roll <= 9000)monster -> attackpower *= 1.16;
        if(roll > 9000 &&  roll <= 10000)monster -> attackpower *= 1.2;
    }
    if(attack_status == STAMINA_ATTACK)
    {
        if(roll <= 1000)monster -> attackpower *= 1;
        if(roll > 1000 &&  roll <= 2000)monster -> attackpower *= 1.03;
        if(roll > 2000 &&  roll <= 3000)monster -> attackpower *= 1.06;
        if(roll > 3000 &&  roll <= 4000)monster -> attackpower *= 1.09;
        if(roll > 4000 &&  roll <= 5000)monster -> attackpower *= 1.1;
        if(roll > 5000 &&  roll <= 6000)monster -> attackpower *= 1.13;
        if(roll > 6000 &&  roll <= 7000)monster -> attackpower *= 1.16;
        if(roll > 7000 &&  roll <= 8000)monster -> attackpower *= 1.19;
        if(roll > 8000 &&  roll <= 9000)monster -> attackpower *= 1.2;
        if(roll > 9000 &&  roll <= 10000)monster -> attackpower *= 1.3;
    }*/
}
float dmg_values_player(CHARACTER* character, int attack_status)
{
    int roll = rng_generator() % 100;

    if (attack_status == BASIC_ATTACK)
    {
        //If Player did a Basic Attack
        float pure_attackpower = character -> base_attackpower;
        
        if(roll <= 10)pure_attackpower *= 0.9;
        if(roll > 10 &&  roll <= 20)pure_attackpower *= 0.92;
        if(roll > 20 &&  roll <= 30)pure_attackpower *= 0.94;
        if(roll > 30 &&  roll <= 40)pure_attackpower *= 0.96;
        if(roll > 40 &&  roll <= 50)pure_attackpower *= 0.98;
        if(roll > 50 &&  roll <= 60)pure_attackpower *= 1;
        if(roll > 60 &&  roll <= 70)pure_attackpower *= 1.02;
        if(roll > 70 &&  roll <= 80)pure_attackpower *= 1.04;
        if(roll > 80 &&  roll <= 90)pure_attackpower *= 1.06;
        if(roll > 90 &&  roll <= 100)pure_attackpower *= 1.1;
        return pure_attackpower;
    }

    //If Player did a Ability Attack
    float pure_abilitypower = character -> base_abilitypower;
    
    if (attack_status == MANA_ATTACK)
    {
        if(roll <= 1000)pure_abilitypower *= 1;
        if(roll > 1000 &&  roll <= 2000)pure_abilitypower *= 1.02;
        if(roll > 2000 &&  roll <= 3000)pure_abilitypower *= 1.04;
        if(roll > 3000 &&  roll <= 4000)pure_abilitypower *= 1.06;
        if(roll > 4000 &&  roll <= 5000)pure_abilitypower *= 1.08;
        if(roll > 5000 &&  roll <= 6000)pure_abilitypower *= 1.1;
        if(roll > 6000 &&  roll <= 7000)pure_abilitypower *= 1.12;
        if(roll > 7000 &&  roll <= 8000)pure_abilitypower *= 1.14;
        if(roll > 8000 &&  roll <= 9000)pure_abilitypower *= 1.16;
        if(roll > 9000 &&  roll <= 10000)pure_abilitypower *= 1.2;
        return pure_abilitypower;
    }
    if(attack_status == STAMINA_ATTACK)
    {
        if(roll <= 1000)pure_abilitypower *= 1;
        if(roll > 1000 &&  roll <= 2000)pure_abilitypower *= 1.03;
        if(roll > 2000 &&  roll <= 3000)pure_abilitypower *= 1.06;
        if(roll > 3000 &&  roll <= 4000)pure_abilitypower *= 1.09;
        if(roll > 4000 &&  roll <= 5000)pure_abilitypower *= 1.1;
        if(roll > 5000 &&  roll <= 6000)pure_abilitypower *= 1.13;
        if(roll > 6000 &&  roll <= 7000)pure_abilitypower *= 1.16;
        if(roll > 7000 &&  roll <= 8000)pure_abilitypower *= 1.19;
        if(roll > 8000 &&  roll <= 9000)pure_abilitypower *= 1.2;
        if(roll > 9000 &&  roll <= 10000)pure_abilitypower *= 1.3;
        return pure_abilitypower;
    }

}
float dmg_calculation(CHARACTER* character,int attack_status)
{
    int roll = rng_generator() % 10001;//Random Number
    int hit_chance = (character -> base_critchance)*100; //Chance of getting a basic attack crit
    int ability_chance = (character -> base_abilitycritchance)*100;//Chance of getting a ability crit
    float pure_damage = dmg_values_player(character,attack_status);//Getting a range of damage values

    if(roll > hit_chance && attack_status == BASIC_ATTACK)
    {
        printf("\nDID A BASIC ATTACK!!!\n");
        printf("DAMAGE DONE : %.2f\n",pure_damage);
        return pure_damage; 
    }


    if(roll <= hit_chance && attack_status == BASIC_ATTACK)
    {
        break_rngloop();
        //If Player did Crit Damage with Basic Attack
        float pure_critdmg = 1+(character-> base_critdmg/100); //Basic Attack Crit Damage
        printf("\nDID A BASIC ATTACK!!!\n");
        printf("**CRIT DAMAGE**\n");
        printf("DAMAGE DONE : %.2f\n", pure_damage * pure_critdmg);
        return pure_damage * pure_critdmg;
    }

    if(roll > ability_chance && attack_status == MANA_ATTACK || attack_status == STAMINA_ATTACK)
    {
        printf("\nDID A ABILITY ATTACK!!!\n");
        printf("DAMAGE DONE: %.2f\n", pure_damage);
        return pure_damage;
    }
    
    if(roll <= ability_chance && attack_status == MANA_ATTACK || attack_status == STAMINA_ATTACK)
    {
        break_rngloop();
        //If Player did Crit Damage with Ability Attack
        float pure_abilitycritdmg = 1+(character-> base_abilitycritdmg/100);
        printf("\nDID A ABILITY ATTACK!!!\n");
        printf("**CRIT DAMAGE**\n");
        printf("DAMAGE DONE : %.2f\n", pure_damage * pure_abilitycritdmg);
        return pure_damage * pure_abilitycritdmg;
    }

}
