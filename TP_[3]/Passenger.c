/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"LinkedList.h"
#include "Passenger.h"
#include"Controller.h"

Passenger* Passenger_new(){

	Passenger* nuevoPasajero = NULL;
	nuevoPasajero=(Passenger*)malloc(sizeof(Passenger)*1);

	if(nuevoPasajero!=NULL){
		Passenger_setId(nuevoPasajero, 0);
		Passenger_setNombre(nuevoPasajero,"");
		Passenger_setApellido(nuevoPasajero,"");
		Passenger_setCodigoVuelo(nuevoPasajero, "");
		Passenger_setEstadoDeVuelo(nuevoPasajero, "");
		Passenger_setTipoPasajero(nuevoPasajero,0);
		Passenger_setPrecio(nuevoPasajero,0);
	}
	return nuevoPasajero;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* estadoDeVueloStr){

	Passenger* nuevoPasajero = NULL;
	if(idStr!=NULL && nombreStr!=NULL && tipoPasajeroStr!=NULL && apellidoStr!=NULL && precioStr!=NULL && codigoVueloStr!=NULL && estadoDeVueloStr != NULL){

		nuevoPasajero = Passenger_new();

		if(nuevoPasajero !=NULL){
			if( (Passenger_setId(nuevoPasajero, atoi(idStr)))==-1||
					(Passenger_setNombre(nuevoPasajero, nombreStr))==-1||
					(Passenger_setEstadoDeVuelo(nuevoPasajero, estadoDeVueloStr))==-1||
					(Passenger_setApellido(nuevoPasajero, apellidoStr))==-1||
					(Passenger_setPrecio(nuevoPasajero, atof(precioStr)))==-1||
					(Passenger_setCodigoVuelo(nuevoPasajero, codigoVueloStr))==-1||
					(Passenger_setTipoPasajero(nuevoPasajero ,atoi(tipoPasajeroStr)))==-1){
				Passenger_delete(nuevoPasajero);

				nuevoPasajero=NULL;
			}
			//printf("%-4d,%-13s,%-14s,%-8f,%-18s,%-14d,%-17s\n",nuevoPasajero->id,nuevoPasajero->nombre,nuevoPasajero->apellido,nuevoPasajero->precio,nuevoPasajero->estadoDeVuelo,nuevoPasajero->tipoPasajero,nuevoPasajero->codigoVuelo);
		}
	}
	return nuevoPasajero;
}
void Passenger_delete(Passenger* this){
	if(this!=NULL){
		free(this);
		this =NULL;
	}
}
int Passenger_setId(Passenger* this,int id){

	int retorno=-1;
	if(this !=NULL && id>0){
		this->id=id;
		retorno=1;
	}

	return retorno;

}
int Passenger_getId(Passenger* this,int* id){

	int retorno =-1;
	if(this!=NULL){
		*id=this->id;
		retorno =1;
	}

	return retorno;
}
int Passenger_setNombre(Passenger* this,char* nombre){

	int retorno =-1;

	if(this!=NULL && nombre !=NULL){

		strcpy(this->nombre,nombre);

		retorno =1;
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre != NULL){
		strcpy(nombre,this->nombre);
		retorno =1;
	}
	return retorno;
}
int Passenger_setApellido(Passenger* this,char* apellido){
	int retorno =-1;

	if(this!=NULL && apellido !=NULL){
		strcpy(this->apellido,apellido);
		retorno =1;
	}
	return retorno;

}
int Passenger_getApellido(Passenger* this,char* apellido){

	int retorno=-1;
	if(this!=NULL && apellido != NULL){
		strcpy(apellido,this->apellido);
		retorno =1;
	}
	return retorno;
}
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno =-1;

	if(this!=NULL && codigoVuelo !=NULL){
		strcpy(this->codigoVuelo,codigoVuelo);
		retorno =1;
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo){
	int retorno=-1;
		if(this!=NULL && codigoVuelo != NULL){
			strcpy(codigoVuelo,this->codigoVuelo);
			retorno =1;
		}
		return retorno;
}
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero){
	int retorno=-1;
	if(this !=NULL && tipoPasajero>0){
		this->tipoPasajero=tipoPasajero;
		retorno=1;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero){
	int retorno =-1;
	if(this!=NULL){
		*tipoPasajero=this->tipoPasajero;
		retorno =1;
	}

	return retorno;
}
int Passenger_setPrecio(Passenger* this,float precio){
	int retorno=-1;
	if(this !=NULL && precio>0){
		this->precio=precio;
		retorno=1;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio){
	int retorno =-1;
	if(this!=NULL){
		*precio=this->precio;
		retorno =1;
	}

	return retorno;
}
int Passenger_setEstadoDeVuelo(Passenger* this,char* estadoDeVuelo){
	int retorno =-1;

	if(this!=NULL && estadoDeVuelo !=NULL){
		strcpy(this->estadoDeVuelo,estadoDeVuelo);
		retorno =1;
	}
	return retorno;
}
int Passenger_getEstadoDeVuelo(Passenger* this,char* estadoDeVuelo){
	int retorno=-1;
	if(this!=NULL && estadoDeVuelo != NULL){
		strcpy(estadoDeVuelo,this->estadoDeVuelo);
		retorno =1;
	}
	return retorno;
}

void Passenger_showAPassenger(Passenger* pasajero,Type eTipo[]){
	char tipoDePasajero[128];
	MatchIds(pasajero,eTipo,tipoDePasajero);
	printf("%-4d|%-13s|%-14s|%-8.2f|%-18s|%-14s|%-17s|\n",pasajero->id,pasajero->nombre,pasajero->apellido,pasajero->precio,tipoDePasajero,pasajero->codigoVuelo,pasajero->estadoDeVuelo);
}

void MatchIds(Passenger* pasajero,Type eTipo[],char* tipoChar){
	for(int i=0;i<3;i++){
		if(pasajero->tipoPasajero == eTipo[i].idType){
			strcpy(tipoChar,eTipo[i].TypeDescription);
			break;
		}
	}
}
void setEstadoVuelo(char* estadoDeVuelo){
	int opcion;
	printf("Indique el estado de su vuelo:\n1.En Horario\n2.Demorado\n3.Cancelado\n");
	scanf("%d",&opcion);
	switch(opcion){
		case 1:
			strcpy(estadoDeVuelo,"En Horario");
		break;
		case 2:
			strcpy(estadoDeVuelo,"Demorado");
		break;
		case 3:
			strcpy(estadoDeVuelo,"Cancelado");
		break;
	}
}
int obtenerID()
{
	static int idIncremental = 1001;
	return idIncremental++;
}
void AddPassenger(Passenger* pasajero,int id, char*nombre, char*apellido, int tipoPasajero, char*codigoVuelo, char*estadoPasajero, float precio,LinkedList* pArrayListPassenger){


	if(id > 0 && nombre != NULL && apellido != NULL && tipoPasajero >0 && codigoVuelo != NULL && estadoPasajero != NULL && precio > 0 && pasajero!=NULL){

		Passenger_setId(pasajero, id);
		Passenger_setNombre(pasajero,nombre);
		Passenger_setApellido(pasajero,apellido);
		Passenger_setCodigoVuelo(pasajero,codigoVuelo);
		Passenger_setEstadoDeVuelo(pasajero,estadoPasajero);
		Passenger_setTipoPasajero(pasajero,tipoPasajero);
		Passenger_setPrecio(pasajero,precio);
		printf("%s",pasajero->estadoDeVuelo);
	}
}
int BuscarPorID(LinkedList* pArrayListPassenger,int* idABuscar){
	int retorno=-1;
	int id;
	Passenger* unPasajero;

	if(pArrayListPassenger !=NULL && idABuscar!=NULL){
		for(int i=0;i<ll_len(pArrayListPassenger);i++){
			unPasajero=(Passenger*)ll_get(pArrayListPassenger,i);
			Passenger_getId(unPasajero, &id);
			if(*idABuscar==id){
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int passenger_compareByPrecio(void* pasajero1, void* pasajero2)
{
	int retorno;
	float pas1;
	float pas2;
	if(pasajero1 != NULL && pasajero2 != NULL){

		Passenger_getPrecio((Passenger*)pasajero1, &pas1);
		Passenger_getPrecio((Passenger*)pasajero1, &pas2);
		if( pas1 > pas2)
		{
			retorno = -1;
		}
		else if(pas1 < pas2)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}

	}

	return retorno;
}
int passenger_compareById(void* pasajero1, void* pasajero2){

	int retorno;
	int pas1;
	int pas2;
	if(pasajero1 != NULL && pasajero2 != NULL){

		Passenger_getId((Passenger*)pasajero1, &pas1);
		Passenger_getId((Passenger*)pasajero1, &pas2);
		if( pas1 > pas2)
		{
			retorno = -1;
		}
		else if(pas1 < pas2)
		{
			retorno = 1;
		}
		else
		{
			retorno = 0;
		}

	}

	return retorno;

}

int passenger_compareByName(void* pasajero1, void* pasajero2){
	int retorno=-1;
	char nombreP1[128];
	char nombreP2[128];

	if(pasajero1 !=NULL && pasajero2 != NULL){
		Passenger_getNombre((Passenger*)pasajero1, nombreP1);
		Passenger_getNombre((Passenger*)pasajero2, nombreP2);
		if(strcmpi(nombreP1,nombreP2)<0){
			retorno =-1;
		}
		else{
			if(strcmpi(nombreP1,nombreP2)>0){
				retorno = 1;
			}
			else{
				retorno =0;
			}
		}
	}
	return retorno;
}
