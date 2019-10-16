#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "Validaciones.h"

/** \brief Comprueba que el id de marca ingresado por el usuario sea valido
 *
 * \param int -- id de marca
 * \param
 * \return
 *
 */

void validarIdMarca(int idMarca)
{
    while(!(idMarca > 999 && idMarca < 1005))
    {
        printf("Codigo de marca no valido, reingrese: ");
        fflush(stdin);
        scanf("%d", &idMarca);
    }
}

/** \brief Comprueba que el id de color ingresado por el usuario sea valido
 *
 * \param int -- id de color
 * \param
 * \return
 *
 */

void validarIdColor(int idColor)
{
    while(!(idColor > 4999 && idColor < 5005))
    {
        printf("Codigo de color no valido, reingrese: ");
        fflush(stdin);
        scanf("%d", &idColor);
    }
}

/** \brief Comprueba que el modelo ingresado por el usuario sea valido
 *
 * \param int -- anio de fabricacion del auto (modelo)
 * \param
 * \return
 *
 */

void validarModelo(int modelo)
{
    while(!(modelo < 2019 && modelo > 1900))
    {
        printf("Error. Reingrese modelo: ");
        fflush(stdin);
        scanf("%d", &modelo);
    }
}

/** \brief Comprueba que el id de servicio ingresado por el usuario sea valido
 *
 * \param int -- id de servicio
 * \param
 * \return
 *
 */

void validarIdServicio(int idServicio)
{
    while(!(idServicio > 19999 && idServicio < 20005))
    {
        printf("Codigo de servicio no valido, reingrese: ");
        fflush(stdin);
        scanf("%d", &idServicio);
    }
}

/** \brief Comprueba que la fecha ingresada por el usuario sea valida
 *
 * \param int -- dia
 * \param int -- mes
 * \param int -- anio
 * \return
 *
 */

void validarFecha(int dia, int mes, int anio)
{
    while(!(mes > 1 && mes < 13) && (!(anio > 2018 && anio < 2025)) && (!(dia > 0 && dia < 32)))
    {
        printf("Error. Reingrese fecha: ");
        scanf("%d/%d/%d", &dia, &mes, &anio);
    }
}
