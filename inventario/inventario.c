#include "inventario.h"
#include <stdio.h>
#include <string.h>

// Implementaciones de las funciones existentes...

void adicionarCompraProducto(char nombres[][50], int cantidades[], float precios[], int *contador, int maxProductos) {
    if (*contador >= maxProductos) {
        printf("No se pueden adicionar más productos, inventario lleno.\n");
        return;
    }

    char nombreProducto[50];
    int cantidadAdicional;
    float precio;

    printf("Ingrese el nombre del producto: ");
    scanf("%s", nombreProducto);
    printf("Ingrese la cantidad adicional: ");
    scanf("%d", &cantidadAdicional);
    printf("Ingrese el precio del producto: ");
    scanf("%f", &precio);

    // Busca el producto en el inventario
    for (int i = 0; i < *contador; i++) {
        if (strcmp(nombres[i], nombreProducto) == 0) {
            cantidades[i] += cantidadAdicional;
            precios[i] = precio;
            printf("Producto actualizado correctamente.\n");
            return;
        }
    }

    // Si no se encontró el producto, lo adiciona como nuevo
    strcpy(nombres[*contador], nombreProducto);
    cantidades[*contador] = cantidadAdicional;
    precios[*contador] = precio;
    (*contador)++;
    printf("Producto adicionado correctamente.\n");
}

void eliminarProducto(char nombres[][50], int cantidades[], float precios[], int *contador) {
    char nombreProducto[50];

    printf("Ingrese el nombre del producto a eliminar: ");
    scanf("%s", nombreProducto);

    for (int i = 0; i < *contador; i++) {
        if (strcmp(nombres[i], nombreProducto) == 0) {
            for (int j = i; j < *contador - 1; j++) {
                strcpy(nombres[j], nombres[j + 1]);
                cantidades[j] = cantidades[j + 1];
                precios[j] = precios[j + 1];
            }
            (*contador)--;
            printf("Producto eliminado correctamente.\n");
            return;
        }
    }
    printf("Producto no encontrado.\n");
}
