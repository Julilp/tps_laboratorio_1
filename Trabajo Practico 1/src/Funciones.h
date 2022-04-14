/*
 * Funciones.h
 *
 *  Created on: 6 abr. 2022
 *      Author: Julian lopez
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_
/// @brief sirve para llamar al menu
///
void menu ();
/// @brief espaciar la consola sirve para limpiar y que quede todo separado
///
void espaciarLaConsola(void);
/// @brief la separacion de temas es nada mas por estetica
///
void SepararTemas(void);
/// @brief funcion para pedir al usuario que me ingrese datos de tipo float
///
/// @param mensaje
/// @return esta funcion te devuelve el numero ingresado por el usuario
float solicitarDato( char mensaje[]);
/// @brief funcion para calcular el precio de los viajes con tarjeta de debito (descuento del 10%)
///
/// @param precioIngresado
/// @return devuelve el valor total del viaje con un descuento del 10%
float calcularpreciodebito (float precioIngresado);
/// @brief funcion para calcular el precio de los viajes con tarjeta de credito (aumento del 25%)
///
/// @param precioIngresado
/// @return devuelve el valor total del viaje con un aumento del 25%
float calcularPrecioCredito (float precioIngresado);
/// @brief funcion para calcular el precio de los viajes con bitcoin
///
/// @param precioIngresado
/// @return devuelve el valor del viaje pasado a la divisa de bitcoin
float calcularPrecioBitcoin (float precioIngresado);
/// @brief esta funcion calcula el costo por kilometro del viaje
///
/// @param precioIngresado
/// @param Km
/// @return devuelve el precio promedio por kilometro
float precioKMUnitario (float precioIngresado, float Km);
/// @brief esta funcion analiza cual de las dos aerolineas te cobre menos y luego realiza una resta para calcular la diferencia entre las dos
///
/// @param precioAerolinea
/// @param precioLATAM
/// @return devuelve la diferencia de plata que hay entre las dos compañias
float calcularDiferencia (float precioAerolinea,float precioLATAM);


#endif /* FUNCIONES_H_ */
