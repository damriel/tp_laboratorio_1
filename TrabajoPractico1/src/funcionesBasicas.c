/*
 * funcionesBasicas.c
 *
 *  Created on: 1 abr. 2021
 *      Author: Damian Lopez
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcionesBasicas.h"
#include "funcionesMatematicas.h"

int mostrarMenu(int numUno, int numDos, int flagNumUno, int flagNumDos)
{
    int opcion;
    if(flagNumUno && flagNumDos)
    {
        system("cls");
        printf("     *** Menu de Opciones ***\n\n");
        printf("1. Ingresar 1er operando (A=%d)\n",numUno);
        printf("2. Ingresar 2do operando (B=%d)\n",numDos);
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    else if(!flagNumUno && flagNumDos)
    {
        system("cls");
        printf("     *** Menu de Opciones ***\n\n");
        printf("1. Ingresar 1er operando (A=x)\n");
        printf("2. Ingresar 2do operando (B=%d)\n",numDos);
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    else if(flagNumUno && !flagNumDos)
    {
        system("cls");
        printf(" ****** MENU DE OPCIONES ******\n\n");
        printf("1. Ingresar 1er operando (A=%d)\n",numUno);
        printf("2. Ingresar 2do operando (B=y)\n");
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    else
    {
        system("cls");
        printf("     *** Menu de Opciones ***\n\n");
        printf("1. Ingresar 1er operando (A=x)\n");
        printf("2. Ingresar 2do operando (B=y)\n");
        printf("3. Calcular todas las operaciones\n");
        printf("4. Informar resultados.\n");
        printf("5. Salir.\n\n");
        printf("Elija una opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);
    }
    return opcion;
}

void ingresarOperando(int* operando, int* flagOperando, int* flagCalculos)
{
    char confirmacion;
    if(operando!=NULL && flagOperando!=NULL && flagCalculos!=NULL)
    {
    	if(!*flagCalculos)
		{
			printf("Ingrese el operando: ");
			fflush(stdin);
			scanf("%d",operando);
			*flagOperando=1;
		}
		else
		{
			printf("Ya se hicieron los calculos, si modifica el operando ahora debera realizar los calculos nuevamente.\n");
			printf("Desea ingresar un nuevo operando A de todos modos?: Si(s) / No(n): ");
			fflush(stdin);
			scanf("%c",&confirmacion);
			while(confirmacion!='s' && confirmacion!='n')
			{
				printf("La opcion ingresada no es valida.\nDesea ingresar un nuevo operando A de todos modos?: Si(s) / No(n): ");
				fflush(stdin);
				scanf("%c",&confirmacion);
			}
			if(confirmacion=='s')
			{
				printf("Ingrese el nuevo operando: ");
				fflush(stdin);
				scanf("%d",operando);
				*flagCalculos=0;
			}
			else if(confirmacion=='n')
			{
				printf("Accion cancelada.\n");
				system("pause");
			}
		}
    }
}

void mostrarResultados(int operando1, int operando2, int rSuma, int rResta, float rDivision, int rMultipicacion, unsigned long long int rFactorialA, unsigned long long int rFactorialB, int pFlagCalculos)
{
    int divisionOk = division(operando1,operando2,&rDivision);
    int factorialAOk = factorial(operando1, &rFactorialA);
    int factorialBOk = factorial(operando2, &rFactorialB);

	if(pFlagCalculos)
    {
        printf("*** Mostrando los resultados ***\n");
        printf("El resultado de A+B es: %d\n", rSuma);
        printf("El resultado de A-B es: %d\n", rResta);
        if(divisionOk)
        {
            printf("El resultado de A/B es: %.2f\n", rDivision);
        }
        else
        {
            printf("ERROR. No se puede dividir por cero.\n");
        }
        printf("El resultado de A*B es: %d\n",rMultipicacion);
        if(factorialAOk && factorialBOk)
        {
            printf("El factorial de A es: %I64u  Y el factorial de B es: %I64u\n", rFactorialA, rFactorialB);
        }
        else if(!factorialAOk && factorialBOk)
        {
			printf("El factorial de A no se puede calcular (A es menor a 0). El factorial de B es: %I64u\n", rFactorialB);
		}
		else if(factorialAOk && !factorialBOk)
		{
			printf("El factorial de A es: %I64u  Pero el factorial de B no se puede calcular (B es menor a 0).\n", rFactorialA);
		}
		else
		{
			printf("No se pudo calcular ninguno de los factoriales porque A y B son menores que 0.\n");
		}
    }
    else
    {
        printf("Aun no se han realizado los calculos, no hay resultados que mostrar.\n");
    }
    system("pause");
}

char validarSalida()
{
    char confirmacion;
    printf("Seguro que desea salir del programa? Si(s) / NO(n): ");
    fflush(stdin);
    scanf("%c",&confirmacion);
    while(confirmacion!='s' && confirmacion!='n')
    {
        printf("La opcion ingresada no es valida.\nSeguro que desea salir del programa? Si(s) / NO(n): ");
        fflush(stdin);
        scanf("%c",&confirmacion);
    }
    if(confirmacion=='s')
    {
        printf("Hasta la proxima!\n");
    }
    else if(confirmacion=='n')
    {
        printf("Regresando al programa...\n");
        system("pause");
    }
    return confirmacion;
}
