#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

player_t *use_item(player_t *player)
{
    player->pokemon[0]->pv += player->item->heal;
    printf("%s use %s\n", player->pokemon[0]->nom_du_pokemon, player->item->item_name);
    printf("%s heal %f pv\n\n", player->pokemon[0]->nom_du_pokemon, player->item->heal);

    return player;
}

game_t *attack(pokemon_t *offensive, pokemon_t *defensive, game_t *game, int player)
{
    float damage = 0;

    damage = (offensive->attaque - defensive->defense) * 10;
    defensive->pv -= damage;
    printf("%s attack %s\n", offensive->nom_du_pokemon, defensive->nom_du_pokemon);
    printf("%s lose %f pv\n\n", defensive->nom_du_pokemon, damage);
    if (defensive->pv <= 0)
        printf("%s is dead\n\n", defensive->nom_du_pokemon);
    
    if (player == 2) {
        game->player->pokemon[0] = defensive;
        game->rival->pokemon[0] = offensive;
    } else {
        game->player->pokemon[0] = offensive;
        game->rival->pokemon[0] = defensive;
    }
    
    return game;
}

int run_away(player_t *player)
{
    int run = 0;

    srand(time(NULL));
    run = rand() % 2;

    return run;
}

pokemon_t **change_pokemon(pokemon_t **pokemon, int choice)
{
    pokemon_t *tmp = pokemon[0];

    pokemon[0] = pokemon[choice];
    pokemon[choice] = tmp;

    return pokemon;
}

pokemon_t **select_pokemon(pokemon_t **pokemon)
{
    int i = 1;
    int no_choice;
    int choice = 0;

    printf("Select a pokemon:\n");
    while (pokemon[i] != NULL) {
        if (pokemon[i]->pv > 0)
            printf("%d. %s\n", i, pokemon[i]->nom_du_pokemon);
        i++;
    }
    no_choice = i;
    printf("%d. Return\n", no_choice);
    scanf("%d", &choice);
    if (choice == no_choice)
        return pokemon;

    return change_pokemon(pokemon, choice);
}

int get_player_action(player_t *player)
{
    int choice = 0;

    printf("1. Attack\n");
    printf("2. Select a pokemon\n");
    printf("3. Bag\n");
    printf("4. Run Away\n\n");
    scanf("%d", &choice);
    if (choice == 1) {
        return 1;
    }
    if (choice == 2) {
        return 2;
    } else if (choice == 3) {
        return 3;
    } else if (choice == 4) {
        return 4;
    }

    return get_player_action(player);
}