#include <stdio.h>
#include <stdlib.h>



player createPlayer(char*name,char*password,pokemon**pokemon){
     cr *player=malloc(sizeof(cr));
    player->name=malloc(sizeof(char)*strlen(name));
    player->password= malloc(sizeof(char*strlen(password));
    player->pokemon*=pokemon;
    strcpy(player->pokemon,pokemon);
    player-> pokemon=pokemon;

    printf("%s\n",name);
    printf("%s",passeword);
    printf("%");

    return player;
}
    




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
