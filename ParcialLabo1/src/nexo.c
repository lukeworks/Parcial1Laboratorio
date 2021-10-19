/*
============================================================================
Lucas Gonzalez Dall Ora - 1F 2021 Parcial 1 Laboratorio
============================================================================
 */
#include "nexo.h"

void AltaCliente(eCliente listaClientes[],int tamClientes){
  int i;
  int auxID=0;

  for (i = 0; i < tamClientes; i++)
  {
      if (listaClientes[i].isEmpty == VACIO)
      {
    	  fflush(stdin);
    	  PedirString("Ingrese el nombre de la empresa: ",listaClientes[i].empresa); // pido ingreso del nombre de la empresa
    	  listaClientes[i].cuit = PedirLongInt("Ingrese el CUIT (sin espacios ni barras): "); // pido ingreso del CUIT de la empresa
    	  fflush(stdin);
    	  PedirString("Ingrese la direccion de la empresa: ",listaClientes[i].direccion); // pido ingreso de la direccion de la empresa
    	  fflush(stdin);
    	  PedirString("Ingrese la localidad de la empresa: ",listaClientes[i].localidad); // pido ingreso de la localidad de la empresa
    	  auxID += 1;
    	  listaClientes[i].id = auxID;
    	  //listaClientes[i].id = GenerarIDCliente(tamClientes, 0, 100); // modificado para pruebas int GenerarIDPedido(ePedido listaPedidos[],int tamPedidos, int min, int max)
    	  listaClientes[i].isEmpty = CARGADO;
      }
      printf("Alta de cliente exitosa! La ID generada para este cliente es: %d\n", listaClientes[i].id);
      break;
  }
}

void ModificarCliente(eCliente listaClientes[],int tamClientes){
	MostrarClientes(listaClientes,tamClientes);
	int IDCliente = PedirEntero("Ingrese la ID del cliente: ");
	for (int i = 0; i < tamClientes; i++)
	{
		if (listaClientes[i].isEmpty != VACIO && listaClientes[i].id == IDCliente)
		{
			fflush(stdin);
			PedirString ("modifique la direccion:",listaClientes[i].direccion);
			fflush(stdin);
			PedirString ("modifique la localidad:",listaClientes[i].localidad);
			break;
		}
    }
}

void BajaCliente (eCliente listaClientes[],int tamClientes){
	MostrarClientes(listaClientes,tamClientes);
	char respuesta = 'n';
	int IDCliente = PedirEntero("Ingrese la ID del cliente: ");
	for (int i = 0; i < tamClientes; i++)
	{
		if (listaClientes[i].isEmpty != VACIO && listaClientes[i].id == IDCliente)
		{
			while(respuesta != 's')
			{
			    printf("Confirma que desea eliminar a este cliente?: (s = Sí, n = No)");
			    fflush(stdin);
			    scanf("%c", &respuesta);
			}
			listaClientes[i].isEmpty = VACIO;
			break;
		}
    }
}

void AltaPedido(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[],int tamClientes)
{
	MostrarClientes(listaClientes, tamClientes);
	int i;
	int auxID = 0;

	for (i = 0; i < tamPedidos; i++)
	{
		if (listaPedidos[i].isEmpty == VACIO)
		{
			int IDCliente = PedirEntero("Ingrese la ID del cliente: ");
			if(IDCliente == listaPedidos[i].cliente.id)
			{
				listaPedidos[i].cantKilosTotales = PedirEntero("Ingrese la cantidad de Kilos a recolectar: ");
		    	auxID += 1;
		    	listaPedidos[i].id = auxID;
				//listaPedidos[i].id = GenerarIDCliente(tamPedidos, 1, 1000); // modificado para pruebas int GenerarIDPedido(ePedido listaPedidos[],int tamPedidos, int min, int max)
				listaPedidos[i].estado = PENDIENTE;
				break;
			}
		 }else
		 {
			 printf("ID ingresada inexistente");
		 }
	 }
}

