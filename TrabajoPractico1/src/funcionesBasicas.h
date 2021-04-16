/*
 * funcionesBasicas.h
 *
 *  Created on: 6 abr. 2021
 *      Author: Usuario
 */

#ifndef FUNCIONESBASICAS_H_
#define FUNCIONESBASICAS_H_



#endif /* FUNCIONESBASICAS_H_ */

/** \brief muestra un menu de opciones de una calculadora immprimiendo dentro del mismo los valores de los operandos que hayan sido ingresados o los reemplaza con "x" e "y" respectivamente
 *
 * \param numUno int primer operando ("A"), si se hubiera ingresado
 * \param numDos int segundo operando ("B"), si se hubiera ingresado
 * \param flagNumUno int valor del flag que indica si se ingreso el primer operando
 * \param flagNumDos int valor del flag que indica si se ingreso el segundo operando
 * \return int devuelve la opcion elegida por el usuario
 *
 */
int mostrarMenu(int numUno, int numDos, int flagNumUno, int flagNumDos);

/** \brief solicita al usuario que ingrese un operando por teclado, lo almacena y carga el flag con valor 1 para saber que se ingreso el operando en cuestion.
 *         De haber hecho las operaciones con operandos ya ingresados pedira confirmacion para modificar el operando.
 *
 * \param operando int* puntero al espacio en memoria donde se guardara el operando
 * \param flagOperando int* puntero al espacio en memoria donde se guardara el flag que indica si se cargó o no el operando
 * \param flagCalculos int* puntero al espacio en memoria del flag que indica si se realizaron las operaciones matemáticas
 * \return void
 *
 */
void ingresarOperando(int* operando, int* flagOperando, int* flagCalculos);

/** \brief Muestra en pantalla los resultados de todas las operaciones realizadas o los problemas que surgieron en cada una
 *
 * \param sumaOk int valor de retorno de la funcion suma
 * \param restaOk int valor de retorno de la funcion resta
 * \param divisionOk int valor de retorno de la funcion division
 * \param multiplicacionOk int valor de retorno de la funcion multiplicacion
 * \param factorialAOk int valor de retorno de la funcion factorial de A
 * \param factorialBOk int valor de retorno de la funcion factorial de B
 * \param rSuma int valor del resultado de la operacion suma
 * \param rResta int valor del resultado de la operacion resta
 * \param rDivision float valor del resultado de la operacion division
 * \param rMultipicacion int valor del resultado de la operacion multiplicacion
 * \param unsigned long long int rFactorialA valor del resultado de la operacion factorial del primer operando
 * \param unsigned long long int rFactorialB valor del resultado de la operacion factorial del segundo operando
 * \param pFlagCalculos int flag que indica si se se realizaron o no las operaciones matematicas
 * \return void
 *
 */
void mostrarResultados(int sumaOk, int restaOk, int divisionOk, int multiplicacionOk, int factorialAOk, int factorialBOk, int rSuma, int rResta, float rDivision, int rMultipicacion, unsigned long long int rFactorialA, unsigned long long int rFactorialB, int flagCalculos);

/** \brief Solicita al usuario ingresar una opcion para confirmar o cancelar la salida y la valida
 *
 * \return char devuelve el caracter ingresado por el usuario, 's' para salir del programa o 'n' para seguir usando el programa
 *
 */
char validarSalida();

/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
 * \return int retorna 0 si se obtuvo el numero o -1 si no
 *
 */
int utn_getNumero(int* pResultado);
