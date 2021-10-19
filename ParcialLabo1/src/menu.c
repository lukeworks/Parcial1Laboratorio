/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio
============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/**
 * \brief Muestra el menu de opciones en base a los parametros que se le pasen a la funcion.
 * \parametro tipo "menu" "listaMenu" = array del menu en base a la estructura "menu".
 * \parametro tipo int "tam" = tamaño del array listaMenu.
 */
void MostrarMenu(menu listaMenu[], int tamMenu)
{
	for (int i=0; i<tamMenu; i++)
	{
		printf ("%d - %s\n", listaMenu[i].opcion,listaMenu[i].mensaje);
	}
}
/*
void ValidarOpcionMenu(char mensaje[], int min, int max, int opcion)
{
	if(opcion < min || opcion > max)
	{

	}
}
*/
