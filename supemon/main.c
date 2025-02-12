#include "game.h"
#include "player.h"
#include "supemon.h"
#include "center.h"
#include <stdio.h>

int main() {
    Player player;

    if (load_game(&player)) {
        printf(" Sauvegarde détectée ! Bienvenue, %s !\n", player.name);
    } else {
        printf(" Aucune sauvegarde trouvee. Creation d'un nouveau joueur.\n");
        init_player(&player);
        choose_starter(&player);
    }

    game_loop(&player);
    return 0;
}
