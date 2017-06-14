#include "estructDatos.h"

struct nodoC_t{
    int elementos;
    int dato;
    struct nodoC_t** vNodos;    //aquí estaría los punteros a [A,B,C,D]
};

struct arbolC_t{
    struct nodoC_t *raiz;
};

typedef struct arbolC_t ARBOLCOMB;
struct nodoC_t* nuevoNodoC(int);
void generarArbol(struct nodoC_t*);
void limpiarArbol(struct arbolC_t*);
struct arbolC_t* nuevoArbol(int);
void eliminarRarbol(struct nodoC_t*);
void rellenarArbol(struct arbolC_t*);
void rellenarArbolR(struct nodoC_t*, struct cola_t*);
