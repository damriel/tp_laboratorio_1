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
    int retorno=0;
    if(resultado!=NULL)
    {
        *resultado=num1+num2;
        retorno=1;
    }
    return retorno;
}

int resta(int num1, int num2, int* resultado)
{
    int retorno=0;
    if(resultado!=NULL)
    {
        *resultado=num1-num2;
        retorno=1;
    }
    return retorno;
}

int division(int num1, int num2, float* resultado)
{
    int retorno=0;
    if(resultado!=NULL && num2!=0)
    {
        *resultado=(float)num1/num2;
        retorno=1;
    }
    return retorno;
}

int multiplicacion(int num1, int num2, int* resultado)
{
    int retorno=0;
    if(resultado!=NULL)
    {
        *resultado=num1*num2;
        retorno=1;
    }
    return retorno;
}

int factorial(int num, unsigned long long int* resultado)
{
    int retorno=0;
    *resultado=1;
    if(resultado!=NULL && num>=0)
    {
        retorno=1;
        if(num>0)
        {
            for(int i=1; i<=num; i++)
            {
                *resultado*=i;
            }
        }
        else if(num==0)
        {
            *resultado=1;
        }
    }

    return retorno;
}
