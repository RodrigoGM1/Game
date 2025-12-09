/**
 * Libreria para la creacion del mapa
*/

#include "mapa.h"

#include <stdio.h>

/**
 * Declaracion de estructiras
 * 
*/

/**
 * Variables globales
*/

int cargarMapa(Mapa* mapa, Vec2 pos)
{    
    for(int x = 1; x <= XMAPSEG; x++){
        for(int y = 1; y <= YMAPSEG; y++){
            if(x == 1 || y == 1 || x == XMAPSEG || y == YMAPSEG){
                mapa->mapa[x][y] = '*';
            }else{
                mapa->mapa[x][y] = ' ';
            }
        }
    }
    mapa->mapa[pos.x][pos.y] = '*';
    mapa->mapa[pos.x+1][pos.y] = '*';
    mapa->mapa[pos.x-1][pos.y] = '*';
    mapa->mapa[pos.x][pos.y+1] = '*';
    mapa->mapa[pos.x][pos.y-1] = '*';
    return 0;
}

void dibujarMapa(Mapa* mapa, Vec2 pos, int alto, int ancho)
{
    int xImapa = pos.x - (ancho / 2);
    int xFmapa = pos.x + (ancho / 2);
    int yImapa = pos.y - (alto / 2);
    int yFmapa = pos.y + (alto / 2);

    for(int x = 2, yM = yImapa; x < ancho - 2 || yM <= yFmapa - 3; x++, yM++){
        for(int y = 2, xM = xImapa; y < alto - 2 || xM <= xFmapa - 3; y++, xM++){
            // if(mapa->mapa[xM][yM] == 1){
            //     printf("\e[%d;%dH*", x, y);
            // }else if(mapa->mapa[xM][yM] == 0){
            //     printf("\e[%d;%dH ", x, y);
            // }
            printf("\e[%d;%dH%c", x, y, mapa->mapa[xM][yM]);
        }
    }
}

void actualizarMapa(Mapa* mapa, Vec2 pos)
{
    cargarMapa(mapa, pos);
}

// char nave[10][10] = 
// {
//     "             ",
//     "      ─╗     ",
//     "       ╠════╣",
//     "      ─╝     ",
//     "             ",
//     "             ",
// };