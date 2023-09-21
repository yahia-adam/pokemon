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

char *read_file(char *filename);
void write_in_file(char *filename, char *content);

#endif/* __POKEMON_H__ */