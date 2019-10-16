#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#ifndef MARCA_H_INCLUDED
#define MARCA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[21];
    int isEmpty;
} eMarca;

#endif // MARCA_H_INCLUDED

void inicializarMarcas(eMarca vec[], int tam);
void mostrarMarca(eMarca x);
void mostrarMarcas(eMarca vec[], int tam);
int hardcodearMarcas( eMarca vec[], int tam, int cantidad);

