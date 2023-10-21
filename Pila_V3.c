// Emmanuel Gonzalez Contreras
#include "Pilas.h"
#include <math.h>

int prec(char operador1, char operador2)
{
	int jer1,jer2;
	
	if(operador1 == '^')
		jer1 = 5;
	if(operador1 == '*' || operador1 == '/')
		jer1 = 4;
	if(operador1 == '+' || operador1 == '-')
		jer1 = 3;
	// 													Estos operandos deben ser menores a los op2
	if(operador1 == ')') 
		jer1 = 0;
	if(operador1 == '(')
		jer1 = 1;
	
	if(operador2 == '^')
		jer2 = 5;
	if(operador2 == '*' || operador2 == '/')
		jer2 = 4;
	if(operador2 == '+' || operador2 == '-')
		jer2 = 3;
	if(operador2 == '(') // 							Este operando debe ser mayor para que prec sea = 0
		jer2 = 6;
	if(operador2 == ')') // 							Este opereando debe ser menor para los operandos ^,*,/,+,- entren y se true pero mayor a (,)
		jer2 = 2;
		
	if(jer1 >= jer2)
		return 1;
	else
		return 0;
}
float evaluar(char expresion[])
 {
 	union datos cubeta;
 	char symb,aux[1];
 	int i = 0;
 	float opnd1,opnd2,value;
 	nodo *p = NULL;
 	while(expresion[i] != '\0')
	{
 		symb = expresion[i];
		if(symb != '^' && symb != '*' && symb != '/' && symb != '+' && symb != '-' )
		{
			cubeta.flo = symb;
			cubeta.flo = cubeta.flo - 48;
			p = push(p,cubeta); // symb es el nuemero, pero al convertirlo a float se le suma a ese numero 48 es por eso que se le resta
		}
		else
		{
			p = pop(p,&cubeta);
			opnd1 = cubeta.flo;
			p = pop(p,&cubeta);
			opnd2 = cubeta.flo;
			if(symb == '^')					// se analiza el orden de la operacion
				value = (pow(opnd2,opnd1));
			if(symb == '+')
				value = (opnd1+opnd2);
			if(symb == '-')
				value = (opnd2-opnd1);
			if(symb == '*')
				value = (opnd1*opnd2);
			if(symb == '/')
				value = (opnd2/opnd1);
			cubeta.flo = value;
			p = push(p,cubeta);				// entra el resultado de dicha operacion
		}
		i++;
	}
	p = pop(p,&cubeta);
	value = cubeta.flo;
	return value;
 }

void postfijo(char expresion[])
{
	union datos cubeta;
	char symb,topsymb;
	int i=0,j=0;
	nodo *pila = NULL;
	char post[50];
	while(expresion[i] != '\0')
	{
		symb = expresion[i];
		if(symb != '^' && symb != '*' && symb != '/' && symb != '+' && symb != '-' && symb != '(' && symb != ')'  )
		{
			post[j] = symb;
			j++;
		}
		else
		{
			stackTop(pila,&cubeta);// 									Analiza y regresa el dato donde esta apuntado y se lo da topsymb
			topsymb = cubeta.cha;
			while(!isEmpty(pila) == 1 && prec(topsymb,symb) == 1)
			{
				pila = pop(pila,&cubeta); // 							Saca el dato de la pila
				topsymb = cubeta.cha;
				post[j] = topsymb;
				j++;
				stackTop(pila,&cubeta);// 								Actualiza el dato
				topsymb = cubeta.cha;
			}
			if(isEmpty(pila) == 1 || symb != ')')
			{
				cubeta.cha = symb;
				pila = push(pila,cubeta);
			}
			else
			{
				pila = pop(pila,&cubeta);
				topsymb = cubeta.cha;
			}
				
		}
		i++;
	}
	while(!isEmpty(pila) == 1)
	{
		pila = pop(pila,&cubeta);
		topsymb = cubeta.cha;
		post[j] = topsymb;
		j++;
	}
	printf("\nPostfijo: %s\n",post);
	printf("\nEl resultado es: %.2f\n",evaluar(post));
}
 int main()
{
	char cadena[50];// (7+2)*2-1 == 72+2*1- = 17
	printf("Ingresa la operacion: ");
	scanf("%s",cadena);
	postfijo(cadena);
	pausa;
	return 0;	
}
