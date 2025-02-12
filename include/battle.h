#ifndef BATTLE_H
#define BATTLE_H

#include "player.h"
#include "supemon.h"
#include "types.h"

void start_wild_battle(Player *player);
void start_battle(Player *player, Supemon *enemy);
int calculate_damage(Supemon *attacker, Supemon *defender, int base_damage);
int attempt_capture(Supemon *enemy_supemon);
int attempt_escape(Supemon *player_supemon, Supemon *enemy_supemon);
void apply_move_effect(Supemon *attacker, Supemon *defender, const char *move);
    
#endif
