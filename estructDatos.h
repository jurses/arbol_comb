#ifndef _ESTRUCT_DAT_
#define _ESTRUCT_DAT_

#include <stdlib.h>

struct nodo_t{
    struct nodo_t *siguiente;
    int dato;
};

struct pila_t{
    struct sll_t* lista;
    unsigned int elementos;
};

typedef struct pila_t PILA;

struct cola_t{
    struct sll_t* lista;
    unsigned int elementos;
};

typedef struct cola_t COLA;

struct sll_t{
    struct nodo_t *cabeza;
    unsigned int elementos;
};

typedef struct sll_t SLISTA;

struct nodo_t* nuevoNodo(void);

//PILA
struct pila_t* nuevaPila(void);
void pushS(struct pila_t*, const int);
void popS(struct pila_t*);
int frontS(struct pila_t*);
void limpiarPila(struct pila_t*);

//COLA
struct cola_t* nuevaCola(void);
void limpiarCola(struct cola_t*);
void pushQ(struct cola_t*, const int);
void popQ(struct cola_t*);
int frontQ(struct cola_t*);

//LISTA
struct nodo_t* obtenerFinal(struct nodo_t*);
void insertarFinal(struct sll_t*, int);
void insertarPrincipio(struct sll_t*, int);
struct sll_t* nuevaLista(void);
struct nodo_t* buscar(struct nodo_t*, int);
struct nodo_t* buscarP(struct nodo_t*, int);
void eliminar(struct sll_t*, int);
void limpiarLista(struct sll_t*);
void eliminaCabeza(struct sll_t*);
void eliminaFin(struct sll_t*);
void mostrarLista(struct sll_t*);
#endif	// _ESTRUCT_DAT_
