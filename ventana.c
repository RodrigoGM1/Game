#include "ventana.h"

void crearPantalla(int alto, int ancho)
{
    for(int i = 0; i < alto; i++){
        for(int j = 0; j < ancho; j++){
            printf("\e[%d;%dH\e[%dm█", i, j, rand() % 300);
        }
    }
}