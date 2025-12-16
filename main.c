#include "i_terminal.h"
#include "ventana.h"
#include "mapa.h"
#include "nave.h"

#include <stdio.h>
#include <time.h>

#include <video/edid.h>
#include <video/sisfb.h>
#include <video/uvesafb.h>

unsigned int ANCHO;
unsigned int ALTO;

// double velocidad;

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
        actualizarPos(&nav);
        actualizarMapa(&mapa, nav.posisionNave);

        actualizarPantalla(keyPresionado('-'));
        /**
         * Mostrar datos
        */
        // printf("\e[20;50H%.1f", velocidad);

        // sleep_ms(5);
        // printf("\e[2;2H%d, %d", pos.x, pos.y);
    }

    restaurarTerminal();

    return 0;
}