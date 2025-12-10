#ifndef NAVE_H
#define NAVE_H

#include "vectores.h"

// extern unsigned char utimaT;
 
extern float velocidad;

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
} Nave;

Nave inciarNave(int posisionIx, int posisionIy);

void procesarEventos();
int keyPresionado(char key);
// int actualizarPos(Vec2* pos);
int actualizarPos(Vec2* pos);

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