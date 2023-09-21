#include <stdio.h>
#include "pokemon.h"
#include "player.h"
#include <stdbool.h>

int attack (pokemon *attacker, pokemon *victim)
{
    int typeBonus = 1;
    
    int lostPv = (attacker->attaque - victim->defense) * typeBonus;

    victim->pv -= lostPv;

    if (victim->pv < 0)
    {
        victim->pv = 0;
        return 1 ; //ko
    }

    return 0; //pas ko
}

int getAction()
{
    return 0;
}

int fight(player *pl, pokemon *rivalPoke)
{
    pokemon *actualPoke = pl->pokemon[0];
    while(true) {
        switch (getAction())
        {
        case 1: //fight
            if (actualPoke->vitesse >= rivalPoke->vitesse)
            {
                if (attack(actualPoke, rivalPoke) == 1) {
                    return 1; //combat gagné
                }
                else {
                    if (attack(rivalPoke, actualPoke) == 1)
                    {
                        //changement pokemon
                    }
                }
            }
            else
            {
                if (attack(rivalPoke, actualPoke) == 1)
                {
                    //changement pokemon
                }
                else
                {
                    if (attack(actualPoke, rivalPoke) == 1) {
                        return 1; //combat gagné
                    }
                }
            }
            break;

        default:
            break;
        }
    }
   
}