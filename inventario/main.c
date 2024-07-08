#include <stdio.h>
#include "lecturas.h"
#include "inventario.h"
#include "clientes.h"
#include "facturas.h"

#define MAX_PRODUCTOS 100
#define MAX_CLIENTES 100
#define MAX_FACTURAS 100

int main() {
    char nombresProductos[MAX_PRODUCTOS][50];
    int cantidades[MAX_PRODUCTOS];
    float precios[MAX_PRODUCTOS];
    int contadorProductos = 0;

    char cedulasClientes[MAX_CLIENTES][11];
    char nombresClientes[MAX_CLIENTES][50];
    int contadorClientes = 0;

    char fechasFacturas[MAX_FACTURAS][11];
    char cedulasFacturas[MAX_FACTURAS][11];
    char nombresFacturas[MAX_FACTURAS][50];
    float valoresFacturas[MAX_FACTURAS];
    int cantidadesFacturas[MAX_FACTURAS];
    int contadorFacturas = 0;

    char opcion;

    cargarProductos(nombresProductos, cantidades, precios, &contadorProductos, "productos.txt");
    cargarClientes(cedulasClientes, nombresClientes, &contadorClientes, "clientes.txt");
    cargarFacturas(fechasFacturas, cedulasFacturas, nombresFacturas, valoresFacturas, cantidadesFacturas, &contadorFacturas, "facturas.txt");

    printf("Bienvenido al sistema de inventario del supermercado\n");

    do {
        printf("\nOpciones:\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Mostrar cantidad total de productos\n");
        printf("4. Buscar producto\n");
        printf("5. Editar producto\n");
        printf("6. Adicionar compra de producto\n");
        printf("7. Eliminar producto\n");
        printf("9. Ingresar cliente\n");
        printf("A. Modificar cliente\n");
        printf("B. Consultar cliente\n");
        printf("C. Ver listado de clientes\n");
        printf("D. Eliminar cliente\n");
        printf("E. Facturar\n");
        printf("F. Buscar factura\n");
        printf("G. Ver listado de facturas\n");
        printf("H. Salir\n");
        opcion = leerCaracter("Elija una opción: ");

        switch (opcion) {
            case '1':
                agregarProducto(nombresProductos, cantidades, precios, &contadorProductos, MAX_PRODUCTOS);
                break;
            case '2':
                mostrarProductos(nombresProductos, cantidades, precios, contadorProductos);
                break;
            case '3':
                printf("Total de productos ingresados: %d\n", contadorProductos);
                break;
            case '4':
                buscarProducto(nombresProductos, cantidades, precios, contadorProductos);
                break;
            case '5':
                editarProducto(nombresProductos, cantidades, precios, contadorProductos);
                break;
            case '6':
                adicionarCompraProducto(nombresProductos, cantidades, precios, &contadorProductos, MAX_PRODUCTOS);
                break;
            case '7':
                eliminarProducto(nombresProductos, cantidades, precios, &contadorProductos);
                break;
            case '9':
                agregarCliente(cedulasClientes, nombresClientes, &contadorClientes, MAX_CLIENTES);
                break;
            case 'A':
                modificarCliente(cedulasClientes, nombresClientes, contadorClientes);
                break;
            case 'B':
                consultarCliente(cedulasClientes, nombresClientes, contadorClientes);
                break;
            case 'C':
                listarClientes(cedulasClientes, nombresClientes, contadorClientes);
                break;
            case 'D':
                eliminarCliente(cedulasClientes, nombresClientes, &contadorClientes);
                break;
            case 'E':
                facturar(fechasFacturas, cedulasFacturas, nombresFacturas, valoresFacturas, cantidadesFacturas, &contadorFacturas, cedulasClientes, nombresClientes, contadorClientes, nombresProductos, cantidades, precios, contadorProductos);
                break;
            case 'F':
                buscarFactura(fechasFacturas, cedulasFacturas, nombresFacturas, valoresFacturas, cantidadesFacturas, contadorFacturas);
                break;
            case 'G':
                listarFacturas(fechasFacturas, cedulasFacturas, nombresFacturas, valoresFacturas, cantidadesFacturas, contadorFacturas);
                break;
            case 'H':
                printf("Saliendo del programa...\n");
                guardarProductos(nombresProductos, cantidades, precios, contadorProductos, "productos.txt");
                guardarClientes(cedulasClientes, nombresClientes, contadorClientes, "clientes.txt");
                guardarFacturas(fechasFacturas, cedulasFacturas, nombresFacturas, valoresFacturas, cantidadesFacturas, contadorFacturas, "facturas.txt");
                break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (opcion != 'H');

    return 0;
}
