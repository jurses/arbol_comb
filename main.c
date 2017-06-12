#include <stdio.h>
#include <stdlib.h>

#define TAM 256

int main(int argc, char **argv){
    FILE *f;	//puntero a un archivo
    if(argc >= 2){	// si tiene dos argumentos el programa: ej. ./a.out party.txt
	f = fopen(argv[1], "r");	// abrimos y damos permisos de escritura
	    if(f){	// si el fichero apunta a un archivo y no hay errores...
		int datos, i;
		char **party;	//vector de cadenas de caracteres
						//party[0] = Néstor...
						//party[1] = ...

		fscanf(f, "%d", &datos);	// lee la primera línea desde f y lo guarda en datos
		party = (char**)malloc(datos * sizeof(char*));	//reservamos memoria, por todas las personas que hay

		for(i=0; i<datos; i++){
		    party[i] = (char*)malloc(datos * sizeof(char)); //reservamos memoria para crear cadenas de hasta 256 caracteres
		    fscanf(f, "%s", party[i]); // leemos miembros
		    printf("%s\n", party[i]);
		}

		//aqui empieza el trasteo
		int numeros[datos];
		int aux = datos;
		time_t t;
		int nuevo = 0;
		srand((unsigned) time(&t)); //se genera nueva semilla
		
		while(aux>0){
			while(//nuevo esta dentro de la lista de jugadores usados)
			{
				nuevo = rand() % datos); //se guarda numero aleatorio
			}
			//añadir a la lista
			//añadir a la lista de jugadores usados
		aux = aux-1;
		}
		
		//imprime lista por pantalla
		

		for(i=0; i<datos; i++)
		    free(party[i]); // liberar memoria

		free(party);	// liberar memoria
	    fclose(f);
	    }
    }
}
