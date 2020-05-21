#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdbool.h>
#include "utilities.h"
#include "linked_list.h"



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
    fscanf(arguments[1],"%d",&tipo);
    if (tipo == 0) {
      int tiempo;
      int num_lineas;
      fscanf(arguments[1],"%d %d",&tiempo,&num_lineas);
      int[num_lineas] lineas;
      for (size_t i = 0; i < count; i++) {
        fscanf(arguments[1], "%d", &lineas[i]);
      }

    }
    else if (tipo == 1) {
      int iteraciones;
      int A,B,C,D;
      int tablero;
      fscanf("tablero.txt", "%d %d %d %d %d %d", &iteraciones,&A,&B,&C,&D,&tablero);
    }

    else{
      printf("Something went wrong\n");
    }

  }
}
