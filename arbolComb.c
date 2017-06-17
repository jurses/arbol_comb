#include "stdio.h"
#include "arbolComb.h"

struct nodoC_t* nuevoNodoC(int elementos){
    struct nodoC_t *nodo = (struct nodoC_t*)malloc(sizeof(struct nodoC_t));
    int i=0;
    nodo->vNodos = (struct nodoC_t**)malloc(elementos * sizeof(struct nodoC_t*));
    nodo->elementos = elementos;
    
    for(;i<elementos; i++)
        nodo->vNodos[i] = NULL;
        
    return nodo;
}

void generarArbol(struct nodoC_t *nodo){
    int i=0;
    for(;i<nodo->elementos;i++){
        nodo->vNodos[i] = nuevoNodoC(nodo->elementos - 1);
        generarArbol(nodo->vNodos[i]);
    }
}

void eliminarRarbol(struct nodoC_t *nodo){
    int i=0;
    for(;i<nodo->elementos; i++){
        eliminarRarbol(nodo->vNodos[i]);
        free(nodo->vNodos[i]);
        nodo->vNodos[i] = NULL;
    }
}

void limpiarArbol(struct arbolC_t *arbol){
    eliminarRarbol(arbol->raiz);
    free(arbol->raiz);
    arbol->raiz = NULL;
}

struct arbolC_t* nuevoArbol(int elementos){
    struct arbolC_t *arbol = (struct arbolC_t*)malloc(sizeof(struct arbolC_t));
    arbol->raiz = nuevoNodoC(elementos);
    generarArbol(arbol->raiz);
    return arbol;
}

void rellenarArbol(struct arbolC_t* arbol){
    struct cola_t* cola = nuevaCola();
    int i=0;
    for(;i<arbol->raiz->elementos+1; i++)
		pushQ(cola, i);

    rellenarArbolR(arbol->raiz, cola);
    limpiarCola(cola);
}

void rellenarArbolR(struct nodoC_t *nodo, struct cola_t *cola){
    nodo->dato = frontQ(cola);
    popQ(cola);
    printf("Añadimos: %d\n", nodo->dato);

    for(int i=0; i<nodo->elementos; i++)
	rellenarArbolR(nodo->vNodos[i], cola);

    pushQ(cola, nodo->dato);
    printf("Recogemos: %d\n", nodo->dato);
}
