#include "Marca.h"
#include "Color.h"
#include "Auto.h"
#include "Servicio.h"
#include "Trabajo.h"
#include "Validaciones.h"
#include "Informes.h"

#define TAMA 10
#define TAMT 15
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
    eAuto coches[TAMA];
    eMarca marcas[TAM];
    eColor colores[TAM];
    eServicio lavados[TAML];
    eTrabajo trabajos[TAMT];
    char salir = 'n';
    int id = 1;
    int idTrabajo = 1;

    inicializarAutos(coches, TAMA);
    inicializarColores(colores, TAM);
    inicializarMarcas(marcas, TAM);
    inicializarServicios(lavados, TAML);
    inicializarTrabajos(trabajos, TAMT);

    hardcodearColores(colores, TAM, 5);
    hardcodearLavados(lavados, TAML, 4);
    hardcodearMarcas(marcas, TAM, 5);
    id = id + hardcodearAutos(coches, TAMA, 10);
    idTrabajo = idTrabajo + hardcodearTrabajos(trabajos, TAMT, 15);

    do
    {
        switch(menu())
        {
        case 1:
            id = id + altaAuto(coches, TAMA, id, marcas, TAM, colores, TAM);
            system("pause");
            break;
        case 2:
            modificarAuto(coches, TAMA, colores, TAM, marcas, TAM);
            system("pause");
            break;
        case 3:
            bajaAuto(coches, TAMA, colores, TAM, marcas, TAM);
            system("pause");
            break;
        case 4:
            mostrarAutos(coches, TAMA, colores, TAM, marcas, TAM);
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
            idTrabajo = idTrabajo + altaTrabajo(trabajos, TAMT, coches, TAMA, idTrabajo, lavados, TAML);
            break;
        case 9:
            mostrarTrabajos(trabajos, TAMT, lavados, TAML);
            break;
        case 10:
            switch(menuInformes())
            {
                case 1:
                    mostrarAutosNegros(coches, TAMA, colores, TAM, marcas, TAM);
                    break;
                case 2:
                    mostrarAutosXMarca(coches, TAMA, colores, TAM, marcas, TAM);
                    break;
                case 3:
                    mostrarTrabajosDeUnAuto(trabajos, TAMT, coches, TAMA, lavados, TAML);
                    break;
                case 4:
                    printf("Informe 4");
                    break;
                case 5:
                    importeTotalXAuto(coches, TAMA, trabajos, TAMT, lavados, TAML);
                    break;
                case 6:
                    servicioMasPedido(trabajos, TAMT, lavados, TAML);
                    break;
                case 7:
                    recaudacionXFecha(trabajos, TAMT, lavados, TAML);
                    break;
                case 8:
                    printf("Informe 8");
                    break;
                case 9:
                    printf("Informe 9");
                    break;
                case 10:
                    printf("Informe 10");
                    break;
                case 11:
                    printf("Informe 11");
                    break;
                case 12:
                    printf("Informe 12");
                    break;
                case 13:
                    system("cls");
                    system("pause");
                    break;
            }
            break;
        case 11:
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
