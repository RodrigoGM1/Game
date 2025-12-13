#include "nave.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

static char keyEstado[256] = {0};

/**
 * Declaraciones de funciones internas
*/

Nave inciarNave(int posisionIx, int posisionIy)
{
    Nave inciarNav;

    inciarNav.nombre = "nave1";
    inciarNav.velocidadActual = 0.0;
    inciarNav.posisionNave.x = posisionIx;
    inciarNav.posisionNave.y = posisionIy;
    inciarNav.pc_nave = ESTE;
    inciarNav.vel_m_m.x = 1.5; // Velocidad de la nave en segundos maxima
    inciarNav.vel_m_m.y = 2.5; // Velocidad de la nave en segundos minima

    return inciarNav;
}

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

int sistemaVelocidad(double vel) {
    if(keyPresionado('z')){
        if(velocidad > -0.5)
            velocidad -= 0.1;
        else
            velocidad = -0.5;
    }else if(keyPresionado('x')){
        if(velocidad < 1.0)
            velocidad += 0.1;
        else
            velocidad = 1.0;
    }
    if(vel >= 0.1 || vel <= -0.1)
        return 1;
    return 0;
}

/*
int actualizarPos(Vec2* pos)
{
    if(sistemaVelocidad(velocidad)){
        if(keyPresionado('w') || keyPresionado('W')){
            pos->y -= 1;
        }
        else if(keyPresionado('s') || keyPresionado('S')){
            pos->y += 1;
        }
        else if(keyPresionado('a') || keyPresionado('A')){
            pos->x -= 1;
        }
        else if(keyPresionado('d') || keyPresionado('D')){
            pos->x += 1;
        }
    }

    return 0;
}
*/

int actualizarPos(Nave* nave, clock_t rejSeg)
{
    /*
    switch(nave->pc_nave){
        case ESTE:
            
            break;
        case SURESTE:
            break;
        case SUR:
            break;
        case SUROESTE:
            break;
        case OESTE:
            break;
        case NORTE:
            break;
    }
    */
   printf("\e[%d;%dH%ld", 50, 55, rejSeg / CLOCKS_PER_SEC);
   clock_t tiempoSeg = rejSeg / CLOCKS_PER_SEC;

    if(sistemaVelocidad(velocidad)){
        if(tiempoSeg == 1.0){
            nave->posisionNave.y -= 1;
        
        }

        // if(keyPresionado('w') || keyPresionado('W')){
        //     nave->posisionNave.y -= 1;
        // }
        else if(keyPresionado('s') || keyPresionado('S')){
            nave->posisionNave.y += 1;
        }
        else if(keyPresionado('a') || keyPresionado('A')){
            nave->posisionNave.x -= 1;
        }
        else if(keyPresionado('d') || keyPresionado('D')){
            nave->posisionNave.x += 1;
        }
    }

    return 0;
}

double setVelocidad() { return velocidad; }