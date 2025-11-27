#include "ventana.h"
#include <signal.h>

#include <stdio.h>
#include <locale.h>
#include <stddef.h>
#include <wchar.h>

/**
 * Declaracion de estructiras
 * 
*/

struct winsize ventana;

/**
 * Variables globales
*/

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
    printf("\e[0;0H╔");
    printf("\e[0;%dH╗", ancho);
    for(int y = 2; y < alto; y++){
        printf("\e[%d;0H║", y);    
        printf("\e[%d;%dH║", y, ancho);
    }
    for(int x = 2; x < ancho; x++){
        printf("\e[0;%dH═", x);    
        printf("\e[%d;%dH═", alto, x);
    }
    printf("\e[%d;0H╚", alto);
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
    system("clear");
}

void m()
{
    // setlocale(LC_ALL, ""); 
    wchar_t mi_cadena[] = L" ·⋅∙•∘○◌◍◎●◉⬤";
    wprintf(L"%ls\n", mi_cadena);
}