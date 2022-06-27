/*
 * FuncionesMias.c
 *
 *  Created on: 9 may. 2022
 *      Author: Julian lopez
 */
#include "funcionesmias.h"
void espaciarLaConsola(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}


int validacionDeCaracteres (char cadena[])
{
	int size = strlen(cadena);
	int validacion=-1;
	for(int i=0;i<size;i++)
	{
		if (isdigit(cadena[i]))
		{
			validacion=0;
		}
	}
	return validacion;
}


 int obtenerID()
{
	static int idIncremental = 1000;
	return idIncremental++;
}




void totalYPromedio(Passenger listaDePasajeros[],int tam)
{
	float acumuladorPrecio=0;
	int contadorPrecio=0;
	float promedioVuelo;
	int contadorMayor=0;

	for(int i=0;i<tam;i++)
	{
		if(listaDePasajeros[i].isEmpty==LLENO)
		{
			acumuladorPrecio=acumuladorPrecio+listaDePasajeros[i].price;
			contadorPrecio++;
		}
	}

	promedioVuelo=acumuladorPrecio/contadorPrecio;


	for(int i=0;i<tam;i++)
	{
		if(listaDePasajeros[i].price > promedioVuelo && listaDePasajeros[i].isEmpty==LLENO)
		{
			contadorMayor++;
		}
	}


	printf("================================================================\n"
			"1) Total de todos los vuelos: %2.f\n"
			"2) Promedio de costo de pasaje: %2.f\n"
			"3) Numero de personas que superan el promedio: %d\n"
		   "================================================================\n"
			, acumuladorPrecio,promedioVuelo,contadorMayor);
}



