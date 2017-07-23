#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "high_score.h"

void set_high_score(int score) {
    FILE *fp;
    char buffer[200];
    sprintf(buffer, "%s/.vi2048_score.ini", get_home_path());
    if ((fp = fopen(buffer, "w+")) == NULL) {
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
    char buffer[200];
    sprintf(buffer, "%s/.vi2048_score.ini", get_home_path());
    if ((fp = fopen(buffer, "r")) == NULL) {
        return 0;
    }
    fscanf(fp, "%d\n", &score);
    fclose(fp);
    return score;
}
