/*
 * funciones.c
 *
 *  Created on: 9 may. 2022
 *      Author: Julian lopez
 */
#include "ArrayPassenger.h"

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
int initPassengers (Passenger listaDePasajeros[],int tam)
{
	int resultado;
	if (tam < 0 || tam > 2000)
	{
		resultado =-1;
	}
	else
	{
		resultado=0;
	}
	for(int i=0;i<tam;i++)
	{
		listaDePasajeros[i].isEmpty =VACIO;
	}

	return resultado;
}
int addPassengers (Passenger listaDePasajeros[], int id,char name[],char lastName[],float price,char flycode[],int typePassenger, int statusFlight)
{
	int index;
	int rtrn=-1;

	index = buscarEspacioLibre(listaDePasajeros,TAM);
	if(index !=-1)
	{
		strcpy(listaDePasajeros[index].name,name);
		strcpy(listaDePasajeros[index].lastName,lastName);
		strcpy(listaDePasajeros[index].flycode,flycode);
		listaDePasajeros[index].price=price;
		listaDePasajeros[index].idtypePassenger=typePassenger;
		listaDePasajeros[index].id=id;
		listaDePasajeros[index].isEmpty=LLENO;
		listaDePasajeros[index].idStatusFlight=statusFlight;
		rtrn =0;
	}


	return rtrn;
}
int findPassengerById(Passenger listaDePasajeros[], int tam,int id)
{
	int index;
	index=-1;
	for(int i=0;i<tam;i++)
	{
		if(listaDePasajeros[i].id==id && listaDePasajeros[i].isEmpty==LLENO)
		{
			index=i;
			break;
		}
	}

	return index;
}
int removePassenger(Passenger listaDePasajeros[], int tam, int id)
{
	int index;
	int seguro=-1;
	int rtrn=-1;
	index=findPassengerById(listaDePasajeros,tam,id);
	if (index != -1)
	{
		printf( "PASAJERO A ELIMINAR:\n "
				"ID %d\n"
				"NOMBRE: %s\n"
				"APELLIDO: %s\n"
				"CODIGO DE VUELO: %s", listaDePasajeros[index].id,listaDePasajeros[index].name,listaDePasajeros[index].lastName,listaDePasajeros[index].flycode);
		printf("\n Seguro de borrar este pasajero? ingrese 1 para borrarlo: ");
		scanf("%d", &seguro);
		if(seguro ==1)
		{
			listaDePasajeros[index].isEmpty=VACIO;
			rtrn=0;
		}
		else
		{
			printf("se cancelo el borrar pasajero\n");
		}


	}
	else
	{
		printf("pasajero no encontrado \n");
	}

	return rtrn;
}
int sortPassengers(Passenger listaDePasajeros[], int tam, int order)
{
	int retorno=-1;


	Passenger typeAux;
	Passenger apellidoAux;

	for (int i=0;i<tam-1;i++)
	{
		for (int j=0;j<tam;j++)
		{
			if(strcmp(listaDePasajeros[i].lastName,listaDePasajeros[j].lastName)==order)
			{
				apellidoAux=listaDePasajeros[i];
				listaDePasajeros[i]=listaDePasajeros[j];
				listaDePasajeros[j]= apellidoAux;
			}
			else
			{
				if(strcmp(listaDePasajeros[i].lastName,listaDePasajeros[j].lastName)==0)
				{
					if(order<0)
					{
						if(listaDePasajeros[i].idtypePassenger < listaDePasajeros[j].idtypePassenger)
							{
									typeAux=listaDePasajeros[i];
									listaDePasajeros[i]=listaDePasajeros[j];
									listaDePasajeros[j]=typeAux;

							}
					}
					else
					{
						if(listaDePasajeros[i].idtypePassenger > listaDePasajeros[j].idtypePassenger)
							{
									typeAux=listaDePasajeros[i];
									listaDePasajeros[i]=listaDePasajeros[j];
									listaDePasajeros[j]=typeAux;
							}
					}
				}
			}
		}
	}
	return retorno;
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
void cargaForzada (Passenger listaDePasajeros[], int tam)

{

	int id;
	char name[][51]={"Leonardo","Carlos","Erica","Facundo"};
	char lastName[][51]= {"Fernandez","Mazza","Hernandez","Rodriguez"};
	float price[]={50000,25000,600,30000};
	char flycode[][10]={"X5RY1","48WEC5","A54XZ","D6C4W"};
	int typePassenger[]={1,2,1,2};
	int statusFlight[]={1,3,2,1};
	int isEmpty[]={1,1,1,1};

	for(int i=0;i<tam;i++)
	{
		id=obtenerID();
		listaDePasajeros[i].id=id;
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








