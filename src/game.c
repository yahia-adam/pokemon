#include <stdio.h>
#include <stdbool.h>
#include "game.h"

void print_battle_result(game_t *game, int game_res)
{
    if (game_res == 1)
        printf("\n\n%s won the battle!\n", game->player->name);
    else if (game_res == 2)
        printf("\n\n%s won the battle!\n", game->rival->name);
    else if (game_res == 3)
        printf("\n\nYou ran away!!!!!!!!\n");
}

int fastest_pokemon(pokemon_t *pokemon1, pokemon_t *pokemon2)
{
    if (pokemon1->vitesse >= pokemon2->vitesse)
        return 1;
    return 2;
}

int is_team_dead(player_t *team)
{
    int i = 0;
    int count = 0;

    for (; team->pokemon[i] != NULL; i++) {
        if (team->pokemon[i]->pv <= 0)
            count++;
    }
    if (i == count)
        return 1;

    return 0;
}

int get_battle_status(player_t *player, player_t *rival, int check)
{
    int battle = 0;

    if (check != 0) {
            if (check == 1) {
                if (is_team_dead(player) == 0) {
                    player->pokemon = select_pokemon(player->pokemon);
                    battle = 4;
                } else
                    battle = 2;
            } else if (check == 2) {
                if (is_team_dead(rival) == 0) {
                    rival->pokemon = select_pokemon(rival->pokemon);
                    battle = 4;
                } else
                    battle = 1;
            }
        }

        return battle;
}

int check_pokemons(pokemon_t *poke1, pokemon_t *poke2)
{
    int check = 0;

    if (poke1->pv <= 0)
        check = 1;
    if (poke2->pv <= 0)
        check = 2;

    return check;
}

int combat(game_t *game)
{
    int check = 0;
    int battle;
    int action;

    while (true)
    {
        battle = 0;
        check = check_pokemons(game->player->pokemon[0], game->rival->pokemon[0]);
        battle = get_battle_status(game->player, game->rival, check);
        if (battle == 4)
            continue;
        else if (battle != 0)
            break;
        action = get_player_action(game->player);
        if (action == 4)
            if (run_away(game->player) == 1) {
                battle = 3;
                break;
            }
        if (fastest_pokemon(game->player->pokemon[0], game->rival->pokemon[0]) == 1) {
            if (action == 1)
                game = attack(game->player->pokemon[0], game->rival->pokemon[0], game, 1);
            else if (action == 2)
                game->player->pokemon = select_pokemon(game->player->pokemon);
            else
                game->player = use_item(game->player);
            game = attack(game->rival->pokemon[0], game->player->pokemon[0], game, 2);
        } else {
            game = attack(game->rival->pokemon[0], game->player->pokemon[0], game, 2);
            if (action == 1)
                game = attack(game->player->pokemon[0], game->rival->pokemon[0], game, 1);
            else if (action == 2)
                game->player->pokemon = select_pokemon(game->player->pokemon);
            else
                game->player = use_item(game->player);
        }
    }
    
    return battle;
}
