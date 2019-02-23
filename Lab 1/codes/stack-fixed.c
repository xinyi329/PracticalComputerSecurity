/* stack-fixed.c */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int bof(char *str)
{
    // char buffer[24];
    char *buffer = (char *)malloc(sizeof(char) * (strlen(str) + 1));

    if(buffer == NULL) {
        return -1;
    }

    strcpy(buffer, str);

    free(buffer);
    buffer = NULL;

    return 1;
}

int main(int argc, char **argv)
{
    char str[517];
    FILE *badfile;

    badfile = fopen("badfile", "r");
    fread(str, sizeof(char), 517, badfile);
    bof(str);

    printf("Returned Properly\n");
    return 1;
}
