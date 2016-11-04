#include <time.h>
#include <stdlib.h>

int get_random_number(int x) {
    srand((unsigned) time(0));
    return rand() % x;
}
