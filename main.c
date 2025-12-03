#include "i_terminal.h"
#include "ventana.h"
#include "mapa.h"

#include <stdio.h>

unsigned int ANCHO;
unsigned int ALTO;

int main(int argv, char* argc[])
{
    
    iniciarTerminal();
    
    Mapa mapa = {"Sector1"};
    Vec2 pos = {20, 20};

    cargarMapa(&mapa, &pos);

    while (1){
        procesarEventos();

        
        for(int y = 0; y < 30; y++){
            for(int x = 0; x < 30; x++){
                printf("%d", mapa.mapa[x][y]);
            }
            printf("\n");
        }
        
        iniciarVentana();

        crearPantalla(ALTO, ANCHO);

        // dibujarMapa(&mapa, pos, ALTO, ANCHO);
        
        // actualizarPantalla(keyPresionado('-'));
        // actualizarPos(&pos);
        // crearCamara(ALTO, ANCHO, pos);
    
        sleep_ms(15);
    }

    restaurarTerminal();

    return 0;
}