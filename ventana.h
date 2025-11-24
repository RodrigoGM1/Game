#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

/**
 * Variables globales
*/

/**
 * Declaracion de estructiras
 * 
*/

void iniciarVentana();
void crearPantalla(int alto, int ancho);
int actualizarPantalla(int tec);
void cambioVentanaS(int sig);