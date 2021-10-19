/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio
============================================================================
 */
#include "pedidos.h"

// Generates and prints 'count' random
// numbers in range [lower, upper].
int GenerarIDPedido(ePedido listaPedidos[],int tamPedidos, int min, int max)
{
	int IDCreada;
	for (int i = 0; i < tamPedidos; i++)
    {
		IDCreada = (rand() %(max - min + 1)) + min;
    }
	return IDCreada;
}

void InicializarPedidos(ePedido listaPedidos[], int tamPedidos){
  for (int i = 0; i < tamPedidos; i++)
    {
	  listaPedidos[i].isEmpty = VACIO;
    }
}

void InicializarTiposPlastico(ePedido listaPedidos[], int tamPedidos){
	for (int i = 0; i < tamPedidos; i++)
	{
    	listaPedidos[i].cantKilosHDPE = VACIO;
    	listaPedidos[i].cantKilosLDPE = VACIO;
    	listaPedidos[i].cantKilosPP = VACIO;
	}
}
