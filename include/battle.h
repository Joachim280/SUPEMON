/* battle.h - Gestion des combats */
#ifndef BATTLE_H
#define BATTLE_H

#include "player.h"
#include "supemon.h"

// Lance un combat contre un Supémon sauvage
void start_battle(Player *player, Supemon *enemy);

// Calcule les dégâts infligés en fonction des stats
int calculate_damage(Supemon *attacker, Supemon *defender, int base_damage);

// Tente une fuite (réussite basée sur la vitesse)
int attempt_escape(Supemon *player_supemon, Supemon *enemy_supemon);

// Tente de capturer un Supémon ennemi
int attempt_capture(Supemon *enemy_supemon);

#endif
