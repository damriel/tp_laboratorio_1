/*
 ============================================================================
 Name        : TrabajoPractico2.c
 Author      : Damian G. Lopez
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "employee.h"
#include "dam.h"
#define LEN 1000
#define MIN_ID 1001
#define MAX_ID 2000

int main()
{
	setbuf(stdout, NULL);
    eEmployee arrayEmployees[LEN]={
        {1001,"Damian Gabriel","Lopez",19000,13,0},
        {1002,"Jefferson","Chocue",12000,15,0},
        {1003,"Marianela","Molinari",17000,1,0},
        {1004,"Mariano Facundo","Seif",18000,11,0},
        {1005,"Juan Pablo","Perez",15500,10,0},
        {1006,"Carolina Victoria","Lopez",13700,3,0},
        {1007,"Maria Fernanda","Magallanes",11000,8,0},
        {1008,"Claudio Victor","Lopez",10200,19,0},
        {1009,"Sandra Lidia","Rosso",22300,29,0},
        {1010,"Gustavo","Cordero",16900,23,0},
        {1011,"Bowie La Rosalia","Molinari",19900,30,0}
    };
    int flagCase1=0;
    int nextId=1001;
    int orden;
    char confirm='n';

    initEmployees(arrayEmployees, LEN);

    for(int i=0;i<11;i++)
    {
        arrayEmployees[i].isEmpty=0;
    }


    do{
        eEmployee auxEmployee={0};

        switch(mainMenu())
        {
        case 1:
            auxEmployee.id=nextId;
            if(findFree(arrayEmployees,LEN)!=-1 &&
               !dam_getNombre(auxEmployee.name,"Ingrese el nombre del empleado: ","ERROR. Ingrese un nombre valido, sin numeros ni simbolos.\n",51,10) &&
               !dam_getNombre(auxEmployee.lastName,"Ingrese el apellido del empleado: ","ERROR. Ingrese un apellido valido, sin numeros ni simbolos.\n",51,10) &&
               !dam_getNumeroFlotante(&auxEmployee.salary, "Ingrese el salario del empleado: ","ERROR. Ingrese un salario valido.\n",1,500000,10) &&
               !dam_getNumero(&auxEmployee.sector,"Ingrese el sector que corresponda al nuevo empleado (0-30): ","ERROR. El sector solo puede contener numeros.\n",0,30,10) &&
               !addEmployee(arrayEmployees, LEN, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector))
            {
                printf("El empleado ha sido cargado correctamente.\n");
                flagCase1=1;
                nextId++;
            }
            else
            {
                printf("Hubo un error en la carga o no hay mas lugar para ingresar nuevos empleados.\n");
            }
            system("pause");
            break;
        case 2:
            if(flagCase1)
            {
                modifyEmployee(arrayEmployees, LEN);
            }
            else
            {
                printf("Aun debe cargar empleados ingresando a la opcion 1.\n");
            }
            system("pause");
            break;
        case 3:
            if(flagCase1)
            {
                printEmployees(arrayEmployees, LEN);
                dam_getNumero(&auxEmployee.id,"Ingrese el ID del empleado que desea dar de baja: ","ERROR. ",MIN_ID,MAX_ID,10);
                if(!removeEmployee(arrayEmployees, LEN, auxEmployee.id))
                {
                    printf("Empleado dado de baja con exito!\n");
                }
                else
                {
                    printf("Hubo un error.\n");
                }
            }
            else
            {
                printf("Aun debe cargar empleados ingresando a la opcion 1.\n");
            }
            system("pause");
            break;
        case 4:
            if(flagCase1)
            {
                switch(reportMenu())
                {
                case 1:
                        if(!dam_getNumero(&orden,"En que orden desea mostrar a los empleados? (0-Descendente / 1-Ascendente): ", "ERROR.\n",0,1,10) &&
                           !sortEmployees(arrayEmployees,LEN,orden))
                        {
                            printEmployees(arrayEmployees, LEN);
                        }
                        else
                        {
                            printf("Hubo un error.\n");
                        }

                    break;
                case 2:
                    reportTwo(arrayEmployees,LEN);
                    break;
                }
            }
            else
            {
                printf("Aun debe cargar empleados ingresando a la opcion 1.\n");
            }
            system("pause");
            break;
        case 5:
            printEmployees(arrayEmployees, LEN);
            system("pause");
            break;
        case 10:
            dam_getCaracter(&confirm,"Seguro desea salir del programa? (s/n): ","ERROR. Ingrese 's' o 'n'.\n",'s','n',10);
            break;
        }
        system("cls");
    }while(confirm=='n');

    return 0;
}

