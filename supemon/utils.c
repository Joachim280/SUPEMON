#include "utils.h"
#include <stdlib.h> 
#include <stdio.h>
#include <string.h> 


void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    printf("\033[H\033[J"); 
#endif
}


void press_enter_to_continue() {
    printf("Press Enter to continue...");
    while (getchar() != '\n'); 
    getchar();
}


int random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}


void secure_input(char *buffer, int length) {
    fgets(buffer, length, stdin);
    buffer[strcspn(buffer, "\n")] = 0;
}
