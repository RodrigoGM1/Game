#include "i_terminal.h"
#include "ventana.h"
#include "mapa.h"

#include <stdio.h>

unsigned int ANCHO;
unsigned int ALTO;

int main(int argv, char* argc[])
{
    
    iniciarTerminal();

    // int mapa[XMAPSEG][YMAPSEG];

    // cargarMapa(mapa);

    Mapa mapa = {"Sector1"};
    Vec2 pos = {5, 5};
    cargarMapa(&mapa, &pos);

    /*
    for(int y = 1; y < XMAPSEG; y++){
        for(int x = 1; x < YMAPSEG; x++){
            if(mapa.mapa[y][x] == 0){
                printf(" ");
            }else if(mapa.mapa[y][x] == 1){
                printf("*");
            }
        }
        printf("\n");
    }
    */
    
    while (1){
        procesarEventos();
        
        iniciarVentana();

        crearPantalla(ALTO, ANCHO);
        actualizarPantalla(keyPresionado('-'));

        actualizarPos(&pos);

        crearCamara(ALTO, ANCHO, pos);
    
        // sleep_ms(10);
    }

    restaurarTerminal();

    return 0;
}