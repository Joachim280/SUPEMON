/* center.c - Gestion du Supémon Center */
#include "center.h"
#include "types.h"
#include "player.h"
#include <stdio.h>

void heal_supemons(Player *player) {
    printf("\n+----------------------------------+\n");
    printf("|       Welcome to the Supemon Center!      |\n");
    printf("+----------------------------------+\n");
    printf("| Here are your Supemons:          |\n");
    printf("+----------------------------------+\n");
    
    for (int i = 0; i < player->supemon_count; i++) {
        printf("| %d - %-10s (HP: %3d/%3d) |\n", i + 1, player->team[i].name, player->team[i].hp, player->team[i].max_hp);
    }
    printf("+----------------------------------+\n");
    
    printf("\nDo you want to heal all your Supemons? (y/n): ");
    char choice;
    scanf(" %c", &choice);
    
    if (choice == 'y' || choice == 'Y') {
        for (int i = 0; i < player->supemon_count; i++) {
            player->team[i].hp = player->team[i].max_hp;
        }
        printf("\n+----------------------------------+\n");
        printf("|  All your Supemons have been fully healed!  |\n");
        printf("+----------------------------------+\n");
    } else {
        printf("\n+----------------------------------+\n");
        printf("|  Come back anytime to heal your Supémons!   |\n");
        printf("+----------------------------------+\n");
    }
}
