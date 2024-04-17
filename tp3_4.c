#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

struct
{
    int ProductoID;       // Numerado en ciclo iterativo
    int Cantidad;         // entre 1 y 10
    char *TipoProducto;   // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} typedef Producto;

struct
{
    int ClienteID;               // Numerado en el ciclo iterativo
    char *NombreCliente;         // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos;          // El tamaño de este arreglo depende de la variable
    // “CantidadProductosAPedir”
} typedef Cliente;

float calcularCosto(Producto costo)
{
    return costo.Cantidad * costo.PrecioUnitario;
};

void mostrar(Cliente *clientes, int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("El id del cliente es: %d", clientes->ClienteID);
        printf("El nombre del cliente es: %s", clientes->NombreCliente);
        printf("La cantidad de productos pedidos es: %d", clientes->CantidadProductosAPedir);

        for (int j = 0; j < clientes->CantidadProductosAPedir; i++)
        {
            printf("El id del producto es: %d", clientes->Productos[j].ProductoID);
            printf("La cantidad es: %d", clientes->Productos[j].Cantidad);
            printf("El tipo de producto es:%s", clientes->Productos[j].TipoProducto);
            printf("El precio unitario es:%d", clientes->Productos[j].PrecioUnitario);
            printf("El costo total seria:%d", calcularCosto(clientes->Productos[j]));
        }
        clientes++;
    }
}

int main()
{

    int cantCliente;
    Cliente *clientes;
    char *buff = malloc(100 * sizeof(char));

    printf("Ingrese la cantidad de clientes: ");
    scanf("%d", &cantCliente);

    clientes = malloc(cantCliente * sizeof(Cliente));

    for (int i = 0; i < cantCliente; i++)
    {

        clientes->ClienteID = i + 1;
        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        scanf("%s",&clientes->NombreCliente);
        fflush(stdin);
        clientes->CantidadProductosAPedir = 1 + rand() % 5;

        clientes->Productos = malloc(clientes->CantidadProductosAPedir * sizeof(Producto));

        for (int j = 0; j < clientes->CantidadProductosAPedir; j++)
        {
            fflush(stdin);
            clientes->Productos[j].ProductoID = j+1;
            fflush(stdin);
            clientes->Productos[j].Cantidad = 1 + rand()%10;
            fflush(stdin);
            char * buff = malloc(100*sizeof(char));
            printf("Ingresa algun producto: ");
            fflush(stdin);
            puts(buff);
            fflush(stdin);
            clientes->Productos[j].TipoProducto = malloc(strlen(buff)+1*sizeof(char));
            fflush(stdin);
            strcpy(clientes->Productos[j].TipoProducto,buff);
            fflush(stdin);
            clientes->Productos[j].PrecioUnitario = 1 + rand()%100;
        }
        clientes++;
    }

    return 0;
}