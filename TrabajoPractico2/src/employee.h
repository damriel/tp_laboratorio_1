/*
 * employee.h
 *
 *  Created on: 12 may. 2021
 *      Author: Damian G. Lopez
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}eEmployee;

#endif /* EMPLOYEE_H_ */

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(eEmployee* list, int len);

/** \brief find an empty space in an existing list of employees and returns the index position in array.
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or empty space not found]
 *
 */
int findFree(eEmployee list[], int len);

/** \brief add in an existing list of employees the values received as parameters in the first empty position
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(eEmployee* list, int len, int id, char name[], char lastName[], float salary, int sector);

/** \brief Find an Employee by Id then returns the index position in array.
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee's ID that the user want to search for
 * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found]
 *
 */
int findEmployeeById(eEmployee* list, int len,int id);

/** \brief Show up a modify menu for the selected employee.
 *
 * \return int option selected or (0) if too many invalid options entered.
 *
 */
int modifyMenu();

/** \brief Modify an Employee (ask what info want to modify and validates the inputs)
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
 int modifyEmployee(eEmployee* list, int len);

/** \brief Remove an Employee by Id (put isEmpty Flag in 1)
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \param id int Employee's ID that the user want to remove
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(eEmployee* list, int len, int order);

/** \brief print the content of employees array
 *
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \return int
 *
 */
int printEmployees(eEmployee* list, int len);

/** \brief print the content of one employee
 *
 * \param anEmploye eEmployee Employee
 *
 */
void printOneEmployee(eEmployee anEmployee);

int reportMenu();

int reportTwo(eEmployee* list, int len);
