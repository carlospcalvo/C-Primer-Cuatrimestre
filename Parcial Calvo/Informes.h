#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Auto.h"
#include "Trabajo.h"

#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
#endif // INFORMES_H_INCLUDED

int menu();
int menuInformes();
void mostrarAutosNegros(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM);
void mostrarAutosXMarca(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM);
void mostrarTrabajosDeUnAuto(eTrabajo lista[], int tamT, eAuto vec[], int tam, eServicio servicio[], int tamS);
void importeTotalXAuto(eAuto vec[], int tam, eTrabajo lista[], int tamT, eServicio servicios[], int tamS);
void servicioMasPedido(eTrabajo lista[], int tamT, eServicio servicios[], int tamS);
void recaudacionXFecha(eTrabajo lista[], int tamT, eServicio servicios[], int tamS);
