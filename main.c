#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <termios.h>
#include <stdlib.h>
#include <sys/ioctl.h>

#define MAPAANCHO 45
#define MAPAALTO 85

static struct termios viaja_terminal, nueva_terminal;
typedef struct jugador{
    int posx;
    int posy;
} Jugador;

static char keyestado[256] = {0};
char mapa[MAPAANCHO][MAPAALTO];
Jugador jugador;

void iniciar_terminal()
{
    tcgetattr(STDIN_FILENO, &viaja_terminal);
    nueva_terminal = viaja_terminal;
    nueva_terminal.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, & nueva_terminal);
    fcntl(STDIN_FILENO, F_SETFL, fcntl(STDIN_FILENO, F_GETFL, 0) | O_NONBLOCK);
    fflush(stdout);
    system("clear");
}

void restore_terminal()
{
    tcsetattr(STDIN_FILENO, TCSANOW, &viaja_terminal);
    // printf("terminal restores");
}

void procesar_eventos()
{
    char c;
    for(int i = 0; i < 256; i++)
        keyestado[i] = 0;
    while(read(STDIN_FILENO, &c, 1) > 0){
        // printf("salida: %c\n", c);
        unsigned char uc = (unsigned char)c;
        keyestado[uc] = 1;
    }
}

int key_precionar(char key) {
    return keyestado[(unsigned char)key];
}

void inicar_mapa(Jugador posJugador)
{
    /*
    for(int x = 1; x <= MAPAANCHO; x++){
        for(int y = 1; y <= MAPAALTO; y++){
            if(x == 1 || x == MAPAANCHO || y == 1 || y == MAPAALTO)
                mapa[x][y] = '*';
            else
                mapa[x][y] = ' ';
        }
    }
    */
    
    for(int x = 1; x <= MAPAANCHO; x++){
        for(int y = 1; y <= MAPAALTO; y++){
            if(x == 1 || x == MAPAANCHO || y == 1 || y == MAPAALTO)
                mapa[x][y] = '*';
        }
    }
    mapa[posJugador.posx][posJugador.posy] = '*';
}

void renderizar()
{
    /*
    for(int x = 1; x <= MAPAANCHO; x++){
        for(int y = 1; y <= MAPAALTO; y++){
            printf("%c", mapa[x][y]);
        }
        printf("\n");
    }
    */
    for(int x = 1; x <= MAPAANCHO; x++){
        for(int y = 1; y <= MAPAALTO; y++){
            printf("%c", mapa[x][y]);
        }
        printf("\n");
    }
}

void actualizar(Jugador* acJuagador)
{
    for(int x = 1; x <= MAPAANCHO; x++){
        for(int y = 1; y <= MAPAALTO; y++){
            if(x == 1 || x == MAPAANCHO || y == 1 || y == MAPAALTO){
                mapa[x][y] = '*';
                continue;
            }
            mapa[x][y] = ' ';
        }
    }
    mapa[acJuagador->posx][acJuagador->posy] = '*';  
}

Jugador iniciar_juagador(int posX, int posY)
{
    Jugador rJugador;
    rJugador.posx = posX;
    rJugador.posy = posY;
    return rJugador;
}

void eventos(Jugador* nJuagadorPos)
{   
    if(key_precionar('w') || key_precionar('W')){
        nJuagadorPos->posx -= 1;
    }
    if(key_precionar('s') || key_precionar('S')){
        nJuagadorPos->posx += 1;
    }
    if(key_precionar('a') || key_precionar('A')){
        nJuagadorPos->posy -= 1;
    }
    if(key_precionar('d') || key_precionar('D')){
        nJuagadorPos->posy += 1;
    }
    if(key_precionar('q') || key_precionar('Q')){
        nJuagadorPos->posx -= 1;
        nJuagadorPos->posy -= 1;
    }
    if(key_precionar('e') || key_precionar('E')){
        nJuagadorPos->posx -= 1;
        nJuagadorPos->posy += 1;
    }
    if(key_precionar('z') || key_precionar('Z')){
        nJuagadorPos->posx += 1;
        nJuagadorPos->posy -= 1;
    }
    if(key_precionar('c') || key_precionar('C')){
        nJuagadorPos->posx += 1;
        nJuagadorPos->posy += 1;
    }
}

int main()
{
    printf("\e[?25l");
    iniciar_terminal();
    
    Jugador jugador1 = iniciar_juagador(MAPAANCHO / 2, MAPAALTO / 2);

    // inicar_mapa(jugador1);
    while(1){
        printf("\e[1;1H");
        printf("\e[%iA", MAPAALTO + 2);
        procesar_eventos();
        eventos(&jugador1);

        actualizar(&jugador1);
        renderizar();
        printf("\e[%iA", MAPAANCHO + 2);

        sleep(0.5);
        // printf("\e[2J");
        // system("clear");
    }
    restore_terminal();
    // printf("\e[?25h");
    return 0;
}