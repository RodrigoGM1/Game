#ifndef NAVE_H
#define NAVE_H

#include "vectores.h"
 
extern double velocidad;

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
    double velocidadActual;
    enum Puntos_Cadinales pc_nave;
    Vec2 posisionNave;
    Vecd2 vel_m_m;
} Nave;

Nave inciarNave(int posisionIx, int posisionIy);

void procesarEventos();
int keyPresionado(char key);
int sistemaVelocidad(double vel);
double setVelocidad();

// int actualizarPos(Vec2* pos);
int actualizarPos(Nave* nave);

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