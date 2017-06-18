#include "mates.h"

long int factorial(int x){
    long int resultado = x;
    if(x<2)
	resultado = 1;
    else
	resultado = x * factorial(x-1);

    return resultado;
}

int combinacion(int m, int n){
    return (factorial(m)/(factorial(n) * factorial(m-n)));
}
