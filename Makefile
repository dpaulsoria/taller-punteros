
punteros: main.o funciones.o bytes.o	 
	gcc -fsanitize=address,undefined main.o funciones.o bytes.o pruebas.a -o punteros

main.o: main.c
	gcc -c -Wall main.c -g 

bytes.o: bytes.c
	gcc -c -Wall bytes.c -g
funciones.o: funciones.c
	gcc -c -Wall funciones.c -g
test_fecha:
	./punteros -p 1

test_bytes: 
	./punteros -p 2

test_substring:
	./punteros -p 3

pruebas.o: pruebas.c
	gcc pruebas.c -I . -c

pruebas.a: pruebas.o
	ar rcs pruebas.a pruebas.o

.PHONY: clean
clean:
	rm -f punteros pruebas.o main.o bytes.o
