/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char estadoDeVuelo[50];


}Passenger;

typedef struct
{
	int idType;
	char TypeDescription[25];

}Type;

/// @brief crea un nuevo pasajero
///
/// @return
Passenger* Passenger_new();

/// @brief recive todos los campos del pasajero para despues settearselos
///
/// @param idStr
/// @param nombreStr
/// @param tipoPasajeroStr
/// @param apellidoStr
/// @param precioStr
/// @param codigoVueloStr
/// @param estadoDeVueloStr
/// @return
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr,char* apellidoStr,char* precioStr,char* codigoVueloStr,char* estadoDeVueloStr);

/// @brief elimina un pasajero
///
void Passenger_delete();

/// @brief recibe el id y lo asigna
///
/// @param this
/// @param id
/// @return
int Passenger_setId(Passenger* this,int id);

///@brief obtiene un id desde un pasajero
///
/// @param this
/// @param id
/// @return
int Passenger_getId(Passenger* this,int* id);

/// @brief recibe el nombre y lo asigna
///
/// @param this
/// @param nombre
/// @return
int Passenger_setNombre(Passenger* this,char* nombre);

/// @brief obtiene un nombre desde un pasajero
///
/// @param this
/// @param nombre
/// @return
int Passenger_getNombre(Passenger* this,char* nombre);

/// @brief recibe el apellido y lo asigna
///
/// @param this
/// @param apellido
/// @return
int Passenger_setApellido(Passenger* this,char* apellido);

/// @brief obtiene un apellido desde un pasajero
///
/// @param this
/// @param apellido
/// @return
int Passenger_getApellido(Passenger* this,char* apellido);

/// @brief recibe el codigo dde vuelo y lo asigna
///
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief obtiene un codigo de vuelo desde un pasajero
///
/// @param this
/// @param codigoVuelo
/// @return
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

/// @brief recibe el tipo de pasajero y lo asigna
///
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero);

/// @brief obtiene un tipo de pasajero desde un pasajero
///
/// @param this
/// @param tipoPasajero
/// @return
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero);

/// @brief recibe elprecio y lo asigna
///
/// @param this
/// @param precio
/// @return
int Passenger_setPrecio(Passenger* this,float precio);

/// @brief obtiene el precio desde un pasajero
///
/// @param this
/// @param precio
/// @return
int Passenger_getPrecio(Passenger* this,float* precio);

/// @brief  recibe el estado de vuelo y lo asigna
///
/// @param this
/// @param estadoDeVuelo
/// @return
int Passenger_setEstadoDeVuelo(Passenger* this,char* estadoDeVuelo);

/// @brief obtiene el estado de vuelo desde un pasajero
///
/// @param this
/// @param estadoDeVuelo
/// @return
int Passenger_getEstadoDeVuelo(Passenger* this,char* estadoDeVuelo);

/// @brief muesta un solo pasajerp
///
/// @param pasajero
/// @param eTipo
void Passenger_showAPassenger(Passenger* pasajero,Type eTipo[]);

/// @brief linkea el id de tipo de pasajero con su descripcion
///
/// @param pasajero
/// @param eTipo
/// @param tipoChar
void MatchIds(Passenger* pasajero,Type eTipo[],char* tipoChar);

/// @brief obtiene el estado de vuelo desde un pasajero
///
/// @param estadoDeVuelo
void setEstadoVuelo(char* estadoDeVuelo);

/// @brief  obtiene un id desde el static
///
/// @return
int obtenerID();

/// @brief agrega un pasajero a la lista para luego cargarlo
///
/// @param pasajero
/// @param id
/// @param nombre
/// @param apellido
/// @param tipoPasajero
/// @param codigoVuelo
/// @param estadoPasajero
/// @param precio
/// @param pArrayListPassenger
void AddPassenger(Passenger* pasajero,int id, char*nombre, char*apellido, int tipoPasajero, char*codigoVuelo, char*estadoPasajero, float precio,LinkedList* pArrayListPassenger);

/// @brief busca por id a un pasajero
///
/// @param pArrayListPassenger
/// @param idABuscar
/// @return
int BuscarPorID(LinkedList* pArrayListPassenger,int* idABuscar);

/// @brief compara por precio
///
/// @param pasajero1
/// @param pasajero2
/// @return
int passenger_compareByPrecio(void* pasajero1, void* pasajero2);

/// @brief compara por id
///
/// @param pasajero1
/// @param pasajero2
/// @return
int passenger_compareById(void* pasajero1, void* pasajero2);

/// @brief compara por nombre
///
/// @param pasajero1
/// @param pasajero2
/// @return
int passenger_compareByName(void* pasajero1, void* pasajero2);



#endif /* PASSENGER_H_ */
