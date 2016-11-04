#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "../lib/keys.h"
#include "../lib/direction.h"
#include "print_tools.h"


void print_save_item(int select_num) {
    char select_array[] = {' ', ' ', ' '};
    int i;
    for (i = 0; i < 3; ++i) {
        if (i == select_num) {
            select_array[i] = '*';
        }
    }
    for (i = 0; i < 3; ++i) {
        printf("                             %c  Data%d\n", select_array[i], i);
    }
}

void print_main_item(int select_num) {
    char select_array[5];
    int i;
    for (i = 0; i < 5; ++i) {
        if (i == select_num) {
            select_array[i] = '*';
            continue;
        }
        select_array[i] = ' ';
    }
    printf("                            %c  RESUME\n", select_array[0]);
    printf("                            %c    NEW\n", select_array[1]);
    printf("                            %c   LOAD\n", select_array[2]);
    printf("                            %c   SAVE\n", select_array[3]);
    printf("                            %c   EXIT\n", select_array[4]);
}

void save_print(int select_num) {
    system("clear");
    print_title();
    print_save_item(select_num);
}

void main_print(int select_num) {
    system("clear");
    print_title();
    print_main_item(select_num);
}

int save_select() {
    int select_num = 0;
    save_print(select_num);
    int direction = get_direction();

    while (direction != ENTER) {
        if (direction == EXIT) {
            return EXIT;
        }
        if (direction == UP) {
            select_num--;
        }
        if (direction == DOWN) {
            select_num++;
        }
        if (select_num > 2) {
            select_num = 0;
        } else if (select_num < 0) {
            select_num = 2;
        }
        save_print(select_num);
        direction = get_direction();
    }
    return select_num;
}

int main_select() {
    int select_num = 0;
    main_print(select_num);
    int direction = get_direction();

    while (direction != ENTER) {

        if (direction == UP) {
            select_num--;
        }
        else if (direction == DOWN) {
            select_num++;
        }
        else if (direction == EXIT) {
            // exit
            return EXIT;
        }
        if (select_num > 4) {
            select_num = 0;
        }
        else if (select_num < 0) {
            select_num = 4;
        }

        main_print(select_num);
        direction = get_direction();
    }
    return select_num;
}

