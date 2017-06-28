OBJS = main.o arbolComb.o estructDatos.o mates.o extrAleat.o
DIRCOMB = ../estructDatos/
CC = gcc

include ../estructDatos/Makefile

all: combinacion.exe


combinacion.exe: $(OBJS)
	$(CC) -o ../combinacion.exe -g $(OBJS)

main.o: main.c extrAleat.h $(DIRCOMB)arbolComb.h
	$(CC) -c -g main.c

mates.o:
	$(CC) -c -g mates.c

extrAleat.o: extrAleat.c mates.h $(DIRCOMB)arbolComb.h $(DIRCOMB)estructDatos.h 
	$(CC) -c -g extrAleat.c

clean:
	rm $(OBJS)

uninstall:
	rm ../combinacion.exe $(OBJS)

