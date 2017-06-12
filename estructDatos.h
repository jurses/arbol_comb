#include <stdlib.h>

struct nodo_t{
    struct nodo_t *siguiente;
    int dato;
};

struct nodoC_t{
    int elementos;
    int dato;
    struct nodoC_t** vNodos;    //aquí estaría los punteros a [A,B,C,D]
};

struct pila_t{
    struct sll_t* lista;
    unsigned int elementos;
};

struct sll_t{
    struct nodo_t *cabeza;
    unsigned int elementos;
};

struct arbolC_t{
    struct nodoC_t *raiz;
};

struct nodo_t* nuevoNodo(void);

struct pila_t* Pila(void);
void push(struct pila_t*, const int);
void pop(struct pila_t*);
int front(struct pila_t*);
void limpiarPila(struct pila_t*);

void  insertarFinal(struct nodo_t*, struct nodo_t*);
void insertar(struct sll_t*, int);
struct sll_t* Sll_t(void);
struct nodo_t* buscar(struct nodo_t*, int);
struct nodo_t* buscarP(struct nodo_t*, int);
void eliminar(struct sll_t*, int);
void limpiarLista(struct sll_t*);
void eliminaCabeza(struct sll_t*);

struct nodoC_t* nuevoNodoC(int);
void generarArbol(struct nodoC_t*);
void limpiarArbol(struct arbolC_t*);
struct arbolC_t* Arbol(int);