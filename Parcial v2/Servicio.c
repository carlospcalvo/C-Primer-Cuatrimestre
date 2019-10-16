#include "Servicio.h"

/** \brief Inicializa el vector de servicios
 *
 * \param eServicio -- vector
 * \param int -- tamanio del vector
 * \return
 *
 */

void inicializarServicios(eServicio vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

/** \brief Muestra un elemento del vector de servicios
 *
 * \param eServicio -- elemento
 * \param
 * \return
 *
 */

void mostrarServicio(eServicio x)
{
    printf("  %d  %10s   %8d\n", x.id, x.descripcion, x.precio);
}

/** \brief Muestra todos los elementos del vector de servicios
 *
 * \param eServicio -- vector
 * \param int -- tamanio del vector
 * \return
 *
 */

void mostrarServicios(eServicio vec[], int tam)
{

    int flag = 0;
    system("cls");

    printf("   ID    Descripcion     Precio \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarServicio(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay servicios que mostrar\n");
    }

    printf("\n\n");
}

/** \brief Hardcodea 5 servicios
 *
 * \param eServicio -- vector
 * \param int -- tamanio del vector
 * \param int -- cantidad de elementos del vector a hardcodear
 * \return int -- 0 si Error
 *                !=0 si Ok
 */

int hardcodearLavados( eServicio vec[], int tam, int cantidad)
{
    int cont = 0;

    eServicio suplentes[]=
    {
        { 20000, "Lavado", 250, 0},
        { 20001, "Pulido", 300, 0},
        { 20002, "Encerado", 400, 0},
        { 20003, "Completo", 600, 0}
    };

    if( cantidad <= 4 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}
