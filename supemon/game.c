/* game.c - Gestion du jeu principal */
#include "game.h"
#include "types.h"
#include "save.h"
#include "shop.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

void game_loop(Player *player) {
    int choice;


    if (load_game(player)) {
        printf("\nWelcome back, %s!\n", player->name);
    } else {
        printf("\nNo previous save found. Starting a new game.\n");
        init_player(player);
        choose_starter(player);
    }

    while (1) {
        clear_screen();
        printf("\n+-----------------------------+\n");
        printf("| Welcome to Supemon World!   |\n");
        printf("+-----------------------------+\n");
        printf("| 1 - Explore (Wild Battle)   |\n");
        printf("| 2 - Enter Shop              |\n");
        printf("| 3 - Supemon Center          |\n");
        printf("| 4 - View Player Info        |\n");
        printf("| 5 - Save and Quit           |\n");
        printf("+-----------------------------+\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start_wild_battle(player);
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
