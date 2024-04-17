#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(){
int cantidad;
printf("Ingrese la cantidad de nombres que quiere ingresar: ");
scanf("%d",&cantidad);

char ** nombre = malloc(cantidad*sizeof(char *));
char * buff = malloc(100*sizeof(char));

for (int i = 0; i < cantidad; i++)
{
    fflush(stdin);
    printf("Ingresa un nombre: \n");
    gets(buff);
    nombre[i] = malloc((strlen(buff)+1)*sizeof(char));
    strcpy(nombre[i],buff);
    
}

for (int i = 0; i < cantidad; i++)
{
    puts(nombre[i]);
}

free(nombre);
free(buff);
   return 0;
}