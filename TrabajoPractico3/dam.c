/**
 * dam.c
 *
 *  Created on: 20 Apr. 2021
 *      Author: Damian
 */
#include <ctype.h>
#include "dam.h"

static int getInt(int* pResultado);
static int myGets(char* cadena, int longitud);
static int esNumerico(char* cadena, int limite);

static int getCharacter(char* pResultado);
static int myGetsChar(char* cadena, int longitud);
static int esCaracter(char* cadena, int limite);

static int getCadenaChar(char* pResultado);
static int esNombre(char* cadena, int limite);

static int getFloat(float* pResultado);
static int esNumeroFlotante(char* cadena, int limite);


static int esTextoEspecial(char* cadena, int limite);
static int getTextoEspecial(char* pResultado);

/*******************************************************************************************************************************/

/** \brief Imprime un menu de opciones (menu principal), pide ingresar una y la valida
 *
 * \return int retorna la opcion validada.
 *
 */
int menuOpciones()
{
    int retorno=-1;
    printf("      *** MENU PRINCIPAL ***\n");
    printf("1) Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2) Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("3) Alta de empleado.\n");
    printf("4) Modificar datos de empleado.\n");
    printf("5) Baja de empleado.\n");
    printf("6) Listar empleados.\n");
    printf("7) Ordenar empleados.\n");
    printf("8) Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9) Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10) Salir.\n");

    while(retorno<1 || retorno>10)
    {
        dam_getNumero(&retorno,"Ingrese una opcion: ", "ERROR. Ingrese una opcion valida.\n",1,10,5);
    }
    return retorno;
}

/** \brief Imprime un menu de opciones (menu de modificaciones), pide ingresar una y la valida
 *
 * \return int retorna la opcion validada.
 *
 */
int menuModificacion()
{
    int retorno=0;
    printf("\n      *** MENU DE MODIFICACION ***\n");
    printf("1) Modificar nombre.\n");
    printf("2) Modificar horas trabajadas.\n");
    printf("3) Modificar sueldo.\n");
    printf("4) Cancelar modificacion.\n");
    printf("5) Guardar cambios y salir.\n");

    do
    {
        dam_getNumero(&retorno,"Ingrese una opcion: ", "ERROR. Ingrese una opcion valida.\n",1,5,5);
    }while(retorno<1 || retorno>5);
    return retorno;
}

/** \brief Imprime un menu de opciones (menu de criterios de ordenamiento), pide ingresar una y la valida
 *
 * \return int retorna la opcion validada.
 *
 */
int menuOrdenamiento()
{
    int retorno=0;
    printf("\n      *** MENU DE ORDENAMIENTO ***\n");
    printf("1) Ordenar por ID (ascendente).\n");
    printf("2) Ordenar por ID (descendente).\n");
    printf("3) Ordenar por Nombre (ascendente).\n");
    printf("4) Ordenar por Nombre (descendente).\n");
    printf("5) Ordenar por Horas Trabajadas (ascendente).\n");
    printf("6) Ordenar por Horas Trabajadas (descendente).\n");
    printf("7) Ordenar por Sueldo (ascendente).\n");
    printf("8) Ordenar por Sueldo (descendente).\n");
    printf("9) Salir.\n");

    do
    {
        dam_getNumero(&retorno,"Ingrese una opcion: ", "ERROR. Ingrese una opcion valida.\n",1,9,5);
    }while(retorno<1 || retorno>9);
    return retorno;
}

/** \brief Solicita un numero al usuario y lo valida como tal, guardandolo por referencia en una variable externa.
 *
 * \param pResultado int*
 * \param mensaje char*
 * \param mensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int
 *
 */
int dam_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
    int retorno=-1;
    int bufferInt;

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && minimo<=maximo && reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            if(getInt(&bufferInt)==0 && bufferInt>=minimo && bufferInt<=maximo)
            {
                *pResultado = bufferInt;
                retorno = 0;
                break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }

    return retorno;
}

/*******************************************************************************************************************************/

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

/*******************************************************************************************************************************/

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

/*******************************************************************************************************************************/

