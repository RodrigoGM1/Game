#include "i_terminal.h"

/**
 * Declaracion de estructiras
 * 
*/

struct termios viaja_terminal, nueva_terminal; 

/**
 * Variables globales
*/

static char keyEstado[256] = {0};

void iniciarTerminal()
{   
    system("clear");
    printf("\e[?25l");
    tcgetattr(STDIN_FILENO, &viaja_terminal);
    nueva_terminal = viaja_terminal;
    nueva_terminal.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, & nueva_terminal);
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL, 0) | O_NONBLOCK);
    fflush(stdout);
}

void restaurarTerminal()
{
    system("clear");
    tcsetattr(STDIN_FILENO, TCSANOW, &viaja_terminal);
    printf("\e[?25h");
}

void procesarEventos()
{
    char c;
    for(int i = 0; i < 256; i++)
        keyEstado[i] = 0;
    while(read(STDERR_FILENO, &c, 1) > 0){
        // printf("Salida: %c\n", c);
        // system("clear");
        unsigned char uc = (unsigned char)c;
        keyEstado[uc] = 1;
    }
}

//Comprobar si las funcion se queda

int keyPresionado(char key)
{
    return keyEstado[(unsigned char)key];
}