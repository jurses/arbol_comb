#include "estructDatos.h"
#include "arbolComb.h"
#include <stdio.h>
#include <stdlib.h>

struct foo{
    int a;
    int b;
    int c;
    int d;
    int e;
};

int main(void){
    struct foo *F = malloc(sizeof(struct foo));
    F->a =1;
    F->b =1;
    F->c =1;
    F->d =1;
    F->e =1;
}
