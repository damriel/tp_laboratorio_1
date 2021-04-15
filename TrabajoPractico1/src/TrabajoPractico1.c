/*
 ============================================================================
 Name        : TrabajoPractico1.c
 Author      : Damian Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo Practico Nº 1 - Laboratorio I - UTN FRA
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesMatematicas.h"
#include "funcionesBasicas.h"

int main(void) {
	setbuf(stdout, NULL);
	int flagPrimerOperando=0;
	int flagSegundoOperando=0;
	int flagCalculos=0;
	int operandoUno;
	int operandoDos;
	int rtaProducto;
	int rtaResta;
	int rtaSuma;
	unsigned long long int rtaFactorialA;
	unsigned long long int rtaFactorialB;
	float rtaDivision;
	char confirmacionSalida='n';

	do{
		switch(mostrarMenu(operandoUno, operandoDos, flagPrimerOperando, flagSegundoOperando))
		{
		case 1:
			ingresarOperando(&operandoUno, &flagPrimerOperando, &flagCalculos);
			break;
		case 2:
			ingresarOperando(&operandoDos, &flagSegundoOperando, &flagCalculos);
			break;
		case 3:
			if(flagPrimerOperando && flagSegundoOperando)
			{
				suma(operandoUno, operandoDos, &rtaSuma);
				resta(operandoUno, operandoDos, &rtaResta);
				division(operandoUno, operandoDos, &rtaDivision);
				multiplicacion(operandoUno, operandoDos, &rtaProducto);
				factorial(operandoUno, &rtaFactorialA);
				factorial(operandoDos, &rtaFactorialB);
				flagCalculos=1;
				printf("Operaciones realizadas.\n");
			}
			else
			{
				printf("Primero es necesario cargar los dos operandos.\n");
			}
			system("pause");
			break;
		case 4:
			mostrarResultados(operandoUno, operandoDos, rtaSuma, rtaResta, rtaDivision, rtaProducto, rtaFactorialA, rtaFactorialB, flagCalculos);
			break;
		case 5:
			confirmacionSalida=validarSalida();
			break;
		default:
			printf("La opcion ingresada no es correcta, vuelva a intentarlo.\n");
			fflush(stdin);
			system("pause");
			break;
		}
		printf("\n\n\n\n\n");
	}while(confirmacionSalida=='n');

	return EXIT_SUCCESS;
}
