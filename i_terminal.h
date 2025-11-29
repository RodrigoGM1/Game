#ifndef I_TERMINAL_H
#define I_TERMINAL_H

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

// void procesarEventos();
void ocultarCursor();


//Comprobar si las funcion se queda

// int keyPresionado(char key);

#endif // I_TERMINAL_H