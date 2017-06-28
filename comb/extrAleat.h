#ifndef _EXTRALEAT_
#define _EXTRALEAT_

#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "mates.h"
#include "../estructDatos/arbolComb.h"
#include "../estructDatos/estructDatos.h"
#include <stdbool.h>

#ifndef TAM
	#define TAM 256
#endif // TAM

typedef struct nombres_t{
	char **nombres;
	int m;
	int n;
} DATOSC;

bool busqueda(struct nodoC_t*, struct nodoC_t*, SLISTA*, const int, const int, FILE*);
void escribirComb(SLISTA*, FILE*);
void imprimePerm(ARBOLCOMB*, DATOSC d, bool, char*);
DATOSC leerNombres(FILE*);

#endif	// _EXTRALEAT_
