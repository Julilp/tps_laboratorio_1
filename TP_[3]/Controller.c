#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pArchivo;
	if(path!=NULL && pArrayListPassenger != NULL){
		pArchivo=fopen(path,"r");
		if(pArchivo!=NULL){
			parser_PassengerFromText(pArchivo, pArrayListPassenger);
			retorno=1;
			printf("Se cargo correctamente el archivo\n");
		}
		else{
			printf("No se pudo leer el archivo\n");
		}
		fclose(pArchivo);
	}

    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pArchivo;

	if(path != NULL && pArrayListPassenger != NULL){
		pArchivo = fopen(path,"rb");
		if(pArchivo != NULL){
			parser_PassengerFromBinary(pArchivo, pArrayListPassenger);
			retorno =1;

		}
		else{
			printf("no se pudo leer el archivo\n");
		}
		fclose(pArchivo);
	}
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[7];
	char estadoDeVuelo[50];

	Passenger* nuevoPasajero=NULL;

	if(pArrayListPassenger != NULL){
		pedirCadena(nombre, "Ingrese el nombre del pasajero: ", "ERROR solo puede ingresar letras: ", 50,1);
		pedirCadena(apellido, "Ingrese el apellido del pasajero: ", "Solo puede ingresar letras: ", 50,1);
		utn_getFloat(&precio, "Ingrese el precio del pasaje", "No esta dentro de los parametros (10.000 y 100.000)", 10000, 100000, 5);
		pedirEntero(&tipoPasajero, "Elegir su clase de vuelo:\n1.Primera Clase\n2.Clase Turista\n3.Clase Economica", "tiene que elegir una de las opciones:\n1.Primera Clase\n2.Clase Turista\n3.Clase Economica",1,3);
		pedirCadena(codigoVuelo, "Ingrese el codigo de vuelo: ", "", 50,0);
		setEstadoVuelo(estadoDeVuelo);
		id=obtenerID();
		retorno=1;
	}
	nuevoPasajero = Passenger_new();
	AddPassenger(nuevoPasajero,id, nombre, apellido, tipoPasajero, codigoVuelo, estadoDeVuelo, precio, pArrayListPassenger);
	ll_add(pArrayListPassenger, nuevoPasajero);
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger,Type* eTipo)
{
	int id;
	int index;
	int tam;
	int option;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char estadoDeVuelo[50];

	Passenger* pasajeroPModificar;
	if(pArrayListPassenger !=NULL){

		tam=ll_len(pArrayListPassenger);
		do{
			pedirEntero(&id, "ingrese el id del pasajero a modificar: ","el id no esta dentro de los parametros 1/1500", 1, tam);
			index=BuscarPorID(pArrayListPassenger, &id);
			//printf("este es el index %d",index);
		}while(index==-1);

		pasajeroPModificar=(Passenger*)ll_get(pArrayListPassenger,index);
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("                          		EMPLEADO A MODIFICAR                                              \n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("ID  |    NOMBRE   |   APELLIDO   | PRECIO | TIPO DE PASAJERO | COD DE VUELO | ESTADO DE VUELO |\n");
		Passenger_showAPassenger(pasajeroPModificar, eTipo);
		printf("----------------------------------------------------------------------------------------------------\n");
		printf("				    >>Seleccione Para Modificar<<						    \n");
		printf("1.NOMBRE					2.APELLIDO         			3.ESTADO DE VUELO   \n");
		printf("4.PRECIO					5.TIPO DE PASAJERO			6.COD DE VUELO      \n");

		pedirEntero(&option, "Opcion->", "no esta dentro de los limites: ", 1, 6);

		switch(option){
		case 1:
			printf("------MENU DE NOMBRE-----\n");
			printf("Nombre viejo -> %s\n",pasajeroPModificar->nombre);
			pedirCadena(nombre, "Nuevo nombre: ", "El nombre es muy largo: ", 50, 1);
			Passenger_setNombre(pasajeroPModificar, nombre);
		break;
		case 2:
			printf("------MENU DE APELLIDO-----\n");
			printf("Nombre viejo -> %s\n",pasajeroPModificar->apellido);
			pedirCadena(apellido, "Nuevo apellido: ", "El apellido es muy largo: ", 50, 1);
			Passenger_setApellido(pasajeroPModificar, apellido);
		break;
		case 3:
			printf("------MENU DE ESTADO DE VUELO-----\n");
			printf("Estado de vuelo viejo -> %s\n",pasajeroPModificar->estadoDeVuelo);
			setEstadoVuelo(estadoDeVuelo);
			Passenger_setEstadoDeVuelo(pasajeroPModificar, estadoDeVuelo);
		break;
		case 4:
			printf("------MENU DE ESTADO DE PRECIO-----\n");
			printf("Precio viejo -> %2.f\n",pasajeroPModificar->precio);
			utn_getFloat(&precio, "Precio nuevo: ", "No esta dentro de los parametros (10.000 y 100.000)", 10000, 100000, 5);
			Passenger_setPrecio(pasajeroPModificar, precio);
		break;
		case 5:
			printf("------MENU DE ESTADO DE TIPO DE PASAJERO-----\n");
			printf("Tipo de pasajero viejo -> %d\n",pasajeroPModificar->tipoPasajero);
			pedirEntero(&tipoPasajero, "Elegir su clase de vuelo nueva:\n1.Primera Clase\n2.Clase Turista\n3.Clase Economica", "tiene que elegir una de las opciones:\n1.Primera Clase\n2.Clase Turista\n3.Clase Economica",1,3);
			Passenger_setTipoPasajero(pasajeroPModificar, tipoPasajero);
		break;
		case 6:
			printf("------MENU DE ESTADO DE CODIGO DE VUELO-----\n");
			printf("Codigo de vuelo viejo -> %s\n",pasajeroPModificar->codigoVuelo);
			pedirCadena(codigoVuelo, "Ingrese el codigo de vuelo: ", "", 50,0);
			Passenger_setCodigoVuelo(pasajeroPModificar, codigoVuelo);
		break;
		}


	}

    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger,Type* eTipo){
	int id;
	int index;
	int tam;
	int confirm;
	Passenger* pasajeroAEliminar;
	if(pArrayListPassenger !=NULL){

		tam=ll_len(pArrayListPassenger);
		do{
			pedirEntero(&id, "ingrese el id del pasajero a modificar: ","el id no esta dentro de los parametros 1/1500", 1, tam);
			index=BuscarPorID(pArrayListPassenger, &id);
			//printf("este es el index %d",index);
		}while(index==-1);

		pasajeroAEliminar=(Passenger*)ll_get(pArrayListPassenger,index);
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("                          		  EMPLEADO A ELIMINAR                                             \n");
		printf("--------------------------------------------------------------------------------------------------\n");
		printf("ID  |    NOMBRE   |   APELLIDO   | PRECIO | TIPO DE PASAJERO | COD DE VUELO | ESTADO DE VUELO |\n");
		Passenger_showAPassenger(pasajeroAEliminar, eTipo);
		printf("--------------------------------------------------------------------------------------------------\n");
		pedirEntero(&confirm, "----SEGURO QUE QUIERE ELIMINAR AL PASAJERO?----\n	1.SI                2.NO             \n Opcion:  ", "Ingrese 1 para borrar y 2 para cancelar", 1, 2);
		if(confirm==1){
			Passenger_delete(pasajeroAEliminar);
			ll_remove(pArrayListPassenger, index);
			printf("Se ha eliminado con exito el pasajero\n");
		}
		else{
			printf("Se cancelo el eliminado de pasajero\n");
		}
	}
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger,Type eTipo[])
{
	int retorno = 0;
	int size;
	size=ll_len(pArrayListPassenger);
	Passenger* nuevoPasajero=NULL;
	if(pArrayListPassenger != NULL){
		printf("------------------------------------------------------------------------\n");
		printf("                       LISTA DE PASAJERO                                \n");
		printf("------------------------------------------------------------------------\n");
		printf("ID  |    NOMBRE   |   APELLIDO   | PRECIO | TIPO DE PASAJERO | COD DE VUELO | ESTADO DE VUELO |\n");
		for(int i=0; i<size;i++){
		nuevoPasajero = (Passenger*)ll_get(pArrayListPassenger,i);
		if(nuevoPasajero!=NULL){
			Passenger_showAPassenger(nuevoPasajero,eTipo);
		}
	 }
		retorno = 1;
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger,Type* eTipo)
{
	int retorno=-1;
	int orden;
	int criterio;
	LinkedList* clonado=NULL;

	if(pArrayListPassenger !=NULL){
		clonado=ll_clone(pArrayListPassenger);
		pedirEntero(&criterio, "como quiere ordenar la list?\n1.Por id    2.Por nombre    3.Por precio", "No esta en los parametros", 1, 3);
		switch(criterio){

		case 1:
			printf("-----ORDENAMIENTO POR ID------");
			pedirEntero(&orden, "indique el orden:\n0.Descendente\n1.Ascendente", "indique el orden:\n0.Descendente\n1.Ascendente", 0, 1);
			printf("ORDENDANDO.....");
			ll_sort(clonado, passenger_compareById,orden);
			controller_ListPassenger(clonado, eTipo);
		break;
		case 2:
			printf("-----ORDENAMIENTO POR NOMBRE------");
			pedirEntero(&orden, "\nindique el orden:\n0.Descendente\n1.Ascendente", "\nindique el orden:\n0.Descendente\n1.Ascendente",0, 1);
			printf("ORDENDANDO.....");
			ll_sort(clonado, passenger_compareByName,orden);
			controller_ListPassenger(clonado, eTipo);
		break;
		case 3:
			printf("-----ORDENAMIENTO POR PRECIO------");
			pedirEntero(&orden, "indique el orden:\n0.Descendente\n1.Ascendente", "indique el orden:\n0.Descendente\n1.Ascendente", 0, 1);
			printf("ORDENDANDO.....");
			ll_sort(clonado, passenger_compareByPrecio,orden);
			controller_ListPassenger(clonado, eTipo);
		break;

		}
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];
	char estadoDeVuelo[50];
	FILE* auxPath;
	Passenger* unPasajero;

	if(pArrayListPassenger){
		auxPath=fopen(path,"w");
		if (auxPath!=NULL){
			for(int i=0;i<ll_len(pArrayListPassenger);i++){
				unPasajero=(Passenger*)ll_get(pArrayListPassenger,i);
				if(unPasajero!=NULL &&
				   Passenger_getId(unPasajero, &id)==1 &&
				   Passenger_getNombre(unPasajero, nombre)==1 &&
				   Passenger_getApellido(unPasajero, apellido)==1 &&
				   Passenger_getPrecio(unPasajero, &precio)==1 &&
				   Passenger_getTipoPasajero(unPasajero, &tipoPasajero)==1 &&
				   Passenger_getCodigoVuelo(unPasajero, codigoVuelo)==1 &&
				   Passenger_getEstadoDeVuelo(unPasajero, estadoDeVuelo)==1){

					fprintf(auxPath,"%d,%s,%s,%f,%d,%s,%s\n",id,nombre,apellido,precio,tipoPasajero,codigoVuelo,estadoDeVuelo);
					retorno=1;
				}
			}
		}
	}
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* auxPath;
	Passenger* unPasajero;


	if(pArrayListPassenger !=NULL){
		auxPath = fopen(path,"wb");
		if(auxPath!=NULL){
			for(int i=0;i<ll_len(pArrayListPassenger);i++){
				unPasajero=(Passenger*)ll_get(pArrayListPassenger,i);
				if(auxPath!=NULL){
					if(fwrite(unPasajero,sizeof(Passenger),1,auxPath)!=1){
						retorno =1;
						break;
					}
				}
			}
		}
		else{
			printf("No se pudo escribir sobre el archivo\n");
		}
	}




    return retorno;
}


