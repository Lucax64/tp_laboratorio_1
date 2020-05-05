#ifndef BIBLIOTECATP1_H_
#define BIBLIOTECATP1_H_

int utn_getNumero(int* pResultado,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);
int sumar(int operador1,int operador2);
int restar(int operador1,int operador2);
int multiplicar(int operador1,int operador2);
float dividir (float* pResultadoDivision,int operador1, int operador2);
int factor(int numero);

#endif /* BIBLIOTECATP1_H_ */
