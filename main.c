#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "arbolComb.h"
#include "extrAleat.h"

#define TAM 256

typedef struct nombres_t{
	char **nombres;
	int m;
	int n;
} NOMBRES;

FILE* abrirArchivo(int, char**);
NOMBRES leerNombres(FILE*);

int main(int argc, char **argv){
	FILE *f = abrirArchivo(argc, argv);
	NOMBRES nombres = leerNombres(f);

    ARBOLCOMB *A = nuevoArbol(nombres.m);
    rellenarArbol(A);

    imprimePerm(A, nombres.n);

    limpiarArbol(A);
    fclose(f);
}

FILE* abrirArchivo(int n, char **cad){
    FILE *f;
    if(n >= 2){
		if(!(f = fopen(cad[1], "r"))){
			printf("%s \n", strerror(errno));
			perror("No se pudo abrir correctamente el fichero");
			exit(EXIT_FAILURE);
		}
    }
    else{
		printf("Inserte el nombre del fichero: ");
		char nombreF[TAM];
		scanf("%s", nombreF);
		if(!(f = fopen(nombreF, "r"))){
			printf("%s \n", strerror(errno));
			perror("No se pudo abrir correctamente el fichero");
			exit(EXIT_FAILURE);
		}
    }
	return f;
}

NOMBRES leerNombres(FILE *f){
    int m, n;
    char **nombres;
    fscanf(f, "%d %d", &m, &n);
    nombres = malloc(m * sizeof(char*));

    for(int i=0; i<m; i++){
		nombres[i] = malloc(TAM * sizeof(char));
		fscanf(f, "%s", nombres[i]);
    }

	NOMBRES X ={
		.nombres = nombres,
		.m = m,
		.n = n
	};

    for(int i=0; i<m; i++)
		free(nombres[i]);

    free(nombres);
	return X;
}