/** \brief Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena un maximo de 'longitud - 1' caracteres.
 *
 * \param cadena char* puntero al espacio en memoria donde se copiara la cadena obtenida
 * \param longitud int tamaño de la cadena
 * \return int retorna 0 si se obtiene una cadena y -1 si no
 *
 */
static int myGetsChar(char* cadena, int longitud)
{
    int retorno = -1;
    char bufferString[4096];
    if(cadena!=NULL && longitud>0)
    {
        fflush(stdin);
        gets(bufferString);
        if(strnlen(bufferString,sizeof(bufferString))<= longitud)
        {
            strncpy(cadena,bufferString,longitud);
            retorno=0;
        }
    }

    return retorno;
}

/*******************************************************************************************************************************/

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

/*******************************************************************************************************************************/

/** \brief Solicita un caracter al usuario de entre 2 posibles y lo valida como tal, guardandolo por referencia en una variable externa.
 *
 * \param pResultado char*
 * \param mensaje char*
 * \param mensajeError char*
 * \param opcion1 char
 * \param opcion2 char
 * \param reintentos int
 * \return int
 *
 */
int dam_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char opcion1, char opcion2, int reintentos)
{
	int retorno = -1;
	char bufferChar;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getCharacter(&bufferChar)==0 && (bufferChar==opcion1 || bufferChar==opcion2))
			{
				*pResultado=tolower(bufferChar);
				retorno = 0;
				break;
			}
			printf("%s",mensajeError);
			reintentos--;
		}while(reintentos>=0);

	}
	return retorno;
}

/*******************************************************************************************************************************/

/** \brief pide al usuario ingresar un caracter limita el tamaño de lo que se ingresa y si verifica que es un caracter valido y almacena el valor por referencia
 *
 * \param pResultado char* puntero al espacio en memoria donde se guardara el caracter obtenido
 * \return int retorna 0 si se guardo el caracter o -1 si no
 *
 */
static int getCharacter(char* pResultado)
{
    int retorno = -1;
    char bufferString;

    if(pResultado != NULL && !myGetsChar(&bufferString,sizeof(bufferString)) && esCaracter(&bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado=tolower(bufferString);
    }
    return retorno;
}

/*******************************************************************************************************************************/

/** \brief verifica si la cadena ingresada es un caracter
 *
 * \param cadena char* cadena de caracteres a ser analizada
 * \param limite int tamaño de la cadena a analizar
 * \return int Retorna 1 (verdadero) si la cadena es un caracter, 0 (falso) si no lo es o -1 en caso de error
 *
 */
static int esCaracter(char* cadena, int limite)
{
    int retorno=-1;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        if((cadena[0]<'A' || cadena[0]>'Z') && (cadena[0]<'a' || cadena[0]>'z') && limite>1)
        {
            retorno=0;
        }
    }
    return retorno;
}

/*******************************************************************************************************************************/

int dam_getNombre(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos)
{
    int retorno=-1;
    char bufferNombre[sizeNombre];

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && sizeNombre>0 && reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            if(getCadenaChar(bufferNombre)==0)
            {
                strcpy(pResultado,bufferNombre);
				retorno = 0;
				break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }

    return retorno;
}

/********************************************************************************************************************************/

/** \brief pide al usuario ingresar un array de de caracteres, limita los caracteres validos y almacena el array por referencia
 *
 * \param pResultado char* puntero al espacio en memoria donde se guardara el array obtenido
 * \return int retorna 0 si se guardo el array o -1 si no
 *
 */
static int getCadenaChar(char* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNombre(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        strcpy(pResultado,bufferString);
    }
    return retorno;
}

/*******************************************************************************************************************************/

/** \brief verifica si la cadena ingresada es un nombre
 *
 * \param cadena char* cadena de caracteres a ser analizada
 * \param limite int tamaño de la cadena a analizar
 * \return int Retorna 1 (verdadero) si la cadena es un nombre, 0 (falso) si no lo es o -1 en caso de error
 *
 */
