#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Color.h"

/** \brief Inicializa el vector de colores
 *
 * \param eColor -- vector
 * \param int -- tamanio del vector
 * \return
 *
 */

void inicializarColores(eColor vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

/** \brief Muestra un elemento del vector de colores
 *
 * \param eColor -- elemento
 * \param
 * \return
 *
 */

void mostrarColor(eColor x)
{
    printf("  %d  %20s\n", x.id, x.nombreColor);
}

/** \brief Muestra todos los elementos del vector de colores
 *
 * \param eColor -- vector
 * \param int -- tamanio del vector
 * \return
 *
 */

void mostrarColores(eColor vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" ID               Descripcion \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarColor(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay colores que mostrar\n");
    }

    printf("\n\n");
}

/** \brief Hardcodea los colores solicitados
 *
 * \param eColor -- vector
 * \param int -- tamanio
 * \param int -- cantidad de elementos del vector a hardcodear
 * \return int -- 0 si Error
 *                !=0 si Ok
 */

int hardcodearColores( eColor vec[], int tam, int cantidad)
{
    int cont = 0;

    eColor suplentes[]=
    {
        { 5000, "NEGRO", 0},
        { 5001, "BLANCO", 0},
        { 5002, "GRIS", 0},
        { 5003, "ROJO", 0},
        { 5004, "AZUL", 0}
    };

    if( cantidad <= 5 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}
