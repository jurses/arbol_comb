#include "estructDatos.h"
#include "arbolComb.h"
#include <stdio.h>
#include <stdlib.h>

static int x = 0;

void dfs(struct nodoC_t *nodo){
	int i=0;
	printf("Tengo %d elementos\n", nodo->elementos);
	for(;i<nodo->elementos; i++){
		printf("Entramos en el nodo[%d]\n", i);
		dfs(nodo->vNodos[i]);
	}
	printf("Salimos\n");
}

void mostrarArbol(struct nodoC_t *nodo){
	int i=0;
	for(;i<nodo->elementos;i++){
		printf("%d\n", nodo->dato);
		mostrarArbol(nodo->vNodos[i]);
	}
}

int main(void){
	ARBOLCOMB *A = nuevoArbol(2);
	int i=0;

	rellenarArbol(A);
	//mostrarArbol(A->raiz);

	limpiarArbol(A);
}
