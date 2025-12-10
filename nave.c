#include "nave.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <unistd.h>

static char keyEstado[256] = {0};

Nave inciarNave(int posisionIx, int posisionIy)
{
    Nave inciarNav;

    inciarNav.nombre = "nave1";
    inciarNav.posisionNave.x = posisionIx;
    inciarNav.posisionNave.y = posisionIy;
    inciarNav.pc_nave = ESTE;

    return inciarNav;
}

void procesarEventos()
{
    char c;
    for(int i = 0; i < 256; i++)
        keyEstado[i] = 0;
    while(read(STDERR_FILENO, &c, 1) > 0){
        // printf("Salida: %c\n", c);
        // utimaT = (unsigned char)c;
        unsigned char uc = (unsigned char)c;
        keyEstado[uc] = 1;
    }
}

int keyPresionado(char key)
{
    return keyEstado[(unsigned char)key];
}
/*
int actualizarPos(Vec2* pos)
{
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
    return 0;
}
*/

int actualizarPos(Vec2* pos)
{
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

    else if(keyPresionado('z')){
        if(velocidad > -1.0){
            velocidad += -0.1;
        }else{
            velocidad = -1.0;
        }
    }else if(keyPresionado('x')){
        if(velocidad < 1.0){
            velocidad += 0.1;
        }else{
            velocidad = 1.0;
        }
    }

    return 0;
}