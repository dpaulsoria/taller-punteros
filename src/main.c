#include "include/funciones.h"
#include <string.h>
#include <stdlib.h>

//Implemente las funciones aqui


int main(int argc, char **argv){
	char c;
	int p = 0;
	while ((c = getopt (argc, argv, ":p")) != -1){
        switch(c){
            case 'p':
			p = atoi(optarg);
			break;
		default:
            printf("Argumento invalido\n");
            exit(1);
        }
    }
	
	// >>> DECLARACIÓN DE VARIABLES - 1 <<<

	// PRIMERA FUNCIÓN

	int day;
	int month;
	int year;


	// SEGUNDA FUNCIÓN

	int num_bytes = 3;
	unsigned char bytes[num_bytes];
	long valor = 342432; //0x539A0
	unsigned long size = sizeof(long);
	// ssh-add

	// TERCERA FUNCIÓN
	/*
	char *string_p; char *substring_p;
	char string[4] = "ESPOL"; char substring[1] = "SP";
	*string_p = &string; *substring_p = &substring;
	*/

	// >>> DECLARACIÓN DE VARIABLES - 0 <<<

	// >>> IMPLEMENTACIÓN DE FUNCIONES - 1 <<<

	// PRIMERA FUNCIÓN

	int parsear = parsear_fecha("28-Jul-2000", &day, &month, &year);
	printf("%d\n", parsear);
	printf("Día: %d - Mes: %d - Año: %d\n", day, month, year);

	// SEGUNDA FUNCIÓN
	
	int byte_S = bytes_significativos(&valor, size, bytes, num_bytes, 1);
	printf("%d\n", byte_S);
	printf("Num_bytes: %d - Bytes: %s - Long: %ld\n", num_bytes, bytes, valor);
	
	// TERCERA FUNCIÓN
	/*
	print("String: %s - PunteroString: %p - Substring: %s -  PunteroSubstring: %p\n", string[4], string_p,  substring[1], substring_p);
	*/
	// >>> IMPLEMENTACIÓN DE FUNCIONES - 0 <<<

	//No borrar el codigo que esta debajo de este comentario
	if(p == 1){
		pruebas(p);
	}
	else if(p == 2){
		printf("Maquina Little Endian\n");
		long valor = -8989898888888888888;
		mostrar_bytes(&valor, sizeof(long));
	
		int num_bytes = 3;
		unsigned char bytes[num_bytes];
		memset(bytes, 0, 3);
		bytes_significativos(&valor, sizeof(long), bytes, num_bytes, 0);
		printf("bytes menos significativos: %02x %02x %02x\n", bytes[0], bytes[1], bytes[2]);

		memset(bytes, 0, 3);
                bytes_significativos(&valor, sizeof(long), bytes, num_bytes, 1);
                printf("bytes mas significativos: %02x %02x %02x\n", bytes[0], bytes[1], bytes[2]);
	
		int res  = bytes_significativos(&valor, sizeof(long), bytes, 20, 1);	
		if(res != 1){
			printf("No valida que num_bytes <= tamano_valor\n");
		}
		else{
			printf("Si valida que num_bytes <= tamano_valor\n");
		}
	}
	else if(p==3){
		char *un_string = "es un gran dia para aprender a usar punteros";
		char *ptr = un_string + 11; 
		char *sub_string = "dia para aprender";

		char * res = buscar_substring(un_string, sub_string);
		if(res != NULL && res == ptr){
			printf("String existente encontrado\n");
		}
		if(buscar_substring(un_string, "dia para aprender no") == NULL){
                        printf("String no existente no encontrado\n");
                }
		if(buscar_substring(un_string, NULL) == NULL){
                        printf("validacion substring == NULL OK\n");
                }
		if(buscar_substring(NULL, sub_string) == NULL){
                        printf("validacion un_string == NULL OK\n");
                }	
	}

	return 0;

}
