#include "i_terminal.h"
#include "ventana.h"

unsigned int ANCHO;
unsigned int ALTO;

void sleep_ms(int milliseconds)
{
    usleep(milliseconds * 1000);
    system("clear");
}

int main()
{
    iniciarTerminal();

    while (1){
        // printf("\e[0;0H");
        procesarEventos();
        iniciarVentana();

        crearPantalla(ALTO, ANCHO);

        // printf("%d, %d", ANCHO, ALTO);
        // printf("\e[10;10f ");

        // for(int i = 0; i < ALTO; i++){
        //     for(int y = 0; y < ANCHO; y++){
        //         if(i == 0 || i == ANCHO || y == 0 || y == ALTO){
        //             printf("*");
        //         }
        //         printf(" "); 
        //     }
        // }

        // sleep_ms(10);
        // printf("\e[0;0H");
    }

    restaurarTerminal();
    system("clear");
    return 0;
}