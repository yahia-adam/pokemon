#include <stdio.h>
#include "pokemon.h"
#include "player.h"
#include <stdbool.h>

int get_battle_status(pokemon *poke1, pokemon *poke2, player_t *player, player_t *rival, int check)
{
    int check = 0;
    int battle = 0;

    if (check != 0) {
            if (check == 1) {
                if (is_team_dead(rival) == 0) {
                    poke2 = select_pokemon(rival);
                    battle = 4;
                } else {
                    battle = 1;
                }
            } else if (check == 2) {
                if (is_team_dead(player) == 0) {
                    poke1 = select_pokemon(player);
                    battle = 4;
                } else {
                    battle = 2;
                }
            } else {
                if (is_team_dead(rival) == 0 && is_team_dead(player) == 0) {
                    poke1 = select_pokemon(player);
                    poke2 = select_pokemon(rival);
                    battle = 4;
                } else if (is_team_dead(rival) == 1 && is_team_dead(player) == 0) {
                    battle = 2;
                } else if (is_team_dead(rival) == 0 && is_team_dead(player) == 1) {
                    battle = 1;
                } else {
                    battle = 3;
                }
            }
        }

        return battle;
}

int check_pokemons(pokemon *poke1, pokemon *poke2)
{
    int check = 0;

    if (poke1->pv <= 0)
        check = 1;
    if (poke2->pv <= 0)
        check = 2;
    if (poke1->pv <= 0 && poke2->pv <= 0)
        check = 3;

    return check;
}

int combat(pokemon *poke1, pokemon *poke2)
{
    player_t *player = malloc(sizeof(player));
    player_t *rival = malloc(sizeof(player));
    int check = 0;
    int battle;

    while (true)
    {
        battle = 0;
        check = check_pokemons(poke1, poke2);
        battle = get_battle_status(poke1, poke2, player, rival, check);
        if (battle == 4)
            continue;
        else if (battle != 0)
            break;
    }
    
    return 0;
}

int main(void)
{
    printf("Combat triggered!\n");
    pokemon *poke1 = malloc(sizeof(pokemon));
    pokemon *poke2 = malloc(sizeof(pokemon));
    int game_res;
    
    game_res = combat(poke1, poke2);
    return 0;
}
