#ifndef __POKEMON_H__
    #define __POKEMON_H__

typedef struct pokemon_s
{
    char *nom_du_pokemon;
    float pv;
    float attaque;
    float defense;
    float vitesse;
    char *type;
}pokemon_t;


int **setMap(int col, int line);
char *read_file(char *filename);
void write_in_file(char *filename, char *content);

#endif/* __POKEMON_H__ */