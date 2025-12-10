#ifndef VENTANA_H
#define VENTANA_H

/**
 * Variables globales
*/

/**
 * Declaracion de estructiras
 * 
*/
#include "vectores.h"
#include "mapa.h"

void iniciarVentana();
void crearPantalla(int alto, int ancho);
int actualizarPantalla(int tec);
void cambioVentanaS(int sig);
void sleep_ms(int milliseconds);

/**
 * Manejador de eventos
*/

// void procesarEventos();
// int keyPresionado(char key);

/**
 * Funciones para menajar el mapa y la ""Camara""
*/


// void crearCamara(int alto, int ancho, Vec2 pos);

// int actualizarPos(Vec2* pos);

#endif // VENTANA_H