/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio

Consigna:
Una empresa de recolecci�n y reciclado de pl�sticos requiere un sistema que les permita administrar
sus clientes y pedidos de recolecci�n. El programa contar� con el siguiente men�:
1) Alta de cliente: Se da de alta un cliente con nombre de la empresa, cuit direcci�n y localidad. Se generar�
un ID �nico para este cliente que se imprimir� por pantalla si el alta es correcta.
2) Modificar datos de cliente: Se ingresa el ID de cliente y se permitir� cambiar la direcci�n y la localidad.
3) Baja de cliente: Se ingresa el ID del cliente. Luego se preguntar� si se quiere confirmar la eliminaci�n.
4) Crear pedido de recolecci�n: Se imprimir�n los clientes por pantalla y se pedir� que se ingrese el ID de un
cliente existente y la cantidad de kilos totales que se recolectar�n del cliente. Se generar� un ID para el pedido y
el mismo quedar� en estado �Pendiente� hasta que se obtengan los residuos del cliente y se trasladen a la
empresa.
5) Procesar residuos: Se elegir� esta opci�n cuando los residuos que volvieron a la empresa se hayan
procesado y separado en los diferentes tipos de pl�stico que la empresa puede reciclar. Se imprimir�n los
pedidos por pantalla y se pedir� seleccionar el ID de uno de ellos. Luego deber�n ingresarse la cantidad de kilos
de pl�stico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que
se recolectaron. Por �ltimo, se marcar� al pedido como �Completado�.
6) Imprimir Clientes: Se imprimir� una lista de clientes con todos sus datos junto con la cantidad de �pedidos
de recolecci�n� que posee en estado �Pendiente�.
7) Imprimir Pedidos pendientes: Se imprimir� una lista de los pedidos que se encuentren en estado
�Pendiente� con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos a recolectar.
8) Imprimir Pedidos procesados: Se imprimir� una lista de los pedidos que se encuentren en estado
�Completado� con la informaci�n: Cuit del cliente, direcci�n del cliente, cantidad de kilos reciclados de cada tipo
de pl�stico.
9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
l
Los tipos de pl�stico que la empresa puede reciclar son:
� HDPE: Polietileno de alta densidad (Envases para l�cteos, perfumes, detergentes l�quidos, etc.)
� LDPE: Polietileno de baja densidad (Bolsas de congelaci�n de alimentos, tapas flexibles o bolsas de
basura.)
� PP: Polipropileno (Pl�sticos utilizados en la industria automovil�stica y en la construcci�n.)
El resto de la basura recolectada es desechada
Recomendaciones:
� Agregar al campo �isEmpty� a cada entidad.
� Generar un ID auto incrementable para cada entidad.
� Antes de comenzar, realizar un diagrama con las entidades, todos sus campos y c�mo se
relacionan.
� Antes de comenzar, realizar las funciones para imprimir cada uno de los arrays con todos sus
campos (sin relacionarlos con los otros arrays) para poder probar los ABM.
� Para poder probar los informes, realizar funciones que carguen con datos falsos los arrays de
las entidades, y ejecutarlas al comenzar el programa.
Nota 0: El sistema soportar� una capacidad m�xima de 100 clientes y 1000 pedidos
Nota 1: Se deber�n desarrollar bibliotecas por cada entidad (Cliente y Pedido) las cuales contendr�n las funciones (Alta,
Baja, Modificar, etc.).Los informes deber�n estar en una biblioteca aparte.
Nota 2: El c�digo deber� tener comentarios con la documentaci�n de cada una de las funciones y respetar las reglas de estilo
de la c�tedra.
============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define tamMenu 8
#define tamClientes 3 // modificado para pruebas
#define tamPedidos 4 // modificado para pruebas
#define tamTipoPlasticos 3
#define tamMenuProcesado 4

int main(void)
{
	setbuf(stdout, NULL);
	int opcion;
	eCliente listaClientes[tamClientes];
	ePedido listaPedidos[tamPedidos];
	ePlastico listaTipoPlasticos[tamTipoPlasticos] = {{1,"HDPE",1},{2,"LDPE",1},{3,"PP",1}};
	menu listaMenu[tamMenu] = {{1,"ALTA de Cliente"},{2,"MODIFICACION de Cliente"},{3,"BAJA de Cliente"},{4,"Crear pedido"},{5,"Procesar residuos"},{6,"Listar clientes"},{7,"Listar pedidos pendientes"},{8,"Listar pedidos procesados"},{9,"Listar pedidos pendientes por localidad"},{10,"Mostrar promedio de PP procesado"},{0,"Salir"}};
    menu listaMenuProcesado[] = {{1,"HDPE"},{2,"LDPE"},{3,"PP"},{4,"Cargar datos"},{0,"Salir de submenu"}};

	InicializarClientes(listaClientes, tamClientes);
	InicializarPedidos(listaPedidos, tamPedidos);

	do
	{
		MostrarMenu(listaMenu, tamMenu);
		opcion = PedirEntero("Ingrese una opcion: ");

		switch(opcion){
		case 1:
        AltaCliente(listaClientes,tamClientes);
        break;
        case 2:
        ModificarCliente(listaClientes,tamClientes);
        break;
        case 3:
        BajaCliente(listaClientes, tamClientes);
        break;
        case 4:
        AltaPedido(listaPedidos,tamPedidos, listaClientes, tamClientes);
        break;
        case 5:
        ProcesarResiduos(listaPedidos, tamPedidos, listaMenuProcesado, tamMenuProcesado);
        break;
        case 6:
        ImprimirClientes(listaPedidos, tamPedidos, listaClientes, tamClientes);
        break;
        case 7:
        ImprimirPedidosPendientes(listaPedidos, tamPedidos);
        break;
        case 8:
        ImprimirPedidosProcesados(listaPedidos, tamPedidos);
        break;
        case 9:
        ContarPedidosPendientesPorLocalidad(listaPedidos, tamPedidos);
        break;
        case 10:
        PromedioPPClientes(listaPedidos, tamPedidos);
        break;
	}

	}while(opcion != 0);

	return 0;
}
