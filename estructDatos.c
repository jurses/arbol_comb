#include "estructDatos.h"

struct nodo_t* nuevoNodo(void){ // esto sería como una especie de constructor
    struct nodo_t *nodo = (struct nodo_t*)malloc(sizeof(struct nodo_t));
    nodo->siguiente = NULL;
    return nodo;
}

struct pila_t* nuevaPila(void){
    struct pila_t *p = (struct pila_t*)malloc(sizeof(struct pila_t));
    p->lista = nuevaLista();
    p->elementos = 0;
    return p;
}

void pushS(struct pila_t *p, const int dato){
    insertarPrincipio(p->lista, dato);
    
    p->elementos++;
}

struct nodo_t* obtenerFinal(struct nodo_t *nodo){
    /* Recursivo */
    /*
    if(nodo->siguiente)
    	return obtenerFinal(nodo->siguiente);
    else
        return nodo;
    */
    /* Iterativo */
    struct nodo_t *aux = nodo;
    
    while(aux->siguiente)
	aux = aux->siguiente;
    
    return aux;
}

void popS(struct pila_t *p){
    if(p->elementos >= 1){
        eliminaCabeza(p->lista);
        p->elementos--;
    }
}

int frontS(struct pila_t *pila){
    if(pila->elementos >= 1){
        return pila->lista->cabeza->dato;
    }
}

void limpiarPila(struct pila_t *pila){
    pila->elementos = 0;
    limpiarLista(pila->lista);
    free(pila->lista);
    pila->lista = NULL;
}

void eliminaCabeza(struct sll_t *lista){
    if(lista->elementos >= 1){
        struct nodo_t *aux = lista->cabeza;
        lista->cabeza = lista->cabeza->siguiente;
        free(aux);
        lista->elementos--;
    }
}

struct sll_t* nuevaLista(void){
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

void insertarFinal(struct sll_t *lista, int dato){
    struct nodo_t *aux = nuevoNodo();
    aux->dato = dato;
    if(lista->cabeza){
        struct nodo_t *fin = obtenerFinal(lista->cabeza);
        fin->siguiente = aux;
    }else
        lista->cabeza = aux;
    lista->elementos++;
}

void insertarPrincipio(struct sll_t* lista, int dato){
    struct nodo_t *aux = nuevoNodo();
    aux->dato = dato;
    if(lista->cabeza)
        aux->siguiente = lista->cabeza;
        
    lista->cabeza = aux;
    lista->elementos++;
}


struct cola_t* nuevaCola(void){
    struct cola_t *cola = (struct cola_t*)malloc(sizeof(struct cola_t));
    cola->elementos = 0;
    cola->lista = nuevaLista();
    
    return cola;
}

void limpiarCola(struct cola_t* cola){
    limpiarLista(cola->lista);
    cola->elementos = 0;
    free(cola->lista);
    cola->lista = NULL;
}

void pushQ(struct cola_t* cola, const int dato){
    insertarPrincipio(cola->lista, dato);
    
    cola->elementos++;
}

int frontQ(struct cola_t* cola){
    if(cola->elementos >= 1){
        struct nodo_t *aux = obtenerFinal(cola->lista->cabeza);
        return aux->dato;
    }
}

void eliminarFin(struct sll_t* lista){
    struct nodo_t *aux = lista->cabeza;
    if(aux->siguiente)
	while(aux->siguiente->siguiente)
	    aux = aux->siguiente;
        
    free(aux->siguiente);
    aux->siguiente = NULL;
    lista->elementos--;
}

void popQ(struct cola_t* cola){
    eliminarFin(cola->lista);
    cola->elementos--;
}
