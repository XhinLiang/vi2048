#include <stdio.h>

void print_lines(int count) {
    int i;
    for (i = 0; i < count; ++i) {
        printf("\n");
    }
}

void print_title() {
    print_lines(3);
    printf("             ██╗   ██╗██╗ ██████╗  ██████╗ ██╗  ██╗ █████╗ \n");
    printf("             ██║   ██║  ║ ╚════██╗██╔═█ ██╗██║  ██║██╔══██╗ \n");
    printf("             ██║   ██║██║ ██████╔╝██║█ ╔██║███████║╚█████╔╝ \n");
    printf("             ╚██╗ ██╔╝██║ ██╔═══╝ ██ █╔╝██║╚════██║██╔══██╗ \n");
    printf("              ╚████╔╝ ██║ ███████╗╚██████╔╝     ██║╚█████╔╝ \n");
    printf("               ╚═══╝  ╚═╝ ╚══════╝ ╚═════╝      ╚═╝ ╚════╝ \n");
    print_lines(3);
    printf("               h: left j:down k:up l:right tab:exit \n");
    print_lines(3);
}
