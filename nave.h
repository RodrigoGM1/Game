#ifndef NAVE_H
#define NAVE_H

#include "vectores.h"

typedef enum _Size_nave {
    NAVE_S,
    NAVE_M,
    NAVE_L,
    NAVE_XL
} Size_nave;

typedef struct _Nave {
    char* nombre;
    Size_nave tm_nave;
    Vec2 posInicial;
} Nave;

#endif