#include <stdio.h>
#include <stdlib.h>
#include "game.h"

item_t *init_item(void)
{
    item_t *item = malloc(sizeof(item_t));

    item->item_name = "Potion";
    item->heal = 20;

    return item;
}

player_t *createPlayer(char *name, char *password, pokemon_t **pokemon)
{
    player_t *player = malloc(sizeof(player_t));

    player->name = name;
    player->password = password;
    player->pokemon = pokemon;
    player->item = init_item();

    player->coordX=1;
    player->coordY=1;
    return player;
}


char *get_next(char *str, int *i)
{
    char *name = malloc(sizeof(char)* 50);
    int j = 0;
    int index = *i;
    for(j = 0; str[index] != ';' && str[index] != '\n' && str[index] != '\0'; index++) {
        name[j++] = str[index];
    }
    index++;
    *i = index;
    name[j] = '\0';
    return (name);
}

pokemon_t **init_pokemon(char *str)
{
    int i = 0;
    int len_pokemon = 0;
    pokemon_t **p;

    for(;str[i] != '\0';i++) {
        if (str[i] == '\n') {
            len_pokemon++;
        }
    }
    p = malloc(sizeof(pokemon_t*)*len_pokemon + 1);
    for(i = 0;str[i] != '\n';i++);
    i++;
    int x = 0;
    for (x = 0;str[i] != '\0';x++) {
        p[x] = malloc(sizeof(pokemon_t)*len_pokemon);
        p[x]->nom_du_pokemon = get_next(str, &i);
        p[x]->pv = atoi(get_next(str, &i));
        p[x]->attaque = atoi(get_next(str, &i));
        p[x]->defense = atoi(get_next(str, &i));
        p[x]->vitesse = atoi(get_next(str, &i));
        p[x]->type = get_next(str, &i);
    }
    p[x] = NULL;
    return (p);
}

void display_pokemon(pokemon_t **p)
{
    for (int i = 0; p[i] != NULL; i++) {
        printf("%s{\npv = %f\nattaque = %fdefense = %f\nvitesse = %f\ntype = %s\n}\n", p[i]->nom_du_pokemon, p[i]->pv, p[i]->attaque, p[i]->defense, p[i]->vitesse, p[i]->type);
    }
}

int check_input(int ac, char**av)
{
    if (ac != 3) {
        printf("Usage: ./my_rpg [player_pokemon_file] [rival_pokemon_file]\n");
        return 0;
    }
    if (av[1] == NULL || av[2] == NULL) {
        printf("Vous devez passer un fichier contenant les pokemon en parametre...\n");
        return 0;
    }
    return 1;
}

int main(int argc, char *argv[])
{
    int x, y;
    int i = 0;
    int game_res;

    if (!check_input(argc, argv))
        return 84;
    
    game_t *game = malloc(sizeof(game_t));
    pokemon_t **poke_player = init_pokemon(read_file(argv[1]));
    pokemon_t **poke_rival = init_pokemon(read_file(argv[2]));

    printf("Ongoing players creation...\n\n");
    game->player =  createPlayer("adam", "sozako", poke_player);
    game->rival =  createPlayer("tom", "hello", poke_rival);
    printf("Player and Rival created!\n\n");
    printf("Player's pokemon\n");
    display_pokemon(poke_player);
    printf("\n\nRival's pokemon\n");
    display_pokemon(poke_rival);

    

    int **map = setMap(25,30);

    int moveres=0;
    while(moveres!=-1)
    {
        moveres = move(game->player, map);
        if (moveres == 1)
        {
            printf("\n\nCombat triggered!\n\n");
            game_res = combat(game);
            print_battle_result(game, game_res);
        }
        printMap(map, game->player,25,30);

        printf("\n\nUtilisez ZQSD pour vous déplacer, P pour quitter");
    }
    
    free (map);
    return 0;
}
