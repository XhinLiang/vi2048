#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "direction.h"
#include "keys.h"

static struct termios newtermset, oldtermset;

void noecho(void) {
    tcgetattr(STDIN_FILENO, &oldtermset);
    newtermset = oldtermset;
    newtermset.c_lflag &= ~ICANON;
    newtermset.c_lflag &= ~ECHO;
    newtermset.c_cc[VMIN] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &newtermset);
}

void reset_term(void) {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldtermset);
}

int getch(void) {
    int ch;
    noecho();
    ch = getchar();
    reset_term();
    return ch;
}

int array_index(int *array, int array_length, int item) {
    int i;
    for (i = 0; i < array_length; ++i) {
        if (*(array + i) == item) {
            return i;
        }
    }
    return -1;
}

int get_direction() {
    int keys_array[] = {UP, DOWN, LEFT, RIGHT, EXIT, ENTER};
    while (1) {
        int ch = getch();
        if (array_index(keys_array, 6, ch) != -1) {
            return ch;
        }
    }
}
