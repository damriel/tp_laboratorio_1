/*
 * funcionesMatematicas.h
 *
 *  Created on: 6 abr. 2021
 *      Author: Damian Lopez
 */

#ifndef FUNCIONESMATEMATICAS_H_
#define FUNCIONESMATEMATICAS_H_



#endif /* FUNCIONESMATEMATICAS_H_ */

/** \brief realiza la suma de dos enteros, almacena el resultado por referencia e informa si pudo realizar la operacion
 *
 * \param num1 int valor del primer operando
 * \param num2 int valor del segundo operando
 * \param resultado int* direccion de memoria del resultado de la suma
 * \return int devuelve 1 si pudo realizar la suma o 0 si no pudo realizarla
 *
 */
int suma(int num1, int num2, int* resultado);

/** \brief realiza la resta de dos enteros, almacena el resultado por referencia e informa si pudo realizar la operacion
 *
 * \param num1 int valor del primer operando
 * \param num2 int valor del segundo operando
 * \param resultado int* direccion de memoria del resultado de la suma
 * \return int devuelve 1 si pudo realizar la resta o 0 si no pudo realizarla
 *
 */
int resta(int num1, int num2, int* resultado);

/** \brief realiza la division de dos enteros, almacena el resultado por referencia e informa si pudo realizar la operacion
 *
 * \param num1 int valor del primer operando
 * \param num2 int valor del segundo operando
 * \param resultado float* referencia para almacenar el resultado
 * \return int devuelve 1 si pudo realizar la division o 0 si no pudo realizarla
 *
 */
int division(int num1, int num2, float* resultado);

/** \brief realiza la multiplicacion de dos enteros, almacena el resultado por referencia e informa si pudo realizar la operacion
 *
 * \param num1 int valor del primer operando
 * \param num2 int valor del segundo operando
 * \param resultado int* referencia para almacenar el resultado
 * \return int devuelve 1 si pudo realizar la multiplicacion o 0 si no pudo realizarla
 *
 */
int multiplicacion(int num1, int num2, int* resultado);

/** \brief realiza el factorial de un entero, almacena el resultado por referencia e informa si pudo realizar la operacion
 *
 * \param num int valor del operando
 * \param unsigned long long int* resultado referencia para almacenar el resultado
 * \return int devuelve 1 si pudo realizar la operacion o 0 si no pudo realizarla
 *
 */
int factorial(int num, unsigned long long int* resultado);
