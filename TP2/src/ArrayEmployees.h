/*
 * ArrayEmployees.h
 *
 *  Created on: 14 may. 2020
 *      Author: Lucas
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define NAME_LEN 51
#define LAST_NAME_LEN 51

typedef struct
{
	int id;
	char name[NAME_LEN];
	char lastName[LAST_NAME_LEN];
	float salary;
	int sector;
	int isEmpty;

}Employee;

int initEmployees(Employee* list, int len);
int emp_getEmptyIndex(Employee* array,int len);
int addEmployee(Employee* list, int len, int indice, int* id);
int findEmployeeById(Employee* list, int len,int id);
int modEmployee(Employee* list, int len, int indice);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int emp_imprimir(Employee* list);
int printEmployees(Employee* list, int length);
void totalPromedioEmpleados(Employee* list, int len);

#endif /* ARRAYEMPLOYEES_H_ */
