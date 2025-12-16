#ifndef NAVE_H
#define NAVE_H

#include <time.h>

#include "vectores.h"

enum Puntos_Cadinales {
    ESTE,
    SURESTE,
    SUR,
    SUROESTE,
    OESTE,
    NORTE
};

typedef struct _nave {
    char* nombre;
    Vec2 posisionNave;
    enum Puntos_Cadinales pc_nave;
    float velocidadActual;
    float velocidaMax;
} Nave;

Nave inciarNave(int posisionIx, int posisionIy);

void procesarEventos();
int keyPresionado(char key);
int actualizarPos(Nave* nave);




/*
int sistemaVelocidad(double vel);
double setVelocidad();
int actualizarPos(Nave* nave, clock_t rejSeg);
double velocidadNave(Vecd2 velNave);
*/
#endif

// char nave[10][10] = 
// {
//     "             ",
//     "      ─╗     ",
//     "       ╠════╣",
//     "      ─╝     ",
//     "             ",
//     "             ",
// };