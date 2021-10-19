/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio
============================================================================
 */

#ifndef CLIENTES_H_
#define CLIENTES_H_

// Defino estado del cliente:
#define CARGADO 1
#define VACIO 0


typedef struct{
	int id;
	char empresa[51];
	long int cuit;
	char direccion[51];
	char localidad[51];
	int isEmpty;
}eCliente;

void InicializarClientes(eCliente listaClientes[], int tam);
int GenerarIDCliente(int tamClientes, int min, int max);

#endif /* CLIENTES_H_ */
