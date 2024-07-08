#include <stdio.h>
#include <string.h>
#include "lecturas.h"
#include "facturas.h"

void facturar(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int *contador, char cedulasClientes[][11], char nombresClientes[][50], int contadorClientes, char nombresProductos[][50], int cantidadesProductos[], float precios[], int contadorProductos) {
    if (*contador >= 100) {
        printf("No se pueden agregar más facturas.\n");
        return;
    }

    printf("Ingresando una nueva factura:\n");
    printf("Fecha de la factura (YYYY-MM-DD): ");
    scanf("%s", fechas[*contador]);

    char cedulaCliente[11];
    printf("Cédula del cliente: ");
    scanf("%s", cedulaCliente);

    int clienteEncontrado = 0;
    for (int i = 0; i < contadorClientes; i++) {
        if (strcmp(cedulasClientes[i], cedulaCliente) == 0) {
            strcpy(cedulas[*contador], cedulaCliente);
            strcpy(nombres[*contador], nombresClientes[i]);
            clienteEncontrado = 1;
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente no encontrado.\n");
        return;
    }

    printf("Ingrese el número de productos a facturar: ");
    int numProductos;
    scanf("%d", &numProductos);

    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        char nombreProducto[50];
        printf("Nombre del producto: ");
        scanf("%s", nombreProducto);

        int productoEncontrado = 0;
        for (int j = 0; j < contadorProductos; j++) {
            if (strcmp(nombresProductos[j], nombreProducto) == 0) {
                int cantidad;
                printf("Cantidad: ");
                scanf("%d", &cantidad);

                if (cantidad <= cantidadesProductos[j]) {
                    cantidadesProductos[j] -= cantidad;
                    total += cantidad * precios[j];
                    cantidades[*contador] += cantidad;
                    productoEncontrado = 1;
                } else {
                    printf("No hay suficiente cantidad de %s en el inventario.\n", nombreProducto);
                }

                break;
            }
        }

        if (!productoEncontrado) {
            printf("Producto no encontrado.\n");
        }
    }

    valores[*contador] = total;
    (*contador)++;

    printf("Factura ingresada exitosamente.\n");
}

void buscarFactura(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int contador) {
    if (contador == 0) {
        printf("No hay facturas en el sistema.\n");
        return;
    }

    char fechaBuscada[11];
    printf("Ingrese la fecha de la factura a buscar (YYYY-MM-DD): ");
    scanf("%s", fechaBuscada);

    for (int i = 0; i < contador; i++) {
        if (strcmp(fechas[i], fechaBuscada) == 0) {
            printf("Factura encontrada:\n");
            printf("  Fecha: %s\n", fechas[i]);
            printf("  Cédula: %s\n", cedulas[i]);
            printf("  Nombre: %s\n", nombres[i]);
            printf("  Valor: %.2f\n", valores[i]);
            printf("  Cantidad: %d\n", cantidades[i]);
            return;
        }
    }

    printf("Factura no encontrada.\n");
}

void listarFacturas(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int contador) {
    if (contador == 0) {
        printf("No hay facturas en el sistema.\n");
        return;
    }

    printf("\nLista de facturas:\n");
    for (int i = 0; i < contador; i++) {
        printf("Factura %d:\n", i + 1);
        printf("  Fecha: %s\n", fechas[i]);
        printf("  Cédula: %s\n", cedulas[i]);
        printf("  Nombre: %s\n", nombres[i]);
        printf("  Valor: %.2f\n", valores[i]);
        printf("  Cantidad: %d\n", cantidades[i]);
    }
}

void cargarFacturas(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int *contador, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de facturas. Se creará uno nuevo.\n");
        return;
    }

    while (fscanf(archivo, "%s %s %s %f %d", fechas[*contador], cedulas[*contador], nombres[*contador], &valores[*contador], &cantidades[*contador]) != EOF) {
        (*contador)++;
    }

    fclose(archivo);
}

void guardarFacturas(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int contador, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de facturas para escribir.\n");
        return;
    }

    for (int i = 0; i < contador; i++) {
        fprintf(archivo, "%s %s %s %f %d\n", fechas[i], cedulas[i], nombres[i], valores[i], cantidades[i]);
    }

    fclose(archivo);
}
