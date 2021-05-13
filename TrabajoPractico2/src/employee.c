/*
 * employee.c
 *
 *  Created on: 12 may. 2021
 *      Author: Damian G. Lopez
 */

#include <stdio.h>
#include <stdlib.h>
#include "dam.h"
#include "employee.h"

int initEmployees(eEmployee* list, int len)
{
    int retorno=-1;
    if(list!=NULL && len>0)
    {
        retorno=0;
        for(int i=0; i<len; i++)
        {
            list[i].isEmpty=1;
        }
    }
    return retorno;
}

int findFree(eEmployee list[], int len)
{
    int index=-1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                index=i;
                break;
            }
        }
    }
    return index;
}

int addEmployee(eEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
    int retorno=-1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                list[i].id=id;
                strcpy(list[i].name, name);
                strcpy(list[i].lastName, lastName);
                list[i].salary=salary;
                list[i].sector=sector;
                list[i].isEmpty=0;
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int findEmployeeById(eEmployee* list, int len,int id)
{
    int retorno=-1;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id==id && !list[i].isEmpty)
            {
                retorno=i;
                break;
            }
        }
    }
    return retorno;
}

int removeEmployee(eEmployee* list, int len, int id)
{
    int retorno=-1;
    int index;
    char confirmRemove;

    if(list!=NULL && len>0)
    {
        index = findEmployeeById(list, len, id);
        if(index!=-1)
        {
            printf(" ID           Nombre                Apellido         Salario   Sector\n");
            printOneEmployee(list[index]);
            if(!dam_getCaracter(&confirmRemove,"Confirma que desea dar de baja a este empleado? (s/n): ","ERROR.\n",'s','n',10) &&
               confirmRemove=='s')
            {
                list[index].isEmpty=1;
                retorno=0;
            }
        }
    }
    return retorno;
}

int modifyMenu()
{
    int retorno;
    printf("\n     MENU DE MODIFICACIONES\n");
    printf("1) Nombre\n");
    printf("2) Apellido\n");
    printf("3) Salario\n");
    printf("4) Sector\n");
    printf("5) Guardar cambios y salir.\n");
    printf("6) Descartar cambios y salir.\n");
    if(dam_getNumero(&retorno, "Ingrese una opcion: ","ERROR, opcion invalida.\n",1,6,20)==-1)
    {
        retorno=0;
    }
    return retorno;
}

int modifyEmployee(eEmployee list[], int len)
{
    int retorno=-1;
    int index;
    int option;
    int idWanted;
    eEmployee auxEmployee;
    int flagNombre=1;
    int flagApellido=1;
    int flagSalario=1;
    int flagSector=1;

    if(list!=NULL && len>0)
    {
        printEmployees(list,len);
        if(!dam_getNumero(&idWanted,"\nIngrese el ID del empleado que desea modificar: ","ERROR.\n",1001,2000,10))
        {
            index = findEmployeeById(list,len,idWanted);
        }

        if(index==-1)
        {
            printf("No se encontro ningun empleado con ese ID.\n");
        }
        else
        {
            printf("Empleado encontrado:\n");
            printf(" ID           Nombre                Apellido         Salario   Sector\n");
            printOneEmployee(list[index]);

            do{
                option = modifyMenu();
                switch(option)
                {
                case 1:
                    flagNombre = dam_getNombre(auxEmployee.name,"Ingrese nuevo nombre: ","Error. ",51,10);
                    break;
                case 2:
                    flagApellido = dam_getNombre(auxEmployee.lastName,"Ingrese nuevo apellido: ","Error. ",51,10);
                    break;
                case 3:
                    flagSalario = dam_getNumeroFlotante(&auxEmployee.salary,"Ingrese nuevo salario: ","Error. ",1,999999,10);
                    break;
                case 4:
                    flagSector = dam_getNumero(&auxEmployee.sector,"Ingrese nuevo sector (1-30): ","Error. ",1,30,10);
                    break;
                case 5:
                    if(!flagNombre)
                    {
                        strcpy(list[index].name,auxEmployee.name);
                    }
                    if(!flagApellido)
                    {
                        strcpy(list[index].lastName,auxEmployee.lastName);
                    }
                    if(!flagSalario)
                    {
                        list[index].salary=auxEmployee.salary;
                    }
                    if(!flagSector)
                    {
                        list[index].sector=auxEmployee.sector;
                    }
                    printf("Cambios realizados y guardados!\n\n");
                    break;
                case 6:
                    printf("Cambios descartados, volviendo al menu principal...\n\n");
                    break;
                }
            }while(option!=5 && option!=6);
            retorno=0;
        }
    }
    return retorno;
}

int sortEmployees(eEmployee* list, int len, int order)
{
    int retorno=-1;
    eEmployee auxEmployee;

    if(list!=NULL && len>0)
    {
        retorno=0;
        for(int i=0; i<len-1; i++)
        {
            for(int j=i+1; j<len; j++)
            {
                if(!order && ((strcmp(list[i].lastName, list[j].lastName)<0) || (strcmp(list[i].lastName, list[j].lastName)==0 && list[i].sector<list[j].sector)))
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                }
                else if(order && ((strcmp(list[i].lastName, list[j].lastName)>0) || (strcmp(list[i].lastName, list[j].lastName)==0 && list[i].sector>list[j].sector)))
                {
                    auxEmployee=list[i];
                    list[i]=list[j];
                    list[j]=auxEmployee;
                }
            }
        }
    }
    return retorno;
}

void printOneEmployee(eEmployee anEmployee)
{
    printf("%4d  %19s    %19s  %9.2f     %2d\n",anEmployee.id,
                                              anEmployee.name,
                                              anEmployee.lastName,
                                              anEmployee.salary,
                                              anEmployee.sector);
}

int printEmployees(eEmployee* list, int len)
{
    int flagEmployees=0;
    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].isEmpty==0)
            {
                flagEmployees=1;
                break;
            }
        }
        if(flagEmployees)
        {
            printf("      LISTA DE EMPLEADOS\n");
            printf(" ID           Nombre                Apellido         Salario   Sector\n");
            for(int i=0; i<len; i++)
            {
                if(!list[i].isEmpty)
                {
                    printOneEmployee(list[i]);
                }
            }
        }
        else
        {
            printf("NO HAY EMPLEADOS CARGADOS POR EL MOMENTO...\n");
        }
    }
    return 0;
}

int reportMenu()
{
    int retorno;
    printf("\n     MENU DE INFORMES\n");
    printf("1) Listado de empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n");
    if(dam_getNumero(&retorno, "Ingrese una opcion: ","ERROR, opcion invalida.\n",1,6,20)==-1)
    {
        retorno=0;
    }
    return retorno;
}

int reportTwo(eEmployee* list, int len)
{
    int retorno=-1;
    int contadorEmpleados=0;
    int empleadosSalarioMayor=0;
    float acumuladorSalario=0;
    float salarioPromedio;

    if(list!=NULL && len>0)
    {
        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty)
            {
                acumuladorSalario+=list[i].salary;
                contadorEmpleados++;
            }
        }
        salarioPromedio=acumuladorSalario/contadorEmpleados;

        for(int i=0; i<len; i++)
        {
            if(!list[i].isEmpty && list[i].salary>salarioPromedio)
            {
                empleadosSalarioMayor++;
            }
        }

        printf("El total de los salarios es de $ %f\n",acumuladorSalario);
        printf("El promedio de los salarios es de $ %f\n",salarioPromedio);
        printf("La cantidad de empleados que superan el salario promedio es de: %d\n",empleadosSalarioMayor);
        retorno=0;
    }
    return retorno;
}
