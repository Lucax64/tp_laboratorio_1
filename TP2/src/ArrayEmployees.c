
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "utn.h"

/**
 * \brief Inicializa el array cambiando en todas las posiciones a isEmpty en 1 (TRUE)
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int initEmployees(Employee* list, int len)
{
	int respuesta=-1;
	int i;

	if(list != NULL && len > 0)
	{
		respuesta=0;
		for(i=0;i<len;i++)
		{
			list[i].isEmpty = 1;
		}
	}

return respuesta;
}


/**
 * \brief Buscar primer posicion vacia
 * \param list Array de empleados
 * \param len Limite del array de empleados
 * \return Retorna el indice de la posicion vacia y -1 (ERROR)
 *
 */
int emp_getEmptyIndex(Employee* list,int len)
{
	int respuesta = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}


/**
 * \brief Da de alta un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \param id Identificador a ser asignado al empleado
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int addEmployee(Employee* list, int len, int indice, int* id)
{
	int respuesta = -1;
	Employee bufferEmpleado;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && id != NULL)
	{
		if(	utn_getNombre(bufferEmpleado.name,NAME_LEN,"\nNombre del empleado?\n","\nERROR\n",2) == 0 &&
			utn_getNombre(bufferEmpleado.lastName,LAST_NAME_LEN,"\nApellido del empleado?\n","\nERROR\n",2) == 0 &&
			utn_getNumeroFlotante(&bufferEmpleado.salary,"\nSalario del empleado?\n","\nERROR\n",0,100000,2) == 0 &&
			utn_getNumero(&bufferEmpleado.sector,"\nEn que sector se encuentra?\n","\nERROR\n",0,1000,2) == 0)
		{
			respuesta = 0;
			bufferEmpleado.id = *id;
			bufferEmpleado.isEmpty = 0;
			list[indice] = bufferEmpleado;
			(*id)++;
		}
	}
	return respuesta;
}


/** \brief Busca un ID en un array y devuelve la posicion en que se encuentra
* \param list Array de empleados
* \param len Limite del array de empleados
* \param id Puntero a la posicion del array donde se encuentra el valor buscado
* \return Return (-1) si no encuentra el valor buscado o Error [Invalid length or NULL pointer] - (0) si encuentra el valor buscado
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int respuesta = -1;
	int i;

	if(list != NULL && len > 0 && id >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				respuesta = i;
				break;
			}
		}
	}
	return respuesta;
}


/**
 * \brief Actualiza los datos de un empleado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param indice Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int modEmployee(Employee* list, int len, int indice)
{
	int respuesta=-1;
	int opcion;
	Employee arrayAuxiliar;

	if(list != NULL && len > 0 && indice < len && indice >= 0 && list[indice].isEmpty == 0)
	{
		if(utn_getNumero(&opcion,"\n\nIngrese el numero de lo que desea modificar: \n1)Nombre \n2)Apellido"
					"\n3)Salario \n4)Sector\n\n","\nError opcion invalida",1,5,2)==0)
		{
			switch(opcion)
			{
				case 1:
					if(utn_getNombre(arrayAuxiliar.name,NAME_LEN,"\nIngrese el nuevo nombre:\n","\nNombre invalido\n",2)==0)
					{
						strncpy(list[indice].name,arrayAuxiliar.name,NAME_LEN);
					}
					break;

			    case 2:
					if(utn_getNombre(arrayAuxiliar.lastName,LAST_NAME_LEN,"\nIngrese el nuevo apellido:\n","\nApellido invalido\n",2)==0)
					{
						strncpy(list[indice].lastName,arrayAuxiliar.lastName,LAST_NAME_LEN);
					}
			    	break;

			    case 3:
					if(utn_getNumeroFlotante(&arrayAuxiliar.salary,"\nIngrese el nuevo salario:\n","\nSalario invalido\n",0,100000,2)==0)
					{
						list[indice].salary = arrayAuxiliar.salary;
					}
			    	break;

			    case 4:
					if(utn_getNumero(&arrayAuxiliar.sector,"\nIngrese el nuevo sector:\n","\nSector invalido\n",0,1000,2)==0)
					{
						list[indice].sector = arrayAuxiliar.sector;
					}
			    	break;
			 }
			respuesta = 0;
		}
	}
	return respuesta;
}

/**
 * \brief Elimina lo cargado en una posicion del array
 * \param list Array de empleados a ser actualizado
 * \param len Limite del array de empleados
 * \param id Posicion a ser actualizada
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int removeEmployee(Employee* list, int len, int id)
{
	int respuesta = -1;
	if(list != NULL && len > 0 && id < len && id >= 0 && list[id].isEmpty == 0)
	{
		list[id].isEmpty = 1;
		respuesta = 0;
	}
	return respuesta;
}


/** \brief Sortea los elementos en el Array de empleados de menor a moayor
 * o viceversa
* \param list Array de empleados a ser actualizado
* \param len Limite del array de empleados
* \param order [1] ascendente - [0] descendente
* \return int Return (-1) Error [Invalid length or NULL pointer] - (0) Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	int respuesta=-1;
	Employee arrayAuxiliar;

    switch(order)
    {
        case 1:
            for(int i=0;i<len;i++)
            {
                for(int j=i+1;j<len;j++)
                {
                    if(list[i].sector > list[j].sector)
                    {
                    	arrayAuxiliar = list[i];
                        list[i] = list[j];
                        list[j] = arrayAuxiliar;
                        respuesta = 0;
                    }
                    else if(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName))
                    {
                    	arrayAuxiliar = list[i];
                    	list[i] = list[j];
                    	list[j] = arrayAuxiliar;
                        respuesta = 0;
                    }
                }
            }
            break;

        case 0:
            for(int i = 0; i<len; i++)
            {
                for(int j = i+1; j<len; j++)
                {
                    if(list[i].sector < list[j].sector)
                    {
                    	arrayAuxiliar = list[i];
                        list[i] = list[j];
                        list[j] = arrayAuxiliar;
                        respuesta= 0;
                    }
                    else if(list[i].sector == list[j].sector && strcmp(list[i].lastName,list[j].lastName))
                    {
                        arrayAuxiliar = list[i];
                        list[i] = list[j];
                        list[j] = arrayAuxiliar;
                        respuesta= 0;
                    }
                }
            }
            break;
    }

	return respuesta;
}


/**
 * \brief Imprime los datos de un empleado
 * \param list Puntero al empleado que se busca imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int emp_imprimir(Employee* list)
{
	int respuesta=-1;
	if(list != NULL && list->isEmpty == 0)
	{
		respuesta=0;
		printf("\nID del Empleado: %d \nNombre: %s \nApellido: %s \nSalario: %0.2f \nSector: %d\n",list->id,list->name,list->lastName,list->salary,list->sector);
	}
	return respuesta;
}


/**
 * \brief Imprime la lista de empleados
 * \param list Array de empleados a imprimir
 * \return Retorna 0 (EXITO) y -1 (ERROR)
 *
 */
