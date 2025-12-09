#include "i_terminal.h"
#include "ventana.h"
#include "mapa.h"
#include "nave.h"

#include <stdio.h>

unsigned int ANCHO;
unsigned int ALTO;

int main(int argv, char* argc[])
{
    iniciarTerminal();
    
    Mapa mapa = {"Sector1"};
    Vec2 pos = {XMAPSEG / 2, YMAPSEG / 2};

    cargarMapa(&mapa, pos);

    while (1){
        procesarEventos();
        iniciarVentana();
        crearPantalla(ALTO, ANCHO);
        
        dibujarMapa(&mapa, pos, ALTO, ANCHO);
        actualizarPos(&pos);
        actualizarMapa(&mapa, pos);
        
        // actualizarPantalla(keyPresionado('-'));
    
        // sleep_ms(5);
        // printf("\e[2;2H%d, %d", pos.x, pos.y);
    }

    restaurarTerminal();

    return 0;
}