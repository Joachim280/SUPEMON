/* items.c - Gestion des objets */
#include "items.h"
#include <stdio.h>
#include <string.h>

void init_items(Item items[]) {
    strcpy(items[0].name, "Potion");
    items[0].effect_value = 5;
    items[0].price = 100;

    strcpy(items[1].name, "Super Potion");
    items[1].effect_value = 10;
    items[1].price = 300;

    strcpy(items[2].name, "Rare Candy");
    items[2].effect_value = 1;  // Augmente d'un niveau
    items[2].price = 700;
}
