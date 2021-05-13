/*
 * dam.h
 *
 *  Created on: 12 may. 2021
 *      Author: Damian G. Lopez
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef DAM_H_
#define DAM_H_



#endif /* DAM_H_ */

int mainMenu();

/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado int* Puntero al espacio en memoria donde se dejara el resultado de la funcion
 * \param mensaje char* El mensaje a ser mostrado
 * \param mensajeError char* El mensaje de error a ser mostrado
 * \param minimo int El numero minimo a ser aceptado
 * \param maximo int El numero maximo a ser aceptado
 * \param reintentos int Cantidad de reintentos permitidos
 * \return int Retorna 0 si se obtuvo el numero o -1 si no
 *
 */
int dam_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

/** \brief Solicita un numero al usuario, luego de verificarlo devuelve el resultado
 *
 * \param pResultado float* Puntero al espacio en memoria donde se dejara el resultado de la funcion
 * \param mensaje char* El mensaje a ser mostrado
 * \param mensajeError char* El mensaje de error a ser mostrado
 * \param minimo int El numero minimo a ser aceptado
 * \param maximo int El numero maximo a ser aceptado
 * \param reintentos int Cantidad de reintentos permitidos
 * \return int Retorna 0 si se obtuvo el numero o -1 si no
 *
 */
int dam_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);

/** \brief Solicita un caracter al usuario entre 2 posibles, luego de verificarlo devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio en memoria donde se dejara el resultado de la funcion
 * \param mensaje char* El mensaje a ser mostrado
 * \param mensajeError char* El mensaje de error a ser mostrado
 * \param minimo int El primer caracter posible a ingresar
 * \param maximo int El segundo caracter posible a ingresar
 * \param reintentos int Cantidad de reintentos permitidos
 * \return int Retorna 0 si se obtuvo el caracter o -1 si no
 *
 */
int dam_getCaracter(char* pResultado, char* mensaje,char* mensajeError, char opcion1, char opcion2, int reintentos);

/** \brief Solicita un nombre al usuario, que puede ser simple o compuesto, luego de verificarlo devuelve el resultado
 *
 * \param pResultado char* Puntero al espacio en memoria donde se dejara el resultado de la funcion
 * \param mensaje char* El mensaje a ser mostrado
 * \param mensajeError char* El mensaje de error a ser mostrado
 * \param sizeNombre int El tamaño maximo aceptado para el nombre
 * \param reintentos int Cantidad de reintentos permitidos
 * \return int Retorna 0 si se obtuvo el nombre o -1 si no
 *
 */
int dam_getNombre(char* pResultado, char* mensaje, char* mensajeError, int sizeNombre, int reintentos);
