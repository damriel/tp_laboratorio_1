#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "dam.h"

/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo Employee y deja todos sus campos inicializados
 *
 * \return Employee* retorna un puntero al lugar de la memoria asignado
 *
 */
Employee* employee_new()
{
    Employee* newEmployee = (Employee*)malloc(sizeof(Employee));
    if(newEmployee!=NULL)
    {
        newEmployee->id=0;
        strcpy(newEmployee->nombre,"");
        newEmployee->horasTrabajadas=0;
        newEmployee->sueldo=0;
    }
    return newEmployee;
}

/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo Employee cargando en todos sus campos los datos pasados como parametros en formato de array de caracteres
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* newEmployee = employee_new();
    if(newEmployee!=NULL)
    {
        employee_setId(newEmployee, atoi(idStr));
        employee_setNombre(newEmployee, nombreStr);
        employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
        employee_setSueldo(newEmployee, atoi(sueldoStr));
    }
    return newEmployee;
}

/** \brief asigna un lugar de la memoria dinamica para un elemento de tipo Employee cargando en todos sus campos los datos pasados como parametros en los formatos correspondientes
 *
 * \param id int
 * \param nombre char*
 * \param horasTrabajadas int
 * \param sueldo int
 * \return Employee*
 *
 */
Employee* employee_newParametrosNoStr(int id, char* nombre, int horasTrabajadas, int sueldo)
{
	Employee* newEmployee = employee_new();

	if(newEmployee!=NULL)
    {
        employee_setId(newEmployee, id);
        employee_setNombre(newEmployee, nombre);
        employee_setHorasTrabajadas(newEmployee, horasTrabajadas);
        employee_setSueldo(newEmployee, sueldo);
    }

	return newEmployee;
}

/** \brief Libera el espacio en memoria apuntado por "this"
 *
 * \param this Employee*
 * \return int
 *
 */
int employee_delete(Employee* this)
{
    int retorno=0;
    if(this!=NULL)
    {
        free(this);
        retorno=1;
    }
    return retorno;
}

/** \brief Muestra un unico empleado
 *
 * \param this Employee*
 * \return int
 *
 */
int employee_showOneEmployee(Employee* this)
{
    int retorno = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    if(this!=NULL &&
       employee_getId(this, &id) &&
       employee_getNombre(this, nombre) &&
       employee_getHorasTrabajadas(this, &horasTrabajadas) &&
       employee_getSueldo(this, &sueldo))
    {
        printf(" %4d   %16s     %8d     %10d\n",id,nombre,horasTrabajadas,sueldo);
        retorno=1;
    }
    return retorno;
}

/** \brief Genera el siguiente ID en funcion del ID mas grande que se encuentre en el array de empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \param len int
 * \return int
 *
 */
int employee_generateId(LinkedList* pArrayListEmployee, int len)
{
	int idMaximo=0;
	int idActual;
	Employee* auxEmpleado;

	if(!ll_isEmpty(pArrayListEmployee))
    {
		for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &idActual);
			if(idActual>idMaximo || i==0)
			{
				idMaximo=idActual;
			}
		}
	}
	return idMaximo+1;
}

/** \brief Busca un empleado por su ID en el LinkedList
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 *
 */
int employee_findById(LinkedList* pArrayListEmployee, int id)
{
	int index;
	int idActual;
	Employee* auxEmpleado;
	index=-1;

	if(pArrayListEmployee!=NULL)
    {
		for(int i=0; i<ll_len(pArrayListEmployee); i++)
        {
			auxEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
			employee_getId(auxEmpleado, &idActual);
			if(idActual==id)
            {
				index=i;
				break;
			}
		}
	}
	else
	{
		printf("Error. No se encuentra la lista.\n");
	}

	return index;
}

/** \brief Modifica uno o varios valores del empleado del cual se informe el ID
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int
 *
 */
