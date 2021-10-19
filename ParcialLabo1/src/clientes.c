/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio
============================================================================
 */

#include "clientes.h"

void InicializarClientes(eCliente listaClientes[], int tam){
  for (int i = 0; i < tam; i++)
    {
	  listaClientes[i].isEmpty = VACIO;
    }
}



// Generates and prints 'count' random
// numbers in range [lower, upper].
int GenerarIDCliente(int tamClientes, int min, int max)
{
	int IDCreada;
	for (int i = 0; i < tamClientes; i++)
    {
		IDCreada = (rand() %(max - min + 1)) + min;
    }
	return IDCreada;
}
