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

static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
static int esNumerico(char* cadena, int limite);

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
			while(utn_getNumero(operando)!=0)
			{
				printf("ERROR. Debe ser un numero entero.\nIngrese el operando: ");
				fflush(stdin);
			}
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
				while(utn_getNumero(operando)!=0)
				{
					printf("ERROR. Debe ser un numero entero.\nIngrese el operando: ");
					fflush(stdin);
				}
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

void mostrarResultados(int sumaOk, int restaOk, int divisionOk, int multiplicacionOk, int factorialAOk, int factorialBOk, int rSuma, int rResta, float rDivision, int rMultipicacion, unsigned long long int rFactorialA, unsigned long long int rFactorialB, int flagCalculos)
{
	if(flagCalculos)
    {
        printf("*** Mostrando los resultados ***\n");
        if(sumaOk==0)
        {
        	printf("El resultado de A+B es: %d\n", rSuma);
        }
        else
        {
        	printf("ERROR. No se pudo realizar la operacion.");
        }

        if(restaOk==0)
        {
        	printf("El resultado de A-B es: %d\n", rResta);
        }
        else
        {
        	printf("ERROR. No se pudo realizar la operacion.");
        }

        if(divisionOk==0)
        {
            printf("El resultado de A/B es: %.2f\n", rDivision);
        }
        else if(divisionOk==-2)
        {
            printf("ERROR. No se puede dividir por cero.\n");
        }
        else
        {
        	printf("ERROR. No se pudo realizar la operacion.");
        }

        if(multiplicacionOk==0)
        {
        	printf("El resultado de A*B es: %d\n",rMultipicacion);
        }
        else
        {
        	printf("ERROR. No se pudo realizar la operacion.");
        }


        printf("El factorial de A es: ");
        if(factorialAOk==0)
        {
        	printf("%I64u",rFactorialA);
        }
        else if(factorialAOk==-2)
        {
        	printf("Error, no se puede factorizar un numero negativo.");
        }
        else
        {
        	printf("Ha ocurrido un error, no se pudo realizar la operacion.");
        }
        printf(" y el factorial de B es: ");
        if(factorialBOk==0)
        {
        	printf("%I64u\n",rFactorialB);
        }
        else if(factorialBOk==-2)
        {
        	printf("Error, no se puede factorizar un numero negativo.\n");
        }
        else
        {
        	printf("Ha ocurrido un error, no se pudo realizar la operacion.\n");
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

/***********************************************************************************************************/

/** \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
 *
 * \param cadena char* puntero al espacio en memoria donde se copiara la cadena obtenida
 * \param longitud int tamaño de la cadena
 * \return int retorna 0 si se obtiene una cadena y -1 si no
 *
 */
static int myGets(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        if(fgets(bufferString,sizeof(bufferString),stdin) != NULL && bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n')
        {
            bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
        }
        if(strnlen(bufferString,sizeof(bufferString))<= longitud)
        {
            strncpy(cadena,bufferString,longitud);
            retorno=0;
        }
    }

    return retorno;
}

/** \brief verifica si la cadena ingresada es numerica
 *
 * \param cadena char* cadena de caracteres a ser analizada
 * \param limite int tamaño de la cadena a analizar
 * \return int Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es o -1 en caso de error
 *
 */
static int esNumerico(char* cadena, int limite)
{
    int retorno=-1;
    int i;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        for(i=0;i<limite && cadena[i]!='\0';i++)
        {
            if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
            {
                continue;
            }
            if(cadena[i]>'9' || cadena[i]<'0')
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief pide al usuario ingresar un numero limita el tamaño de lo que se ingresa y si verifica que es un numero entero, convierte la cadena en entero y almacena el valor por referencia
 *
 * \param pResultado int* puntero al espacio en memoria donde se guardara el entero obtenido
 * \return int retorna 0 si se guardo el entero o -1 si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNumerico(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atoi(bufferString);
    }
    return retorno;
}

int utn_getNumero(int* pResultado)
{
    int retorno=-1;
    int bufferInt;

    if(pResultado!=NULL)
    {
		if(getInt(&bufferInt)==0)
		{
			*pResultado = bufferInt;
			retorno = 0;
		}
    }

    return retorno;
}
