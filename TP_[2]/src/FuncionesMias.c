/*
 * FuncionesMias.c
 *
 *  Created on: 9 may. 2022
 *      Author: Julian lopez
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayPassenger.h"
#include <ctype.h>
#include <string.h>



int IngresarEntero(char mensaje [], int min, int max)
{
    int retorno;
    char numeroIngresado[100];
    int validacion;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%s", numeroIngresado);
    validacion=validarNumero(numeroIngresado);
    while(validacion==0)
    {
        printf("\n reingrese el numero (sin letras):  \n");
        fflush(stdin);
        scanf("%s", numeroIngresado);
        validacion= validarNumero(numeroIngresado);
    }

    retorno=atoi(numeroIngresado);

    while(retorno < min || retorno > max)
        {
            printf("\nError, vuelva a ingresar el número dentro de los limites:  \n");
            fflush(stdin);
            scanf("%s", numeroIngresado);
            retorno=atoi(numeroIngresado);
        }

    return retorno;
}
float pedirFlotante(char mensaje[], char mensajeError[])
{
    int retorno = -1;
    char numeroCadena[100];
    int validacion;



	printf("%s", mensaje);
	fflush(stdin);
	scanf("%s", numeroCadena);
	validacion=validarNumero(numeroCadena);
	while(validacion==0)
		{
		printf("%s", mensajeError);
		scanf("%s", numeroCadena);
		validacion=validarNumero (numeroCadena);
		}

	retorno=atof(numeroCadena);



    return retorno;
}
int pedirCadena(char* cadena, char* mensaje, char* mensajeError,int validar)
{
    int retorno = -1;
    char buffer[256];
    int validacion;

    if(cadena != NULL && mensaje != NULL && mensajeError != NULL)
    {
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", buffer);
        if(validar==1)
        {
		 validacion=validacionDeCaracteres (buffer);
		  while(validacion==0)
			{
				printf("%s", mensajeError);
				scanf("%s", buffer);
				validacion=validacionDeCaracteres (buffer);
			}
        }



        strcpy(cadena, buffer);
        retorno = 0;
    }

    return retorno;
}
void espaciarLaConsola(void)
{
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void pedirDatos (Passenger listaDePasajeros[], int tam)
{
	int carga;
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;

	id=obtenerID();
	pedirCadena(name,"ingrese su nombre: ","ERROR, ingrese su nombre (solo letras): ",1);
	pedirCadena(lastName,"ingrese su apellido: ","ERROR, ingrese su apellido (solo letras): ",1);
	price=pedirFlotante( "ingrese el precio del vuelo: ", "Error, ingrese el precio del vuelo (Solo numeros): ");
	pedirCadena(flycode,"ingrese el codigo de vuelo","0",0);
	typePassenger=IngresarEntero("ingrese el tipo de pasajero (1 para primera clase y 2 para clase turista): ", 1, 2);
	statusFlight=IngresarEntero("ingrese el estado de vuelo\n1.EN HORARIO\n2.DEMORADO\n3.SUSPENDIDO ", 1, 3);

	 Mayuscula (name);
	 Mayuscula (lastName);

	carga = addPassengers (listaDePasajeros,id, name, lastName, price, flycode, typePassenger, statusFlight);

	if(carga == -1)
	{
		printf("Hubo un error en la carga, posiblemente no haya mas espacio \n");
	}
	else
	{
		printf("Se cargo todo correctamente \n");
	}
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

int buscarEspacioLibre(Passenger listaDePasajeros[], int tam)
{
    int rtn = -1;
    int indice;

    if(listaDePasajeros != NULL)
    {
        if (tam >= 0)
        {
            for (indice = 0; indice < tam; indice++)
            {
                if(listaDePasajeros[indice].isEmpty == 0)
                {
                    rtn = indice;
                    break;
                }
            }
        }
    }
    return rtn;
}
 int obtenerID()
{
	static int idIncremental = 1000;
	return idIncremental++;
}

int modificarPasajero(Passenger listaDePasajeros[],int tam)
{
	int idIngresado;
	int index;
	int opcion;
	int seguir=1;
	printf("ingrese el id del pasajero: ");
	scanf("%d", &idIngresado);

	index = findPassengerById(listaDePasajeros, tam, idIngresado);
	if(index==-1)
	{
		printf("No se a encontrado el id\n");
		seguir=-1;
	}
	while(seguir==1)
	{
		int validacion;
		char name[51];
		char lastName[51];
		char price[20];
		int typePassenger;
		int statusFlight;
		espaciarLaConsola();
		printf(     "==================================\n"
					"|           1-NOMBRE             |\n"
					"|           2-APELLIDO           |\n"
					"|           3-PRECIO             |\n"
					"|           4-TIPO DE PASAJERO   |\n"
					"|           5-CODIGO DE VUELO    |\n "
					"|           6-ESTADO DE VUELO    |\n"
					"|           7-SALIR              |\n"
					"==================================\n"
					"\n"
					"Ingrese una opcion: ");

			scanf("%d", &opcion);

			while(opcion < 1 || opcion > 7)
				{
					printf("Error opcion no valida, ingrese nuevamente una opcion: ");
					scanf("%d", &opcion);
				}

			switch(opcion)
				{
				case 1:

					printf("ingrese su nombre: \n");
					scanf("%s", name);
					validacion= validacionDeCaracteres(name);
					while(validacion==0)
					{
						printf("ingrese su nombre (solo letras): \n");
						scanf("%s", name);
						validacion= validacionDeCaracteres(name);
					}
					strcpy(listaDePasajeros[index].name,name);
				break;

				case 2:

					printf("ingrese su apellido:\n ");
					scanf("%s", lastName);
					validacion= validacionDeCaracteres(lastName);
					while(validacion==0)
					{
						printf("ingrese su apellido (solo letras): \n");
						scanf("%s", lastName);
						validacion= validacionDeCaracteres(lastName);
					}
					strcpy(listaDePasajeros[index].lastName,lastName);
				break;

				case 3:

					printf("ingrese el precio del viaje:\n ");
					scanf("%s", price);
					validacion= validacionDeCaracteres(price);
					while(validacion==1)
						{
							printf("ingrese el precio del vuelo (solo numeros): \n");
							scanf("%s", price);
							validacion= validacionDeCaracteres(price);
						}
						listaDePasajeros[index].price=atof(price);
				break;

				case 4:
					printf("ingrese el tipo de pasajero (1 para primera clase y 2 para clase turista):\n ");
					scanf("%d", &typePassenger);
					while(typePassenger!=1 || typePassenger!=2)
					{
						printf("ingrese el tipo de pasajero (1 para primera clase y 2 para clase turista):\n ");
						scanf("%d", &typePassenger);
					}
					listaDePasajeros[index].idtypePassenger=typePassenger;
				break;

				case 5:
					printf("ingrese el codigo de vuelo:\n ");
					scanf("%s", listaDePasajeros[index].flycode);
				break;
				case 6:
					printf("ingrese el estado de vuelo\n1.EN HORARIO\n2.DEMORADO\n3.SUSPENDIDO ");
						scanf("%d", &statusFlight);
						while(statusFlight!=1 || statusFlight != 2 || statusFlight!= 3)
						{
							printf("ingrese el tipo de pasajero (1 para primera clase y 2 para clase turista): ");
							scanf("%d", &statusFlight);
						}
						listaDePasajeros[index].idStatusFlight=statusFlight;
				break;
				case 7:
					seguir=-1;
				break;

				}
	}

		return 0;
}
int validarNumero (char numeros[])
{
	int validacion=-1;
	for(int i=0;i<strlen(numeros);i++)
	{
		 if(!(numeros[i] == 46 || (numeros[i]>=48 && numeros[i]<=57)))
		{

			validacion = 0;

		}
	}
	return validacion;
}
void Mayuscula (char cadena [])
{
    int i;
    int size;

    size= strlen(cadena);
    strlwr(cadena);

    for(i= 0; i<size; i++)
    {
        if(cadena[i-1]==32 || i==0)
        {
        	cadena[i] = toupper(cadena[i]);
        }
    }

}
void mostrarUnPasajero(Passenger listaDePasajeros,eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam)
{

	int indexType;
	int idexStatus;

	if(listaDePasajeros.isEmpty==LLENO)
	{

		idexStatus=descripcionStatusFlight( listaDePasajeros, estadodevueloid, 3);
		indexType=descripcionTypePassengerr( listaDePasajeros, typeid,  2);

		printf(
				" |%2d   |       %12s      |        %8s       |       %10.2f   |      %10s     |        %15s         |        %13s     |\n"
				,listaDePasajeros.id ,listaDePasajeros.lastName,listaDePasajeros.name,listaDePasajeros.price,listaDePasajeros.flycode,typeid[indexType].typePassenger,estadodevueloid[idexStatus].StatusFlight);

	}




}

int descripcionStatusFlight(Passenger listaDePasajeros,eStatusFlight estadodevueloid[], int tam)
{
	int index;

	for(int i=0;i<tam;i++)
	{
		if(listaDePasajeros.idStatusFlight==estadodevueloid[i].idStatusFlight)
		{
			index=i;
			break;
		}
	}


	return index;
}
int descripcionTypePassengerr(Passenger listaDePasajeros,eTypePassenger typeid[], int tam)
{
	int index;

	for(int i=0;i<tam;i++)
	{
		if(listaDePasajeros.idtypePassenger==typeid[i].idtypePassenger)
		{
			index=i;
			break;
		}
	}


	return index;
}
void cargaForzada (Passenger listaDePasajeros[], int tam)

{

	int id[] = {1000,1001,1002,1003,1004};
	char name[][51]={"Leonardo","Carlos","Erica","Facundo"};
	char lastName[][51]= {"Fernandez","Mazza","Hernandez","Rodriguez"};
	float price[]={50000,25000,600,30000};
	char flycode[][10]={"X5RY1","48WEC5","A54XZ","D6C4W"};
	int typePassenger[]={1,2,1,2};
	int statusFlight[]={1,3,2,1};
	int isEmpty[]={1,1,1,1};

	for(int i=0;i<tam;i++)
	{
		listaDePasajeros[i].id=id[i];
		strcpy(listaDePasajeros[i].name,name[i]);
		strcpy(listaDePasajeros[i].lastName,lastName[i]);
		listaDePasajeros[i].price=price[i];
		strcpy(listaDePasajeros[i].flycode,flycode[i]);
		listaDePasajeros[i].idtypePassenger=typePassenger[i];
		listaDePasajeros[i].idStatusFlight=statusFlight[i];
		listaDePasajeros[i].isEmpty=isEmpty[i];
	}

	printf("se cargo exitosamente\n");
	system("pause");

}


void informar(Passenger listaDePasajeros[],eStatusFlight estadodevueloid[],eTypePassenger typeid[], int tam)
{
	char opcionChar[5];
	int r;
	int opcion;
	int order;

	printf(
					"==================================\n"
					"|      1-ORDENAR POR APELLIDO    |\n"
					"|      2-TOTAL Y PROMEDIO        |\n"
					"|      3-ORDENAR POR COD DE VUELO|\n"
					"|      4-MOSTRAR VUELOS ACTIVOS  |\n"
					"==================================\n"
					"\n"
					"Ingrese una opcion: ");

	scanf("%s", opcionChar);
	r=validarNumero(opcionChar);
	while(r==0)
		{
			printf("Ingrese una opcion valida (solo numeros): ");
			scanf("%s", opcionChar);
			r=validarNumero(opcionChar);
		}
	opcion=atoi(opcionChar);

	switch(opcion)
	{
	case 1:
		printf("ingrese como quiere ordenar la lista\n1 para la forma ascendente\n-1 para la forma descendente\ningrese la opcion: ");
		scanf("%d", &order);
		while(order !=1 && order != -1)
		{
			printf("ingrese como quiere ordenar la lista\n1 para la forma ascendente\n-1 para la forma descendente\ningrese la opcion: ");
			scanf("%d", &order);
		}
		sortPassengers( listaDePasajeros,TAM, order);
		printPassenger( listaDePasajeros, estadodevueloid, typeid,TAM);
		system("pause");
	break;
	case 2:
		 totalYPromedio( listaDePasajeros, TAM);
	break;
	case 3:
		 ordenarPorCodDeVuelo ( listaDePasajeros,  TAM);
		 printPassenger( listaDePasajeros, estadodevueloid, typeid,TAM);
	break;
	case 4:
		printFiltrados(listaDePasajeros,  TAM, estadodevueloid,  3,  typeid,  2);
	break;
	default:
		printf("Ingreso un numero incorrecto vuelva a intentarlo:");
	break;
	}





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

void ordenarPorCodDeVuelo (Passenger listaDePasajeros[], int tam)

{
	Passenger codVuelo;
	Passenger status;

	for (int i=0;i<tam-1;i++)
	{
		for (int j=0;j<tam;j++)
		{
			if(strcmp(listaDePasajeros[i].flycode,listaDePasajeros[j].flycode)==-1)
			{
				codVuelo=listaDePasajeros[i];
				listaDePasajeros[i]=listaDePasajeros[j];
				listaDePasajeros[j]= codVuelo;
			}
			else
			{
				if(strcmp(listaDePasajeros[i].flycode,listaDePasajeros[j].flycode)==0)
				{

					if(listaDePasajeros[i].idtypePassenger < listaDePasajeros[j].idtypePassenger)
					{
							status=listaDePasajeros[i];
							listaDePasajeros[i]=listaDePasajeros[j];
							listaDePasajeros[j]=status;

					}
				}
			}
		}
	}
}

void printFiltrados(Passenger listaDePasajeros[], int tam, eStatusFlight statusFlight[], int statusTam, eTypePassenger typePassenger[], int typeTam)
{
    for(int i=0; i<tam;i++)
    {
        if(listaDePasajeros[i].idStatusFlight == 1)
        {
            mostrarUnPasajero(listaDePasajeros[i], statusFlight, statusTam, typePassenger, typeTam);
        }
    }
}
