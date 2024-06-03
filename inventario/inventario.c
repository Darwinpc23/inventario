#include <stdio.h>
#include "inventario.h"
#include "lecturas.h"

void agregarProducto(Producto productos[], int *contador, int maxProductos) {
    if (*contador >= maxProductos) {
        printf("Inventario lleno. No se pueden agregar más productos.\n");
        return;
    }

    printf("Ingresando un nuevo producto:\n");
    printf("Nombre del producto: ");
    scanf("%s", productos[*contador].nombre);

    productos[*contador].cantidad = leerEnteroPositivo("Cantidad del producto: ");
    productos[*contador].precio = leerFlotantePositivo("Precio del producto: ");
    
    (*contador)++;
    printf("Producto agregado exitosamente.\n");
}

void mostrarProductos(Producto productos[], int contador) {
    if (contador == 0) {
        printf("No hay productos en el inventario.\n");
        return;
    }

    printf("\nLista de productos:\n");
    for (int i = 0; i < contador; i++) {
        printf("Producto %d:\n", i + 1);
        printf("  Nombre: %s\n", productos[i].nombre);
        printf("  Cantidad: %d\n", productos[i].cantidad);
        printf("  Precio: %.2f\n", productos[i].precio);
    }
}
