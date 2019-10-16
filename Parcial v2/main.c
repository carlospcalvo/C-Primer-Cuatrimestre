#include "Marca.h"
#include "Color.h"
#include "Auto.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Validaciones.h"

#define TAM 5
#define TAML 4

/** \brief Main - Inicializa los vectores y se le asigna funciones a las opciones del menu
 *
 * \param
 * \param
 * \return int -- 0 si OK
 *                !=0 si Error
 *
 */


int main()
{
    eAuto coches[TAM];
    eMarca marcas[TAM];
    eColor colores[TAM];
    eServicio lavados[TAML];
    eTrabajo trabajos[TAM];
    char salir = 'n';
    int id = 1;
    int idTrabajo = 1;

    inicializarAutos(coches, TAM);
    inicializarColores(colores, TAM);
    inicializarMarcas(marcas, TAM);
    inicializarServicios(lavados, TAML);
    inicializarTrabajos(trabajos, TAM);

    hardcodearColores(colores, TAM, 5);
    hardcodearLavados(lavados, TAML, 4);
    hardcodearMarcas(marcas, TAM, 5);
    hardcodearAutos(coches, TAM, 5);

    do
    {
        switch(menu())
        {
        case 1:
            id = id + altaAuto(coches, TAM, id, marcas, TAM, colores, TAM);
            system("pause");
            break;
        case 2:
            modificarAuto(coches, TAM, colores, TAM, marcas, TAM);
            system("pause");
            break;
        case 3:
            bajaAuto(coches, TAM, colores, TAM, marcas, TAM);
            system("pause");
            break;
        case 4:
            mostrarAutos(coches, TAM, colores, TAM, marcas, TAM);
            break;
        case 5:
            mostrarMarcas(marcas, TAM);
            system("pause");
            break;
        case 6:
            mostrarColores(colores, TAM);
            system("pause");
            break;
        case 7:
            mostrarServicios(lavados, TAML);
            system("pause");
            break;
        case 8:
            idTrabajo = idTrabajo + altaTrabajo(trabajos, TAM, coches, TAM, idTrabajo, lavados, TAML);
            break;
        case 9:
            mostrarTrabajos(trabajos, TAM, lavados, TAML);
            break;
        case 10:
            printf("Confirma salir? (s/n): ");
            salir = getche();
            while(!(salir == 's' || salir == 'n'))
            {
                printf("Opcion incorrecta. Reingrese (s/n): ");
                salir = getche();
            }
            break;
        default:
            printf("Opcion incorrecta. Reingrese: ");
        }


    }
    while(salir == 'n');

    return 0;
}
