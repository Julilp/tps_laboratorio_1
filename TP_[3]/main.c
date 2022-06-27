#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    int loadFlag=1;
    Type tiposPasajeros[3]={{1,"Primera Clase"},{2,"Clase Turista"},{3,"Clase Economica"}};
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	printf("=====================================================================================\n");
		printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
		printf("2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n");
		printf("3. Alta de pasajero\n");
		printf("4. Modificar datos de pasajero\n");
		printf("5. Baja de pasajero\n");
		printf("6. Listar pasajeros\n");
		printf("7. Ordenar pasajeros\n");
		printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
		printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
		printf("10. Salir\n");
		printf("=====================================================================================\n");
		pedirEntero(&option, "ingrese una opcion: ", "El numero no esta dentro de las opciones", 1, 10);
        switch(option)
        {
            case 1:
            	if(loadFlag==1){
            		controller_loadFromText("data.csv",listaPasajeros);
            		loadFlag=0;
            	}
            	else{
            		printf("solo se puede cargar el archivo una vez");
            	}
                break;
            case 2:
            	if(loadFlag==1){
            		controller_loadFromBinary("data.bin",listaPasajeros);
					loadFlag=0;
				}
				else{
					printf("solo se puede cargar el archivo una vez");
				}
            break;
            case 3:
            	controller_addPassenger(listaPasajeros);
            break;
            case 4:
            	controller_editPassenger(listaPasajeros, tiposPasajeros);
            break;
            case 5:
            	controller_removePassenger(listaPasajeros, tiposPasajeros);
            break;
            case 6:
            	if (loadFlag==0){
            		controller_ListPassenger(listaPasajeros,tiposPasajeros);
            	}
            	else {
            		printf("debes cargar un archivo para mostrarlo");
            	}
            break;
            case 7:
            		controller_sortPassenger(listaPasajeros,tiposPasajeros);
            break;
            case 8:
					controller_saveAsText("data.csv", listaPasajeros);
            break;
            case 9:
            		controller_saveAsBinary("data.bin", listaPasajeros);
             break;
        }
    }while(option != 10);
    printf("saliendo.....");
    return 0;
}

