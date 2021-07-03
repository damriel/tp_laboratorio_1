#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "dam.h"

int main()
{
    /*
    int ll_set(LinkedList* this, int index,void* pElement);
    int ll_remove(LinkedList* this,int index);
    int ll_clear(LinkedList* this);
    int ll_deleteLinkedList(LinkedList* this);
    int ll_indexOf(LinkedList* this, void* pElement);
    int ll_isEmpty(LinkedList* this);
    int ll_push(LinkedList* this, int index, void* pElement);
    void* ll_pop(LinkedList* this,int index);
    int ll_contains(LinkedList* this, void* pElement);
    int ll_containsAll(LinkedList* this,LinkedList* this2);
    LinkedList* ll_subList(LinkedList* this,int from,int to);
    LinkedList* ll_clone(LinkedList* this);
    int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);
    LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*));
    */
    int option;
    LinkedList* lista = NULL;
    int tam;
    int auxTam;
    int indexOpt9;
    Employee emp1 = {1, "Juan", 50, 10000};
    Employee emp2 = {2, "Bob", 32, 5000};
    Employee emp3 = {3, "Pedro", 70, 15000};
    Employee emp4 = {4, "Gaston", 88, 19500};

    Employee auxEmp = {0, "Empty", 0, 0};

    do{
        option = menuOpciones();
        tam = ll_len(lista);
        switch(option){
            case 1:
                lista = ll_newLinkedList();
                if(lista!=NULL)
                {
                    printf("Se creo una nueva LinkedList vacia.\n");
                }
                break;
            case 2:
                if(tam>=0)
                {
                    printf("Tamanio de la LinkedList: %d\n",tam);
                }
                else
                {
                    printf("ERROR. La lista no existe.\n");
                }
                break;
            case 3:
                if(!ll_add(lista, &emp1) &&
                   !ll_add(lista, &emp2) &&
                   !ll_add(lista, &emp3) &&
                   !ll_add(lista, &emp4))
                {
                    printf("Se agregaron 4 empleados a la LinkedList.\n");
                }
                break;
            case 4:
                auxTam = tam;
                while(auxTam!=0)
                {
                    employee_showOneEmployee(ll_get(lista, auxTam));
                    auxTam--;
                }
                break;
            case 5:
                auxTam = 0;
                for(int i=0; i<tam; i++)
                {
                    if(!ll_set(lista, i, &auxEmp))
                    {
                        auxTam++;
                    }
                }
                if(auxTam==tam)
                {
                    printf("Se setearon todos los empleados a los valores iniciales.\n");
                }
                break;
            case 6:
                if(!ll_remove(lista, tam-1))
                {
                    printf("Se ha eliminado el ultimo empleado de la lista.\n");
                }
                break;
            case 7:
                if(!ll_clear(lista))
                {
                    printf("Se eliminaron todos los empleados de la lista.\n");
                }
                break;
            case 8:
                if(!ll_deleteLinkedList(lista))
                {
                    printf("La lista de empleados ya no existe...\n\n");
                    printf("Creando nueva lista vacia para continuar las pruebas.\n");
                    lista = ll_newLinkedList();
                }
                break;
            case 9:
                indexOpt9 = ll_indexOf(lista, &emp2);
                if(indexOpt9!=-1)
                {
                    printf("Se busco el indice del empleado: ");
                    employee_showOneEmployee(&emp2);
                    printf("\nSu indice es: %d",indexOpt9);
                }
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                break;
            case 15:
                break;
            case 16:
                break;
            case 17:
                break;
            case 18:
                break;
            case 19:
                break;
            case 20:
                break;
        }
    }while(option!=21);

    free(lista);
    return 0;
}
