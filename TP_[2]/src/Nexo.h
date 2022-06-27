/*
 * Nexo.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Julian lopez
 */

#ifndef NEXO_H_
#define NEXO_H_
#include "ArrayPassenger.h"
#include "funcionesmias.h"
#include "inputs.h"
#include "statusflight.h"
#include "typePassenger.h"
/// @brief
/// repite una funcion para poder mostrar todos los pasajeros
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param typeid
/// @param tam
void printPassenger(Passenger listaDePasajeros[],eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam);
/// @brief muestra un pasajero en consola
///
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param typeid
/// @param tam
void mostrarUnPasajero(Passenger listaDePasajeros,eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam);
/// @brief devuelve la posicion de la descripcion del tipo de pasajero
///
/// @param listaDePasajeros
/// @param typeid
/// @param tam
/// @return
int descripcionTypePassengerr(Passenger listaDePasajeros,eTypePassenger typeid[], int tam);
/// @brief devuelve la posicion de la descripcion del tipo del estado de vuelo
///
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param tam
/// @return
int descripcionStatusFlight(Passenger listaDePasajeros,eStatusFlight estadodevueloid[], int tam);
/// @brief muesta un sub menu que te da opciones para el ordenamiento
///
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param typeid
/// @param tam
void informar(Passenger listaDePasajeros[],eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam);
/// @brief
///
/// @param listaDePasajeros
/// @param tam
/// @param statusFlight
/// @param statusTam
/// @param typePassenger
/// @param typeTam
void mostrarVueloValido(Passenger listaDePasajeros[], int tam, eStatusFlight statusFlight[], int statusTam, eTypePassenger typePassenger[], int typeTam);
/// @brief  muestra los vuelos que estan en horario
///
/// @param listaDePasajeros
/// @param tam
/// @param statusFlight
/// @param statusTam
/// @param typePassenger
/// @param typeTam
void printFiltrados(Passenger listaDePasajeros[], int tam, eStatusFlight statusFlight[], int statusTam, eTypePassenger typePassenger[], int typeTam);

#endif /* NEXO_H_ */
