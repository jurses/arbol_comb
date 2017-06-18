#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "arbolComb.h"
#include <stdbool.h>
#include "mates.h"

#define TAM 256

bool busqueda(struct nodoC_t*, struct nodoC_t*, SLISTA*, const int, const int, FILE*);
void escribirComb(SLISTA*, FILE*);

void imprimePerm(ARBOLCOMB *A, int n){
    SLISTA *L = nuevaLista();
    int i = 0;
    FILE *f;
    const int comb = combinacion(A->raiz->elementos, n);
    if(!(f = fopen("oComb.txt", "w"))){
	printf("%s \n", strerror(errno));
	perror("No se pudo abrir correctamente el fichero");
	exit(EXIT_FAILURE);
    }
    for(int j=0; j<A->raiz->elementos; j++)
	for(int i =0; i<factorial(A->raiz->elementos); i++){
	    busqueda(A->raiz->vNodos[j], A->raiz, L, A->raiz->elementos, comb, f);
	    limpiarLista(L);
	}

    fclose(f);
}

void escribirComb(SLISTA* L, FILE *f){
    struct nodo_t *aux = L->cabeza;
    while(aux){
	fprintf(f, "%d ", aux->dato);
	aux = aux->siguiente;
    }
    fprintf(f, "\n");
}

bool busqueda(struct nodoC_t* nodo, struct nodoC_t* padre, SLISTA *L, const int m, const int comb, FILE *f){
    static int cont = 0;
    insertarFinal(L, nodo->dato);
    if(nodo->cont == nodo->elementos)
	padre->cont++;
    else if(nodo->vNodos[0]->elementos == 0){
	padre->cont++;
	insertarFinal(L, nodo->vNodos[0]->dato);
	if(L->elementos == m){
	    if(!(cont % comb))
	        escribirComb(L, f);
	    cont++;
	}
	return true;
    }
    else
        return busqueda(nodo->vNodos[nodo->cont], nodo, L, m, comb, f);
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
    int m, n;
    char **nombres;
    fscanf(f, "%d %d", &m, &n);
    nombres = malloc(m * sizeof(char*));

    for(int i=0; i<m; i++){
	nombres[i] = malloc(TAM * sizeof(char));
	fscanf(f, "%s", nombres[i]);
    }

    ARBOLCOMB *A = nuevoArbol(m);
    rellenarArbol(A);

    imprimePerm(A, n);

    limpiarArbol(A);
    for(int i=0; i<m; i++)
	free(nombres[i]);

    free(nombres);
    fclose(f);
}
