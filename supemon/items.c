/* items.c - Gestion des objets */
#include "types.h"
#include "items.h"
#include "supemon.h"
#include <stdio.h>
#include <string.h>

void use_item(Player *player, Supemon *supemon, int item_index) {
    Item item = player->inventory[item_index];

    if (strcmp(item.name, "Potion") == 0) {
        supemon->hp += item.effect_value;
        if (supemon->hp > supemon->max_hp) {
            supemon->hp = supemon->max_hp;
        }
        printf("%s recovered %d HP!\n", supemon->name, item.effect_value);
    } 
    else if (strcmp(item.name, "Rare Candy") == 0) {
        level_up_supemon(supemon);
    } 
    else {
        printf("This item has no effect.\n");
        return;
    }


    for (int i = item_index; i < player->item_count - 1; i++) {
        player->inventory[i] = player->inventory[i + 1];
    }
    player->item_count--;

    printf("Used %s. Remaining items: %d\n", item.name, player->item_count);
}

void init_items(Item items[])
{
    strcpy(items[0].name, "Potion");
    items[0].effect_value = 5;
    items[0].price = 100;

    strcpy(items[1].name, "Super Potion");
    items[1].effect_value = 10;
    items[1].price = 300;

    strcpy(items[2].name, "Rare Candy");
    items[2].effect_value = 1;  
    items[2].price = 700;
}
