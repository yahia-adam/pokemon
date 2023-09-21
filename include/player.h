#ifndef __PLAYER_H__
    #define __PLAYER_H__

#include "pokemon.h"

typedef struct player
{
 char*name;
 char*password;
 pokemon **pokemon;

} player;

#endif /* __PLAYER_H__ */