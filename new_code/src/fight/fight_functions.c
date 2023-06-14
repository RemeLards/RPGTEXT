//-------------------------
//HEADERS
//-------------------------
#include "fight_functions.h"

//-------------------------
//Defines
//-------------------------

#define ZERO_HEALTH_VALUE 0 

//-------------------------
//Functions
//-------------------------

float
fight_monsters_base_dmg_calculation(MONSTER *monster_struct_ptr)
{
    printf("\nTHE MONSTER HITTED YOU!!!\n");
    int roll = rng_generate_random_positive_number() % 101;
    float monster_base_physical_power = monster_struct_ptr -> physical_power;

    if (roll <= 10) monster_base_physical_power *= 0.9;
    if (roll > 10 &&  roll <= 20) monster_base_physical_power *= 0.92;
    if (roll > 20 &&  roll <= 30) monster_base_physical_power *= 0.94;
    if (roll > 30 &&  roll <= 40) monster_base_physical_power *= 0.96;
    if (roll > 40 &&  roll <= 50) monster_base_physical_power *= 0.98;
    if (roll > 50 &&  roll <= 60) monster_base_physical_power *= 1;
    if (roll > 60 &&  roll <= 70) monster_base_physical_power *= 1.02;
    if (roll > 70 &&  roll <= 80) monster_base_physical_power *= 1.04;
    if (roll > 80 &&  roll <= 90) monster_base_physical_power *= 1.06;
    if (roll > 90 &&  roll <= 100) monster_base_physical_power *= 1.1;
    
    printf("DAMAGE RECEIVE: %.2f\n",monster_base_physical_power);
    return monster_base_physical_power;
    
    //Didn't Add Mana/Stamina Attacks in MONSTER, And IDK Yet How Can I Make A Mob "Choose" a Random Ability

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

float
fight_character_base_dmg_calculation(CHARACTER *character_struct_ptr)
{
    int roll = rng_generate_random_positive_number() % 101;

    if (character_struct_ptr -> attack_type == PHYSICAL_ATTACK)
    {
        //If Player did a Physical Attack
        float base_physical_power = character_struct_ptr -> base_physical_power;
        
        if (roll <= 10) base_physical_power *= 0.9;
        if (roll > 10 &&  roll <= 20) base_physical_power *= 0.92;
        if (roll > 20 &&  roll <= 30) base_physical_power *= 0.94;
        if (roll > 30 &&  roll <= 40) base_physical_power *= 0.96;
        if (roll > 40 &&  roll <= 50) base_physical_power *= 0.98;
        if (roll > 50 &&  roll <= 60) base_physical_power *= 1;
        if (roll > 60 &&  roll <= 70) base_physical_power *= 1.02;
        if (roll > 70 &&  roll <= 80) base_physical_power *= 1.04;
        if (roll > 80 &&  roll <= 90) base_physical_power *= 1.06;
        if (roll > 90 &&  roll <= 100) base_physical_power *= 1.1;
        return base_physical_power;
    }
    
    if ( character_struct_ptr -> attack_type == ABILITY_ATTACK )
    {
         //If Player did a Ability Attack
        float base_ability_power = character_struct_ptr -> base_ability_power;

        if (character_struct_ptr -> ability_type == MANA_ABILITY)
        {
            if (roll <= 1000) base_ability_power *= 1;
            if (roll > 1000 &&  roll <= 2000) base_ability_power *= 1.02;
            if (roll > 2000 &&  roll <= 3000) base_ability_power *= 1.04;
            if (roll > 3000 &&  roll <= 4000) base_ability_power *= 1.06;
            if (roll > 4000 &&  roll <= 5000) base_ability_power *= 1.08;
            if (roll > 5000 &&  roll <= 6000) base_ability_power *= 1.1;
            if (roll > 6000 &&  roll <= 7000) base_ability_power *= 1.12;
            if (roll > 7000 &&  roll <= 8000) base_ability_power *= 1.14;
            if (roll > 8000 &&  roll <= 9000) base_ability_power *= 1.16;
            if (roll > 9000 &&  roll <= 10000) base_ability_power *= 1.2;
        }

        if (character_struct_ptr -> ability_type == STAMINA_ABILITY)
        {
            if (roll <= 1000) base_ability_power *= 1;
            if (roll > 1000 &&  roll <= 2000) base_ability_power *= 1.03;
            if (roll > 2000 &&  roll <= 3000) base_ability_power *= 1.06;
            if (roll > 3000 &&  roll <= 4000) base_ability_power *= 1.09;
            if (roll > 4000 &&  roll <= 5000) base_ability_power *= 1.1;
            if (roll > 5000 &&  roll <= 6000) base_ability_power *= 1.13;
            if (roll > 6000 &&  roll <= 7000) base_ability_power *= 1.16;
            if (roll > 7000 &&  roll <= 8000) base_ability_power *= 1.19;
            if (roll > 8000 &&  roll <= 9000) base_ability_power *= 1.2;
            if (roll > 9000 &&  roll <= 10000) base_ability_power *= 1.3;
        }

        return base_ability_power;
    }
    
    return FIGHT_FUNCTION_FLOAT_ERROR;

}

float
fight_character_overall_dmg_calculation(CHARACTER *character_struct_ptr)
{
    int roll = rng_generate_random_positive_number() % 101;//Random Number
    int physical_crit_chance = (character_struct_ptr -> base_physical_crit_chance); //Chance of getting a basic physical crit
    int ability_crit_chance = (character_struct_ptr -> base_ability_crit_chance); //Chance of getting a ability crit
    float character_base_damage = fight_character_base_dmg_calculation(character_struct_ptr); //Getting a range of damage values

    if ( (character_struct_ptr -> attack_type == PHYSICAL_ATTACK) )
    {

        //Player did not Crit with physical attack
        if ( (roll > physical_crit_chance) )
        {
            printf("\nDID A PHYSICAL ATTACK!!!\n");
            printf("DAMAGE DONE : %.2f\n",character_base_damage);
            
            return character_base_damage; 
        }

        //If Player did Crit Damage with physical attack
        if ( (roll <= physical_crit_chance) )
        {
            
            float physical_crit_dmg = 1+(character_struct_ptr-> base_physical_crit_dmg/100); //PHYSICAL ATTACK Crit Damage
            
            printf("\nDID A PHYSICAL ATTACK!!!\n");
            printf("**CRIT DAMAGE**\n");
            printf("DAMAGE DONE : %.2f\n", character_base_damage * physical_crit_dmg) ;
            
            return character_base_damage * physical_crit_dmg ;
        }

    }

    if ( (character_struct_ptr -> attack_type == ABILITY_ATTACK) )
    {
        //Player did not Crit with ability attack
        if ( (roll > ability_crit_chance) && (character_struct_ptr -> ability_type == MANA_ABILITY || character_struct_ptr -> ability_type == STAMINA_ABILITY) )
        {
            printf("\nDID AN ABILITY ATTACK!!!\n");
            printf("DAMAGE DONE: %.2f\n", character_base_damage);
            
            return character_base_damage;
        }

        //If Player did Crit Damage with Ability Attack  
        if ( (roll <= ability_crit_chance) && (character_struct_ptr -> ability_type == MANA_ABILITY || character_struct_ptr -> ability_type == STAMINA_ABILITY) )
        {
            
            float ability_crit_dmg = 1+(character_struct_ptr-> base_ability_crit_dmg/100); //Ability Attack Crit Damage
            
            printf("\nDID AN ABILITY ATTACK!!!\n");
            printf("**CRIT DAMAGE**\n");
            printf("DAMAGE DONE : %.2f\n",character_base_damage * ability_crit_dmg);
            
            return character_base_damage * ability_crit_dmg;
        }
    }

    return FIGHT_FUNCTION_INT_ERROR;

}

void
fight_character_death(CHARACTER *character_struct_ptr)
{
    system_clear();
    printf("YOU DIED, DO BETTER NEXT TIME!!!\n");
    printf("Press ENTER to continue!");
    getchar(); 

    character_free_all(character_struct_ptr);
    //imenu(); //Retuns to the initial menu  
}

void
fight_character_killed_monsters(CHARACTER *character_struct_ptr, MONSTER *monster_struct_ptr)
{
    system("cls");
    printf("YOU KILLED THE MONSTER, GOOD JOB!!!!\n");
    printf("Press ENTER to continue!");
    getchar();
        
    character_struct_ptr -> level_struct_ptr -> experience += monster_struct_ptr -> experience_given; //Giving EXP To Player
    printf("\n\nYOU GOT %.0f XP\n",monster_struct_ptr -> experience_given);  //Print XP That Player Got 
    character_level_calculation(character_struct_ptr);         //Calculating If Player Leveled Up
}

//TODO
void
fight_attack_choise_menu(CHARACTER *character_struct_ptr)
{
    const char *options_names[] = {"Physical Attack","Ability Attack"};
    const int num_options = 2;
    int option_chosen = menu_creation_menu_option_chosen(options_names , num_options);

    if (option_chosen == 0) character_struct_ptr -> attack_type = PHYSICAL_ATTACK;
    if (option_chosen == 1) 
    {
        character_struct_ptr -> attack_type = ABILITY_ATTACK;
        character_struct_ptr -> ability_type = MANA_ABILITY; // MENU FOR ABILITY CHOOSEN DOESNT EXIST
    }
}

int
fight_fight_result(CHARACTER *character_struct_ptr,MONSTER *monster_struct_ptr)
{
  
    monster_struct_ptr -> health -= fight_character_overall_dmg_calculation(character_struct_ptr); //Monster Damage Received
        
    if(monster_struct_ptr -> health > ZERO_HEALTH_VALUE) //If Monster wasn't killed
    {
        printf("\nMonster Health: %.2f\n", monster_struct_ptr -> health);

        character_struct_ptr -> base_health -= fight_monsters_base_dmg_calculation(monster_struct_ptr); // Monster Attack 
        printf("\nYOUR Health: %.2f\n", character_struct_ptr -> base_health);
        printf("Press ENTER to continue\n\n");
        getchar();

        if(character_struct_ptr -> base_health > ZERO_HEALTH_VALUE) return CHARACTER_IS_ALIVE; //Player isn't dead

        else return CHARACTER_IS_DEAD; //Player died
    }

    else return CHARACTER_KILLED_MONSTERS;// If Monster Died ==> monster -> health <= ZERO_HEALTH_VALUE

}

int
fight_fight_menu(CHARACTER *character_struct_ptr,MONSTER *monster_struct_ptr/*, MONSTER *monster_count[]*/)
{
    int fight_status = CHARACTER_IS_ALIVE;
    
    while (fight_status == CHARACTER_IS_ALIVE)
    {
        // Player encountered a monster (or group of monsters) before
        // Choose  Monster to attack (or do an area attack) (in the moment there will be only one and no area attack)
        fight_attack_choise_menu(character_struct_ptr);
        fight_status = fight_fight_result(character_struct_ptr,monster_struct_ptr);
    }

    /*FIGHT IS OVER*/

    printf("\nPress ENTER to continue!\n");
    getchar();

    if (fight_status == CHARACTER_IS_DEAD) fight_character_death(character_struct_ptr);

    if (fight_status == CHARACTER_KILLED_MONSTERS) fight_character_killed_monsters(character_struct_ptr, monster_struct_ptr);

    free(monster_struct_ptr);//Freeing monsters malloced struct (we could generalize to a group of monters or in other words a vector of monsters)


    return fight_status;
}