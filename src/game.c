#include <stdlib.h>
#include <stdio.h>
#include "game.h"
#include "../lib/random_number.h"
#include "../lib/direction.h"
#include "../lib/keys.h"
#include "high_score.h"
#include "print_tools.h"

const int HEAD = 10;
const int MID = 20;
const int END = 30;

const int PRINT_TIME = 4;
const int HALF_PRINT_TIME = 1;


Game *game_init() {
    Game *game = (Game *) malloc(sizeof(Game));
    game_reset(game);
    return game;
}

void set_number(Game *game, int x, int y, int number_data) {
    game->numbers[y][x] = number_data;
}

void line_print(Game *game, int line_number) {
    int i, j;
    if (line_number == HEAD) {
        for (i = 0; i < 4; ++i) {
            printf("##");
            for (j = 0; j < PRINT_TIME; ++j) {
                printf("##");
            }
            printf("##");
        }
        printf("\n");
        return;
    }
    if (line_number == MID) {
        for (i = 0; i < 4; ++i) {
            printf("##");
            for (j = 0; j < PRINT_TIME; ++j) {
                printf("  ");
            }
            printf("##");
        }
        printf("\n");
        return;
    }
    if (line_number == END) {
        for (i = 0; i < 4; ++i) {
            printf("##");
            for (j = 0; j < PRINT_TIME; ++j) {
                printf("##");
            }
            printf("##");
        }
        printf("\n");
        return;
    }
    for (i = 0; i < N; ++i) {
        if (game->numbers[line_number][i] == 0) {
            printf("##  %s  ##", "    ");
            continue;
        }
        printf("##  %4d  ##", game->numbers[line_number][i]);
    }
    switch (line_number) {
        case 0:
            printf("   SCORE:  %d\n", game->score);
            break;
        case 1:
            printf("   HIGH:  %d\n", get_high_score());
            break;
        case 2:
            printf("\n");
            break;
        default:
            printf("\n");
            break;
    }
}

void game_reset(Game *game) {
    int x = get_random_number(N);
    int y = get_random_number(N);
    int i, j;
    for (i = 0; i < N; ++i) {
        for (j = 0; j < N; ++j) {
            if (i == y && j == x) {
                set_number(game, j, i, 2);
                continue;
            }
            set_number(game, j, i, 0);
        }
    }
    game->score = 0;
    if (get_high_score() > 999999 || get_high_score() < 0) {
        set_high_score(game->score);
    }
}

int is_fail(Game *game) {
    int x, y;
    for (y = 0; y < N; y++) {
        for (x = 0; x < N; x++) {
            if (game->numbers[x][y] == 0 ||
                (x > 0 && game->numbers[x][y] == game->numbers[x - 1][y]) ||
                (x < 3 && game->numbers[x][y] == game->numbers[x + 1][y]) ||
                (y > 0 && game->numbers[x][y] == game->numbers[x][y - 1]) ||
                (y < 3 && game->numbers[x][y] == game->numbers[x][y + 1])) {
                return 0;
            }
        }
    }
    system("clear");
    print_title();
    printf("                             GAME OVER!\n");
    printf("                           YOU SCORE: %d\n", game->score);
    printf("                           PRESS TAB TO EXIT!\n");
    while (get_direction() != EXIT);
    return 1;
}

void screen_print(Game *game) {
    system("clear");
    int i, j;

    if (game->score > get_high_score()) {
        set_high_score(game->score);
    }
    for (i = 0; i < N; ++i) {
        line_print(game, HEAD);
        for (j = 0; j < HALF_PRINT_TIME; ++j) {
            line_print(game, MID);
        }
        line_print(game, i);
        for (j = 0; j < HALF_PRINT_TIME; ++j) {
            line_print(game, MID);
        }
        line_print(game, END);
    }
}


