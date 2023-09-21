#ifndef __POKEMON_H__
    #define __POKEMON_H__

typedef struct pokemon
{
    char *nom_du_pokemon;
    float pv;
    float attaque;
    float defense;
    float vitesse;
    char *type;
}pokemon;

void printMap(int **map, player *p, int col, int line);
void move(player *p, int **map);
int **setMap(int col, int line);
char *read_file(char *filename);
void write_in_file(char *filename, char *content);

#endif/* __POKEMON_H__ */