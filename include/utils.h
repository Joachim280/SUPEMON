/* utils.h - Fonctions utilitaires */
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>

// Efface l'écran (compatible Windows et Linux)
void clear_screen();

// Pause en attendant une entrée de l'utilisateur
void press_enter_to_continue();

// Génère un nombre aléatoire entre min et max
int random_int(int min, int max);

// Sécurise la saisie utilisateur (évite les erreurs d'input)
void secure_input(char *buffer, int length);

#endif