void insert_random_number(Game *game) {
    int location, random_number = 2;
    int x, y;

    /* 统计现在到底有几个 0 */
    int x_array[N * N];
    int y_array[N * N];
    int index = 0;

    for (y = 0; y < N; ++y) {
        for (x = 0; x < N; ++x) {
            if (game->numbers[y][x] == 0) {
                x_array[index] = x;
                y_array[index] = y;
                ++index;
            }
        }
    }

    location = get_random_number(index);
    if (get_random_number(10) > 8) {
        random_number = 4;
    }

    set_number(game, x_array[location], y_array[location], random_number);
}

void slide(Game *game, int direction) {
    /* 标识这次滑动是否对状态造成了影响 */
    int change = 0;
    int x, y, x1, y1;

    if (direction == UP) {
        for (y = 0; y < N; ++y) {
            for (x = 0; x < N; ++x) {
                for (x1 = x + 1; x1 < 4; x1++) {
                    if (game->numbers[x1][y] > 0) {
                        if (game->numbers[x][y] <= 0) {
                            game->numbers[x][y] = game->numbers[x1][y];
                            game->numbers[x1][y] = 0;
                            x--;
                            change = 1;
                        } else if (game->numbers[x][y] == game->numbers[x1][y]) {
                            game->numbers[x][y] = game->numbers[x][y] * 2;
                            game->numbers[x1][y] = 0;
                            game->score += game->numbers[x][y];
                            change = 1;
                        }
                        break;
                    }
                }
            }
        }
    }

    if (direction == DOWN) {
        for (y = 0; y < N; y++) {
            for (x = N - 1; x >= 0; x--) {
                for (x1 = x - 1; x1 >= 0; x1--) {
                    if (game->numbers[x1][y] > 0) {
                        if (game->numbers[x][y] <= 0) {
                            game->numbers[x][y] = game->numbers[x1][y];
                            game->numbers[x1][y] = 0;
                            x++;
                            change = 1;
                        } else if (game->numbers[x][y] == game->numbers[x1][y]) {
                            game->numbers[x][y] = game->numbers[x][y] * 2;
                            game->numbers[x1][y] = 0;
                            game->score += game->numbers[x][y];
                            change = 1;
                        }
                        break;
                    }
                }
            }
        }
    }

    if (direction == LEFT) {
        for (x = 0; x < N; x++) {
            for (y = 0; y < N; y++) {
                for (y1 = y + 1; y1 < 4; y1++) {
                    if (game->numbers[x][y1] > 0) {
                        if (game->numbers[x][y] <= 0) {
                            game->numbers[x][y] = game->numbers[x][y1];
                            game->numbers[x][y1] = 0;
                            y--;
                            change = 1;
                        } else if (game->numbers[x][y] == game->numbers[x][y1]) {
                            game->numbers[x][y] = game->numbers[x][y] * 2;
                            game->numbers[x][y1] = 0;
                            game->score += game->numbers[x][y];
                            change = 1;
                        }
                        break;
                    }
                }
            }
        }
    }

    if (direction == RIGHT) {
        for (x = 0; x < N; x++) {
            for (y = N - 1; y >= 0; y--) {
                for (y1 = y - 1; y1 >= 0; y1--) {
                    if (game->numbers[x][y1] > 0) {
                        if (game->numbers[x][y] <= 0) {
                            game->numbers[x][y] = game->numbers[x][y1];
                            game->numbers[x][y1] = 0;
                            y++;
                            change = 1;
                        } else if (game->numbers[x][y] == game->numbers[x][y1]) {
                            game->numbers[x][y] = game->numbers[x][y] * 2;
                            game->numbers[x][y1] = 0;
                            game->score += game->numbers[x][y];
                            change = 1;
                        }
                        break;
                    }
                }
            }
        }
    }
    /* 如果这次滑动对状态有影响，随机在一个空格里插入一个数 */
    if (change) {
        insert_random_number(game);
    }
}

void game_resume(Game *game) {
    int direction;
    while (1) {
        /* 打印屏幕 */
        screen_print(game);
        /* 获取键盘输入的值 */
        direction = get_direction();
        /* 如果不是 ESC 键，那么继续游戏 */
        if (direction == EXIT) {
            return;
        }
        /* 将刚刚的键用于滑动 */
        slide(game, direction);

        if (is_fail(game)) {
            return;
        }
    }
}
