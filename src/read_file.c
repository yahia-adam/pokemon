#include <stdio.h>
#include <stdlib.h>

char *read_file(char *filename)
{
    FILE *file = fopen(filename, "r");

    char *content = malloc(sizeof(char) * 10000);
    char c = fgetc(file);
    int i = 0;

    while ((c != EOF)) {
        content[i++] = c;
        c = fgetc(file);
    }
    fclose(file);
    content[--i] = '\0';
    return content;
}
