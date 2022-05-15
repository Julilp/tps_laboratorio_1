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

struct
{
	int idtypePassenger;
	char typePassenger[20];
}typedef eTypePassenger;

struct
{
	int idStatusFlight;
	char StatusFlight[20];
}typedef eStatusFlight;



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
/// @brief
/// repite una funcion para poder mostrar todos los pasajeros
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param typeid
/// @param tam
void printPassenger(Passenger listaDePasajeros[],eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam);



//------FUNCIONES PARTICULARES------//
/// @brief
/// pide un entero y valida que este entre
/// @param mensaje
/// @param min
/// @param max
/// @return
int IngresarEntero(char mensaje [], int min, int max);
/// @brief
/// muestra espacios en la consola si se acomoda la consola
void espaciarLaConsola(void);
/// @brief
/// pide todos los datos de la estructura y se los pasa a addPassenger
/// @param listaDePasajeros
/// @param tam
void pedirDatos (Passenger listaDePasajeros[],int tam);
/// @brief
/// valida que solo se usen caracteres dentro de una cadena
/// @param cadena
/// @return
int validacionDeCaracteres (char cadena[]);
/// @brief
/// recorre el array y vusca un espacio libre
/// @param listaDePasajeros
/// @param tam
/// @return devuelve el espacio libre
int buscarEspacioLibre(Passenger listaDePasajeros[], int tam);
/// @brief
/// genera un id de manera autoincremental automaticamente
/// @return
int obtenerID();
/// @brief
/// muestra un sub menu que da opcion al usuario en que dato modificar
/// @param listaDePasajeros
/// @param tam
/// @return
int modificarPasajero(Passenger listaDePasajeros[],int tam);
/// @brief
/// validaq que solo se usen numeros en una cadena
/// @param numeros
/// @return
int validarNumero (char numeros[]);
/// @brief
///pone las mayusculas cuando detecta un espacio o el inicioi de una palabra
/// @param cadena
void Mayuscula (char cadena []);
/// @brief
/// pide un flotante y valida que este sean todos numeros
/// @param mensaje
/// @param mensajeError
/// @return
float pedirFlotante(char mensaje[], char mensajeError[]);
/// @brief
/// pide una cadena y valida que todos los caracteres sea letras
/// @param cadena
/// @param mensaje
/// @param mensajeError
/// @param validar
/// @return
int pedirCadena(char* cadena, char* mensaje, char* mensajeError, int validar);
/// @brief
/// muestra 1 solo pasajero con la estructura de una tabla
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param typeid
/// @param tam
void mostrarUnPasajero(Passenger listaDePasajeros,eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam);
/// @brief
/// recibe el id del estado de vuelo y lo compara con la estructura del estado de vuelo para poder mostrar el tipo y no el id
/// @param listaDePasajeros
/// @param typeid
/// @param tam
/// @return
int descripcionTypePassengerr(Passenger listaDePasajeros,eTypePassenger typeid[], int tam);
/// @brief
///recibe el id del tipo de pasajero y lo compara con la estructura del estado de vuelo para poder mostrar el tipo y no el id
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param tam
/// @return
int descripcionStatusFlight(Passenger listaDePasajeros,eStatusFlight estadodevueloid[], int tam);
/// @brief
/// carga de manera automatica 4 personas con todos sus datos
/// @param listaDePasajeros
/// @param tam
void cargaForzada (Passenger listaDePasajeros[], int tam);
/// @brief
/// abre un sub menu para que el usuario pueda indicar que es lo que quiere que se le informe
/// @param listaDePasajeros
/// @param estadodevueloid
/// @param typeid
/// @param tam
void informar(Passenger listaDePasajeros[],eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam);
/// @brief
/// calcula el total y promedio de los costos de vuelo
/// @param listaDePasajeros
/// @param tam
void totalYPromedio(Passenger listaDePasajeros[],int tam);
/// @brief
/// ordena a los pasajeros por codigo de vuelo
/// @param listaDePasajeros
/// @param tam
void ordenarPorCodDeVuelo (Passenger listaDePasajeros[], int tam);
/// @brief
/// muestra unicamente los vuelos que estan EN HORARIO
/// @param listaDePasajeros
/// @param tam
/// @param statusFlight
/// @param statusTam
/// @param typePassenger
/// @param typeTam
void mostrarVueloValido(Passenger listaDePasajeros[], int tam, eStatusFlight statusFlight[], int statusTam, eTypePassenger typePassenger[], int typeTam);


#endif /* ARRAYPASSENGER_H_ */
