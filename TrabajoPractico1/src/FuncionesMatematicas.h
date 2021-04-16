/*
 * funcionesMatematicas.h
 *
 *  Created on: 6 abr. 2021
 *      Author: Damian Lopez
 */

#ifndef FUNCIONESMATEMATICAS_H_
#define FUNCIONESMATEMATICAS_H_



#endif /* FUNCIONESMATEMATICAS_H_ */

/** \brief realiza la suma de dos enteros, almacena el resultado por referencia
 *
 * \param num1 int valor del primer operando
 * \param num2 int valor del segundo operando
 * \param resultado int* puntero al espacio en memoria donde se almacenara el resultado
 * \return int retorna 0 si pudo realizar la suma o -1 si no pudo
 *
 */
int suma(int num1, int num2, int* resultado);

/** \brief realiza la resta de dos enteros, almacena el resultado por referencia
 *
 * \param num1 int valor del primer operando
 * \param num2 int valor del segundo operando
 * \param resultado int* puntero al espacio en memoria donde se almacenara el resultado
 * \return int retorna 0 si pudo realizar la resta o -1 si no pudo
 *
 */
int resta(int num1, int num2, int* resultado);

/** \brief realiza la division de dos enteros, almacena el resultado por referencia
 *
 * \param num1 int valor del primer operando
 * \param num2 int valor del segundo operando
 * \param resultado float* puntero al espacio en memoria donde se almacenara el resultado
 * \return int retorna 0 si pudo realizar la division, -2 si el denominador es cero, o -1 si hubo otro error
 *
 */
int division(int num1, int num2, float* resultado);

/** \brief realiza la multiplicacion de dos enteros, almacena el resultado por referencia
 *
 * \param num1 int valor del primer operando
 * \param num2 int valor del segundo operando
 * \param resultado int* puntero al espacio en memoria donde se almacenara el resultado
 * \return int retorna 0 si pudo realizar la multiplicacion o -1 si no pudo
 *
 */
int multiplicacion(int num1, int num2, int* resultado);

/** \brief realiza el factorial de un entero, almacena el resultado por referencia
 *
 * \param num int valor del operando
 * \param unsigned long long int* resultado referencia para almacenar el resultado
 * \return int devuelve 0 si pudo realizar la operacion, -2 si el numero es negativo o -1 si hubo otro error
 *
 */
int factorial(int num, unsigned long long int* resultado);