static int esNombre(char* cadena, int limite)
{
    int retorno=-1;
    if (cadena!= NULL && limite>0)
    {
        retorno = 1;
        for(int i=0; i<limite && cadena[i]!='\0'; i++)
        {
            if(i==0 && cadena[i]==' ')
            {
                retorno=0;
                break;
            }
            else if(cadena[i]!=' ' && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z'))
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/*******************************************************************************************************************************/

int dam_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje);
			if(getFloat(&bufferFloat)==0 && bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			reintentos--;
            printf("%s",mensajeError);
		}while(reintentos >= 0);
	}
	return retorno;
}

/*******************************************************************************************************************************/

/** \brief pide al usuario ingresar un numero limita el tamaño de lo que se ingresa y si verifica que es un numero entero, convierte la cadena en entero y almacena el valor por referencia
 *
 * \param pResultado int* puntero al espacio en memoria donde se guardara el entero obtenido
 * \return int retorna 0 si se guardo el entero o -1 si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esNumeroFlotante(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        *pResultado = atof(bufferString);
    }
    return retorno;
}

/*******************************************************************************************************************************/

/** \brief verifica si la cadena ingresada es numerica
 *
 * \param cadena char* cadena de caracteres a ser analizada
 * \param limite int tamaño de la cadena a analizar
 * \return int Retorna 1 (verdadero) si la cadena es numerica, 0 (falso) si no lo es o -1 en caso de error
 *
 */

static int esNumeroFlotante(char* cadena, int limite)
{
    int retorno=-1;
    int flagComa=0;
    if(cadena!=NULL && limite>0)
    {
        retorno=1;
        for(int i=0;i<limite && cadena[i]!='\0';i++)
        {
            if(i==0 && (cadena[i]=='-' || cadena[i]=='+'))
            {
                continue;
            }
            if(cadena[i]==',')
            {
                if(flagComa==1 || i==0)
                {
                    retorno=0;
                    break;
                }
                flagComa=1;
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

/*******************************************************************************************************************************/

int dam_getTextoEspecial(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos)
{
    int retorno=-1;
    char bufferNombre[sizeNombre];

    if(pResultado!=NULL && mensaje!=NULL && mensajeError!=NULL && sizeNombre>0 && reintentos>=0)
    {
        do{
            printf("%s",mensaje);
            if(getTextoEspecial(bufferNombre)==0)
            {
                strcpy(pResultado,bufferNombre);
				retorno = 0;
				break;
            }
            reintentos--;
            printf("%s",mensajeError);
        }while(reintentos>=0);
    }

    return retorno;
}

/*******************************************************************************************************************************/

/** \brief verifica si la cadena ingresada es un texto especcial. Acepta ciertos caracteres especiales ('-', '_', '@' y espacio) y numeros
 *
 * \param cadena char* cadena de caracteres a ser analizada
 * \param limite int tamaño de la cadena a analizar
 * \return int Retorna 1 (verdadero) si la cadena es un nombre, 0 (falso) si no lo es o -1 en caso de error
 *
 */
static int esTextoEspecial(char* cadena, int limite)
{
    int retorno=-1;
    if (cadena!= NULL && limite>0)
    {
        retorno = 1;
        for(int i=0; i<limite && cadena[i]!='\0'; i++)
        {
            if(i==0 && cadena[i]==' ')
            {
                retorno=0;
                break;
            }
            else if(cadena[i]!=' ' && (cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A' || cadena[i]>'Z') && cadena[i]!='@' && cadena[i]!='-' && cadena[i]!='_' && (cadena[i]<0 || cadena[i]>9))
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

/********************************************************************************************************************************/

/** \brief pide al usuario ingresar un array de de caracteres (texto especial), limita los caracteres validos (con mas posibilidades que la funcion getCadenaChar() y almacena el array por referencia
 *
 * \param pResultado char* puntero al espacio en memoria donde se guardara el array obtenido
 * \return int retorna 0 si se guardo el array o -1 si no
 *
 */
static int getTextoEspecial(char* pResultado)
{
    int retorno = -1;
    char bufferString[4096];

    if(pResultado != NULL && !myGets(bufferString,sizeof(bufferString)) && esTextoEspecial(bufferString,sizeof(bufferString)))
    {
        retorno=0;
        strcpy(pResultado,bufferString);
    }
    return retorno;
}
