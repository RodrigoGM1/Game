#include "i_terminal.h"
#include "ventana.h"
#include "mapa.h"
#include "nave.h"

#include <stdio.h>
#include <time.h>

unsigned int ANCHO;
unsigned int ALTO;

double velocidad;
// unsigned char utimaT;

int main(int argv, char* argc[])
{
    clock_t inicio = clock();
    double intervalo_ms = 1.0;
    clock_t intervalo = (clock_t)(intervalo_ms * CLOCKS_PER_SEC);

    iniciarTerminal();

    Mapa mapa = {"Sector1"};
    Nave nav = inciarNave((int)XMAPSEG / 2, (int)YMAPSEG / 2);

    cargarMapa(&mapa, nav.posisionNave);

    while (1){
        clock_t actual = clock();
        procesarEventos();
        iniciarVentana();
        // crearPantalla(ALTO, ANCHO);

        dibujarMapa(&mapa, nav.posisionNave, ALTO, ANCHO);

        // actualizarPos(&nav);

        actualizarMapa(&mapa, nav.posisionNave);

        /**
         * Mostrar datos
        */
        printf("\e[%d;%dH%.1f", 50, 55, velocidad);
        printf("\e[%d;%dH%d", 50, 50, actualizarPos(&nav));
        actualizarPantalla(keyPresionado('-'));

        if (actual - inicio >= intervalo) {
            inicio = actual;
        }
        printf("\e[%d;%dH%ld", 50, 55, inicio);
    
        // sleep_ms(5);
        // printf("\e[2;2H%d, %d", pos.x, pos.y);
    }

    restaurarTerminal();

    return 0;
}