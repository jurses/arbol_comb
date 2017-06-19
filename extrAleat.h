#ifndef _EXTRALEAT_
#define _EXTRALEAT_

#include <stdbool.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include "mates.h"
#include "arbolComb.h"
#include "estructDatos.h"

bool busqueda(struct nodoC_t*, struct nodoC_t*, SLISTA*, const int, const int, FILE*);
void escribirComb(SLISTA*, FILE*);
void imprimePerm(ARBOLCOMB*, const int);

#endif	// _EXTRALEAT_
