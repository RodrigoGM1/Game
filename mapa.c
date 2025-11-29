/**
 * Libreria para la creacion del mapa
*/

#include "mapa.h"

/**
 * Declaracion de estructiras
 * 
*/

/**
 * Variables globales
*/

int cargarMapa(Mapa* mapa, Vec2* pos)
{
    for(int y = 0; y < XMAPSEG; y++){
        for(int x = 0; x < YMAPSEG; x++){
            mapa->mapa[x][y] = 0;
        }
    }

    mapa->mapa[pos->x][pos->y] = 1;

    return 0;
}