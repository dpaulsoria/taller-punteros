
punteros: obj/main.o obj/funciones.o obj/bytes.o	 
	gcc -fsanitize=address,undefined obj/main.o obj/funciones.o obj/bytes.o pruebas.a -o punteros

main.o: src/main.c
	gcc -c -Wall src/main.c -g 

bytes.o: src/bytes.c
	gcc -c -Wall src/bytes.c -g
funciones.o: src/funciones.c
	gcc -c -Wall src/funciones.c -g
test_fecha:
	./punteros -p 1

test_bytes: 
	./punteros -p 2

test_substring:
	./punteros -p 3

pruebas.o: src/pruebas.c
	gcc src/pruebas.c -I . -c

pruebas.a: obj/pruebas.o
	ar rcs pruebas.a obj/pruebas.o

.PHONY: clean
clean:
	rm -f punteros obj/pruebas.o obj/main.o obj/bytes.o
