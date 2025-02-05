/* player.h - Gestion du joueur */
#ifndef PLAYER_H
#define PLAYER_H

#include "supemon.h"
#include "items.h"

#define MAX_SUPEMONS 6
#define MAX_ITEMS 10

typedef struct {
    char name[50];  // Nom du joueur
    Supemon team[MAX_SUPEMONS];  // Liste des Supémons possédés
    int supemon_count;  // Nombre de Supémons
    int selected_supemon;  // Supémon actuellement utilisé en combat
    int supcoins;  // Monnaie du jeu
    Item inventory[MAX_ITEMS];  // Liste des objets possédés
    int item_count;  // Nombre d'objets possédés
} Player;

// Initialise un nouveau joueur
void init_player(Player *player);
// Permet au joueur de choisir son premier Supémon
void choose_starter(Player *player);
// Affiche les informations du joueur
void display_player_info(const Player *player);

#endif
