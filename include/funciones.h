#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stddef.h>

void pruebas();			//NO IMPLEMENTAR ESTA FUNCION
void mostrar_bytes(void *valor, int size);	//NO IMPLEMENTAR ESTA FUNCION


//Retorna 0 si el parseo fue correcto
//y -1 si hubo error
int parsear_fecha(const char *fecha_str, int *dia, int *mes, int *anio);

int fecha_error(int *dia, int *mes, int *ano);
int fecha_verificar_caracter(char *mes1, char *mes2);
int fecha_verificar_mes(char *mes, int *dia, int *mes1, int *ano);

// Esta funcion devuelve el los n byes menos significatios del tipo de dato apuntado por valor
//
// valor: datos del cual queremos los bytes
// tamano: tamano del tipo de dato apuntado por valor
// bytes: arreglo donde se guardaran los n bytes menos/mas signficativos
// num_bytes: cantidad de bytes menos significativos que solicitamos. Es el tamano del arreglo bytes
// mas_menos: 0 trae los bytes menos significativos, 1 los mas significativos
//
// Los bytes deben guardarlos en el orden que los van encontrando.
int bytes_significativos(void *valor, unsigned long tamano_valor, unsigned char *bytes, int num_bytes, int mas_menos);
int decToHex(void *valorDecimal, char arreglo[64]);

//Retorna el puntero al primer caracter donde empieza el substring en un_string
//y NULL si no se encuentra el substring.
char *buscar_substring(char *un_string, char *substring);
