#include <stdio.h>
#include <stdlib.h>
#include "pokemon.h"

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

pokemon **init_pokemon(char *str)
{
    int i = 0;
    int len_pokemon = 0;
    pokemon **p;

    for(;str[i] != '\0';i++) {
        if (str[i] == '\n') {
            len_pokemon++;
        }
    }
    p = malloc(sizeof(pokemon*)*len_pokemon + 1);
    for(i = 0;str[i] != '\n';i++);
    i++;
    int x = 0;
    for (x = 0;str[i] != '\0';x++) {
        p[x] = malloc(sizeof(pokemon)*len_pokemon);
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

void display_pokemon(pokemon **p)
{
    for (int i = 0; p[i] != NULL; i++) {
        printf("%s{\npv = %f\nattaque = %fdefense = %f\nvitesse = %f\ntype = %s\n}\n", p[i]->nom_du_pokemon, p[i]->pv, p[i]->attaque, p[i]->defense, p[i]->vitesse, p[i]->type);
    }
}

int main(int argc, char *argv[])
{
    int x, y;
    int i = 0;
    if (argv[1] == NULL) {
        printf("Vous devez passer un fichier contenant les pokemon en parametre...\n");
        return 0;
    }
    pokemon **pokemon_tab = init_pokemon(read_file(argv[1]));

    display_pokemon(pokemon_tab);
    return 0;
}
