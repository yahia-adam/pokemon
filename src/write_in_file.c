#include <stdio.h>
#include <stdlib.h>

void write_in_file(char *filename, char *content)
{
    FILE *file = fopen(filename, "a");
    fputs(content, file);
    fclose(file);
}
