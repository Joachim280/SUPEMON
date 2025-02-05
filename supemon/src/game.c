/* game.c - Gestion du jeu */
#include "game.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void game_loop(Player *player) {
    int choice;
    while (1) {
        clear_screen();
        printf("\n+-----------------------------+\n");
        printf("| Welcome to Supémon World!   |\n");
        printf("+-----------------------------+\n");
        printf("| 1 - Explore (Wild Battle)   |\n");
        printf("| 2 - Enter Shop              |\n");
        printf("| 3 - Supémon Center          |\n");
        printf("| 4 - View Player Info        |\n");
        printf("| 5 - Save and Quit           |\n");
        printf("+-----------------------------+\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You venture into the wild...\n");
                // start_battle(player, enemy); // À implémenter plus tard
                break;
            case 2:
                enter_shop(player);
                break;
            case 3:
                heal_supemons(player);
                break;
            case 4:
                display_player_info(player);
                break;
            case 5:
                save_game(player);
                printf("Game saved. Exiting...\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
        press_enter_to_continue();
    }
}
