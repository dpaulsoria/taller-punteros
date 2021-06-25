
bin/punteros: obj/main.o obj/funciones.o obj/bytes.o	 
	gcc -fsanitize=address,undefined -I include/funciones.h obj/main.o obj/funciones.o obj/bytes.o pruebas.a -o punteros

obj/main.o: src/main.c
	gcc -c -Wall -I include/funciones.h src/main.c -g 

obj/bytes.o: src/bytes.c
	gcc -c -Wall -I include/funciones.h src/bytes.c -g
obj/funciones.o: src/funciones.c
	gcc -c -Wall -I include/funciones.h src/funciones.c -g
test/fecha:
	./punteros -p 1

test/bytes: 
	./punteros -p 2

test/substring:
	./punteros -p 3

test/pruebas.o: src/pruebas.c
	gcc src/pruebas.c -I . -c

pruebas.a: test/pruebas.o
	ar rcs pruebas.a test/pruebas.o

.PHONY: clean
clean:
	rm -f bin/* obj/*
