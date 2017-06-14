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

    printf("PUSH\n");
    for(; i<10; i++){
        pushQ(c, rand()%50);
        printf("%d,\t%d\n", frontQ(c), c->lista->elementos);
    }
    
    printf("\nPOP & FRONT\n");
    while(c->elementos){
	printf("%d\n",frontQ(c));
	popQ(c);
    }

    limpiarCola(c);
    printf("%p\n", c->lista);
}
