#ifndef MAPA_H
#define MAPA_H

#define XMAPSEG 1000
#define YMAPSEG 1000

#include "vectores.h"

/**
 * Declaracion de estructiras
 * 
*/

typedef struct {
    char nombre[10];
    int mapa[XMAPSEG][XMAPSEG];
} Mapa;

/**
 * Variables globales
*/

int cargarMapa(Mapa* mapa, Vec2* pos);
// void dibujarMapa(Mapa* mapa, int alto, int ancho);
void dibujarMapa(Mapa* mapa, Vec2* pos, int alto, int ancho);
void actualizarMapa(Mapa* mapa, Vec2* pos);

#endif // MAPA_H