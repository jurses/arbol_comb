#include "estructDatos.h"
#include <stdio.h>

static int x = 0;

void dfs(struct nodoC_t *nodo){ 
    int i;
    for(i=0; i<nodo->elementos; i++){
        dfs(nodo->vNodos[i]);
        x++;
    }
}

int main(void){
    struct arbolC_t *arbol = Arbol(3);
    dfs(arbol->raiz);
    limpiarArbol(arbol);
    printf("%d\n",x);
}