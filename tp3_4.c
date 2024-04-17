#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    Producto *Productos;         // El tamaño de este arreglo depende de la variable
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
        printf("\nEl id del cliente es: %d", clientes[i].ClienteID);
        printf("\nEl nombre del cliente es: ");
        puts(clientes[i].NombreCliente);
        printf("\nLa cantidad de productos pedidos es: %d", clientes[i].CantidadProductosAPedir);

        float costoTotal = 0.0;

        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++)
        {
            printf("\nEl id del producto es: %d", clientes->Productos[j].ProductoID);
            printf("\nLa cantidad es: %d", clientes->Productos[j].Cantidad);
            printf("\nEl tipo de producto es:%s", clientes->Productos[j].TipoProducto);
            printf("\nEl precio unitario es:%.2f", clientes->Productos[j].PrecioUnitario);
            float costo = calcularCosto(clientes[i].Productos[j]);
            printf("\nCosto total del producto: %.2f\n", costo);

            costoTotal += costo;
        }

        printf("\nTotal a pagar por el cliente: %.2f\n", costoTotal);
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
    srand(time(NULL));
    for (int i = 0; i < cantCliente; i++)
    {

        clientes[i].ClienteID = i + 1;
        clientes[i].NombreCliente = malloc(100 * sizeof(char));

        printf("Ingrese el nombre del cliente: ");
        fflush(stdin);
        fgets(clientes[i].NombreCliente, 100, stdin);
        clientes[i].NombreCliente[strcspn(clientes[i].NombreCliente, "\n")] = '\0';

        clientes[i].CantidadProductosAPedir = 1 + rand() % 5;

        clientes[i].Productos = malloc(clientes->CantidadProductosAPedir * sizeof(Producto));

        for (int j = 0; j < clientes->CantidadProductosAPedir; j++)
        {
            fflush(stdin);
            clientes->Productos[j].ProductoID = j + 1;
            fflush(stdin);
            clientes->Productos[j].Cantidad = 1 + rand() % 10;
            fflush(stdin);
            clientes->Productos[j].TipoProducto = TiposProductos[rand() % 5];
            fflush(stdin);
            clientes->Productos[j].PrecioUnitario = 10.0 + (rand() % 91);
        }
    }

    mostrar(clientes, cantCliente);

    for (int i = 0; i < cantCliente; i++)
    {
        free(clientes[i].NombreCliente);
        free(clientes[i].Productos);
    }
    free(clientes);
    

    return 0;
}