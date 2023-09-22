#ifndef __GAME_H__
    #define __GAME_H__

#include "pokemon.h"
#include "player.h"

typedef struct game_s
{
    player_t *player;
    player_t *rival;
} game_t;

int combat(game_t *game);
int get_player_action(player_t *player);
pokemon_t **select_pokemon(pokemon_t **pokemon);
pokemon_t **change_pokemon(pokemon_t **pokemon, int choice);
int run_away(player_t *player);
player_t *use_item(player_t *player);
game_t *attack(pokemon_t *offensive, pokemon_t *defensive, game_t *game, int player);
void print_battle_result(game_t *game, int game_res);

void printMap(int **map, player_t *p, int col, int line);
int move(player_t *p, int **map);


#endif /* __GAME_H__ */