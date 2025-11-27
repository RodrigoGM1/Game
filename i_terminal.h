#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <termios.h>
#include <stdlib.h>

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
void ocultarCursor();


//Comprobar si las funcion se queda

int keyPresionado(char key);