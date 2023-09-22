#include <stdio.h>
#include "pokemon.h"
#include "player.h"
#include <stdbool.h>
#include <time.h>

int checkColisions (player *p, char dir, int **map)
{
    switch (dir)
    {
    case 'z':
        if (map[p->coordY-1][p->coordX] != "2")
        {
            return 0; //move ok
        }
        else
        {
            return 1;
        }
        break;
    case 's':
        if (map[p->coordY+1][p->coordX] != "2")
        {
            return 0; //move ok
        }
        else
        {
            return 1;
        }
        break;
    case 'q':
        if (map[p->coordY][p->coordX-1] != "2")
        {
            return 0; //move ok
        }
        else
        {
            return 1;
        }
        break;
    case 'd':
        if (map[p->coordY][p->coordX+1] != "2")
        {
            return 0; //move ok
        }
        else
        {
            return 1;
        }
        break;
    }
}

void highGrass(player *p, int **map)
{
    srand(time(NULL));
    if (map[p->coordY][p->coordX] == 1)
    {
        if (rand()<0.1)
        {
            //start fight
        }
    }
}

void move(player *p, int **map)
{
    char input = scanf("%c");

    switch (input)
    {
    case 'z':
        if (checkColisions(p, input, map) == 0)
        {
            p->coordY--;
            highGrass(p,map);
        }
        break;
    
    case 's':
        if(checkColisions(p, input, map) ==0)
        {
            p->coordY++;
            highGrass(p,map);
        }
        break;

    case 'q':
        if (checkColisions(p, input, map) ==0)
        {
            p->coordX--;
            highGrass(p,map);
        }
        break;

    case 'd':
        if (checkColisions(p, input, map)==0)
        {
            p->coordX++;
            highGrass(p,map);
        }
        break;
    default:
        break;
    }

    
}