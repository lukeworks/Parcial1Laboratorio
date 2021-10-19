/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio
============================================================================
 */
#ifndef PEDIDOS_H_
#define PEDIDOS_H_

#include "clientes.h"

#define CARGADO 1
#define VACIO 0

//Defines para los tipos de plastico disponibles:
#define HDPE 1
#define LDPE 2
#define PP 3
// Defino estado de los pedidos:
#define PENDIENTE 0
#define PROCESADO 1

// Estructura para plasticos:
typedef struct{
	int id;
	int tipo;
	int isEmpty;
}ePlastico;

// Estructura para Pedidos:
typedef struct{
	int id;
	int estado;
	char descripcion[51];
	eCliente cliente;
	ePlastico tipoPlastico;
	float cantKilosTotales;
	float cantKilosHDPE;
	float cantKilosLDPE;
	float cantKilosPP;
	float cantKilosOtros;
	int isEmpty;
}ePedido;

int GenerarIDPedido(ePedido listaPedidos[],int tamPedidos, int min, int max);
void InicializarPedidos(ePedido listaPedidos[], int tamPedidos);
void InicializarTiposPlastico(ePedido listaPedidos[], int tamPedidos);

#endif /* PEDIDOS_H_ */
