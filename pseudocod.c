#include <stdio.h>
#include <stdlib.h>

#define TAM 256

arbolC_t recursiva (pila_t posibilid, arbolC_t resultadoit, int posresult, arbolC_t contodosresultados){
    //le recuerdo al sr. Dani, que son punteros y que no hace falta devolver nada
    //porque se está trabajando en esa zona de memoria, por lo tanto devuelve void
    //no es necesario pasarle la pila,
    //bue esto es lo que se me ocurre, lo que esta pasando todo el rato son las posibilidades
    //que no ha cogido(posibilid), el resultado hasta el momento, la posicion para añadir el siguiente
    //resultado al arbol de resultado, y todas las soluciones que se han encontrado hasta el
    //momento (contodosresultados)
    
    //vamos a probarlo, si tienes dudas de las funciones o estructuras están en el .h
    
    //contodosresultados es una array de arboles
    pila_t restantes();
    if (posibilid.size() > 1){ //se hace mientras quede mas de 1 numero
        for (int i=0; i<posibilid.size(); i++){
            resultado[posresult] = posibilid[i]; //numero escogido en este turno = posibilid[i]
            restantes = posibilid - posibilid[i] // pila con numeros restantes - el escogido anteriormente
            resultado = recursiva(restantes, resultado, posresult++, contodosresultados); //se repite la funcion con el resultado hasta el momento, 
            //la siguiente posicion y los numeros restantes que no se han cogido
            contodosresultados.añadir(resultado);
        }
    }else{
        resultado.añadir(posibilid[0]);
        return resultado
    }
}

int main(int argc, char **argv){