#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define cantNombre 5


int main(){

char ** nombre = malloc(cantNombre*sizeof(char *));
char * buff = malloc(100*sizeof(char));

for (int i = 0; i < cantNombre; i++)
{
    printf("Ingresa un nombre: \n");
    gets(buff);
    nombre[i] = malloc((strlen(buff)+1)*sizeof(char));
    strcpy(nombre[i],buff);
    
}

for (int i = 0; i < cantNombre; i++)
{
    puts(nombre[i]);
}

   return 0;
}