/*
version 3
prueva basica, ingresa ususario y contraseña, debuelve OK

			FUNCIONA
*/



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
	char str[100];
	char user[3];
	char pass[6];
	int acceso;

	while(1) {
        // Tomo de la consola el texto a escribir
		
		memset(user, '\0', strlen(user));
		memset(pass, '\0', strlen(pass));
		
		printf("ingrese numero de usuario: ");
		fgets(user, 3, stdin);
		//strcpy(user,"1");
		//printf("\nIngrese contraseña para ususario %s:",user);
		printf("contraseña:");
		fgets(pass, 6, stdin);
		
		//acceso = requestAcc(user, pass);
		memset(str, '\0', strlen(str));
		strcat(str, "00,p,");
		strcat(str, user);
		strcat(str, ",");
		strcat(str, pass);
		strcat(str, ",0,0,$");

		printf("%s",str);
		file_write(file, "/proc/td3/i2c", str);
			
		sleep(1);
			
		file_read(file, "/proc/td3/i2c", str);
		printf("%s\n\n\n",str);
		
		char p = str[14];
		
		printf("%c\n", p);
		//int a = atoi(p);
		int a = p - '0';//convierte char a entero
		printf("%d\n", a);
			
		if(a == 5){
			acceso = 5;
			printf("ACSESO CONCEDIDO");
		}
			
		if(acceso != 5){
			printf("\nACSESO DENEGADO\n");
		}
		
	}
        // Escribo y leo el archivo
		
	//	file_write(file, "/proc/td3/i2c", str);
	//	sleep(1);
	//	file_read(file, "/proc/td3/i2c", str);
        // Muestro lectura por consola

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