int printEmployees(Employee* list, int length)
{
	int respuesta = -1;
	int i;
	if(list != NULL && length > 0)
	{
		respuesta = 0;
		for(i=0;i<length;i++)
		{
			emp_imprimir(&list[i]);
		}
	}
	return respuesta;
}


/** \brief Total del salario de empleados, el promedio de todos los salarios
 * y que salario excede el promedio
* \param list Array de empleados a calcular
* \param length Limite del array de empleados
* \return void
*
*/
void totalPromedioEmpleados(Employee* list, int len)
{
	float totalSalario;
	float promedioSalario;
	int contador;
	int empMasPromedio;
	int i;

	for(i=0;i<len;i++)
	{
        if(list[i].isEmpty == 0){
            totalSalario = list[i].salary + totalSalario;
            contador++;
        }
	}

	promedioSalario = totalSalario/contador;

    for(i=0;i<len;i++){
        if(list[i].salary > promedioSalario && list[i].isEmpty == 0){
        	empMasPromedio++;
        }
    }

    printf("\n\nEl total de los salarios es de: $%.2f \n",totalSalario);
    printf("El promedio de los salarios es de: $%.2f \n",promedioSalario);
    printf("La cantidad de empleados que superan el promedio es de: %d \n",empMasPromedio);

}
