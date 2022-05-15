/*
 * funciones.c
 *
 *  Created on: 9 may. 2022
 *      Author: Julian lopez
 */


#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include <ctype.h>
#include <string.h>





int initPassengers (Passenger listaDePasajeros[],int tam)
{
	int resultado;
	if (tam < 0 || tam > 2000)
	{
		resultado =-1;
	}
	else
	{
		resultado=0;
	}
	for(int i=0;i<tam;i++)
	{
		listaDePasajeros[i].isEmpty =VACIO;
	}

	return resultado;
}
int addPassengers (Passenger listaDePasajeros[], int id,char name[],char lastName[],float price,char flycode[],int typePassenger, int statusFlight)
{
	int index;
	int rtrn=-1;

	index = buscarEspacioLibre(listaDePasajeros,TAM);
	if(index !=-1)
	{
		strcpy(listaDePasajeros[index].name,name);
		strcpy(listaDePasajeros[index].lastName,lastName);
		strcpy(listaDePasajeros[index].flycode,flycode);
		listaDePasajeros[index].price=price;
		listaDePasajeros[index].idtypePassenger=typePassenger;
		listaDePasajeros[index].id=id;
		listaDePasajeros[index].isEmpty=LLENO;
		listaDePasajeros[index].idStatusFlight=statusFlight;
		rtrn =0;
	}


	return rtrn;
}
int findPassengerById(Passenger listaDePasajeros[], int tam,int id)
{
	int index;
	index=-1;
	for(int i=0;i<tam;i++)
	{
		if(listaDePasajeros[i].id==id && listaDePasajeros[i].isEmpty==LLENO)
		{
			index=i;
			break;
		}
	}

	return index;
}
int removePassenger(Passenger listaDePasajeros[], int tam, int id)
{
	int index;
	int seguro=-1;
	int rtrn=-1;
	index=findPassengerById(listaDePasajeros,tam,id);
	if (index != -1)
	{
		printf( "PASAJERO A ELIMINAR:\n "
				"ID %d\n"
				"NOMBRE: %s\n"
				"APELLIDO: %s\n"
				"CODIGO DE VUELO: %s", listaDePasajeros[index].id,listaDePasajeros[index].name,listaDePasajeros[index].lastName,listaDePasajeros[index].flycode);
		printf("\n Seguro de borrar este pasajero? ingrese 1 para borrarlo: ");
		scanf("%d", &seguro);
		if(seguro ==1)
		{
			listaDePasajeros[index].isEmpty=VACIO;
			rtrn=0;
		}
		else
		{
			printf("se cancelo el borrar pasajero\n");
		}


	}
	else
	{
		printf("pasajero no encontrado \n");
	}

	return rtrn;
}
int sortPassengers(Passenger listaDePasajeros[], int tam, int order)
{
	int retorno=-1;


	Passenger typeAux;
	Passenger apellidoAux;

	for (int i=0;i<tam-1;i++)
	{
		for (int j=0;j<tam;j++)
		{
			if(strcmp(listaDePasajeros[i].lastName,listaDePasajeros[j].lastName)==order)
			{
				apellidoAux=listaDePasajeros[i];
				listaDePasajeros[i]=listaDePasajeros[j];
				listaDePasajeros[j]= apellidoAux;
			}
			else
			{
				if(strcmp(listaDePasajeros[i].lastName,listaDePasajeros[j].lastName)==0)
				{
					if(order<0)
					{
						if(listaDePasajeros[i].idtypePassenger < listaDePasajeros[j].idtypePassenger)
							{
									typeAux=listaDePasajeros[i];
									listaDePasajeros[i]=listaDePasajeros[j];
									listaDePasajeros[j]=typeAux;

							}
					}
					else
					{
						if(listaDePasajeros[i].idtypePassenger > listaDePasajeros[j].idtypePassenger)
							{
									typeAux=listaDePasajeros[i];
									listaDePasajeros[i]=listaDePasajeros[j];
									listaDePasajeros[j]=typeAux;
							}
					}
				}
			}
		}
	}
	return retorno;
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






/*
 *                            "1 5 1 9 8 4 4"
 * 							 49
 *
 *
 *
 *
 */







