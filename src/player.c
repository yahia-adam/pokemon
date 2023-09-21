#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "pokemon.h"
#include "player.h"

player *createPlayer(char*name, char*password, pokemon**pokemon)
{
    player *player = malloc(sizeof(player));

    player->name= strdup(name);
    player->password= strdup(password);
    player->pokemon = pokemon;

    printf("%s\n",name);
    printf("%s",password);
    printf("\n");

    return player;
}
