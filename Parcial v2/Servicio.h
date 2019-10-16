#ifndef SERVICIO_H_INCLUDED
#define SERVICIO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[26];
    int precio;
    int isEmpty;
} eServicio;

#endif // SERVICIO_H_INCLUDED

void inicializarServicios(eServicio vec[], int tam);
void mostrarServicio(eServicio x);
void mostrarServicios(eServicio vec[], int tam);
int hardcodearLavados(eServicio vec[], int tam, int cantidad);
