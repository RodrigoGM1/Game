#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <termios.h>
#include <stdlib.h>
#include <sys/ioctl.h>

/**
 * Variables globales
*/

/**
 * Declaracion de estructiras
 * 
*/

extern struct termios viaja_terminal, nueva_terminal;
extern struct winsize ventana;

void iniciarTerminal();
void restaurarTerminal();

void procesarEventos();

//Comprobar si las funcion se queda

int keyPresionado(char key);

void iniciarVentana();

// void crearPantalla();