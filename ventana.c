#include "ventana.h"

/**
 * Variables globales
*/

int cambio = 0;

/**
 * Declaracion de estructiras
 * 
*/

/*
void crearPantalla(int alto, int ancho)
{
    for(int y = 0; y < alto; y++){
        for(int x = 0; x < ancho; x++){
            printf("\e[%d;%dH\e[%dm█", i, j, rand() % 300);
        }
    }
}
*/

void crearPantalla(int alto, int ancho)
{   
    printf("\e[0;0H╔");
    printf("\e[0;%dH╗", ancho);

    printf("\e[%d;0H╚", alto);
    printf("\e[%d;%dH╝", alto, ancho);
}

int actualizarPantalla(int alto, int ancho)
{
    int cAlto = 0;
    int cAncho = 0;

    if(cambio == 0){
        if(cAlto = alto || cAncho = ancho){
            
        }
        

        cambio = 1;
        printf("si hay cambio\n");
    }

    if(cambio == 1){
        printf("no hay cambio\n");
    }

    printf("%d, %d", cAlto, cAncho);
    return 0;
}