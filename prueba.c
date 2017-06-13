#include "estructDatos.h"
#include <stdio.h>
#include <stdlib.h>

static int x = 0;

void dfs(struct nodoC_t *nodo){ 
    int i;
    for(i=0; i<nodo->elementos; i++){
        dfs(nodo->vNodos[i]);
        x++;
    }
}

int main(void){
    COLA *c = nuevaCola();
    int i = 0;
    printf("%p\n", c->lista);
    printf("PUSH\n");
    for(; i<10; i++){
        pushQ(c, rand()%50);
        printf("%d,\t%d\n", frontQ(c), c->lista->elementos);
    }
    
    printf("\nPOP\n");
    
    for(i=0; i<10; i++){
        printf("%d,\t%d\n", frontQ(c), c->lista->elementos);
        popQ(c);
    }
    limpiarCola(c);
    printf("%p\n", c->lista);
}