/* save.h - Gestion des sauvegardes */
#ifndef SAVE_H
#define SAVE_H

#include "player.h"

// Sauvegarde la progression du joueur dans un fichier
void save_game(Player *player);

// Charge une sauvegarde existante
int load_game(Player *player);

#endif
