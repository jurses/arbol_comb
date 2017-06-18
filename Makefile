OBJS = main.o arbolComb.o estructDatos.o mates.o

all: combinacion.exe

combinacion.exe: $(OBJS)
	gcc -o combinacion.exe -g $(OBJS)

main.o: main.c estructDatos.h mates.h arbolComb.h
	gcc -c -g main.c

mates.o: mates.c mates.h
	gcc -c -g mates.c

arbolComb.o: arbolComb.c arbolComb.h estructDatos.h
	gcc -c -g arbolComb.c

estructDatos.o: estructDatos.c estructDatos.h
	gcc -c -g estructDatos.c

clean:
	rm $(OBJS)

uninstall:
	rm combinacion.exe $(OBJS)
