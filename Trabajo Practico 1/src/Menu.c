/*
 * Menu.c
 *
 *  Created on: 6 abr. 2022
 *      Author: Julian lopez
 */


#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


void menu(void)
{
	setbuf(stdout, NULL);
	int banderaautenticacion=0;
	int opciones;
	int subOpcion;
	float x =0;
	float y =0;
	float z =0;

	float precioDebitoAerolineas;
	float precioCreditoAerolineas;
	float precioBitcoinAerolineas;
	float precioUnitarioAerolineas;

	float diferenciaDePrecio;

	float precioDebitoLatam;
	float precioCreditoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;

	do
	{
		SepararTemas();

		printf("1- Ingresar Kilómetros: ");
		printf("\n 2- Ingresar Precio de Vuelos: ");
		printf("\n 3- Calcular todos los costos: ");
		printf("\n 4- Informar Resultados");
		printf("\n 5- Carga forzada de datos");
		printf("\n 6- Salir");

		SepararTemas();
		fflush(stdin);
		scanf("%d", &opciones);
		while(opciones > 6)
		{
			printf("Esa opcion no existe, ingrese una correcta");
			scanf("%d", &opciones);
			espaciarLaConsola();
		}

		switch(opciones)
		{
		case 1:
			x =solicitarDato("ingrese los Km: ");
			espaciarLaConsola();
		break;
		case 2:
			printf("1- Ingresar Precio Aerolíneas \n");
			printf("2- Ingresar Precio Latam\n");
			scanf("%d", &subOpcion);

			if(subOpcion == 1)
			{
				y = solicitarDato("Precio de vuelo (Aerolíneas):\n ");
			}
			else
			{
				if(subOpcion == 2)
				{
					z = solicitarDato("Precio de vuelo (Latam):\n ");
				}
				else
				{
					printf("Opción inválida, ingrese 1 o 2\n");
				}
			}
			espaciarLaConsola();

		break;
		case 3:
			if (x ==0||y==0||z==0)
				{
					printf("no se cargaron todos los datos en la opcion 1 y/o 2, por favor revise \n");
					system("pause");
				}
			else
				{
					banderaautenticacion = 1;
					precioDebitoAerolineas=calcularpreciodebito (y);
					precioCreditoAerolineas=calcularPrecioCredito (z);

					precioDebitoLatam=calcularPrecioCredito (y);
					precioCreditoLatam=calcularPrecioCredito (z);

					precioBitcoinAerolineas=calcularPrecioBitcoin(y);
					precioBitcoinLatam=calcularPrecioBitcoin(z);

					precioUnitarioAerolineas=precioKMUnitario(y,x);
					precioUnitarioLatam=precioKMUnitario(z,x);

					diferenciaDePrecio=calcularDiferencia(y,z);
				}
		break;
		case 4:
			if (banderaautenticacion == 0)
			{
				printf("error, por favor ingrese nuevamente los datos");
			}
			else
			{
					printf("\n A- Precio por Aerolineas: %.2f", y);
					printf("\n B- Precio con tarjeta de debito por Aerolineas: %.2f", precioDebitoAerolineas);
					printf("\n C- Precio con tarjeta de credito por Aerolineas: %.2f", precioCreditoAerolineas);
					printf("\n D- Precio en BITCOIN por Aerolineas: %.2f", precioBitcoinAerolineas);
					printf("\n E- Precio Unitario por Aerolineas: %.2f", precioUnitarioAerolineas);
					printf("\n");
					printf("\n A- Precio por Latam: %.2f", z);
					printf("\n B- Precio con tarjeta de debito por Latam: %.2f", precioDebitoLatam);
					printf("\n C- Precio con tarjeta de credito por Latam: %.2f", precioCreditoLatam);
					printf("\n D- Precio en BITCOIN por Latam: %.2f", precioBitcoinLatam);
					printf("\n E- Precio Unitario por Latam: %.2f", precioUnitarioLatam);
					printf("\n");
					printf("\n La diferencia de precio es: %.2f", diferenciaDePrecio);
			}
		break;
		case 5:
			printf("Carga forzada: \n");
			x = 7090;
			y = 162965;
			z = 159339;

			precioDebitoAerolineas = calcularpreciodebito(y);
			precioCreditoAerolineas = calcularPrecioCredito(y);
			precioBitcoinAerolineas = calcularPrecioBitcoin(y);
			precioUnitarioAerolineas = precioKMUnitario(y, x);

			precioDebitoLatam = calcularpreciodebito(z);
			precioCreditoLatam = calcularPrecioCredito(z);
			precioBitcoinLatam = calcularPrecioBitcoin(z);
			precioUnitarioLatam = precioKMUnitario(z, x);

			diferenciaDePrecio = calcularDiferencia(y, z);

			printf("\n A- Precio por Aerolineas: %.2f", y);
			printf("\n B- Precio con tarjeta de debito por Aerolineas: %.2f", precioDebitoAerolineas);
			printf("\n C- Precio con tarjeta de credito por Aerolineas: %.2f", precioCreditoAerolineas);
			printf("\n D- Precio en BITCOIN por Aerolineas: %.2f", precioBitcoinAerolineas);
			printf("\n E- Precio Unitario por Aerolineas: %.2f", precioUnitarioAerolineas);
			printf("\n");
			printf("\n A- Precio por Latam: %.2f", z);
			printf("\n B- Precio con tarjeta de debito por Latam: %.2f", precioDebitoLatam);
			printf("\n C- Precio con tarjeta de credito por Latam: %.2f", precioCreditoLatam);
			printf("\n D- Precio en BITCOIN por Latam: %.2f", precioBitcoinLatam);
			printf("\n E- Precio Unitario por Latam: %.2f", precioUnitarioLatam);
			printf("\n");
			printf("\n La diferencia de precio es: %.2f", diferenciaDePrecio);
		break;
		default:
			printf("Fin del Programa...");
		break;
		}
	}while(opciones != 6);



}
