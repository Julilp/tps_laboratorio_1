/*
 * Funciones.c
 *
 *  Created on: 6 abr. 2022
 *      Author: Julian lopez
 */

#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"
#define Bitcoin 4606954.55

void espaciarLaConsola(void)
{
	printf("\n\n\n\n\n\n\n\n");
}

void SepararTemas(void)
{
	printf("-------------------------------------\n");
}

float solicitarDato( char mensaje[])
{
	float numeroIngresado;
	printf("%s", mensaje);
	scanf("%f", &numeroIngresado);

	return numeroIngresado;
}
float calcularpreciodebito (float precioIngresado)
{
	float precioDebitoFinal;
	float descuento;
	float porcentajeDeDescuento;
	porcentajeDeDescuento = 10;
	descuento = precioIngresado * porcentajeDeDescuento / 100;
	precioDebitoFinal=precioIngresado - descuento;
	return  precioDebitoFinal;
}
float calcularPrecioCredito (float precioIngresado)
{
		float precioCreditoFinal;
		float aumento;
		float porcentajeDeAumento;
		porcentajeDeAumento= 25;
		aumento = precioIngresado * porcentajeDeAumento / 100;
		precioCreditoFinal=precioIngresado + aumento;
		return precioCreditoFinal;
}
float calcularPrecioBitcoin (float precioIngresado)
{
	float precioBTCFinal;

	precioBTCFinal=precioIngresado / Bitcoin;
	return precioBTCFinal;
}
float precioKMUnitario (float precioIngresado, float Km)
{
	float precioUnitario;

	precioUnitario = precioIngresado / Km;

	return precioUnitario;
}
float calcularDiferencia (float precioAerolinea,float precioLATAM)
{
	float resultado;

	if (precioLATAM > precioAerolinea){
		resultado = precioLATAM - precioAerolinea;
	}
	else
	{
	resultado = precioAerolinea - precioLATAM;
	}

	return resultado;
}