int employee_editEmployee(LinkedList* pArrayListEmployee, int index)
{
	int retorno = -1;
	int opcion = 0;
	int flag=0;
	int horasTrabajadas;
	int sueldo;
	char confirmar=' ';
	char nombre[128];
	Employee* auxEmpleado = ll_get(pArrayListEmployee, index);
	Employee* auxEmpleado2 = (Employee*) malloc(sizeof(Employee));

	if(pArrayListEmployee!=NULL && auxEmpleado!=NULL && auxEmpleado2!=NULL)
    {
        retorno=0;
        //Copia de respaldo
        employee_getId(auxEmpleado, &auxEmpleado2->id);
        employee_getNombre(auxEmpleado, auxEmpleado2->nombre);
        employee_getHorasTrabajadas(auxEmpleado, &auxEmpleado2->horasTrabajadas);
        employee_getSueldo(auxEmpleado, &auxEmpleado2->sueldo);

        printf("\n  ID           Nombre       Horas Trabajadas   Sueldo\n");
        employee_showOneEmployee(auxEmpleado);
        do
        {
            opcion = menuModificacion();
            switch(opcion)
            {
                case 1:
                    dam_getNombre(nombre,"Ingrese nuevo nombre: ", "Error. No es un nombre valido.\n",128,5);
                    employee_setNombre(auxEmpleado, nombre);
                    printf("\n  ID           Nombre       Horas Trabajadas   Sueldo\n");
                    employee_showOneEmployee(auxEmpleado);
                    flag=1;
                    break;
                case 2:
                    dam_getNumero(&horasTrabajadas, "Ingrese nueva cantidad de horas trabajadas: ","ERROR. Intente nuevamente (limite 0-99999).\n",0,99999,5);
                    employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas);
                    printf("\n  ID           Nombre       Horas Trabajadas   Sueldo\n");
                    employee_showOneEmployee(auxEmpleado);
                    flag=1;
                    break;
                case 3:
                    dam_getNumero(&sueldo, "Ingrese nuevo sueldo: ","ERROR. Intente nuevamente (limite 1-999999).\n",0,99999,5);
                    employee_setSueldo(auxEmpleado, sueldo);
                    printf("\n  ID           Nombre       Horas Trabajadas   Sueldo\n");
                    employee_showOneEmployee(auxEmpleado);
                    flag=1;
                    break;
                case 4:
                    if(flag)
                    {
                        do
                        {
                            dam_getCaracter(&confirmar,"Si continua se perderan los cambios realizados hasta el momento. Desea continuar? (S/N): ","Error.\n",'n','s',1);
                        }while(confirmar!='n' && confirmar!='s');
                        if(confirmar=='s')
                        {
                            employee_setNombre(auxEmpleado, auxEmpleado2->nombre);
                            employee_setHorasTrabajadas(auxEmpleado, auxEmpleado2->horasTrabajadas);
                            employee_setSueldo(auxEmpleado, auxEmpleado2->sueldo);
                            printf("Modificacion cancelada.\n");
                        }
                        else
                        {
                            printf("Se mantuvieron los cambios. Volviendo al menu de modificacion.\n");
                        }
                    }
                    break;
                case 5:
                    printf("Empleado modificado y guardado con exito!\n");
                    break;
            }
        }while(opcion!=4 && opcion!=5);
        employee_delete(auxEmpleado2);
        printf("\n  ID           Nombre       Horas Trabajadas   Sueldo\n");
        employee_showOneEmployee(auxEmpleado);
        printf("\n\n");
    }

	return retorno;
}

/** \brief Compara a los empleados del LinkedList por su ID
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int Retorna 1 si el primer valor es mas grande, -1 si el segundo es mas grande o 0 si son iguales
 *
 */
int employee_compareById(void* empleado1, void* empleado2)
{
	int retorno;

	if(empleado1!=NULL && empleado2!=NULL)
    {
        if(((Employee*)empleado1)->id > ((Employee*)empleado2)->id)
        {
            retorno=1;
        }
        else if(((Employee*)empleado1)->id < ((Employee*)empleado2)->id)
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }

	return retorno;
}

/** \brief Compara a los empleados del LinkedList por su Nombre
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int Retorna 1 si el primer valor es mas grande, -1 si el segundo es mas grande o 0 si son iguales
 *
 */
int employee_compareByName(void* empleado1, void* empleado2)
{
	int retorno;

	if(empleado1!=NULL && empleado2!=NULL)
    {
        if(strcmp(((Employee*)empleado1)->nombre, ((Employee*)empleado2)->nombre)>0)
        {
            retorno=1;
        }
        else if(strcmp(((Employee*)empleado1)->nombre, ((Employee*)empleado2)->nombre)<0)
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }

	return retorno;
}

/** \brief Compara a los empleados del LinkedList por las Horas Trabajadas de cada uno
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int Retorna 1 si el primer valor es mas grande, -1 si el segundo es mas grande o 0 si son iguales
 *
 */
int employee_compareByHorasTrabajadas(void* empleado1, void* empleado2)
{
	int retorno;

	if(empleado1!=NULL && empleado2!=NULL)
    {
        if(((Employee*)empleado1)->horasTrabajadas > ((Employee*)empleado2)->horasTrabajadas)
        {
            retorno=1;
        }
        else if(((Employee*)empleado1)->horasTrabajadas < ((Employee*)empleado2)->horasTrabajadas)
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }

	return retorno;
}

/** \brief Compara a los empleados del LinkedList por su sueldo
 *
 * \param empleado1 void*
 * \param empleado2 void*
 * \return int Retorna 1 si el primer valor es mas grande, -1 si el segundo es mas grande o 0 si son iguales
 *
 */
int employee_compareBySueldo(void* empleado1, void* empleado2)
{
	int retorno;

	if(empleado1!=NULL && empleado2!=NULL)
    {
        if(((Employee*)empleado1)->sueldo > ((Employee*)empleado2)->sueldo)
        {
            retorno=1;
        }
        else if(((Employee*)empleado1)->sueldo < ((Employee*)empleado2)->sueldo)
        {
            retorno=-1;
        }
        else
        {
            retorno=0;
        }
    }

	return retorno;
}

        ///SETTERS Y GETTERS

int employee_setId(Employee* this, int id)
{
    int retorno=0;
    if(this!=NULL && id>0)
    {
        this->id=id;
        retorno=1;
    }
    return retorno;
}

int employee_getId(Employee* this, int* id)
{
    int retorno=0;
    if(this!=NULL)
    {
        *id = this->id;
        retorno=1;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL && strlen(nombre)>1 && strlen(nombre)<30)
    {
        strcpy(this->nombre,nombre);
        retorno=1;
    }
    return retorno;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=0;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=1;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=0;
    if(this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=1;
    }
    return retorno;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=0;
    if(this!=NULL && horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=1;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo>0)
    {
        this->sueldo=sueldo;
        retorno=1;
    }
    return retorno;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=0;
    if(this!=NULL && sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=1;
    }
    return retorno;
}
