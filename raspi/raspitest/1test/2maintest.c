#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototipos de funciones

void file_write(FILE *file, char *path, char *str);
void file_read(FILE *file, char *path, char *str);

/**
 * @brief Programa principal
 */
int main(int argc, char *argv[]) {
    // Puntero a archivo
	FILE *file;
	int aux=0;
	while(1) {
        // Tomo de la consola el texto a escribir
		char str[100];
		printf("Ingrese una opcion: \n  1 .Apagar RTOS\n  2 .Encender Led\n  3 .Apagar Led\n 4 .leer datos\n  exit .salir\n ");
		fgets(str, 100, stdin);

		if(!strcmp(str, "exit")) {
			puts("Saliendo del programa...");
			return 0;
		}
		aux = atoi(str);

		switch(aux){
			case 1:
				strcpy(str, "A"),
				file_write(file, "/proc/td3/i2c", str);
		                sleep(1);
		                file_read(file, "/proc/td3/i2c", str);
				printf("Contenido: %s\n", str);
				break;
			case 2:
				strcpy(str, "B");
				file_write(file, "/proc/td3/i2c", str);
				break;
			case 3:
				strcpy(str, "C");
				file_write(file, "/proc/td3/i2c", str);
				break;
			case 4:
				strcpy(str, "D");
				file_write(file, "/proc/td3/i2c", str);
				sleep(1);
				file_read(file, "/proc/td3/i2c", str);
				printf("Contenido: %s\n", str);
				break;
			default:
				printf("opcion invalida");
		}
        // Escribo y leo el archivo
		
	//	file_write(file, "/proc/td3/i2c", str);
	//	sleep(1);
	//	file_read(file, "/proc/td3/i2c", str);
        // Muestro lectura por consola
	}
}

/**
 * @brief Wrapper para escribir un archivo
 * @param file puntero a archivo
 * @param path ruta al archivo
 * @param str cadena de caracteres para escribir
 */
void file_write(FILE *file, char *path, char *str) {
    // Abro archivo con permisos de escritura, escribo y cierro
	file = fopen(path, "w");
	fputs(str, file);
	fclose(file);
}

/**
 * @brief Wrapper para leer un archivo
 * @param file puntero a archivo
 * @param path ruta al archivo
 * @param str puntero donde escribir el contenido del archivo
 */
void file_read(FILE *file, char *path, char *str) {
    // Abro archivo con permisos de lectura, leo y cierro
	file = fopen(path, "r");
	fgets(str, 100, file);
	fclose(file);
}
