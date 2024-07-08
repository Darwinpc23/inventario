
void facturar(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int *contador, char cedulasClientes[][11], char nombresClientes[][50], int contadorClientes, char nombresProductos[][50], int cantidadesProductos[], float precios[], int contadorProductos);
void buscarFactura(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int contador);
void listarFacturas(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int contador);
void cargarFacturas(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int *contador, const char *nombreArchivo);
void guardarFacturas(char fechas[][11], char cedulas[][11], char nombres[][50], float valores[], int cantidades[], int contador, const char *nombreArchivo);


