/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio
============================================================================
 */

#ifndef MENU_H_
#define MENU_H_

struct
{
 int opcion;
 char mensaje[100];
}typedef menu;

void MostrarMenu(menu listaMenu[], int tamMenu); // lograr que arme un menu con numero de opcion y mensaje. QUE NO LLAME POR CADA OPCION!

// funcion validar opcion!
void ValidarOpcionMenu(char mensaje[], int min, int max, int opcion);

#endif /* MENU_H_ */
