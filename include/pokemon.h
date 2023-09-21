#ifndef __POKEMON_H__
    #define __POKEMON_H__

char *read_file(char *filename);


typedef struct pokemon
{
    char *nom_du_pokemon;
    float pv;
    float attaque;
    float defense;
    float vitesse;
    float type;
}pokemon;

#endif/* __POKEMON_H__ */