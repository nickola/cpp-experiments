#include <stdio.h>
#include <stdlib.h>

// Library
#include "utilities.h"

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("C/C++ Experiments\n");
        printf("Usage: main <argument>\n");
        printf("If \"argument\" is 0, output is \"SUCCESS\". Otherwise, output is \"ERROR\".\n");
        exit(0);
    }

    // Function from "utilities.h"
    wait(5);

    // Success
    if (atoi(argv[1]) == 0) {
        printf("SUCCESS\n");
        exit(0);
    }

    // Error
    else {
        printf("ERROR\n");
        exit(1);
    }
}
