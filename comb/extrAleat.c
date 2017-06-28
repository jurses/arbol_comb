#include "extrAleat.h"

DATOSC leerNombres(FILE *f){
    int m, n;
    char **nombres;
    fscanf(f, "%d %d", &m, &n);
    nombres = malloc(m * sizeof(char*));

    for(int i=0; i<m; i++){
		nombres[i] = malloc(TAM * sizeof(char));
		fscanf(f, "%s", nombres[i]);
    }

	DATOSC X ={
		.nombres = nombres,
		.m = m,
		.n = n
	};

    for(int i=0; i<m; i++)
		free(nombres[i]);

    free(nombres);
	return X;
}

void imprimePerm(ARBOLCOMB *A, DATOSC d, bool bFILE, char *nombre){
    SLISTA *L = nuevaLista();
    int i = 0;
    FILE *f = NULL;
    const int comb = combinacion(A->raiz->elementos, d.m);

	if(bFILE){
		if(!(f = fopen(nombre, "w"))){
			printf("%s \n", strerror(errno));
			perror("No se pudo abrir correctamente el fichero");
			exit(EXIT_FAILURE);
		}
		fprintf(f, "%d %d\n", d.m, d.n);
	}else
		printf("%d %d\n", d.m, d.n);

    for(int j=0; j<A->raiz->elementos; j++)
		for(int i =0; i<factorial(A->raiz->elementos); i++){
			busqueda(A->raiz->vNodos[j], A->raiz, L, A->raiz->elementos, comb, f);
			limpiarLista(L);
		}
	if(bFILE)
		fclose(f);
}

void escribirComb(SLISTA* L, FILE *f){
    struct nodo_t *aux = L->cabeza;
    while(aux){
		if(f)
			fprintf(f, "%d ", aux->dato); else
			printf("%d ", aux->dato);
		aux = aux->siguiente;
    }
	if(f)
		fprintf(f, "\n");
	else
		printf("\n");
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
