#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "dam.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile=NULL;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path,"r");
        if(pFile != NULL)
        {
            parser_EmployeeFromText(pFile, pArrayListEmployee);
            retorno=0;
            fclose(pFile);
        }
    }

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile=NULL;
    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile!=NULL)
        {
            if(parser_EmployeeFromBinary(pFile, pArrayListEmployee))
            {
                retorno = 0;
            }
            fclose(pFile);
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int id;
    int horasTrabajadas;
    int sueldo;
    char nombre[128];
	Employee* auxEmpleado=NULL;

	if(pArrayListEmployee!=NULL)
    {
        printf("\n====================================================\n");
        printf("                 ALTA DE EMPLEADO\n");
        printf("====================================================\n");
        if(!dam_getNombre(nombre,"Ingrese nombre: ","Error, solo se permiten letras y hasta 20 caracteres\n",128,5) &&
           !dam_getNumero(&horasTrabajadas,"Ingrese cantidad de horas trabajadas: ", "Error. Vuelva a intentarlo (limite 0-99999)\n",0,99999,5) &&
           !dam_getNumero(&sueldo,"Ingrese sueldo: ", "Error. (limite 1-999999)\n",1,999999,3))
        {
            id = employee_generateId(pArrayListEmployee, ll_len(pArrayListEmployee));
            auxEmpleado = employee_newParametrosNoStr(id, nombre, horasTrabajadas, sueldo);
            ll_add(pArrayListEmployee, auxEmpleado);
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int index;
    int retorno=-1;

    if(pArrayListEmployee!=NULL)
    {
        printf("\n====================================================\n");
        printf("               MODIFICAR EMPLEADO\n");
        printf("====================================================\n");
        do
        {
            dam_getNumero(&id,"Ingrese el ID del empleado que desea modificar: ","Error. Intente nuevamente.\n",1,5000,3);
            index = employee_findById(pArrayListEmployee, id);
            if(index==-1)
            {
                printf("No se encontro el empleado.\n");
            }
            else
            {
                if(!employee_editEmployee(pArrayListEmployee, index))
                {
                    retorno=1;
                }
            }
        }while(index==-1);
    }
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int id;
    int index;
    char confirmar=' ';
    Employee* auxEmpleado=NULL;

    if(pArrayListEmployee!=NULL)
    {
        printf("\n====================================================\n");
        printf("                BAJA DE EMPLEADOS\n");
        printf("====================================================\n");
        retorno=1;
        dam_getNumero(&id,"Ingrese el ID del empleado que quiere eliminar: ","Error. Ingrese un ID valido (limite 1-5000)\n",1,5000,5);
        index = employee_findById(pArrayListEmployee, id);
        if(index!=-1)
        {
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee, index);
            employee_showOneEmployee(auxEmpleado);
            while(confirmar!='n' && confirmar!='s')
            {
                dam_getCaracter(&confirmar,"Seguro desea eliminar a este empleado de la lista? (S/N): ", "Error.\n",'s','n',5);
            }
            if(confirmar=='s')
            {
                ll_remove(pArrayListEmployee,index);
            }
            else
            {
                printf("Baja cancelada.\n");
                retorno=0;
            }
        }
        else
        {
            printf("No se encontro al empleado.\n");
            retorno=0;
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmpleado=NULL;

    if(pArrayListEmployee!=NULL)
    {
        retorno=0;
        printf("\n====================================================\n");
        printf("             LISTADO DE EMPLEADOS\n");
        printf("====================================================\n");
        printf(" ID           Nombre       Horas Trabajadas   Sueldo\n");
        for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
            auxEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
            employee_showOneEmployee(auxEmpleado);
        }
        printf("\n");
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = 1;
	int opcion;

    opcion = menuOrdenamiento();
    printf("Ordenando...\n");
    switch(opcion)
    {
    	case 1:
    		if(ll_sort(pArrayListEmployee, employee_compareById, 1)!=0)
            {
    			retorno = -1;
    		}
    		break;
    	case 2:
    		if(ll_sort(pArrayListEmployee, employee_compareById, 0)!=0)
            {
				retorno = -1;
			}
			break;
    	case 3:
    		if(ll_sort(pArrayListEmployee, employee_compareByName, 1)!=0)
            {
				retorno = -1;
			}
			break;
    	case 4:
    		if(ll_sort(pArrayListEmployee, employee_compareByName, 0)!=0)
            {
				retorno = -1;
			}
			break;
        case 5:
    		if(ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, 1)!=0)
            {
    			retorno = -1;
    		}
    		break;
    	case 6:
    		if(ll_sort(pArrayListEmployee, employee_compareByHorasTrabajadas, 0)!=0)
            {
				retorno = -1;
			}
			break;
        case 7:
    		if(ll_sort(pArrayListEmployee, employee_compareBySueldo, 1)!=0)
            {
    			retorno = -1;
    		}
    		break;
    	case 8:
    		if(ll_sort(pArrayListEmployee, employee_compareBySueldo, 0)!=0)
            {
				retorno = -1;
			}
			break;
    }
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int id;
	int horasTrabajadas;
	int sueldo;
	char nombre[128];
	Employee* auxEmpleado=NULL;
	FILE* pFile=NULL;
	if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path, "w");
        if(pFile==NULL)
        {
            retorno = 0;
        }
        else
        {
            fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                if(auxEmpleado!=NULL &&
                   employee_getId(auxEmpleado, &id) &&
                   employee_getNombre(auxEmpleado, nombre) &&
                   employee_getHorasTrabajadas(auxEmpleado, &horasTrabajadas) &&
                   employee_getSueldo(auxEmpleado, &sueldo))
                {
                       fprintf(pFile, "%d,%s,%d,%d\n", id,nombre,horasTrabajadas,sueldo);
                }
            }
            retorno = 1;
            fclose(pFile);
        }
    }
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno=1;
	Employee* auxEmpleado=NULL;
	FILE* pFile=NULL;
	if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile = fopen(path, "wb");
        if(pFile==NULL)
        {
            retorno = 0;
        }
        else
        {
            for(int i=0; i<ll_len(pArrayListEmployee); i++)
            {
                auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
                if(fwrite(auxEmpleado, sizeof(Employee), 1, pFile)!=1)
                {
                    retorno=-1;
                    break;
                }
            }
            fclose(pFile);
        }
    }
	return retorno;
}
