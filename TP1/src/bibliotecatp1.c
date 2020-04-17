#include <stdio.h>
#include <stdlib.h>

//Funcion para almacenar un numero, se muestra un mensaje, se pide el numero entre un rango determinado, si es invalido se muestra un mensaje de error y se da una cierta cantidad de intentos
int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos)

{

	int bufferInt; //donde se almacena la dirreccion del numero
	int retorno = -1; //respuesta negativa


	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s",mensaje); //mensaje
			scanf("%d",&bufferInt); //almacena la respuesta del usuario
			if(bufferInt >= minimo && bufferInt <= maximo) //el numero tiene que estar en el rango
			{
				*pResultado = bufferInt;
				retorno = 0; //respuesta positiva
				break; //corta el while
			}
			else //si no esta en el rango
			{
				printf("%s",mensajeError); //mensaje de error
				reintentos--; //se saca un reintento
			}
		}while(reintentos >= 0); //reitera mientra los reintentos sean mayor o igual a 0

	}
	return retorno;
}


int sumar(int operador1,int operador2) //funcion de sumar

{
	int resultadoSuma;

	resultadoSuma=operador1 + operador2; //suma

	return resultadoSuma;
}

int restar(int operador1,int operador2) //funcion de restar
{
	int resultadoResta;

	resultadoResta=operador1 - operador2; //resta

	return resultadoResta;
}

int multiplicar(int operador1,int operador2) //funcion de producto
{
	int resultadoProducto;

	resultadoProducto=operador1 * operador2; //multiplicacion

	return resultadoProducto;
}

int dividir (float* pResultadoDivision,int operador1, int operador2) //funcion de dividir (regresa al main un 0 o -1 a la direccion de la variable)

{
	float resultadoDivision;

	int retorno = -1; //regresara una respuesta negativa (no se puede dividir por cero)

	if(pResultadoDivision != NULL && operador2 != 0) //entrara si el operador 2 es ditinto de 0
	{
		resultadoDivision = (float) operador1 / operador2; //division

		*pResultadoDivision = resultadoDivision;

		retorno = 0; //cambia a una respuesta positiva
	}

	return retorno;
}

int factor(int numero) //funcion del factorial
{
	int factorial=1;

	for (int i=numero ; i>=1 ; i--) //reitera mientras el numero sea mayor o igual a 1 y se resta 1 en cada iteracion
	{
	factorial=factorial*i; //factorial (producto entre el numero y sus antecedentes positivos)
	}

	return factorial;
}
