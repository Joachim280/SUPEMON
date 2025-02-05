/* items.h - Définition des objets */
#ifndef ITEMS_H
#define ITEMS_H

typedef struct {
    char name[20];  // Nom de l'objet
    int effect_value;  // Valeur de l'effet (ex: +HP, +Niveau)
    int price;  // Prix d'achat de l'objet
} Item;

// Initialise la liste des objets du jeu
void init_items(Item items[]);

#endif
