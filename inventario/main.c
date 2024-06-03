#include <stdio.h>
#include "inventario.h"
#include "lecturas.h"

#define MAX_PRODUCTOS 100

int main() {
    Producto productos[MAX_PRODUCTOS];
    int contador = 0;
    char opcion;

    printf("Bienvenido al sistema de inventario del supermercado\n");

    do {
        printf("\nOpciones:\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Mostrar cantidad total de productos\n");
        printf("4. Salir\n");
        opcion = leerCaracter("Elija una opción: ");

        switch (opcion) {
            case '1':
                agregarProducto(productos, &contador, MAX_PRODUCTOS);
                break;
            case '2':
                mostrarProductos(productos, contador);
                break;
            case '3':
                printf("Total de productos ingresados: %d\n", contador);
                break;
            case '4':
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción no válida, intente nuevamente.\n");
        }
    } while (opcion != '4');

    return 0;
}
