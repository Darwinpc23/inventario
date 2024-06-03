typedef struct {
    char nombre[50];
    int cantidad;
    float precio;
} Producto;

void agregarProducto(Producto productos[], int *contador, int maxProductos);
void mostrarProductos(Producto productos[], int contador);