#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char* argv[]) {

    if (argc > 1) {
        char* command = (char*)malloc(sizeof(char) * 1000);

        int i;
        for (i = 1; i < argc; i++) {
            strcat(command, argv[i]);
            strcat(command, " ");
        }

        system(command);
    }
}