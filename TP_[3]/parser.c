#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int validacion;
	char id[128];
	char nombre[128];
	char apellido[128];
	char precio[128];
	char tipoPasajero[128];
	char codigoVuelo[128];
	char estadoDeVuelo[128];

	Passenger* NuevoPasajero=NULL;

	if(pFile!=NULL && pArrayListPassenger !=NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" ,id,nombre,apellido,precio,estadoDeVuelo,tipoPasajero,codigoVuelo);
		while(!feof(pFile)){

			validacion =fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n" ,id,nombre,apellido,precio,tipoPasajero,codigoVuelo,estadoDeVuelo);
			//printf("%s,%s,%s,%s,%s,%s,%s",id,nombre,apellido,precio,estadoDeVuelo,tipoPasajero,codigoVuelo);
			if(validacion == 7){
				NuevoPasajero= Passenger_newParametros(id, nombre, tipoPasajero, apellido, precio, codigoVuelo,estadoDeVuelo);
				//printf("%s,%s",NuevoPasajero->nombre,NuevoPasajero->apellido);
				if(NuevoPasajero!=NULL){
					ll_add(pArrayListPassenger,NuevoPasajero);
					//printf("%-4d,%-13s,%-14s,%-8f,%-18s,%-14d,%-17s\n",NuevoPasajero->id,NuevoPasajero->nombre,NuevoPasajero->apellido,NuevoPasajero->precio,NuevoPasajero->estadoDeVuelo,NuevoPasajero->tipoPasajero,NuevoPasajero->codigoVuelo);

					retorno=1;
				}
			}
		}
	}
    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	//int validacion;
	Passenger* nuevoPasajero=NULL;

	if(pFile!=NULL && pArrayListPassenger !=NULL){
		while(!feof(pFile)){
			nuevoPasajero = Passenger_new();
			if(nuevoPasajero!=NULL){
				if(fread(nuevoPasajero , sizeof(Passenger) , 1 , pFile)){
					ll_add(pArrayListPassenger , nuevoPasajero);
					retorno=1;
				}
				else{
					printf("no se pudo cargar el pasajero");
					Passenger_delete(nuevoPasajero);
				}
			}



		}
	}

    return retorno;
}
