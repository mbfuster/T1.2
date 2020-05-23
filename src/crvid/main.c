#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>


int main(int argument_count, char* arguments[])
{
/**-------------------------- Si el input está mal puesto---------------------*/
	if (argument_count != 3)
	{
		printf("Modo de uso: %s <input.txt> <número>\n\n", arguments[0]);
		printf("\tinput inicial: archivo de texto plano que contiene las lineas con descripciones para los procesos\n");
		return 1;
	}
  else
  {
    int tipo;
		//Como usamos execvp el nombre del archivo siempre deberia estar correcto
		char* inputname = arguments[1];
		FILE* file = fopen(inputname, "r");
    if( file == NULL ) {
       perror("Custom error alert: Error ");
       return -1;
    }
    fscanf(file,"%d",&tipo);

		//Tipo generador
    if (tipo == 0) {
			clock_t start = clock();
			int status = 0;
      float tiempo;
      int num_lineas;
      fscanf(file,"%f %d",&tiempo,&num_lineas);

      int lineas[num_lineas];
      for (int i = 0; i < num_lineas; i++) {
        fscanf(file, "%d", &lineas[i]);
      }

			//Aqui hace los hijos y deberia volver a ejecutar este mismo programa
			for (int i = 0; i < num_lineas; i++) {
				char* c_linea;
				char linea[10];
				snprintf(linea,10,"%d",lineas[i]);
				strcpy(c_linea,linea);
				char *args[]={arguments[0],inputname,c_linea};
				fork();
				execvp(args[0],args);
			}
			fclose(file);


			float diff_time = (float)(clock()-start)/CLOCKS_PER_SEC;
			while(diff_time < tiempo && wait(&status)>0){
				diff_time = (float)(clock()-start)/CLOCKS_PER_SEC;
			}
      //Una vez q termina el tiempo tiene que imprimir estadisticas


    }
		//Tipo simulador
    else if (tipo == 1) {
      int iteraciones;
      int A,B,C,D;
      int tablero;
      fscanf(file, "%d %d %d %d %d %d", &iteraciones,&A,&B,&C,&D,&tablero);
      //Agregar fork y time y exec

    }


    else{
      printf("Something went wrong\n");
    }

  }
}
