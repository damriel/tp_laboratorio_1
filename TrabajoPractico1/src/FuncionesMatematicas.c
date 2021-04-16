/*
 * funcionesMatematicas.c
 *
 *  Created on: 1 abr. 2021
 *      Author: Damian Lopez
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesMatematicas.h"

int suma(int num1, int num2, int* resultado)
{
    int retorno=-1;
    if(resultado!=NULL)
    {
        *resultado=num1+num2;
        retorno=0;
    }
    return retorno;
}

int resta(int num1, int num2, int* resultado)
{
    int retorno=-1;
    if(resultado!=NULL)
    {
        *resultado=num1-num2;
        retorno=0;
    }
    return retorno;
}

int division(int num1, int num2, float* resultado)
{
    int retorno=-1;
    if(resultado!=NULL)
    	retorno=-2;
		if(num2!=0)
		{
			*resultado=(float)num1/num2;
			retorno=0;
		}
    return retorno;
}

int multiplicacion(int num1, int num2, int* resultado)
{
    int retorno=-1;
    if(resultado!=NULL)
    {
        *resultado=num1*num2;
        retorno=0;
    }
    return retorno;
}

int factorial(int num, unsigned long long int* resultado)
{
    int retorno=-1;
    if(resultado!=NULL)
    {
        retorno=-2;
        if(num>=0)
        {
        	retorno=0;
        	if(num==0)
        	{
        		*resultado=1;
        	}
        	else
        	{
        		*resultado=1;
        		for(int i=1; i<=num; i++)
				{
					*resultado*=i;
				}
        	}
        }
    }

    return retorno;
}
