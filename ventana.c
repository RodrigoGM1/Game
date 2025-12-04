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

static char keyEstado[256] = {0};
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

/**
 * Manejador de eventos
*/

void procesarEventos()
{
    char c;
    for(int i = 0; i < 256; i++)
        keyEstado[i] = 0;
    while(read(STDERR_FILENO, &c, 1) > 0){
        // printf("Salida: %c\n", c);
        unsigned char uc = (unsigned char)c;
        keyEstado[uc] = 1;
    }
}

int keyPresionado(char key)
{
    return keyEstado[(unsigned char)key];
}

/**
 * Funciones para menajar el mapa y la ""Camara""
*/
/*
void dibujarMapa(Mapa* mapa, int alto, int ancho)
{  
    for(int yp = 2, y = 0; yp < alto || y < alto - 2; yp++, y++){
        for(int xp = 2, x = 0; xp < ancho || x < ancho - 2; xp++, x++){
            if(mapa->mapa[y][x] == 1){
                printf("\e[%d;%dH*", yp, xp);
            }else if(mapa->mapa[y][x] == 0){
                printf("\e[%d;%dH ", yp, xp);
            }
        }
        printf("\n");
    }
}
*/
void crearCamara(int alto, int ancho, Vec2 pos)
{
    for(int y = 2; y < ALTO; y++){
        for(int x = 2; x < ANCHO; x++){
            printf("\e[%d;%df ", y, x);
            printf("\e[%d;%df*", pos.y, pos.x);
        }
        printf("\n");
    }
}

int actualizarPos(Vec2* pos)
{   
    if(keyPresionado('w') || keyPresionado('W')){
        pos->x -= 1;
    }
    else if(keyPresionado('s') || keyPresionado('S')){
        pos->x += 1;
    }
    else if(keyPresionado('a') || keyPresionado('A')){
        pos->y -= 1;
    }
    else if(keyPresionado('d') || keyPresionado('D')){
        pos->y += 1;
    }
    
    return 0;
}