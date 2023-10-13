//Emmanuel Gonzalez Contreras
#include "Pilas.h"

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

void postfijo(char expresion[])
{
	char symb,topsymb;
	int i=0,j=0;
	nodo *pila = NULL;
	char postfijo[50];
	while(expresion[i] != '\0')
	{
		symb = expresion[i];
		if(symb != '^' && symb != '*' && symb != '/' && symb != '+' && symb != '-' && symb != '(' && symb != ')'  )
		{
			postfijo[j] = symb;
			j++;
		}
		else
		{
			stackTop(pila,&topsymb);// 									Analiza y regresa el dato donde esta apuntado y se lo da topsymb
			while(!isEmpty(pila) == 1 && prec(topsymb,symb) == 1)
			{
				//printf("\nope1:%c",topsymb);
				//printf("\tope2:%c\n",symb);
				pila = pop(pila,&topsymb); // 							Saca el dato de la pila
				postfijo[j] = topsymb;
				//printf("\n\tEntro a postfijo: %c\n",topsymb);
				j++;
				stackTop(pila,&topsymb);// 								Actualiza el dato
			}
			//imprimir(pila);
			if(isEmpty(pila) == 1 || symb != ')')
				pila = push(pila,symb);
			else
			{
				pila = pop(pila,&topsymb);
				//printf("\nPop de topsymb de else: %c\n",topsymb);
			}
				
		}
		i++;
	}
	while(!isEmpty(pila) == 1)
	{
		pila = pop(pila,&topsymb);
		postfijo[j] = topsymb;
		//printf("\n\tEntro al ultimo postfijo: %c\n",topsymb);
		j++;
	}
	i =0;
	printf("\n");
	while(postfijo[i] != '\0') // 				Imprime la cadena postfijo
	{
		printf("%c",postfijo[i]);
		i++;	
	}
	printf("\n");
}

int main()
{
	char cadena[50];// (7+2)*2-1 == 72+2*1- | (A+B)-(C-D) == AB+CD--| ((A+B)*C-(D-E))^(F+G) == AB+C*DE--FG+^
	printf("Ingresa la operacion: ");
	scanf("%s",cadena);
	postfijo(cadena);
	pausa;
	return 0;	
}
