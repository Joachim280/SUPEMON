/* player.c - Gestion du joueur */
#include "player.h"
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
    printf("\nHello %s! Welcome to Supémon World!\n", player->name);
    printf("+--------------------------------+\n");
    printf("| Choose your starter Supémon:   |\n");
    printf("| 1 - Supmander                  |\n");
    printf("| 2 - Supasaur                   |\n");
    printf("| 3 - Supirtle                   |\n");
    printf("+--------------------------------+\n");
    printf("Enter 1, 2, or 3: ");

    int choice;
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            strcpy(player->team[0].name, "Supmander");
            player->team[0].hp = player->team[0].max_hp = 10;
            player->team[0].attack = player->team[0].base_attack = 1;
            break;
        case 2:
            strcpy(player->team[0].name, "Supasaur");
            player->team[0].hp = player->team[0].max_hp = 9;
            player->team[0].attack = player->team[0].base_attack = 1;
            break;
        case 3:
            strcpy(player->team[0].name, "Supirtle");
            player->team[0].hp = player->team[0].max_hp = 11;
            player->team[0].attack = player->team[0].base_attack = 1;
            break;
        default:
            printf("Invalid choice. Defaulting to Supmander.\n");
            strcpy(player->team[0].name, "Supmander");
            player->team[0].hp = player->team[0].max_hp = 10;
            player->team[0].attack = player->team[0].base_attack = 1;
    }
    player->supemon_count = 1;
}

void display_player_info(const Player *player) {
    printf("\n+----------------------------+\n");
    printf("| Player Info               |\n");
    printf("+----------------------------+\n");
    printf("Name: %s\n", player->name);
    printf("Supcoins: %d\n", player->supcoins);
    printf("Supémons owned: %d\n", player->supemon_count);
    for (int i = 0; i < player->supemon_count; i++) {
        printf(" - %s (HP: %d/%d)\n", player->team[i].name, player->team[i].hp, player->team[i].max_hp);
    }
    printf("+----------------------------+\n");
}
