/*
 * TP2.c
 *
 *  Created on: 14 may. 2020
 *      Author: Lucas
 */
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "ArrayEmployees.h"
#define CANTIDAD_EMPLEADOS 1000

int main(void)
{
	setbuf (stdout,NULL);

	Employee arrayEmpleados[CANTIDAD_EMPLEADOS];

	int opcion;
	int idEmpleado=0;
	int auxiliarIndice;
	int auxiliarId;
	int orden;

	if(initEmployees(arrayEmpleados,CANTIDAD_EMPLEADOS) == 0)
	{
		printf("Array inicializado correctamente. \n\n");
	}

    do
    {

    	if(!utn_getNumero(	&opcion,
    								"\n\n1.ALTAS de empleados"
    								"\n2.MODIFICAR empleado"
    								"\n3.BAJA a empleado"
    								"\n4.INFORMAR (Lista de empleados y Promedio de salarios)"
    								"\n5.SALIR\n\n","\nError opcion invalida",1,5,2) )
    	{
    		switch(opcion)
    		{
    			case 1:
    				auxiliarIndice = emp_getEmptyIndex(arrayEmpleados,CANTIDAD_EMPLEADOS);
    				if(auxiliarIndice>=0)
    				{
    					if(addEmployee(arrayEmpleados,CANTIDAD_EMPLEADOS,auxiliarIndice,&idEmpleado)==0)
    					{
    						printf("\nEmpleado cargado con exito\n");
    					}
    					else
    					{
    						printf("\nNo se pueden cargar mas empleados (Limite: 1000 empleados)\n");
    					}
    				}
    				break;

    			case 2:
    				printEmployees(arrayEmpleados,CANTIDAD_EMPLEADOS);
    				if(utn_getNumero(&auxiliarId,"\nIndique el ID del Empleado a modificar:\n","\nID invalido\n",0,idEmpleado,2)==0)
    				{
    					auxiliarIndice = findEmployeeById(arrayEmpleados,CANTIDAD_EMPLEADOS,auxiliarId);
    					if(	auxiliarIndice >= 0 &&
    							modEmployee(arrayEmpleados,CANTIDAD_EMPLEADOS,auxiliarIndice) == 0)
    					{
    						printf("\nModificacion realizada con exito\n");
    					}
    				}
    				break;

    			case 3:
    				printEmployees(arrayEmpleados,CANTIDAD_EMPLEADOS);
    				if(utn_getNumero(&auxiliarId,"\nIndique el ID del Empleado a dar de baja:\n","\nID invalido\n",0,idEmpleado,2)==0)
    				{
    					auxiliarIndice = findEmployeeById(arrayEmpleados,CANTIDAD_EMPLEADOS,auxiliarId);
    					if(	auxiliarIndice >= 0 &&
    							removeEmployee(arrayEmpleados,CANTIDAD_EMPLEADOS,auxiliarIndice) == 0)
    					{
    						printf("\nBaja realizada con exito\n");
    					}
    				}
    				break;

    			case 4:
    				if(utn_getNumero(&orden,"\nInformar de manera Ascendente (1), o Descendente (0)?\n","\nNumero invalido\n",0,1,2)==0)
    				{
    					if(sortEmployees(arrayEmpleados,CANTIDAD_EMPLEADOS,orden)==0)
    					{
    						printEmployees(arrayEmpleados,CANTIDAD_EMPLEADOS);
    						totalPromedioEmpleados(arrayEmpleados,CANTIDAD_EMPLEADOS);
    					}
    				}
    				break;
    		}
    	}
    }while(opcion!=5);

	return EXIT_SUCCESS;
}



