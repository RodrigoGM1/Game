#include "i_terminal.h"
#include "ventana.h"

// #include <stdio.h>
// #include <stdlib.h>
// #include <wchar.h>
// #include <locale.h>

unsigned int ANCHO;
unsigned int ALTO;

int main(int argv, char* argc[])
{
    Vec2 pos = {10, 10};

    iniciarTerminal();
    

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

/*
int main() {
    // Configura el locale para usar UTF-8 para que se impriman correctamente los caracteres anchos
    setlocale(LC_ALL, ""); 

    wchar_t mi_cadena[10][10];

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            mi_cadena[i][j] = L'*';
        }
    }

    while (1)
    {
        for(int i = 0; i < 10; i++){
            for(int y = 0; y < 10; y++){
                wprintf(L"%ls", mi_cadena);
            }
            printf("\n");
        }
    }
    
    return 0;
}
*/