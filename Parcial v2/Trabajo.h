#include "Auto.h"
#include "Servicio.h"
#include "Validaciones.h"

#ifndef TRABAJO_H_INCLUDED
#define TRABAJO_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

typedef struct
{
    int id;
    int patente;
    int idServicio;
    eFecha fecha;
    int isEmpty;
} eTrabajo;

#endif // TRABAJO_H_INCLUDED

void inicializarTrabajos(eTrabajo vec[], int tam);
void mostrarTrabajo(eTrabajo x, eServicio servicio[], int tamS);
void mostrarTrabajos(eTrabajo vec[], int tam, eServicio servicio[], int tamS);
int altaTrabajo(eTrabajo lista[], int tamT, eAuto vec[], int tam, int idTrabajo, eServicio servicio[], int tamS);
eTrabajo newTrabajo(int idTrabajo, int patente, int idServicio, eFecha fecha);
