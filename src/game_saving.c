#include <stdio.h>
#include <stdlib.h>
#include "game_saving.h"
#include "print_tools.h"
#include "../lib/keys.h"
#include "../lib/direction.h"
#include "utils.h"

void game_save(int save_num, Game *game) {
    FILE *fp;
    int i, j;
    char buffer[200];
    sprintf(buffer, "%s/.vi2048_save_game_%d", get_home_path(), save_num);
    fp = fopen(buffer, "w+");
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
    int numbers[N][N];
    int score;
    char buffer[200];
    sprintf(buffer, "%s/.vi2048_save_game_%d", get_home_path(), load_num);
    fp = fopen(buffer, "r");
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
            if (fscanf(fp, "%d", &numbers[i][j]) != 1) {
                fclose(fp);
                system("clear");
                print_title();
                printf("                           SAVE DATA BROKEN!\n");
                printf("                           PRESS TAB TO EXIT!\n");
                while (1) {
                    if (get_direction() == EXIT) {
                        return EXIT;
                    }
                }
            }
        }
    }
    if (fscanf(fp, "%d", &score) != 1) {
        fclose(fp);
        system("clear");
        print_title();
        printf("                           SAVE DATA BROKEN!\n");
        printf("                           PRESS TAB TO EXIT!\n");
        while (1) {
            if (get_direction() == EXIT) {
                return EXIT;
            }
        }
    }
    fclose(fp);

    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            game->numbers[i][j] = numbers[i][j];
        }
    }
    game->score = score;

    return 1;
}
