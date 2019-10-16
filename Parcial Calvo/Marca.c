#include "Marca.h"

/** \brief Inicializa vector de marcas
 *
 * \param eMarca -- vector
 * \param int -- tamanio del vector
 * \return
 *
 */

void inicializarMarcas(eMarca vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

/** \brief Muestra un elemento del vector de marcas
 *
 * \param eMarca -- elemento
 * \param
 * \return
 *
 */

void mostrarMarca(eMarca x)
{
    printf("  %d  %20s\n", x.id, x.descripcion);
}

/** \brief Muestra todos los elemntos del vector de marcas
 *
 * \param eMarca -- vector
 * \param int -- tamanio del vector
 * \return
 *
 */

void mostrarMarcas(eMarca vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf(" ID               Descripcion \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarMarca(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay marcas que mostrar\n");
    }

    printf("\n\n");
}

/** \brief Hardcodea 5 marcas de autos (as requested)
 *
 * \param eMarca -- vector
 * \param int -- tamanio del vector
 * \param int -- cantidad de elementos del vector a hardcodear
 * \return int -- 0 si Error
 *                !=0 si Ok
 */

int hardcodearMarcas( eMarca vec[], int tam, int cantidad)
{
    int cont = 0;

    eMarca suplentes[]=
    {
        { 1000, "RENAULT", 0},
        { 1001, "FIAT", 0},
        { 1002, "FORD", 0},
        { 1003, "CHEVROLET", 0},
        { 1004, "PEUGEOT", 0}
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

