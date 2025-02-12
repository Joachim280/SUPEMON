/* battle.c - Gestion des combats */
#include "battle.h"
#include "types.h"
#include "items.h"  
#include "supemon.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void start_wild_battle(Player *player) {
    Supemon supemon_list[3];
    init_supemons(supemon_list);  

    srand(time(NULL));
    int index = rand() % 3; 

    Supemon wild_supemon = {0}; 
    memcpy(&wild_supemon, &supemon_list[index], sizeof(Supemon));

  
    wild_supemon.level = player->team[player->selected_supemon].level;


    if (wild_supemon.level <= 0 || wild_supemon.level > 100) {
        wild_supemon.level = 1;  
    }

    
    int target_level = wild_supemon.level;
    wild_supemon.level = 1;  
    for (int i = 1; i < target_level; i++) {
        level_up_supemon(&wild_supemon);
    }

    printf("\nA wild %s appeared! (Lvl %d)\n", wild_supemon.name, wild_supemon.level);
    printf("Stats: HP: %d/%d | Atk: %d | Def: %d | Acc: %d | Eva: %d\n",
           wild_supemon.hp, wild_supemon.max_hp, wild_supemon.attack, 
           wild_supemon.defense, wild_supemon.accuracy, wild_supemon.evasion);

    start_battle(player, &wild_supemon);
}



int attempt_capture(Supemon *enemy_supemon) {
    int capture_chance = rand() % 100;
    return (capture_chance < 50);  
}


int attempt_escape(Supemon *player_supemon, Supemon *enemy_supemon) {
    return (player_supemon->speed > enemy_supemon->speed) || (rand() % 2 == 0);
}


int calculate_damage(Supemon *attacker, Supemon *defender, int base_damage) {
    int damage = base_damage + (attacker->attack - defender->defense);
    if (damage < 0) damage = 1;  
    return damage;
}

void apply_move_effect(Supemon *attacker, Supemon *defender, const char *move) {
    if (strcmp(move, "Growl") == 0) {
        attacker->attack += 1;
        printf("%s used Growl! Attack increased!\n", attacker->name);
        return; 
    } 
    else if (strcmp(move, "Foliage") == 0) {
        attacker->evasion += 1;
        printf("%s used Foliage! Evasion increased!\n", attacker->name);
        return;
    } 
    else if (strcmp(move, "Shell") == 0) {
        attacker->defense += 1;
        printf("%s used Shell! Defense increased!\n", attacker->name);
        return;
    } 
    else {
        
        int damage = calculate_damage(attacker, defender, 3);
        defender->hp -= damage;
        printf("%s used %s! %s took %d damage!\n", attacker->name, move, defender->name, damage);
    }
}