/*
 * 5) Procesar residuos: Se elegirá esta opción cuando los residuos que volvieron a la empresa se hayan
procesado y separado en los diferentes tipos de plástico que la empresa puede reciclar. Se imprimirán los
pedidos por pantalla y se pedirá seleccionar el ID de uno de ellos. Luego deberán ingresarse la cantidad de kilos
de plástico de cada uno de los 3 tipos que la empresa puede procesar que se obtuvieron de los kilos totales que
se recolectaron. Por último, se marcará al pedido como “Completado”.
*/
void ProcesarResiduos(ePedido listaPedidos[],int tamPedidos, menu listaMenuProcesado[], int tamMenuProcesado)
{
	MostrarPedidos(listaPedidos, tamPedidos);
	int IDPedidos = PedirEntero("Ingrese la ID del pedido: ");

	for(int i=0; i<tamPedidos; i++)
	{
		if(IDPedidos == listaPedidos[i].id)
		{
			IngresarKgPorTipoPlastico(listaPedidos, tamPedidos, IDPedidos, listaMenuProcesado, tamMenuProcesado);
		}
	}
}

void MostrarClientes(eCliente listaClientes[],int tamClientes)
{
    for (int i=0; i<tamClientes; i++)
    {
        printf ("%d %23s %11ld %4s %4s\n", listaClientes[i].id,listaClientes[i].empresa, listaClientes[i].cuit, listaClientes[i].direccion,listaClientes[i].localidad);
    }
}

void MostrarPedidos(ePedido listaPedidos[],int tamPedidos)
{
    for (int i=0; i<tamPedidos; i++)
    {
        printf ("%d %4s %23s %4d %.2f\n", listaPedidos[i].id, listaPedidos[i].estado, listaPedidos[i].cliente.empresa, listaPedidos[i].cliente.id, listaPedidos[i].cantKilosTotales);
    }
}

int IngresarKgPorTipoPlastico(ePedido listaPedidos[],int tamPedidos,int IDPedido, menu listaMenuProcesado[], int tamMenuProcesado){
    int opcion;
    int retorno;
    float AuxKg;

    for(int i =0; i<tamPedidos; i++)
    {
        if(listaPedidos[i].id == IDPedido)
        {
        	InicializarTiposPlastico(listaPedidos, tamPedidos);

        	AuxKg = listaPedidos[i].cantKilosTotales;
            do
            {
            printf("Por favor, clasifique los residuos por tipo de plastico (Kg Totales: %.2f Kg / Kg restantes = %.2f Kg):  \n",listaPedidos[i].cantKilosTotales,AuxKg);
            printf("Polietileno de alta densidad (HDPE):%6.2f Kg\n",listaPedidos[i].cantKilosHDPE);
            printf(": Polietileno de baja densidad (LDPE):%6.2f Kg\n",listaPedidos[i].cantKilosLDPE);
            printf("Polipropileno (PP):%6.2f Kg\n",listaPedidos[i].cantKilosPP);
            printf("BASURA:%6.2f Kg\n\n",listaPedidos[i].cantKilosOtros);

            if(AuxKg<0)
            {
                printf("Error! Por favor, ingrese datos validos..\n");
            }
            MostrarMenu(listaMenuProcesado, tamMenuProcesado);
            opcion = PedirEntero("Ingrese una opcion: ");// opcion=LoadInt("OPCION: ",0,4);
            switch(opcion)
            {
                case 1:
                listaPedidos[i].cantKilosHDPE = PedirFloat("Ingrese la cantidad de Kg de HDPE: ");
                break;
                case 2:
                listaPedidos[i].cantKilosLDPE = PedirFloat("Ingrese la cantidad de Kg de HDPE: ");
                break;
                case 3:
                listaPedidos[i].cantKilosPP = PedirFloat("Ingrese la cantidad de Kg de HDPE: ");
                break;
                case 4:
                if(AuxKg>0)
                {
                	listaPedidos[i].estado = PROCESADO;
                	strcpy(listaPedidos[i].descripcion,"COMPLETADO");
                	retorno=0;
                }
                break;
                case 0:
                listaPedidos[i].cantKilosHDPE = 0;
                listaPedidos[i].cantKilosLDPE = 0;
                listaPedidos[i].cantKilosPP = 0;
                retorno=-1;
                break;
            }
            AuxKg = listaPedidos[i].cantKilosTotales - listaPedidos[i].cantKilosHDPE - listaPedidos[i].cantKilosLDPE - listaPedidos[i].cantKilosPP;
            listaPedidos[i].cantKilosOtros = AuxKg; //kilos basura que no se pudo procesar

            }while((opcion!=0 && opcion!=4) || AuxKg<0);
        }
    }
  return retorno;
}
/*
 * 6) Imprimir Clientes: Se imprimirá una lista de clientes con todos sus datos junto con la cantidad de “pedidos
de recolección” que posee en estado “Pendiente”.
 */
