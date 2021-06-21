#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
Employee* employee_newParametrosNoStr(int id, char* nombre, int horasTrabajadas, int sueldo);
int employee_delete(Employee* this);

int employee_showOneEmployee(Employee* this);
int employee_findById(LinkedList* pArrayListEmployee, int id);
int employee_generateId(LinkedList* pArrayListEmployee, int len);
int employee_editEmployee(LinkedList* pArrayListEmployee, int index);
int employee_compareById(void* empleado1, void* empleado2);
int employee_compareByName(void* empleado1, void* empleado2);
int employee_compareByHorasTrabajadas(void* empleado1, void* empleado2);
int employee_compareBySueldo(void* empleado1, void* empleado2);

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

#endif // employee_H_INCLUDED
