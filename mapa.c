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

/*
int cargarMapa(Mapa* mapa, Vec2* pos)
{
    for(int y = 0; y < XMAPSEG; y++){
        for(int x = 0; x < YMAPSEG; x++){
            if(y == 1 || x == 1 || y == XMAPSEG || x == YMAPSEG){
                mapa->mapa[y][x] = 1;
                continue;
            }
            mapa->mapa[y][x] = 0;
            // mapa->mapa[y][x] = 0;
        }
    }
    
    mapa->mapa[pos->x][pos->y] = 1;

    return 0;
}

void dibujarMapa(Mapa* mapa, Vec2* pos, int alto, int ancho)
{
    int iy = pos->x - (alto / 2);
    int fy = pos->x + (alto / 2);
    int ix = pos->y - (ancho / 2);
    int fx = pos->y + (ancho / 2);

    for(int yp = 2, y = iy; yp < alto || y < fy - 2; yp++, y++){
        for(int xp = 2, x = ix; xp < ancho || x < fx - 2; xp++, x++){
            if(mapa->mapa[y][x] == 1){
                printf("\e[%d;%dH*", yp, xp);
            }else if(mapa->mapa[y][x] == 0){
                printf("\e[%d;%dH ", yp, xp);
            }
        }
        printf("\n");
    }
}

void actualizarMapa(Mapa* mapa, Vec2* pos)
{
    for(int y = 0; y < XMAPSEG; y++){
        for(int x = 0; x < YMAPSEG; x++){
            mapa->mapa[y][x] = 0;
        }
    }

    mapa->mapa[pos->x][pos->y] = 1;
}
*/

int cargarMapa(Mapa* mapa, Vec2 pos)
{    
    for(int x = 1; x <= XMAPSEG; x++){
        for(int y = 1; y <= YMAPSEG; y++){
            if(x == 1 || y == 1 || x == XMAPSEG || y == YMAPSEG){
                mapa->mapa[x][y] = 1;
            }else{
                mapa->mapa[x][y] = 0;
            }
        }
    }
    mapa->mapa[pos.x][pos.y] = 1;
    return 0;
}

void dibujarMapa(Mapa* mapa, Vec2 pos, int alto, int ancho)
{
    /*
    int xImapa = pos.x - (ancho / 2);
    int xFmapa = pos.x + (ancho / 2);
    int yImapa = pos.y - (alto / 2);
    int yFmapa = pos.y + (alto / 2);

    for(int x = 2, yM = yImapa; x <= ancho - 1 || yM <= yFmapa - 2; x++, yM++){
        for(int y = 2, xM = xImapa; y <= alto - 1 || xM <= xFmapa - 2; y++, xM++){
            if(mapa->mapa[xM][yM] == 1){
                printf("\e[%d;%dH*", x, y);
            }else if(mapa->mapa[xM][yM] == 0){
                printf("\e[%d;%dH ", x, y);
            }
        }
    }
    */

    int xImapa = pos.x - (ancho / 2);
    int xFmapa = pos.x + (ancho / 2);
    int yImapa = pos.y - (alto / 2);
    int yFmapa = pos.y + (alto / 2);

    for(int y = 2, yM = yImapa; y <= alto - 1 || yM <= yFmapa - 2; y++, yM++){
        for(int x = 2, xM = xImapa; x <= ancho - 1 || xM <= xFmapa - 2; x++, xM++){
            if(mapa->mapa[xM][yM] == 1){
                printf("\e[%d;%dH*", x, y);
            }else if(mapa->mapa[xM][yM] == 0){
                printf("\e[%d;%dH ", x, y);
            }
        }
    }
    
    // for(int y = 1; y <= YMAPSEG; y++){
    //     for(int x = 1; x <= XMAPSEG; x++){
    //         if(mapa->mapa[x][y] == 1){
    //             printf("\e[%d;%dH*", 1 + y, 1 + x);
    //         }else if(mapa->mapa[x][y] == 0){
    //             printf("\e[%d;%dH ", 1 + y, 1 + x);
    //         }
    //     }
    //     printf("\n");
    // }
}

void actualizarMapa(Mapa* mapa, Vec2 pos)
{
    cargarMapa(mapa, pos);
}