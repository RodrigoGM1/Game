#include "nave.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

static char keyEstado[256] = {0};
// double velocidad;

/**
 * Declaraciones de funciones internas
*/

// int sistemaVelocidad(double* velocidadActualNave);
// int sistemaDec();

Nave inciarNave(int posisionIx, int posisionIy)
{
    Nave inciarNav;

    inciarNav.nombre = "nave1";
    inciarNav.posisionNave.x = posisionIx;
    inciarNav.posisionNave.y = posisionIy;
    inciarNav.pc_nave = ESTE;
    inciarNav.velocidadActual = 0.0;
    inciarNav.velocidaMax = 2.5;

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
/*
int actualizarPos(Nave* nave)
{
    if(sistemaDec()){
        if(keyPresionado('w') || keyPresionado('W')){
            nave->posisionNave.y -= 1;
        }
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
*/
int actualizarPos(Nave* nave)
{
    double i;
    double max = 100000000 / nave->velocidadActual; 
    if(nave->velocidadActual != 0){

        // printf("\e[21;50HHola\n");
        
        for(i = 0; i < max + 1; i++){
            if(i == max){
                printf("\e[21;50HHola%d\n", 1);
                i = 0;
            }
        }
    }

    if(keyPresionado('x')){
        if(nave->velocidadActual < nave->velocidaMax - 0.1)
            nave->velocidadActual += 0.1;
        else
            nave->velocidadActual = nave->velocidaMax;
    }else if(keyPresionado('z')){
        if(nave->velocidadActual > -nave->velocidaMax + 0.1)
            nave->velocidadActual -= 0.1;
        else
            nave->velocidadActual = -nave->velocidaMax;
    }
    

    printf("\e[20;50H%.1f", nave->velocidadActual);
    // printf("\e[21;50H%ld", intervalo_ms);

    return 0;
}
/*
int sistemaDec()
{
    if(keyPresionado('x')){
        if(velocidad < 1.0)
            velocidad += 0.1;
        else
            velocidad = 1.0;
    }else if(keyPresionado('z')){
        if(velocidad > -1.0)
            velocidad -= 0.1;
        else
            velocidad = -1.0;
    }

    if(velocidad >= 0.1)
        return 1;
    else if(velocidad <= -0.1)
        return -1;
    return 0;
}
*/
/*
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

int actualizarPos(Nave* nave, clock_t rejSeg)
{
    
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
  

    clock_t intervalo = (clock_t)(velocidadNave(nave->vel_m_m) * CLOCKS_PER_SEC);
    // printf("\e[%d,%dH%ld", 50, 50, rejSeg);

    if(sistemaVelocidad(velocidad)){
        // if(keyPresionado('w') || keyPresionado('W')){
        //     nave->posisionNave.y -= 1;
        // }
        if (rejSeg >= intervalo) {
            nave->posisionNave.x += 1;
        }
        
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

double velocidadNave(Vecd2 velNave)
{
    return 2.5;
}
*/