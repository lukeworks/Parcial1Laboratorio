/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio
============================================================================
 */
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"

int PedirEntero(char mensaje[])
{
    int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}

long int PedirLongInt(char mensaje[])
{
    long int numeroIngresado;

    printf("%s", mensaje);
    scanf("%d",&numeroIngresado);

    return numeroIngresado;
}


float PedirFloat(char mensaje[])
{
    float numeroIngresado;

    printf("%s \n", mensaje);
    scanf("%f",&numeroIngresado);

    return numeroIngresado;
}

void PedirString(char mensaje[], char stringIngresado[])
{
    printf("%s \n", mensaje);
    //__fpurge(stdin);
    scanf("%[^\n]", stringIngresado);
}
