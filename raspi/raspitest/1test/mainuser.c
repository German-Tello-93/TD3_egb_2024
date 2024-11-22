/*
version 2
sin funcion de request, todo en el main





				NO FUNCIONA





*/






#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef enum{
	READ,
	WRITE,
	SCANN,
	CONT_DIG_OK,
	CONT_DIG_ERR,
	ACC_OK,
	ACC_DEN,
	ACC_ERROR,
	ACC_MAESTRA,
	ACC_30SEG,
	ACC_SIN_ASIGNAR,
	ACC_ASIGNADO,
	ACC_MASTER,
	CAMBIO_ESTADO
}accion_t;

typedef enum{
	ALARMA,
	PUERTA,
	CIERRE
}tipo_t;



// Prototipos de funciones
void file_write(FILE *file, char *path, char *str);
void file_read(FILE *file, char *path, char *str);
int requestAcc(char *user, char *pass);
void operar(char *op);
int requestNuevo(char *user);
void asignar(char *user, char *pass);





/**
 * @brief Programa principal
 */
int main(int argc, char *argv[]) {
    // Puntero a archivo
	FILE *file;
	int aux=0;
	int acceso = ACC_DEN;
	char str[128];
	
	char straux[128];	
	char user[3];	
	char pass[6];
	
	memset(str, '\0', strlen(str));


	printf("Bienvenido al sistema de control de accseso          Cargando...\n");
	//sleep(6);
	
	
	while(1) {
        //bucle para esperar confirmacion de acseso
		while(acceso != ACC_OK){
			
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
			printf("%s",str);
			
			char p = str[14];
			
			printf("%c", p);
			int a = atoi(p);
			
			if(a == ACC_OK){
				acceso = ACC_OK;
			}
			
			if(acceso != ACC_OK){
				printf("\nACSESO DENEGADO\n");
			}
		
		}
		
		acceso = ACC_DEN;


		printf("Ingrese una opcion: \n  1 .Ingresar con usuario\n  2 .Menu\n  3 .Log\n  exit .salir del programa");
		fgets(straux, 100, stdin);

		if(!strcmp(str, "exit")) {
			puts("Saliendo del programa...");
			return 0;
		}
		aux = atoi(straux);

		switch(aux){
			case 1:
				
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
				printf("%s",str);
				
				char p = str[14];
				int a = atoi(p);
				
				if(a == ACC_OK){
					acceso = ACC_OK;
				}
				
				if(acceso != ACC_OK){
					printf("\nACSESO DENEGADO\n");
					operar("6");//6=accseso denegado
				}
				else{
					printf("\nACSESO OK\n");
					operar("5");//5=accseso OK
				
				}
				
				break;
			case 2:
				printf("Ingrese una opcion: \n  1 .Asignar usuario\n  2 .burrar usuario\n  3. menu anterior");
			
				fgets(straux, 100, stdin);
				switch(aux){
					case 1:
						memset(user, '\0', strlen(user));
						memset(pass, '\0', strlen(pass));
						
						printf("ingrese numero de usuario: ");
						fgets(user, 2, stdin);
						
						if(requestNuevo(user) != ACC_ASIGNADO){
							printf("\nNo se uede agregar usuario\n");
						}
						else{
							printf("\nIngrese contraseña:");
							fgets(pass, 5, stdin);
							
							asignar(user, pass);
						}
						break;
					case 2:
					
						memset(user, '\0', strlen(user));
						memset(pass, '\0', strlen(pass));
						
						printf("ingrese numero de usuario a borrar: ");
						fgets(user, 2, stdin);
						strcpy(pass, "0000");
						asignar(user, pass);
						
						break;
				}
				break;
			case 3:
				break;
			default:
				printf("opcion invalida");
				break;
		}
        // Escribo y leo el archivo
		
	//	file_write(file, "/proc/td3/i2c", str);
	//	sleep(1);
	//	file_read(file, "/proc/td3/i2c", str);
        // Muestro lectura por consola
	}
}



 
 int requestNuevo(char *user){
	
	memset(str, '\0', strlen(user));
	strcat(str, "00,p,");
	strcat(str, user);
	strcat(str, ",0000,0,2,$");//2=scan
	
	file_write(file, "/proc/td3/i2c", str);
	
	sleep(1);
	
	file_read(file, "/proc/td3/i2c", str);
	
	char p = str[14];
	int a = atoi(p);
	
	if(a == ACC_ASIGNADO){
		return ACC_ASIGNADO;
	}
	else{
		return ACC_SIN_ASIGNAR;
	}
	
	return ACC_ERROR;
 }
 
 
 void asignar(char *user, char *pass){
	
	memset(str, '\0', strlen(user));
	strcat(str, "00,p,");
	strcat(str, user);
	strcat(str, ",");
	strcat(str, pass);
	strcat(str, ",0,1,$");//1=write
	
	file_write(file, "/proc/td3/i2c", str);
 }
 
 void operar(char *op){
	 
	memset(str, '\0', strlen(str));
	strcat(str, "00,a,1,");
	strcat(str, op);
	strcat(str, ",$");
	
	file_write(file, "/proc/td3/i2c", str);
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
