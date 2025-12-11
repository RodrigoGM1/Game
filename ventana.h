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

#endif // VENTANA_H