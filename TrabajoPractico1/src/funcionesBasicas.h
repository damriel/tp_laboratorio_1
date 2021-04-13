/*
 * funcionesBasicas.h
 *
 *  Created on: 6 abr. 2021
 *      Author: Usuario
 */

#ifndef FUNCIONESBASICAS_H_
#define FUNCIONESBASICAS_H_



#endif /* FUNCIONESBASICAS_H_ */

/** \brief muestra un menu de opciones de una calculadora immprimiendo dentro del mismo los valores de los operandos que hayan sido ingresados o los reemplaza con "x" e "y"
 *
 * \param numUno int recibe el primer operando ("A") si se hubiera ingresado
 * \param numDos int recibe el segundo operando ("B") si se hubiera ingresado
 * \param flagNumUno int recibe 1 si se ingreso el primer operando o 0 si no fue ingresado
 * \param flagNumDos int recibe 1 si se ingreso el segundo operando o 0 si no fue ingresado
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
 * \param operando1 int recibe el valor del primer operando
 * \param operando2 int recibe el valor del segundo operando
 * \param rSuma int recibe el resultado de la operacion suma
 * \param rResta int recibe el resultado de la operacion resta
 * \param rDivision float recibe el resultado de la operacion division
 * \param rMultipicacion int recibe el resultado de la operacion multiplicacion
 * \param unsigned long long int rFactorialA recibe el resultado de la operacion factorial del primer operando
 * \param unsigned long long int rFactorialB recibe el resultado de la operacion factorial del segundo operando
 * \param pFlagCalculos int recibe 0 si no se realizaron las operaciones o 1 si han sido realizadas
 * \return void
 *
 */
void mostrarResultados(int operando1, int operando2, int rSuma, int rResta, float rDivision, int rMultipicacion, unsigned long long int rFactorialA, unsigned long long int rFactorialB, int pFlagCalculos);

/** \brief Pide y valida la opcion de salida cuando es seleccionada por el usuario
 *
 * \return char devuelve el caracter ingresado por el usuario, 's' para salir del programa o 'n' para seguir usando el programa
 *
 */
char validarSalida();
