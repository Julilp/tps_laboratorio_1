/*
 * funciones.h
 *
 *  Created on: 9 may. 2022
 *      Author: Julian lopez
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_
#define TAM 2000
#define LLENO 1
#define VACIO 0
#include "inputs.h"
#include "funcionesmias.h"
#include "typePassenger.h"
struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int idtypePassenger;
	int isEmpty;
	int idStatusFlight;
}typedef Passenger;


Passenger listaDePasajeros[TAM];
//------FUNCIONES OBLIGATORIAS------//
/// @brief
/// esta funcion lo que hace es recorrer el array cambiando el valor de isEmpy para que este quede en vacio
/// @param listaDePasajeros
/// @param tam
/// @return devuelve un entero para realizar una validacion
int initPassengers (Passenger listaDePasajeros[],int tam);
/// @brief
/// recibe valores de otra funcion y esta los carga dentro de la estructura de lista
/// @param listaDePasajeros
/// @param id
/// @param name
/// @param lastName
/// @param price
/// @param flycode
/// @param typePassenger
/// @param statusFlight
/// @return devuelve un entero para realizar una validacion
int addPassengers (Passenger listaDePasajeros[], int id,char name[],char lastName[],float price,char flycode[],int typePassenger, int statusFlight);
/// @brief
/// esta funcion busca el id ingresado por el usuario
/// @param listaDePasajeros
/// @param tam
/// @param id
/// @return devuelve un entero para realizar una validacion
int findPassengerById(Passenger listaDePasajeros[], int tam,int id);
/// @brief
/// esta funcion es el contrario al innit lo que hace es cambiar el empty de lleno a vacio asi logicamente desaparece del programa
/// @param listaDePasajeros
/// @param tam
/// @param id
/// @return devuelve un entero para realizar una validacion
int removePassenger(Passenger listaDePasajeros[], int tam, int id);
/// @brief
/// esta funcion realiza un burbujeo y ordena la lista de pasajeros
/// @param listaDePasajeros
/// @param len
/// @param order
/// @return
int sortPassengers(Passenger listaDePasajeros[], int len, int order);
/// @brief recorre la lista de pasajeros y devuelve la primer posicion vacia
///
/// @param listaDePasajeros
/// @param tam
/// @return
int buscarEspacioLibre(Passenger listaDePasajeros[], int tam);
/// @brief te muestra un sub menu para modificar todos los pasajeros
///
/// @param listaDePasajeros
/// @param tam
/// @return
int modificarPasajero(Passenger listaDePasajeros[],int tam);
/// @brief calcula el promedio y total de los datos
///
/// @param listaDePasajeros
/// @param tam
void totalYPromedio(Passenger listaDePasajeros[],int tam);
/// @brief  ordena a toda la lista por codigo de vuelo
///
/// @param listaDePasajeros
/// @param tam
void ordenarPorCodDeVuelo (Passenger listaDePasajeros[], int tam);
/// @brief pide todos los datos necesarios para cargar un pasajero y luego los pasa a otra funcion que los cargue
///
/// @param listaDePasajeros
/// @param tam
void pedirDatos (Passenger listaDePasajeros[],int tam);
/// @brief carga algunos pasajeros con datos ya asignados
///
/// @param listaDePasajeros
/// @param tam
void cargaForzada (Passenger listaDePasajeros[], int tam);
#endif /* ARRAYPASSENGER_H_ */
