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
/*
void dibujarMapa(Mapa* mapa, int alto, int ancho)
{  
    for(int yp = 2, y = 0; yp < alto || y < alto - 2; yp++, y++){
        for(int xp = 2, x = 0; xp < ancho || x < ancho - 2; xp++, x++){
            if(mapa->mapa[y][x] == 1){
                printf("\e[%d;%dH*", yp, xp);
            }else if(mapa->mapa[y][x] == 0){
                printf("\e[%d;%dH ", yp, xp);
            }
        }
        printf("\n");
    }
}
*/
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