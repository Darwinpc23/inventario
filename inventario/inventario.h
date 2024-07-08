#ifndef INVENTARIO_H
#define INVENTARIO_H

void cargarProductos(char nombres[][50], int cantidades[], float precios[], int *contador, const char *nombreArchivo);
void agregarProducto(char nombres[][50], int cantidades[], float precios[], int *contador, int maxProductos);
void mostrarProductos(char nombres[][50], int cantidades[], float precios[], int contador);
void buscarProducto(char nombres[][50], int cantidades[], float precios[], int contador);
void editarProducto(char nombres[][50], int cantidades[], float precios[], int contador);
void adicionarCompraProducto(char nombres[][50], int cantidades[], float precios[], int *contador, int maxProductos);
void eliminarProducto(char nombres[][50], int cantidades[], float precios[], int *contador);

#endif