void ImprimirClientes(ePedido listaPedidos[],int tamPedidos, eCliente listaClientes[],int tamClientes)
{
	for(int i = 0; i<tamClientes; i++)
	{
		if(listaPedidos[i].estado == PENDIENTE)
		{
			printf ("%d %23s %11ld %4s %4s %d %4s %.2f\n",listaClientes[i].id,listaClientes[i].empresa, listaClientes[i].cuit, listaClientes[i].direccion,listaClientes[i].localidad, listaPedidos[i].id, listaPedidos[i].estado, listaPedidos[i].cantKilosTotales);
		}
	}
}
/*
 * 7) Imprimir Pedidos pendientes: Se imprimirá una lista de los pedidos que se encuentren en estado
“Pendiente” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos a recolectar.
 */
void ImprimirPedidosPendientes(ePedido listaPedidos[],int tamPedidos)
{
	for(int i = 0; i<tamPedidos; i++)
	{
		if(listaPedidos[i].estado == PENDIENTE)
		{
			printf ("%11ld %4s %.2f\n", listaPedidos[i].cliente.cuit, listaPedidos[i].cliente.direccion, listaPedidos[i].cantKilosTotales);
		}
	}
}
/*
 * 8) Imprimir Pedidos procesados: Se imprimirá una lista de los pedidos que se encuentren en estado
“Completado” con la información: Cuit del cliente, dirección del cliente, cantidad de kilos reciclados de cada tipo
de plástico
 */
void ImprimirPedidosProcesados(ePedido listaPedidos[],int tamPedidos)
{
	for(int i = 0; i<tamPedidos; i++)
	{
		if(listaPedidos[i].descripcion == "COMPLETADO")
		{
			printf ("%11ld %4s %.2f %.2f %.2f\n", listaPedidos[i].cliente.cuit, listaPedidos[i].cliente.direccion, listaPedidos[i].cantKilosHDPE, listaPedidos[i].cantKilosLDPE, listaPedidos[i].cantKilosPP);
		}
	}
}

/*
 * 9) Ingresar una localidad e indicar la cantidad de pedidos pendientes para dicha localidad.
 */
int ContarPedidosPendientesPorLocalidad(ePedido listaPedidos[],int tamPedidos)
{
	int retorno;
	char localidad[51];

	for(int i = 0; i<tamPedidos; i++)
	{
		localidad = PedirString ("Ingrese la localidad:",listaPedidos[i].cliente.localidad);
		if(listaPedidos[i].estado == PENDIENTE && localidad == listaPedidos[i].cliente.localidad)
		{
			retorno++; // falta clasificar contadores por cada localidad existente...
		}
	}
	return retorno;
}

/*
10) Cantidad de kilos de polipropileno reciclado promedio por cliente. (kilos totales / cantidad de clientes)
 */
float PromedioPPClientes(ePedido listaPedidos[],int tamPedidos)
{
	int contadorClientes = 0;
	float AcumuladorKgTotales = 0;
	float promedio;
	for(int i = 0; i < tamPedidos; i++)
	{
		if(listaPedidos != NULL && tamPedidos > 0 && listaPedidos->cantKilosPP > 0 && listaPedidos[i].estado != PENDIENTE)
	    {
	    	AcumuladorKgTotales += listaPedidos[i].cantKilosPP;
	    	contadorClientes++;
	    }
	}
	promedio = (AcumuladorKgTotales / contadorClientes);

    return promedio;
}
