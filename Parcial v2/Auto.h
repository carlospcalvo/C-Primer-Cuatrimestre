#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Marca.h"
#include "Color.h"
#include "Validaciones.h"

#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

typedef struct
{
    int id;
    int patente;
    int idMarca;
    int idColor;
    int modelo;
    int isEmpty;
} eAuto;

#endif // AUTO_H_INCLUDED

void inicializarAutos(eAuto vec[], int tam);
void mostrarAuto(eAuto x, eColor vec[], int tamC, eMarca marcas[], int tamM);
void mostrarAutos(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM);
int buscarLibre(eAuto vec[], int tam);
int altaAuto(eAuto vec[], int tam, int id, eMarca marcas[], int tamM, eColor color[], int tamC);
int buscarAuto(int patente, eAuto vec[], int tam);
int modificarAuto(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM);
int bajaAuto(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM);
int hardcodearAutos( eAuto vec[], int tam, int cantidad);
eAuto newAuto(int id, int patente, int idMarca, int idColor, int modelo);
