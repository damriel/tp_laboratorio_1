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
 *         De haber hecho las operaciones con operandos ya ingresados avisara que debera realizar nuevamente las operaciones si cambia el operando almacenado.
 *
 * \param operando int* direccion de memoria del operando a ingresar
 * \param flagOperando int* direccion de memoria del flag que indica si se cargó o no el operando
 * \param flagCalculos int* direccion de memoria del flag que indica si se realizaron las operaciones matemáticas
 * \return void
 *
 */
void ingresarOperando(int* operando, int* flagOperando, int* flagCalculos);

/** \brief Muestra en pantalla los resultados de todas las operaciones realizadas o los problemas que surgieron en cada una
 *
 * \param operando1 int valor del primer operando
 * \param operando2 int valor del segundo operando
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
void mostrarResultados(int operando1, int operando2, int rSuma, int rResta, float rDivision, int rMultipicacion, unsigned long long int rFactorialA, unsigned long long int rFactorialB, int pFlagCalculos);

/** \brief Solicita al usuario ingresar una opcion para confirmar o cancelar la salida y la valida
 *
 * \return char devuelve el caracter ingresado por el usuario, 's' para salir del programa o 'n' para seguir usando el programa
 *
 */
char validarSalida();