void start_battle(Player *player, Supemon *enemy) {
    Supemon *player_supemon = &player->team[player->selected_supemon];
    printf("\nA wild %s appears! Prepare for battle!\n", enemy->name);
    
    
    int player_turn = (player_supemon->speed > enemy->speed) || (rand() % 2 == 0);
    
    while (player_supemon->hp > 0 && enemy->hp > 0) {
        clear_screen();
        printf("+Your supemon+\n");
        printf("+----------------------------+\n");
        printf("\n%s (HP: %d/%d | Lvl: %d | Atk: %d | Def: %d | Acc: %d | Eva: %d)\n", 
               player_supemon->name, player_supemon->hp, player_supemon->max_hp, 
               player_supemon->level, player_supemon->attack, player_supemon->defense, 
               player_supemon->accuracy, player_supemon->evasion);
        printf("Wild Supemon\n");
        printf("+----------------------------+\n");
        printf("%s (HP: %d/%d | Lvl: %d | Atk: %d | Def: %d | Acc: %d | Eva: %d)\n", 
               enemy->name, enemy->hp, enemy->max_hp, 
               enemy->level, enemy->attack, enemy->defense, 
               enemy->accuracy, enemy->evasion);
        printf("+----------------------------+\n");
        
        if (player_turn) {
            printf("\nYour turn! Choose an action:\n");
            printf("+----------------------------+\n");
            printf("| 1 - Move                  |\n");
            printf("| 2 - Change Supemon        |\n");
            printf("| 3 - Use Item              |\n");
            printf("| 4 - Capture               |\n");
            printf("| 5 - Run Away              |\n");
            printf("+----------------------------+\n");
            printf("Choice: ");
            
            int choice;
            scanf("%d", &choice);
            
            switch (choice) {
                case 1: { 
                    printf("\nChoose your move:\n");
                    for (int i = 0; i < MAX_MOVES; i++) {
                        if (player_supemon->moves[i][0] != '\0') { 
                            printf("%d - %s\n", i + 1, player_supemon->moves[i]);
                        }
                    }
                
                    printf("Choice: ");
                    int move_index;
                    scanf("%d", &move_index);
                    move_index--; 
                
                    if (move_index >= 0 && move_index < MAX_MOVES && strlen(player_supemon->moves[move_index]) > 0) {
                        printf("%s uses %s!\n", player_supemon->name, player_supemon->moves[move_index]);
                
                        
                        apply_move_effect(player_supemon, enemy, player_supemon->moves[move_index]);
                    } else {
                        printf("Invalid move selection!\n");
                    }
                    break;
                }
                
                case 2: { 
                    printf("\nChoose a Supemon to switch to:\n");
                    for (int i = 0; i < player->supemon_count; i++) {
                        if (player->team[i].hp > 0) {
                            printf("%d - %s (HP: %d/%d)\n", i + 1, player->team[i].name, player->team[i].hp, player->team[i].max_hp);
                        }
                    }
                    printf("Choice: ");
                    int new_supemon;
                    scanf("%d", &new_supemon);
                    new_supemon--;
                    
                    if (new_supemon >= 0 && new_supemon < player->supemon_count && player->team[new_supemon].hp > 0) {
                        player->selected_supemon = new_supemon;
                        player_supemon = &player->team[player->selected_supemon];
                        printf("You switched to %s!\n", player_supemon->name);
                    } else {
                        printf("Invalid choice!\n");
                    }
                    break;
                }
                case 3: { 
                    if (player->item_count > 0) {
                        printf("\nChoose an item to use:\n");
                        for (int i = 0; i < player->item_count; i++) {
                            printf("%d - %s (+%d HP)\n", i + 1, player->inventory[i].name, player->inventory[i].effect_value);
                        }
                        printf("Choice: ");
                        int item_choice;
                        scanf("%d", &item_choice);
                        item_choice--;
                
                        if (item_choice >= 0 && item_choice < player->item_count) {
                            use_item(player, player_supemon, item_choice);
                        } else {
                            printf("Invalid item choice!\n");
                        }
                    } else {
                        printf("You have no items!\n");
                    }
                    break;
                }
                
                case 4: 
                    if (attempt_capture(enemy)) {
                        printf("You captured %s!\n", enemy->name);
                        player->team[player->supemon_count] = *enemy;
                        player->supemon_count++;
                        return; 
                    } else {
                        printf("Capture failed!\n");
                    }
                    break;
                case 5: // Fuir
                    if (attempt_escape(player_supemon, enemy)) {
                        printf("You escaped successfully!\n");
                        return;
                    } else {
                        printf("Failed to escape!\n");
                    }
                    break;
                default:
                    printf("Invalid choice!\n");
            }
        } else {
            printf("\n%s attacks!\n", enemy->name);
            int damage = calculate_damage(enemy, player_supemon, 2);
            player_supemon->hp -= damage;
            printf("%s takes %d damage!\n", player_supemon->name, damage);
        }
        
        player_turn = !player_turn; 
        press_enter_to_continue();
    }

    if (player_supemon->hp <= 0) {
        printf("\n%s has fainted! You lost the battle!\n", player_supemon->name);
    } else {
        printf("\nYou defeated %s!\n", enemy->name);

        int exp_gained = (100 + (rand() % 401)) * enemy->level; 
        printf("\n%s gained %d EXP!\n", player_supemon->name, exp_gained);
        player_supemon->experience += exp_gained;
        level_up_supemon(player_supemon);  

        int coins_won = 100 + (rand() % 401);
        player->supcoins += coins_won;
        printf("\nYou won %d Supcoins! You now have %d Supcoins.\n", coins_won, player->supcoins);
    }
    
    
    

}

