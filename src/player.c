/*#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "pokemon.h"
#include "player.h"

player_t *createPlayer(char*name, char*password, pokemon_t**pokemon)
{
    player_t *player = malloc(sizeof(player));

    player->name= strdup(name);
    player->password= strdup(password);
    player->pokemon = pokemon;

    player->coordX = 1;
    player->coordY = 1;

    printf("%s\n",name);
    printf("%s",password);
    printf("\n");

    return player;
}
*/