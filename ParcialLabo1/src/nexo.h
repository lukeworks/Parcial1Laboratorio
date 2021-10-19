/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio
============================================================================
 */

#ifndef NEXO_H_
#define NEXO_H_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "menu.h"
#include "clientes.h"
#include "pedidos.h"

void AltaPedido(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[],int tamClientes);
void MostrarClientes(eCliente listaClientes[],int tamClientes);
void MostrarPedidos(ePedido listaPedidos[],int tamPedidos);
void AltaCliente(eCliente listaClientes[],int tamClientes);
void ModificarCliente(eCliente listaClientes[],int tamClientes);
void BajaCliente(eCliente listaClientes[],int tamClientes);
int IngresarKgPorTipoPlastico(ePedido listaPedidos[],int tamPedidos,int IDPedido, menu listaMenuProcesado[], int tamMenuProcesado);
void ProcesarResiduos(ePedido listaPedidos[],int tamPedidos, menu listaMenuProcesado[], int tamMenuProcesado);
void ImprimirClientes(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[],int tamClientes);
void ImprimirPedidosPendientes(ePedido listaPedidos[],int tamPedidos);
void ImprimirPedidosProcesados(ePedido listaPedidos[],int tamPedidos);
int ContarPedidosPendientesPorLocalidad(ePedido listaPedidos[],int tamPedidos);
float PromedioPPClientes(ePedido listaPedidos[],int tamPedidos);

#endif /* NEXO_H_ */
