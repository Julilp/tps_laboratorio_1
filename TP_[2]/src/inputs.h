/*
 * inputs.h
 *
 *  Created on: 27 jun. 2022
 *      Author: Julian lopez
 */

#ifndef INPUTS_H_
#define INPUTS_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// @brief esta funcion pide un entero y te lo guarda en una variable
///
/// @param mensaje es el mensaje que se mostrara en consola
/// @param min
/// @param max
/// @return numero que ingreso el usuario
int IngresarEntero(char mensaje [], int min, int max);
/// @brief esta funcion valida que la cadena ingresada solo tenga letras
///
/// @param cadena
/// @return devuelve -1 o 0 depende la validacion
int validacionDeCaracteres (char cadena[]);
/// @brief esta funcion valida que lo ingresado sea solo numeros
///
/// @param numeros
/// @return
int validarNumero (char numeros[]);
/// @brief agrega mayusculas despues de cada espacio
///
/// @param cadena
void Mayuscula (char cadena []);
/// @brief pide un numero flotante y lo guarda
///
/// @param mensaje
/// @param mensajeError
/// @return
float pedirFlotante(char mensaje[], char mensajeError[]);
/// @brief pide una cadena de caracteres, esta puede ser validada a solo letras si se le pide
///
/// @param cadena
/// @param mensaje
/// @param mensajeError
/// @param validar si se le pasa 1 valida a solo numeros
/// @return
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int validar);


#endif /* INPUTS_H_ */
