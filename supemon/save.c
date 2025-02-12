/* save.c - Gestion de la sauvegarde */
#include "save.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SAVE_FILE "save_data.txt"

void save_game(Player *player) {
    FILE *file = fopen(SAVE_FILE, "w");
    if (!file) {
        printf("Error: Unable to save game.\n");
        return;
    }
    
    fprintf(file, "%s\n", player->name);
    fprintf(file, "%d\n", player->supcoins);
    fprintf(file, "%d\n", player->supemon_count);
    
    for (int i = 0; i < player->supemon_count; i++) {
        Supemon *s = &player->team[i];
        fprintf(file, "%s\n%d %d %d %d %d %d %d %d %d %d %d %d\n",
                s->name, s->level, s->experience, s->hp, s->max_hp,
                s->attack, s->base_attack, s->defense, s->base_defense,
                s->evasion, s->base_evasion, s->accuracy, s->base_accuracy);
        
        
        for (int j = 0; j < MAX_MOVES; j++) {
            fprintf(file, "%s ", s->moves[j]);
        }
        fprintf(file, "\n"); 
    }
    
    fprintf(file, "%d\n", player->item_count);
    for (int i = 0; i < player->item_count; i++) {
        fprintf(file, "%s %d %d\n", player->inventory[i].name,
                player->inventory[i].effect_value, player->inventory[i].price);
    }
    
    fclose(file);
    printf("Game saved successfully.\n");
}

int load_game(Player *player) {
    FILE *file = fopen("save_data.txt", "r");
    if (!file) {
        printf(" Aucun fichier de sauvegarde trouvé !\n");
        return 0; 
    }

    printf(" Sauvegarde détectée ! Chargement...\n");

    fscanf(file, "%s %d %d", player->name, &player->supcoins, &player->supemon_count);

    for (int i = 0; i < player->supemon_count; i++) {
        fscanf(file, " %19s", player->team[i].name);

        printf("DEBUG: Loaded %s\n", player->team[i].name);

        fscanf(file, "%d %d %d %d %d %d %d %d %d %d %d %d",
               &player->team[i].level, &player->team[i].experience,
               &player->team[i].hp, &player->team[i].max_hp,
               &player->team[i].attack, &player->team[i].base_attack,
               &player->team[i].defense, &player->team[i].base_defense,
               &player->team[i].evasion, &player->team[i].base_evasion,
               &player->team[i].accuracy, &player->team[i].base_accuracy);
    
        for (int j = 0; j < MAX_MOVES; j++) {
            if (fscanf(file, " %19s", player->team[i].moves[j]) != 1) {
                player->team[i].moves[j][0] = '\0'; 
            }
        }

        printf("DEBUG: Loaded %s - Lvl: %d, HP: %d/%d, Atk: %d, Def: %d\n",
            player->team[i].name,
            player->team[i].level, player->team[i].hp, player->team[i].max_hp,
            player->team[i].attack, player->team[i].defense);
    }

    fclose(file);
    return 1; 
}
