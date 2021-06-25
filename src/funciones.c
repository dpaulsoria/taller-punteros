#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int error_fecha(int *dia, int *mes, int *ano) {
	*dia = -1; *mes = -1; *ano = -1;
	return 1;
}

int parsear_fecha(const char *fecha_str, int *dia, int *mes, int *ano) {

	// >>> MANEJO DE ERRORES - 1 <<<

	if (fecha_str == NULL) 
		return error_fecha(dia, mes, ano);

	// >>> MANEJO DE ERRORES - 0 <<<

	// >>> VARIABLES - 1 <<<

	char tmp[12] = {0};
	char *p = tmp;
	char *token = NULL;
	int counter = 0;
	char *months[12] = {"Ene", "feb", "Mar", "Abr", "May", "Jun", "Jul", "Ago", "Sep", "Oct", "Nov", "Dic"} ;
	
	// >>> VARIABLES - 0 <<<

	// >>> IMPLEMENTACIÓN - 1 <<<

	strcpy(tmp, fecha_str);
	
	while ( (token = strtok_r(p, "-", &p)) != NULL) {

		// Contador - [1 -> dia, 2 -> mes, 3 -> ano]
		counter++;

		// Abril, Junio, Septiembre y Noviembre -> Días del mes con 30 días
		// dia - valida error
		if (counter == 1 && (atoi(token) < 1 || atoi(token) > 31))
			return error_fecha(dia, mes, ano);
		else if (counter == 1)
			*dia = atoi(token);
		// mes - valida error
		else if (counter == 2 && strlen(token) > 3)
			return error_fecha(dia, mes, ano);
		else if (counter == 2) {
			for (int i = 0; i<12; i++) {
				if (strcmp(months[i], token))
					*mes = i + 1;
				if (*mes == 2 && *dia > 29)
					return error_fecha(dia, mes, ano);
				else if ( (*mes == 4 || *mes == 6 || *mes ==9 || *mes == 11) && *dia > 30)
					return error_fecha(dia, mes, ano);
			}
		// año - validad error
		} else if (counter == 3 && atoi(token) < 0)
			return error_fecha(dia, mes, ano);
		else if (counter == 3)
			*ano = atoi(token);	

	}

	// >>> IMPLEMENTACIÓN - 0 <<<

	return 0;
}

int bytes_significativos(void *valor, unsigned long tamano_valor, unsigned char *bytes, int num_bytes, int mas_menos) {
	
	// >>> MANEJO DE ERRORES - 1 <<<
	if (valor == NULL || num_bytes > tamano_valor || bytes == NULL)
		return 1;
	// >>> MANEJO DE ERRORES - 0 <<<
	
	// >>> VARIABLES - 1 <<<

	// Uso LONG porque representa 8 bytes de memoria, el máximo que puede almacenar una variable
	unsigned long *cp_valor = (unsigned long *)valor;
	char array[64];
	// Tiene 64 espacios porque el máximo de bytes disponibles por variable es 8
	
	// >>> VARIABLES - 0 <<<

	// >>> IMPLEMENTACIÓN - 1 <<<

	int dec = decToHex(&cp_valor, &array[64]);
	printf("DEC: %d\n", dec);
	// MSB - dec = 0 indica éxtio en decToHex
	if (mas_menos == 1 || dec == 0) {
		printf("array: %c\n", array[1]);
	// LSB -  dec = 0 indica éxtio en decToHex
	} else if  (mas_menos == 0 || dec == 0) {
		printf("array: %c\n", array[1]);
	// ERROR
	} else
		return 1;

	// >>> IMPLEMENTACIÓN - 0 <<<

	return 0;
}

int decToHex(void *valorDecimal, char arreglo[64]) {
    // char array to store hexadecimal number
    // char hexaDeciNum[100];

	// >>> MANEJO DE ERRORES - 1 <<<

	if ((int *)valorDecimal == 0 || arreglo == NULL) {
		return 1;
	}

	// >>> MANEJO DE ERRORES - 0 <<<

	// Casteo de voi * a int *
	int *n = (int *)valorDecimal;
    int i = 0;
    while (*n != 0) {
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = *n % 16;
 
        // check if temp < 10
        if (temp < 10) {
            arreglo[i] = temp + 48;
            i++;
        }
        else {
            arreglo[i] = temp + 55;
            i++;
        }
 
        *n /= 16;
    }
	return 0;
}

char *buscar_substring(char *un_string, char *substring) {
	
	/*
	if (un_string == NULL || substring == NULL) 
		return NULL;
	int len_string = strlen(un_string);
	int len_substring = strlen(substring);

	int tamano = len_string - len_substring + 1;
	int i, j = 0;
	char flag = 1;

	for (i = 0; i < tamano; i++) {
		flag = 1;
		for (j = 0; j < len_substring; j++) {
			if (un_string[i + j] != substring[j])
				flag = 0;
		}
	}
	*/
	return NULL;
}
