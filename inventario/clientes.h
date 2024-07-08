#ifndef CLIENTES_H
#define CLIENTES_H

int esCedulaValida(const char *cedula);
void agregarCliente(char cedulas[][11], char nombres[][50], int *contador, int maxClientes);
void modificarCliente(char cedulas[][11], char nombres[][50], int contador);
void consultarCliente(char cedulas[][11], char nombres[][50], int contador);
void listarClientes(char cedulas[][11], char nombres[][50], int contador);
void eliminarCliente(char cedulas[][11], char nombres[][50], int *contador);

#endif




