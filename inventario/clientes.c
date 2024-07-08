#include <stdio.h>
#include <string.h>
#include "clientes.h"

int esCedulaValida(const char *cedula) {
    if (strlen(cedula) != 10) return 0;
    int provincia = (cedula[0] - '0') * 10 + (cedula[1] - '0');
    if (provincia < 1 || provincia > 24) return 0;
    int tercerDigito = cedula[2] - '0';
    if (tercerDigito < 0 || tercerDigito > 5) return 0;
    return 1;
}

void agregarCliente(char cedulas[][11], char nombres[][50], int *contador, int maxClientes) {
    if (*contador >= maxClientes) {
        printf("No se pueden agregar más clientes.\n");
        return;
    }

    printf("Ingresando un nuevo cliente:\n");
    do {
        printf("Cédula del cliente: ");
        scanf("%s", cedulas[*contador]);
        if (!esCedulaValida(cedulas[*contador])) {
            printf("Cédula no válida. Intente nuevamente.\n");
        }
    } while (!esCedulaValida(cedulas[*contador]));

    printf("Nombre del cliente: ");
    scanf("%s", nombres[*contador]);

    (*contador)++;
    printf("Cliente ingresado correctamente.\n");
}

void modificarCliente(char cedulas[][11], char nombres[][50], int contador) {
    char cedula[11];
    printf("Ingrese la cédula del cliente a modificar: ");
    scanf("%s", cedula);

    for (int i = 0; i < contador; i++) {
        if (strcmp(cedulas[i], cedula) == 0) {
            printf("Ingrese el nuevo nombre del cliente: ");
            scanf("%s", nombres[i]);
            printf("Cliente modificado correctamente.\n");
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}

void consultarCliente(char cedulas[][11], char nombres[][50], int contador) {
    char cedula[11];
    printf("Ingrese la cédula del cliente a consultar: ");
    scanf("%s", cedula);

    for (int i = 0; i < contador; i++) {
        if (strcmp(cedulas[i], cedula) == 0) {
            printf("Cliente encontrado:\n");
            printf("Cédula: %s\n", cedulas[i]);
            printf("Nombre: %s\n", nombres[i]);
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}

void listarClientes(char cedulas[][11], char nombres[][50], int contador) {
    printf("Listado de clientes:\n");
    for (int i = 0; i < contador; i++) {
        printf("Cédula: %s, Nombre: %s\n", cedulas[i], nombres[i]);
    }
}

void eliminarCliente(char cedulas[][11], char nombres[][50], int *contador) {
    char cedula[11];
    printf("Ingrese la cédula del cliente a eliminar: ");
    scanf("%s", cedula);

    for (int i = 0; i < *contador; i++) {
        if (strcmp(cedulas[i], cedula) == 0) {
            for (int j = i; j < *contador - 1; j++) {
                strcpy(cedulas[j], cedulas[j + 1]);
                strcpy(nombres[j], nombres[j + 1]);
            }
            (*contador)--;
            printf("Cliente eliminado correctamente.\n");
            return;
        }
    }
    printf("Cliente no encontrado.\n");
}
