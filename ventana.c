#include "ventana.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>

#include <stdint.h>

/**
 * Declaracion de estructiras
 * 
*/

struct winsize ventana;

/**
 * Variables globales
*/

// static char keyEstado[256] = {0};
extern unsigned int ANCHO;
extern unsigned int ALTO;

/*
void crearPantalla(int alto, int ancho)
{
    for(int y = 0; y < alto; y++){
        for(int x = 0; x < ancho; x++){
            printf("\e[%d;%dH\e[%dm█", y, x, rand() % 300);
        }
    }
}
*/

void iniciarVentana()
{
    ioctl(STDERR_FILENO, TIOCGWINSZ, &ventana);
    ANCHO = ventana.ws_col;
    ALTO = ventana.ws_row;
}

void crearPantalla(int alto, int ancho)
{   
    printf("\e[1;1H╔");
    printf("\e[1;%dH╗", ancho);
    for(int y = 2; y < alto; y++){
        printf("\e[%d;1H║", y);    
        printf("\e[%d;%dH║", y, ancho);
    }
    for(int x = 2; x < ancho; x++){
        printf("\e[1;%dH═", x);    
        printf("\e[%d;%dH═", alto, x);
    }
    printf("\e[%d;1H╚", alto);
    printf("\e[%d;%dH╝", alto, ancho);
}

int actualizarPantalla(int tec)
{
    signal(SIGWINCH, cambioVentanaS);
    if(tec){
        system("clear");
    }
    return 0;
}

void cambioVentanaS(int sig) {
    if (sig == SIGWINCH) {
        system("clear");
    }
}

void sleep_ms(int milliseconds)
{
    usleep(milliseconds * 1000);
    // printf("\e[0K");
    printf("\e[1J");
    printf("\e[0;0H");
    // system("clear");
}