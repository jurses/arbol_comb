#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "arbolComb.h"

#define TAM 256

void busqueda(struct nodoC_t*, struct nodoC_t*, SLISTA*);

void imprimePerm(ARBOLCOMB *A){
    SLISTA *L = nuevaLista();
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
    busqueda(A->raiz->vNodos[0], A->raiz, L);
    limpiarLista(L);
}

void busqueda(struct nodoC_t* nodo, struct nodoC_t* padre, SLISTA *L){
    insertarFinal(L, nodo->dato);
    if(nodo->cont == nodo->elementos)
	padre->cont++;
    else if(nodo->vNodos[0]->elementos == 0){
	padre->cont++;
	insertarFinal(L, nodo->vNodos[0]->dato);
	mostrarLista(L);
    }
    else
        busqueda(nodo->vNodos[nodo->cont], nodo, L);
}

int main(int argc, char **argv){
    FILE *f;
    if(argc >= 2){
	if(!(f = fopen(argv[1], "r"))){
	    printf("%s \n", strerror(errno));
	    perror("No se pudo abrir correctamente el fichero");
	    exit(EXIT_FAILURE);
	}
    }
    else{
	printf("Inserte el nombre del fichero: ");
	char nombreF[TAM];
	scanf("%s", nombreF);
	if(!(f = fopen(nombreF, "r"))){
	    printf("%s \n", strerror(errno));
	    perror("No se pudo abrir correctamente el fichero");
	    exit(EXIT_FAILURE);
	}
    }
    int elementos;
    char **nombres;
    fscanf(f, "%d", &elementos);
    nombres = malloc(elementos * sizeof(char*));

    for(int i=0; i<elementos; i++){
	nombres[i] = malloc(TAM * sizeof(char));
	fscanf(f, "%s", nombres[i]);
    }

    ARBOLCOMB *A = nuevoArbol(elementos);
    rellenarArbol(A);

    imprimePerm(A);

    limpiarArbol(A);
    for(int i=0; i<elementos; i++)
	free(nombres[i]);

    free(nombres);
    fclose(f);
}
