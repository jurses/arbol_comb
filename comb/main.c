#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "../estructDatos/arbolComb.h"
#include "extrAleat.h"
#include <stdbool.h>

#ifndef TAM
	#define TAM 256
#endif // TAM


FILE* abrirArchivo(int, char**, bool*, char*);

int main(int argc, char **argv){
	bool bFILE = false;
	char nFileO[256];
	FILE *f = abrirArchivo(argc, argv, &bFILE, nFileO);
	DATOSC datof = leerNombres(f);

    ARBOLCOMB *A = nuevoArbol(datof.m);
    rellenarArbol(A);

    imprimePerm(A, datof, bFILE, nFileO);

    limpiarArbol(A);
    fclose(f);
}

//////////////////////////////////////////

FILE* abrirArchivo(int n, char **cad, bool *bFILE, char *nFileO){
    FILE *f;
    if(n >= 2){
		if(!(f = fopen(cad[1], "r"))){
			printf("%s \n", strerror(errno));
			perror("No se pudo abrir correctamente el fichero");
			exit(EXIT_FAILURE);
		}
		if(n >= 4)
			if(!strcmp(cad[2], "-f")){
				strcpy(nFileO, cad[3]);
				*bFILE = true;
			}else
				*bFILE = false;
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
