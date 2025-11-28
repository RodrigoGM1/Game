#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <signal.h>

/**
 * Variables globales
*/

/**
 * Declaracion de estructiras
 * 
*/

typedef struct{
    int x;
    int y;
} Vec2;

void iniciarVentana();
void crearPantalla(int alto, int ancho);
int actualizarPantalla(int tec);
void cambioVentanaS(int sig);
void sleep_ms(int milliseconds);

void crearCamara(int alto, int ancho, Vec2 pos);

int actualizarPos(Vec2* pos);

// Manejador de eventos

void procesarEventos();
int keyPresionado(char key);

// void m();