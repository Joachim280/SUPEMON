#include "shop.h"
#include "types.h"  
#include "items.h"  
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void enter_shop(Player *player) {
    int choice;
    while (1) {
        clear_screen();
        printf("\n+-----------------------------+\n");
        printf("| Welcome to the Supemon Shop! |\n");
        printf("+-----------------------------+\n");
        printf("| 1 - Buy Items               |\n");
        printf("| 2 - Sell Items              |\n");
        printf("| 3 - Exit Shop               |\n");
        printf("+-----------------------------+\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                buy_item(player);
                break;
            case 2:
                sell_item(player);
                break;
            case 3:
                printf("Leaving the shop...\n");
                return;
            default:
                printf("Invalid choice. Try again.\n");
        }
        press_enter_to_continue();
    }
}

void buy_item(Player *player) {
    Item shop_items[3];
    init_items(shop_items);
    
    printf("\nAvailable Items:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d - %s (Effect: +%d, Price: %d Supcoins)\n", i + 1, shop_items[i].name, shop_items[i].effect_value, shop_items[i].price);
    }
    printf("Enter the item number to buy (0 to cancel): ");
    int choice;
    scanf("%d", &choice);
    
    if (choice > 0 && choice <= 3) {
        Item selected = shop_items[choice - 1];
        if (player->supcoins >= selected.price) {
            player->supcoins -= selected.price;
            player->inventory[player->item_count++] = selected;
            printf("You bought %s!\n", selected.name);
        } else {
            printf("Not enough Supcoins!\n");
        }
    }
}

void sell_item(Player *player) {
    if (player->item_count == 0) {
        printf("You have no items to sell.\n");
        return;
    }
    
    printf("\nYour Items:\n");
    for (int i = 0; i < player->item_count; i++) {
        printf("%d - %s (Sell Price: %d Supcoins)\n", i + 1, player->inventory[i].name, player->inventory[i].price / 2);
    }
    printf("Enter the item number to sell (0 to cancel): ");
    int choice;
    scanf("%d", &choice);
    
    if (choice > 0 && choice <= player->item_count) {
        Item selected = player->inventory[choice - 1];
        player->supcoins += selected.price / 2;
        
        for (int i = choice - 1; i < player->item_count - 1; i++) {
            player->inventory[i] = player->inventory[i + 1];
        }
        player->item_count--;
        printf("You sold %s!\n", selected.name);
    }
}
