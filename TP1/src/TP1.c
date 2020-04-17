/*
 TP1 Lucas Soria 1H

Enunciado:
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones */


#include <stdio.h>
#include <stdlib.h>
#include "bibliotecatp1.h"

int main(void)

{
	setbuf (stdout,NULL);

	int opcion;
	int respuesta;
    int operandoA=0;
    int operandoB=0;
    int resultadoSuma;
    int resultadoResta;
    int resultadoProducto;
    float resultadoDivision;
    int verificarDivision;
    int factoriales[2];

    do
    {
    	printf("Seleccione una opcion:\n\n1. Ingresar 1er operando (A=%d)\n2. Ingresar 2do operando (B=%d)\n",operandoA,operandoB);
    	respuesta = utn_getNumero(&opcion,"3. Calcular todas las operaciones\n4. Informar resultados\n5. Salir\n","No es una opcion valida\n\n",1,5,2);

    	if(respuesta==0)
    	{
    		switch(opcion)
    		{
    			case 1:
    				printf("Ingrese el numero A: \n");
    				fflush(stdin);
    				scanf("%d",&operandoA);
    				break;

    			case 2:
    				printf("Ingrese el numero B: \n");
    				fflush(stdin);
    				scanf("%d",&operandoB);
    				break;

    			case 3:
    				resultadoSuma = sumar(operandoA,operandoB);
    				resultadoResta = restar(operandoA,operandoB);
    				resultadoProducto = multiplicar(operandoA,operandoB);
    				verificarDivision = dividir(&resultadoDivision,operandoA,operandoB);
    				factoriales[0] = factor(operandoA);
    				factoriales[1] = factor(operandoB);
    				printf("Se calcularon las operaciones.\n\n");
    				break;

    			case 4:
    				printf("El resultado de A+B es: %d\n", resultadoSuma);
    				printf("El resultado de A-B es: %d\n", resultadoResta);

    				if(verificarDivision == 0)
    				{
    					printf("El resultado de A/B es: %f\n ", resultadoDivision);
    				}
    				else
    				{
    					printf("No es posible dividir por cero\n");
    				}

    				printf("El resultado de A*B es: %d\n", resultadoProducto);
    				printf("El factorial de A es: %d y El factorial de B es: %d\n\n", factoriales[0], factoriales[1]);
    				break;
    		}
    	}
    }while(opcion!=5);
}




