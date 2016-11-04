#ifndef VI_2048_GAME_H
#define VI_2048_GAME_H

#define N 4

typedef struct {
    int numbers[N][N];
    int score;
} Game;

Game *game_init();

void start_game(Game *game);

void game_reset(Game *game);

#endif // VI_2048_GAME_H
