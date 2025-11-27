#include "i_terminal.h"
#include "ventana.h"

unsigned int ANCHO;
unsigned int ALTO;

int main(int argv, char* argc[])
{
    iniciarTerminal();
    

    while (1){
        m();
        procesarEventos();
        // iniciarVentana();

        // crearPantalla(ALTO, ANCHO);
        // actualizarPantalla(keyPresionado('-'));

    
        // for(int y = 2; y < ALTO - 5; y++){
        //     for(int x = 2; x < ANCHO - 5; x++){
        //         printf("\e[%d;%df ", y, x);
        //         printf("\e[%d;%df*", 10, 10);
        //     }
        //     printf("\n");
        // }
        // sleep_ms(10);
    }

    restaurarTerminal();
    return 0;
}
/*
int main() {
    // Configura el locale para usar UTF-8 para que se impriman correctamente los caracteres anchos
    setlocale(LC_ALL, ""); 

    wchar_t mi_cadena[] = L" ·⋅∙•∘○◌◍◎●◉⬤";
    while (1)
    {
        wprintf(L"%ls", mi_cadena);
    }
    
    return 0;
}
*/