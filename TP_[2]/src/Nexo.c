/*
 * Nexo.c
 *
 *  Created on: 27 jun. 2022
 *      Author: Julian lopez
 */

#ifndef NEXO_C_
#define NEXO_C_
#include "Nexo.h"
void informar(Passenger listaDePasajeros[],eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam)
{
	char opcionChar[5];
	int r;
	int opcion;
	int order;

	printf(
					"==================================\n"
					"|      1-ORDENAR POR APELLIDO    |\n"
					"|      2-TOTAL Y PROMEDIO        |\n"
					"|      3-ORDENAR POR COD DE VUELO|\n"
					"|      4-MOSTRAR VUELOS ACTIVOS  |\n"
					"==================================\n"
					"\n"
					"Ingrese una opcion: ");

	scanf("%s", opcionChar);
	r=validarNumero(opcionChar);
	while(r==0)
		{
			printf("Ingrese una opcion valida (solo numeros): ");
			scanf("%s", opcionChar);
			r=validarNumero(opcionChar);
		}
	opcion=atoi(opcionChar);

	switch(opcion)
	{
	case 1:
		printf("ingrese como quiere ordenar la lista\n1 para la forma ascendente\n-1 para la forma descendente\ningrese la opcion: ");
		scanf("%d", &order);
		while(order !=1 && order != -1)
		{
			printf("ingrese como quiere ordenar la lista\n1 para la forma ascendente\n-1 para la forma descendente\ningrese la opcion: ");
			scanf("%d", &order);
		}
		sortPassengers( listaDePasajeros,TAM, order);
		printPassenger( listaDePasajeros, estadodevueloid, typeid,TAM);
		system("pause");
	break;
	case 2:
		 totalYPromedio( listaDePasajeros, TAM);
	break;
	case 3:
		 ordenarPorCodDeVuelo ( listaDePasajeros,  TAM);
		 printPassenger( listaDePasajeros, estadodevueloid, typeid,TAM);
	break;
	case 4:
		printFiltrados(listaDePasajeros,  TAM, estadodevueloid,  3,  typeid,  2);
	break;
	default:
		printf("Ingreso un numero incorrecto vuelva a intentarlo:");
	break;
	}

}
void mostrarUnPasajero(Passenger listaDePasajeros,eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam)
{

	int indexType;
	int idexStatus;

	if(listaDePasajeros.isEmpty==LLENO)
	{
		idexStatus=descripcionStatusFlight( listaDePasajeros, estadodevueloid, 3);
		indexType=descripcionTypePassengerr( listaDePasajeros, typeid,  2);

		printf(
				" |%2d   |       %12s      |        %8s       |       %10.2f   |      %10s     |        %15s         |        %13s     |\n"
				,listaDePasajeros.id ,listaDePasajeros.lastName,listaDePasajeros.name,listaDePasajeros.price,listaDePasajeros.flycode,typeid[indexType].typePassenger,estadodevueloid[idexStatus].StatusFlight);
	}

}
int descripcionStatusFlight(Passenger listaDePasajeros,eStatusFlight estadodevueloid[], int tam)
{
	int index;

	for(int i=0;i<tam;i++)
	{
		if(listaDePasajeros.idStatusFlight==estadodevueloid[i].idStatusFlight)
		{
			index=i;
			break;
		}
	}


	return index;
}
int descripcionTypePassengerr(Passenger listaDePasajeros,eTypePassenger typeid[], int tam)
{
	int index;

	for(int i=0;i<tam;i++)
	{
		if(listaDePasajeros.idtypePassenger==typeid[i].idtypePassenger)
		{
			index=i;
			break;
		}
	}


	return index;
}
void printFiltrados(Passenger listaDePasajeros[], int tam, eStatusFlight statusFlight[], int statusTam, eTypePassenger typePassenger[], int typeTam)
{
    for(int i=0; i<tam;i++)
    {
        if(listaDePasajeros[i].idStatusFlight == 1)
        {
            mostrarUnPasajero(listaDePasajeros[i], statusFlight,  typePassenger,TAM);
        }
    }
}
void printPassenger(Passenger listaDePasajeros[],eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam)
{
	printf( "  ________________________________________________________________________________________________________________________________________________________________\n "
			"|  ID   |      APELLIDO           |         NOMBRE        |      PRECIO        |     COD. VUELO      |      TIPO PASAJERO             |         ESTADO DE VUELO  |\n");
	printf( " |_______|_________________________|_______________________|____________________|_____________________|________________________________|__________________________|\n");

	for (int i=0;i<tam;i++)
	{
		mostrarUnPasajero(listaDePasajeros[i], estadodevueloid, typeid, tam);
	}
	printf(" |________________________________________________________________________________________________________________________________________________________________|\n");
	system("pause");
	espaciarLaConsola();

}
#endif /* NEXO_C_ */
