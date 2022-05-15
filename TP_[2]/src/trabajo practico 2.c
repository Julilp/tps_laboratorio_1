/*
 ============================================================================
 Name        : trabajo.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "ArrayPassenger.h"
#define TAM 2000
int main(void)
{
	eTypePassenger typeid[2] ={{1,"PRIMERA CLASE"},{2,"TURISTA"}};
	eStatusFlight estadodevueloid[3]={{1,"EN HORARIO"},{2,"DEMORADO"},{3,"SUSPENDIDO"}};

	setbuf(stdout,NULL);
	Passenger listaDePasajeros[TAM];
	int r;
	int id;
	int opcion;
	char opcionChar[5];
	int bandera=0;

	initPassengers(listaDePasajeros, TAM);

	do
	{
		printf( "\n            BIENVENIDO          \n"
				"==================================\n"
				"|           1-ALTA               |\n"
				"|           2-MODIFICAR          |\n"
				"|           3-BAJA               |\n"
				"|           4-INFORMAR           |\n"
				"|           5-CARGA FORZADA      |\n"
				"|           6-SALIR              |\n"
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

		while(opcion < 1 || opcion > 6)
		{
			printf("Ingrese una opcion valida : ");
			scanf("%s", opcionChar);
			r=validarNumero(opcionChar);
		while(r==0)
		{
			printf("Ingrese una opcion valida : ");
			scanf("%s", opcionChar);
			r=validarNumero(opcionChar);
			opcion=atoi(opcionChar);
		}

		}
		espaciarLaConsola();
		switch(opcion)
		{
		case 1:
			pedirDatos(listaDePasajeros,TAM);
			bandera=1;
		break;

		case 2:
			if(bandera==1)
			{
				modificarPasajero(listaDePasajeros,TAM);
			}
			else
			{
				printf("todavia no se realizaron cargas, por favor cargar datos.... \n\n");
			}
		break;

		case 3:
			if(bandera==1)
				{
					printf("ingrese el id del pasajero que desea eliminar:");
					scanf("%d", &id);
					r=removePassenger(listaDePasajeros,TAM,id);
					if(r==0)
					{
						printf("se elimino correctamente\n");
					}
				}
				else
				{
					printf("todavia no se realizaron cargas, por favor cargar datos");
				}
		break;

		case 4:
			if(bandera==1)
				{
				 	 informar( listaDePasajeros, estadodevueloid, typeid,  TAM);
				}
				else
				{
					printf("todavia no se realizaron cargas, por favor cargar datos");
				}

		break;

		case 5:
			cargaForzada ( listaDePasajeros, 4);
			bandera=1;
		break;

		case 6:
			printf("SALIENDO...");
		break;
		default:
			printf("ingreso una opcion no valida, vuelva a intentarlo...");
		break;

		}

	}while(opcion!=6);
	return 0;
}
