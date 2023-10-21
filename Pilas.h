#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define pausa system("pause")
#define cls system("cls")
#define NL putchar("\n")
 
 
 union datos
 {
 	char cha;
 	float flo;
 };
 
 struct Nodo{
 	union datos info;
	struct Nodo *sig;	
 };
 
typedef struct Nodo nodo;
nodo *raiz=NULL;

//Prototipos
nodo *push(nodo *raiz,union datos dato);
nodo *pop(nodo *raiz,union datos *dato);
int isEmpty(nodo *raiz);
nodo *stackTop(nodo *raiz,union datos *dato);
void imprimir(nodo *raiz);
//primitivas


nodo *push(nodo *raiz,union datos dato)
{
	nodo *nuevo = NULL;
	nuevo = (nodo *) malloc(sizeof(nodo));
	if (nuevo == NULL)
	{
		printf("No hay sistema.(NULL)\n");
		exit(1);
	}
	nuevo -> info = dato;
	nuevo -> sig = NULL;
	
	nuevo -> sig = raiz;
	raiz = nuevo;
	return raiz;
}
nodo *pop(nodo *raiz,union datos *dato)
{
	nodo *siguiente = NULL;
	if(raiz == NULL)
	{
		//printf("Lista vacia\n");
		return ('\0');
	}
	siguiente = raiz;
	raiz = raiz -> sig; 
	*dato = siguiente -> info;
	free(siguiente);
	return raiz;
}

int isEmpty(nodo *raiz)
{
	if(raiz==NULL)
		return 1;
	
	else 
		return 0;
}

nodo *stackTop(nodo *raiz,union datos *dato)
{
	if(raiz == NULL)
	{
		//printf("Lista vacía, no ha nada que eliminar.\n");
		//pausa;
		return 0;
	}
	*dato = raiz ->info;
	return raiz;
}

 void imprimir(nodo *raiz)
 {	
 	nodo *recorre=raiz;
 	while(recorre != NULL)
	{
 			printf("%c, ",recorre->info);
			recorre = recorre -> sig;
	}
		putchar('\n');
 }

