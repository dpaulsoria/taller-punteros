
#include <stdio.h>


void mostrar_bytes(void *valor, int size){

	unsigned char *p = (unsigned char *) valor;
	for(int i = 0; i  < size; i++){
		printf("%02x " , *(p+i));
	}
	printf("\n");
}
