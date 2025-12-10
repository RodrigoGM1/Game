#include "i_terminal.h"
#include "ventana.h"
#include "mapa.h"
#include "nave.h"

#include <stdio.h>

unsigned int ANCHO;
unsigned int ALTO;

float velocidad;
// unsigned char utimaT;

int main(int argv, char* argc[])
{
    iniciarTerminal();
    
    Mapa mapa = {"Sector1"};
    Nave nav = inciarNave((int)XMAPSEG / 2, (int)YMAPSEG / 2);

    cargarMapa(&mapa, nav.posisionNave);

    while (1){
        procesarEventos();
        iniciarVentana();
        // crearPantalla(ALTO, ANCHO);

        dibujarMapa(&mapa, nav.posisionNave, ALTO, ANCHO);
        actualizarPos(&nav.posisionNave);
        actualizarMapa(&mapa, nav.posisionNave);
        printf("\e[%d;%dH%.1f", 50, 50, velocidad);
        actualizarPantalla(keyPresionado('-'));
    
        // sleep_ms(5);
        // printf("\e[2;2H%d, %d", pos.x, pos.y);
    }

    restaurarTerminal();

    return 0;
}