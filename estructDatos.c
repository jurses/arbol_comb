#include "estructDatos.h"

struct nodo_t* nuevoNodo(void){ // esto sería como una especie de constructor
    struct nodo_t *nodo = (struct nodo_t*)malloc(sizeof(struct nodo_t));
    nodo->siguiente = NULL;
    return nodo;
}

struct pila_t *Pila(void){
    struct pila_t *p = (struct pila_t*)malloc(sizeof(struct pila_t));
    p->elementos = 0;
    return p;
}

void push(struct pila_t *p, const int dato){
    struct nodo_t* aux = nuevoNodo();
    aux->dato = dato;
    insertarFinal(p->lista->cabeza, aux);
    p->elementos++;
}

void  insertarFinal(struct nodo_t *nodo, struct nodo_t *aux){
    if(nodo->siguiente)
    	insertarFinal(nodo->siguiente, aux);
    else
	    nodo->siguiente = aux;
}

void pop(struct pila_t *p){
    if(p->elementos >= 1){
        eliminaCabeza(p->lista);
        p->elementos--;
    }
}

int front(struct pila_t *pila){
    if(pila->elementos >= 1){
        return pila->lista->cabeza->dato;
    }
}

void limpiarPila(struct pila_t *pila){
    pila->elementos = 0;
    limpiarLista(pila->lista);
}

void eliminaCabeza(struct sll_t *lista){
    if(lista->elementos >= 1){
        struct nodo_t *aux = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        free(aux);
        lista->elementos--;
    }
}

struct sll_t* Sll_t(void){
    struct sll_t *lista = (struct sll_t*)malloc(sizeof(struct sll_t));
    lista->elementos = 0;
    return lista;
}

struct nodo_t* buscar(struct nodo_t* nodo, int dato){
    if(nodo->dato == dato)
        return nodo;
    else if(nodo->siguiente)
        return buscar(nodo->siguiente, dato);
    else if(!nodo->siguiente)
        return NULL;
}

struct nodo_t* buscarP(struct nodo_t* nodo, int dato){ // te da el nodo padre del que buscas
    if(nodo->siguiente)
        if(nodo->siguiente->dato == dato)
            return nodo;
        else
            return buscarP(nodo->siguiente, dato);
    else
        return NULL;    // no tiene padre
}

void eliminar(struct sll_t *lista, int dato){
    struct nodo_t *aux1, *aux2;
    switch(lista->elementos){
        case 0: return;
                break;
        case 1: aux1 = lista->cabeza;
                free(aux1);
                lista->cabeza = NULL;
                lista->elementos--;
                break;
        default:    if((aux1 = buscarP(lista->cabeza, dato))){ // tiene padre
                        if((aux2 = aux1->siguiente->siguiente)){    // tiene hijo
                            free(aux1->siguiente);
                            aux1->siguiente = aux2;
                            lista->elementos--;
                        }else{
                            free(aux1->siguiente);
                            aux1->siguiente = NULL;
                            lista->elementos--;
                        }
                    }else{
                        aux1 = lista->cabeza;
                        lista->cabeza = aux1->siguiente;
                        free(aux1);
                        lista->elementos--;
                    }
                            
    };
}

void eliminarR(struct nodo_t *nodo){
    if(nodo->siguiente){
        eliminarR(nodo->siguiente);
        nodo->siguiente = NULL;
    }
    free(nodo);
}

void limpiarLista(struct sll_t *lista){
    if(lista->cabeza){
        eliminarR(lista->cabeza);
        lista->elementos = 0;
        lista->cabeza = NULL;
    }
}

void insertar(struct sll_t *lista, int dato){
    struct nodo_t *aux = nuevoNodo();
    aux->dato = dato;
    if(lista->cabeza)
        insertarFinal(lista->cabeza, aux);
    else
        lista->cabeza = aux;
    lista->elementos++;
}

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

struct arbolC_t* Arbol(int elementos){
    struct arbolC_t *arbol = (struct arbolC_t*)malloc(sizeof(struct arbolC_t));
    arbol->raiz = nuevoNodoC(elementos);
    generarArbol(arbol->raiz);
    return arbol;
}