#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "dam.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.bin (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int option;
    char continuar='s';
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        option = menuOpciones();
        switch(option)
        {
            case 1:
                if(!ll_isEmpty(listaEmpleados))
                {
                    printf("Ya hay datos cargados en la lista, si continua se sobreescribira la informacion.\n");
                    dam_getCaracter(&continuar,"Desea continuar? (S/N): ","ERROR. Ingrese una opcion valida.\n",'s','n',2);
                    if(continuar=='n')
                    {
                        break;
                    }
                    else
                    {
                        ll_clear(listaEmpleados);
                    }
                }
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    printf("Empleados del archivo 'data.cvs' cargados con exito!\n\n");
                }
                else
                {
                    printf("Ocurrio un error intentando abrir el archivo (no existe, no se pudo abrir o esta corrompido).\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 2:
                if(!ll_isEmpty(listaEmpleados))
                {
                    printf("Ya hay datos cargados en la lista, si continua se sobreescribira la informacion.\n");
                    dam_getCaracter(&continuar,"Desea continuar? (S/N): ","ERROR. Ingrese una opcion valida.\n",'s','n',2);
                    if(continuar=='n')
                    {
                        break;
                    }
                    else
                    {
                        ll_clear(listaEmpleados);
                    }
                }
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("Empleados del archivo 'data.bin' cargados con exito!\n\n");
                }
                else
                {
                    printf("Ocurrio un error intentando abrir el archivo (no existe, no se pudo abrir o esta corrompido).\n\n");
                }
                system("pause");
                system("cls");
                break;
            case 3:
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("Empleado cargado con exito!\n");
                }
                else
                {
                    printf("Ocurrio un error. No se pudo cargar al empleado.\n");
                }
                system("pause");
                system("cls");
                break;
            case 4:
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("Aun no hay empleados cargados.\n");
                }
                else
                {
                    controller_ListEmployee(listaEmpleados);
                    controller_editEmployee(listaEmpleados);
                }
                system("pause");
                system("cls");
                break;
            case 5:
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("Aun no hay empleados cargados.\n");
                }
                else
                {
                    controller_ListEmployee(listaEmpleados);
                    if(controller_removeEmployee(listaEmpleados))
                    {
                        printf("Baja exitosa.\n");
                    }
                    else
                    {
                        printf("No se pudo realizar la baja.\n");
                    }
                }
                system("pause");
                system("cls");
                break;
            case 6:
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("Aun no hay empleados cargados.\n");
                }
                else
                {
                    controller_ListEmployee(listaEmpleados);
                }
                system("pause");
                system("cls");
                break;
            case 7:
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("Aun no hay empleados cargados.\n");
                }
                else
                {
                    if(controller_sortEmployee(listaEmpleados))
                    {
                        printf("Lista de empleados ordenada con exito!\n");
                    }
                    else
                    {
                        printf("Ha ocurrido un error. No se pudo ordenar la lista.\n");
                    }
                }
                system("pause");
                system("cls");
                break;
            case 8:
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("Aun no hay empleados cargados.\n");
                }
                else
                {
                    if(controller_saveAsText("data.csv",listaEmpleados))
                    {
                        printf("Lista guardada como texto en data.csv\n");
                    }
                    else
                    {
                        printf("Ocurrio un error.\n");
                    }
                }
                system("pause");
                system("cls");
                break;
            case 9:
                if(ll_isEmpty(listaEmpleados))
                {
                    printf("Aun no hay empleados cargados.\n");
                }
                else
                {
                    if(controller_saveAsBinary("data.bin",listaEmpleados))
                    {
                        printf("Lista guardada como binario en data.bin\n");
                    }
                    else
                    {
                        printf("Ocurrio un error.\n");
                    }
                }
                system("pause");
                system("cls");
                break;
        }
    }while(option!=10);
    ll_deleteLinkedList(listaEmpleados);

    return 0;
}

