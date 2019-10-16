#include "Trabajo.h"
#include "Validaciones.h"

/** \brief Inicializa el vector de trabajos
 *
 * \param eTrabajo -- vector
 * \param int -- tamanio del vector
 * \return
 *
 */

void inicializarTrabajos(eTrabajo vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

/** \brief Muestra un elemento del vector de trabajos
 *
 * \param eTrabajo -- elemento
 * \param eServicio -- vector de servicios
 * \param int -- tamanio del vector
 * \return
 *
 */

void mostrarTrabajo(eTrabajo x, eServicio servicio[], int tamS)
{

    char descripcionServ[21];

    for(int i=0; i < tamS; i++)
    {
        if( servicio[i].id == x.idServicio && servicio[i].isEmpty == 0)
        {
            strcpy(descripcionServ, servicio[i].descripcion);
            break;
        }
    }

    printf("  %d  %8d    %10s       %02d/%02d/%d \n",
           x.id,
           x.patente,
           descripcionServ,
           x.fecha.dia,
           x.fecha.mes,
           x.fecha.anio);
}

/** \brief Muestra todos los elementos del vector de trabajos
 *
 * \param eTrabajo -- vector de trabajos
 * \param int -- tamanio del vector de trabajos
 * \param eServicio -- vector de servicios
 * \param int -- tamanio del vector de servicios
 * \return
 *
 */

void mostrarTrabajos(eTrabajo vec[], int tam, eServicio servicio[], int tamS)
{

    int flag = 0;
    system("cls");

    printf(" ID    Patente      Servicio      Fecha\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarTrabajo(vec[i], servicio, tamS);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay trabajos que mostrar\n\n");
    }

    system("pause");
    printf("\n\n");
}

/** \brief PErmite dar de alta un trabajo.
 *
 * \param eTrabajo -- vector de trabajos
 * \param int -- tamanio del vector de trabajos
 * \param eAuto -- vector de autos
 * \param int -- tamanio del vector de autos
 * \param int -- id del trabajo
 * \param eServicio -- vector de servicios
 * \param int -- tamanio del vector de servicios
 * \return int -- 0 si error
 *                1 si Ok
 */

int altaTrabajo(eTrabajo lista[], int tamT, eAuto vec[], int tam, int idTrabajo, eServicio servicio[], int tamS)
{
    int todoOk = 0;
    int coche;
    int patente;
    int indice;
    int idServicio;
    eFecha fecha;

    system("cls");

    printf("*****Alta Trabajo*****\n\n");

    printf("Ingrese patente: ");
    fflush(stdin);
    scanf("%d", &patente);

    coche = buscarAuto(patente, vec, tam);

    if( coche == -1)
    {
        printf("\nNo existe un auto con esa patente\n\n");
        system("pause");
    }
    else
    {
        indice = buscarLibre(vec, tam);

        if( indice == -1)
        {
            printf("\nSistema completo\n\n");
        }
        else
        {
            mostrarServicios(servicio, tamS);
            printf("Ingrese id de servicio: ");
            fflush(stdin);
            scanf("%d", &idServicio);
            validarIdServicio(idServicio);

            printf("Ingrese fecha del trabajo (dd/mm/aaaa): ");
            scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
            validarFecha(fecha.dia, fecha.mes, fecha.anio);
        }
    }
    lista[indice] = newTrabajo(idTrabajo, patente, idServicio, fecha);
    todoOk = 1;
    printf("Alta exitosa.\n\n");


    return todoOk;


}

/** \brief Crea un elemento eTrabajo
 *
 * \param int -- id del trabajo
 * \param int -- patente del auto
 * \param int -- id del servicio
 * \param eFecha -- fecha del trabajo
 * \return eTrabajo -- nuevo trabajo
 *
 */

eTrabajo newTrabajo(int idTrabajo, int patente, int idServicio, eFecha fecha)
{
    eTrabajo lavado;
    lavado.id = idTrabajo;
    lavado.patente = patente;
    lavado.idServicio = idServicio;
    lavado.fecha = fecha;
    lavado.isEmpty = 0;

    return lavado;
}
