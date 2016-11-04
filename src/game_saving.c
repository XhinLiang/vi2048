#include <stdio.h>
#include <stdlib.h>
#include "game_saving.h"
#include "print_tools.h"
#include "../lib/keys.h"
#include "../lib/direction.h"

void game_save(int save_num, Game *game) {
    FILE *fp;
    int i, j;
    switch (save_num) {
        case 0:
            fp = fopen(".savegame1.ini", "w+");
            break;
        case 1:
            fp = fopen(".savegame1.ini", "w+");
            break;
        case 2:
            fp = fopen(".savegame2.ini", "w+");
            break;
        default:
            fp = NULL;
    }
    if (fp == NULL) {
        printf("can not open file!\n");
        /* 显示光标 */
        printf("\033[?25h");
        exit(0);
    }
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            fprintf(fp, "%d ", game->numbers[i][j]);
        }
    }
    fprintf(fp, "%d ", game->score);
    fclose(fp);
}

int load_game(int load_num, Game *game) {
    FILE *fp;
    int i, j;
    switch (load_num) {
        case 0:
            fp = fopen(".savegame0.ini", "r");
            break;
        case 1:
            fp = fopen(".savegame1.ini", "r");
            break;
        case 2:
            fp = fopen(".savegame2.ini", "r");
            break;
        default:
            fp = NULL;
    }

    if (fp == NULL) {
        system("clear");
        print_title();
        printf("                           CAN NOT OPEN FILE!\n");
        printf("                           PRESS TAB TO EXIT!\n");
        while (1) {
            i = get_direction();
            if (i == EXIT) {
                return EXIT;
            }
        }
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            fscanf(fp, "%d", game->numbers[i] + j);
        }
    }
    fscanf(fp, "%d", &(game->score));
    fclose(fp);
    return 1;
}


