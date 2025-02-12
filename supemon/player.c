/* player.c - Gestion du joueur */
#include "player.h"
#include "supemon.h"  
#include <stdio.h>
#include <string.h>

void init_player(Player *player) {
    printf("Enter your name: ");
    scanf("%s", player->name);
    player->supemon_count = 0;
    player->supcoins = 500;
    player->item_count = 0;
}

void choose_starter(Player *player) {
    Supemon starters[3];  
    init_supemons(starters);  

    printf("\nHello %s! Welcome to Supemon World!\n", player->name);
    printf("+--------------------------------+\n");
    printf("| Choose your starter Supemon:   |\n");
    printf("| 1 - Supmander                  |\n");
    printf("| 2 - Supasaur                   |\n");
    printf("| 3 - Supirtle                   |\n");
    printf("+--------------------------------+\n");
    printf("Enter 1, 2, or 3: ");

    int choice;
    scanf("%d", &choice);

    if (choice < 1 || choice > 3) {
        printf("Invalid choice. Defaulting to Supmander.\n");
        choice = 1;
    }


    player->team[0] = starters[choice - 1];
    player->supemon_count = 1;
    player->selected_supemon = 0;
}

void display_player_info(const Player *player) {
    printf("\n+----------------------------+\n");
    printf("| Player Info               |\n");
    printf("+----------------------------+\n");
    printf("Name: %s\n", player->name);
    printf("Supcoins: %d\n", player->supcoins);
    printf("Supemons owned: %d\n", player->supemon_count);
    for (int i = 0; i < player->supemon_count; i++) {
        printf(" - %s (HP: %d/%d, Lvl: %d)\n", 
               player->team[i].name, player->team[i].hp, player->team[i].max_hp, player->team[i].level);
    }
    printf("+----------------------------+\n");
}
