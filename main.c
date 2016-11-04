#include <stdlib.h>
#include <stdio.h>
#include "src/game.h"
#include "src/menu.h"
#include "src/game_saving.h"

extern const int EXIT;

int main() {
    int select = 0;
    int load_result;
    /* 隐藏光标 */
    printf("\033[?25l");
    Game *game = game_init();
    while (1) {
        switch (main_select()) {
            case 0:
                start_game(game);
                continue;
            case 1:
                game_reset(game);
                start_game(game);
                continue;
            case 2:
                select = save_select();
                if (select == EXIT) {
                    continue;
                }
                load_result = game_load(select, game);
                if (load_result == EXIT) {
                    continue;
                }
                start_game(game);
                continue;
            case 3:
                select = save_select();
                if (select == EXIT) {
                    continue;
                }
                game_save(select, game);
                continue;
            default:
                system("clear");
                free(game);
                /* 显示光标 */
                return 0;
        }
    }
}
