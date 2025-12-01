#include "i_terminal.h"
#include "ventana.h"
#include "mapa.h"

#include <stdio.h>

unsigned int ANCHO;
unsigned int ALTO;

int main(int argv, char* argc[])
{
    
    iniciarTerminal();

    Vec2 pos = {20, 20};

    while (1){
        procesarEventos();
        
        iniciarVentana();

        crearPantalla(ALTO, ANCHO);

        // dibujarMapa(&mapa, pos, ALTO, ANCHO);
        
        actualizarPantalla(keyPresionado('-'));
        actualizarPos(&pos);
        crearCamara(ALTO, ANCHO, pos);
    
        sleep_ms(15);
    }

    restaurarTerminal();

    return 0;
}