#ifndef TYPES_H
#define TYPES_H

#define MAX_MOVES 4
#define MAX_SUPEMONS 6
#define MAX_ITEMS 10


typedef struct {
    char name[20];
    int level;
    int experience;
    int hp, max_hp;
    int attack, base_attack;
    int defense, base_defense;
    int evasion, base_evasion;
    int accuracy, base_accuracy;
    int speed;
    char moves[MAX_MOVES][20];
} Supemon;


typedef struct {
    char name[20];
    int effect_value;
    int price;
} Item;


typedef struct {
    char name[50];
    Supemon team[MAX_SUPEMONS];
    int supemon_count;
    int selected_supemon;
    int supcoins;
    Item inventory[MAX_ITEMS];
    int item_count;
} Player;

#endif
