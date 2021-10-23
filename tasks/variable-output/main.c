#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc,char **argv) {
    int i=0;

    char *HOME = getenv("HOME");
    char *USER = getenv("USER");

    printf("Home directory: \"%s\"\n",HOME);
    printf("User name: \"%s\"\n",USER);

    while (__environ[i] != NULL) {
        printf("%s\n",__environ[i]);
        i++;
    };
    return 0;
};