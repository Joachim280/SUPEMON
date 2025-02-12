/* supemon.c - Gestion des Supémons */
#include "supemon.h"
#include <stdio.h>
#include <string.h>
#include <math.h>  
#include <stdlib.h> 

void level_up_supemon(Supemon *supemon) {
    if (supemon->level < 100) {
        supemon->level++;

        
        supemon->max_hp = (int)(supemon->max_hp * 1.3);
        supemon->attack = (int)(supemon->attack * 1.3);
        supemon->defense = (int)(supemon->defense * 1.3);
        supemon->accuracy = (int)(supemon->accuracy * 1.3);
        supemon->evasion = (int)(supemon->evasion * 1.3);

        
        if (rand() % 2) supemon->max_hp++;
        if (rand() % 2) supemon->attack++;
        if (rand() % 2) supemon->defense++;
        if (rand() % 2) supemon->accuracy++;
        if (rand() % 2) supemon->evasion++;

        printf("%s leveled up to level %d!\n", supemon->name, supemon->level);
    } else {
        printf("%s has already reached the maximum level!\n", supemon->name);
    }
}

void init_supemons(Supemon supemons[]) {
    
    strcpy(supemons[0].name, "Supmander");
    supemons[0].level = 1;
    supemons[0].experience = 0;
    supemons[0].hp = supemons[0].max_hp = 10;
    supemons[0].attack = supemons[0].base_attack = 1;
    supemons[0].defense = supemons[0].base_defense = 1;
    supemons[0].evasion = supemons[0].base_evasion = 1;
    supemons[0].accuracy = supemons[0].base_accuracy = 2;
    supemons[0].speed = 1;
    strcpy(supemons[0].moves[0], "Scratch");
    strcpy(supemons[0].moves[1], "Growl");

    strcpy(supemons[1].name, "Supasaur");
    supemons[1].level = 1;
    supemons[1].experience = 0;
    supemons[1].hp = supemons[1].max_hp = 9;
    supemons[1].attack = supemons[1].base_attack = 1;
    supemons[1].defense = supemons[1].base_defense = 1;
    supemons[1].evasion = supemons[1].base_evasion = 3;
    supemons[1].accuracy = supemons[1].base_accuracy = 2;
    supemons[1].speed = 2;
    strcpy(supemons[1].moves[0], "Pound");
    strcpy(supemons[1].moves[1], "Foliage");

    strcpy(supemons[2].name, "Supirtle");
    supemons[2].level = 1;
    supemons[2].experience = 0;
    supemons[2].hp = supemons[2].max_hp = 11;
    supemons[2].attack = supemons[2].base_attack = 1;
    supemons[2].defense = supemons[2].base_defense = 2;
    supemons[2].evasion = supemons[2].base_evasion = 2;
    supemons[2].accuracy = supemons[2].base_accuracy = 1;
    supemons[2].speed = 2;
    strcpy(supemons[2].moves[0], "Pound");
    strcpy(supemons[2].moves[1], "Shell");

    
    for (int j = 2; j < MAX_MOVES; j++) {
        supemons[0].moves[j][0] = '\0';
    }
    
    
    for (int j = 2; j < MAX_MOVES; j++) {
        supemons[1].moves[j][0] = '\0';
    }
    
    
    for (int j = 2; j < MAX_MOVES; j++) {
        supemons[2].moves[j][0] = '\0';
    }
}
