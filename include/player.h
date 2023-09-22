#ifndef __PLAYER_H__
    #define __PLAYER_H__

#include "pokemon.h"

typedef struct item_s
{
    char *item_name;
    float heal;
}item_t;

typedef struct player_s
{
    char *name;
    char *password;
    pokemon_t **pokemon;
    item_t *item;

    int coordX;
    int coordY;
} player_t;

#endif /* __PLAYER_H__ */
