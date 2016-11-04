#include <stdio.h>
#include <stdlib.h>
#include "high_score.h"


void set_high_score(int score) {
    FILE *fp;
    if ((fp = fopen("/tmp/vi2048/.score.ini", "w+")) == NULL) {
        printf("can not open file!\n");
        printf("\033[?25h");
        exit(0);
    }
    fprintf(fp, "%d\n", score);
    fclose(fp);
}

int get_high_score() {
    FILE *fp;
    int score;
    if ((fp = fopen("/tmp/vi2048/.score.ini", "r")) == NULL) {
        return 0;
    }
    fscanf(fp, "%d\n", &score);
    fclose(fp);
    return score;
}
