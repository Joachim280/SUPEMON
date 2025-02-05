/* supemon.h - Définition des Supémons */
#ifndef SUPEMON_H
#define SUPEMON_H

#define MAX_MOVES 4

typedef struct {
    char name[20];  // Nom du Supémon
    int level;
    int experience;
    int hp, max_hp;
    int attack, base_attack;
    int defense, base_defense;
    int evasion, base_evasion;
    int accuracy, base_accuracy;
    int speed;
    char moves[MAX_MOVES][20];  // Liste des attaques
} Supemon;

// Initialise une liste de Supémons de base
void init_supemons(Supemon supemons[]);

#endif
