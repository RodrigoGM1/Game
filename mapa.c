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
    // mapa->mapa[pos.x+1][pos.y] = '*';
    // mapa->mapa[pos.x-1][pos.y] = '*';
    // mapa->mapa[pos.x][pos.y+1] = '*';
    // mapa->mapa[pos.x][pos.y-1] = '*';
    return 0;
}

void dibujarMapa(Mapa* mapa, Vec2 pos, int alto, int ancho)
{
    /*
    int xImapa = pos.x - (ancho / 2);
    int xFmapa = pos.x + (ancho / 2);
    int yImapa = pos.y - (alto / 2);
    int yFmapa = pos.y + (alto / 2);

    for(int x = 2, yM = yImapa; x < ancho - 10 || yM <= yFmapa - 10; x++, yM++){
        for(int y = 2, xM = xImapa; y < alto - 10 || xM <= xFmapa - 10; y++, xM++){
            // if(mapa->mapa[xM][yM] == 1){
            //     printf("\e[%d;%dH*", x, y);
            // }else if(mapa->mapa[xM][yM] == 0){
            //     printf("\e[%d;%dH ", x, y);
            // }
            printf("\e[%d;%dH%c", x, y, mapa->mapa[xM][yM]);
        }
    }

    for(int yP = 2, yM = 1; yP <= alto - 10 || yM <= 20; yP++, yM++){
        for(int xP = 2, xM = 1; xP <= ancho - 35 || xM <= 40; xP++, xM++){
            // printf("\e[%d;%dH%c", yP, xP, mapa->mapa[xM][yM]);
            printf("\e[%d;%dH*", yP, xP);
        }
        printf("\n");
    }
    printf("\e[%d;%dH%d", alto - 9, 2, xImapa);
    printf("\e[%d;%dH%d", alto - 8, 2, xFmapa);
    printf("\e[%d;%dH%d", alto - 7, 2, yImapa);
    printf("\e[%d;%dH%d", alto - 6, 2, yFmapa);
    printf("\e[%d;%dHPosision x: %d", alto - 5, 2, pos.x);
    printf("\e[%d;%dHPosision y: %d", alto - 4, 2, pos.y);

    printf("\e[%d;%dHPosision x: %d", alto - 3, 2, ancho);
    printf("\e[%d;%dHPosision y: %d", alto - 2, 2, alto);
    */

    int xImapa = (ancho / 2) - pos.x;
    int xFmapa = (ancho / 2) + pos.x;
    int yImapa = (alto / 2) - pos.y;
    int yFmapa = (alto / 2) + pos.y;

   for(int yP = 2, yM = 1; yP <= 21 || yM <= 20; yP++, yM++){
        for(int xP = 2, xM = 1; xP <= 41 || xM <= 40; xP++, xM++){
            printf("\e[%d;%dH%c", yP, xP, mapa->mapa[xM][yM]);
        }
        printf("\n");
    }
    printf("\e[%d;%dH%d", alto - 9, 2, xImapa);
    printf("\e[%d;%dH%d", alto - 8, 2, xFmapa);
    printf("\e[%d;%dH%d", alto - 7, 2, yImapa);
    printf("\e[%d;%dH%d", alto - 6, 2, yFmapa);
    printf("\e[%d;%dHPosision x: %d", alto - 5, 2, pos.x);
    printf("\e[%d;%dHPosision y: %d", alto - 4, 2, pos.y);

    printf("\e[%d;%dHPantalla x: %d", alto - 3, 2, ancho);
    printf("\e[%d;%dHPantalla y: %d", alto - 2, 2, alto);
}

void actualizarMapa(Mapa* mapa, Vec2 pos)
{
    cargarMapa(mapa, pos);
}