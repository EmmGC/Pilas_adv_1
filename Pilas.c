//Emmanuel Gonzalez Contreras
#include "Pilas.h"

int prec(char operador1, char operador2)
{
	int jer1,jer2;
	if(operador1 == '^')
		jer1 = 3;
	if(operador1 == '*' || operador1 == '/')
		jer1 = 2;
	if(operador1 == '+' || operador1 == '-')
		jer1 = 1;
	
	if(operador2 == '^')
		jer2 = 3;
	if(operador2 == '*' || operador2 == '/')
		jer2 = 2;
	if(operador2 == '+' || operador2 == '-')
		jer2 = 1;
		
	if(jer1 >= jer2)
		return 1;
	else
		return 0;
}

void postfijo(char expresion[])
{
	char symb,topsymb,aux = 0;
	int i=0,j=0;
	nodo *pila = NULL;
	//nodo *stack = NULL;
	char postfijo[50];
	while(expresion[i] != '\0')
	{
		symb = expresion[i];
		if(symb != '^' && symb != '*' && symb != '/' && symb != '+' && symb != '-' )
		{
			postfijo[j] = symb;
			j++;
		}
		else
		{
			pila = stackTop(pila,&aux);
			while(!isEmpty(pila) == 1 && prec(aux,symb) == 1)
			{
				pila = pop(pila,&aux);
				topsymb = aux;
				postfijo[j] = topsymb;
				j++;
			}
			pila = push(pila,symb);
		}
		i++;
	}
	while(isEmpty(pila) != 1)
	{
		pila = pop(pila,&aux);
		topsymb = aux;
		postfijo[j] = topsymb;
		j++;
	}
	i =0;
	while(postfijo[i] != '\0')
	{
		printf("%c",postfijo[i]);
		i++;	
	}
	printf("\n");
}

int main()
{
	char cadena[50] = "7+2*5-3";// 725*+3-
	/*printf("Dame una expresion aritmetica: ");
	gets(cadena);*/
	postfijo(cadena);
	pausa;
	return 0;	
}
