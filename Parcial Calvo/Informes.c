#include "Informes.h"

/** \brief Muestra el menu y pide al usuario elegir una opcion
 *
 * \param
 * \param
 * \return int -- opcion elegida
 *
 */

int menu()
{
    int opcion = 0;

    system("cls");
    printf("****Menu de opciones****\n\n");
    printf("1-Alta Auto\n");
    printf("2-Modificar Auto\n");
    printf("3-Baja Auto\n");
    printf("4-Listar Autos\n");
    printf("5-Listar Marcas\n");
    printf("6-Listar Colores\n");
    printf("7-Listar Servicios\n");
    printf("8-Alta Trabajo\n");
    printf("9-Listar trabajos\n");
    printf("10-Informes\n");
    printf("11-Salir\n\n");
    scanf("%d", &opcion);
    return opcion;
}



int menuInformes()
{
    int opcion = 0;

    system("cls");
    printf("****Menu de informes****\n\n");
    printf("1-Mostrar autos de color negro\n");
    printf("2-Mostrar autos de una marca seleccionada\n");
    printf("3-Mostrar todos los trabajos efectuados al auto seleccionado\n");
    //printf("4-Listar los autos que no tuvieron trabajos\n");
    printf("5-Informar importe total de los trabajos realizados a un auto seleccionado\n");
    printf("6-Mostrar el servicio mas pedido\n");
    printf("7-Mostrar la recaudacion en una fecha en particular\n");
    //printf("8-Mostrar todos los autos que realizaron un encerado y la fecha\n");
    //printf("9-Trabajos realizados a autos blancos\n");
    //printf("10-Facturacion total por los pulidos");
    //printf("11-Informar la marca de autos que efectuaron mas lavados completos\n");
    //printf("12-Listar los autos que recibieron trabajos en una fecha determinada\n");
    printf("13-Salir\n\n");
    scanf("%d", &opcion);
    return opcion;
}

void mostrarAutosNegros(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM)
{
    system("cls");
    printf(" ID    Patente      Marca          Color   Modelo\n\n");
    for(int i= 0; i<tam; i++)
    {
        if (vec[i].idColor == 5000 && vec[i].isEmpty == 0)
        {
            mostrarAuto(vec[i], colores,tamC, marcas, tamM);
        }
    }
    system("pause");
}

void mostrarAutosXMarca(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM)
{
    int idMarca;

    system("cls");
    mostrarMarcas(marcas, tamM);
    printf("Ingrese id de marca: ");
    fflush(stdin);
    scanf("%d", &idMarca);
    validarIdMarca(idMarca);
    system("cls");
    printf(" ID    Patente      Marca          Color   Modelo\n\n");

    for(int i= 0; i<tam; i++)
    {
        if (vec[i].idMarca == idMarca && vec[i].isEmpty == 0)
        {
            mostrarAuto(vec[i], colores,tamC, marcas, tamM);
        }
    }

    system("pause");
}

void mostrarTrabajosDeUnAuto(eTrabajo lista[], int tamT, eAuto vec[], int tam, eServicio servicio[], int tamS)
{
    int patente;
    int indice;
    system("cls");
    printf("Ingrese patente: ");
    scanf("%d", &patente);

    indice = buscarAuto(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe un auto con esa patente\n\n");

    }
    else
    {
        printf("\n\n");
        printf(" ID    Patente      Servicio      Fecha\n\n");
        for(int i=0; i<tamT; i++)
        {
            if(lista[i].patente == patente && lista[i].isEmpty == 0)
            {
                mostrarTrabajo(lista[i], servicio, tamS);
            }
        }
    }

    printf("\n\n");
    system("pause");
}
/*
void mostrarAutosSinTrabajo(eTrabajo lista[], int tamT, eAuto vec[], int tam, eServicio servicio[], int tamS)
{
    system("cls");
    int trabajosPorPatente[tamT];

    for(int i=0; i<tamT; i++)
    {
        trabajosPorPatente[i] = lista[i].patente;
    }

    for(int j=0; j<tam; j++)
    {

    }


    system("pause");
}
*/

void importeTotalXAuto(eAuto vec[], int tam, eTrabajo lista[], int tamT, eServicio servicios[], int tamS)
{
    int patente;
    int indice;
    int importe = 0;
    system("cls");

    printf("Ingrese patente: ");
    scanf("%d", &patente);

    indice = buscarAuto(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe un auto con esa patente\n\n");

    }
    else
    {
        printf("\n");
        for(int i=0; i<tamT; i++)
        {
            if(lista[i].patente == patente && lista[i].isEmpty == 0)
            {
                for(int j=0; j<tamS; j++)
                {
                    if(lista[i].idServicio == servicios[j].id)
                    {
                        importe = importe + servicios[j].precio;
                    }
                }

            }
        }
    }
    printf("El importe total para el auto con patente %d es $%d", patente, importe);
    printf("\n\n");
    system("pause");
}

void servicioMasPedido(eTrabajo lista[], int tamT, eServicio servicios[], int tamS)
{
    int contLavado = 0;
    int contPulido = 0;
    int contEncerado = 0;
    int contCompleto = 0;
    system("cls");

    for(int i=0; i<tamT; i++)
    {
        if(lista[i].idServicio == 20000)
        {
            contLavado++;
        }
        else if(lista[i].idServicio == 20001)
        {
            contPulido++;
        }
        else if(lista[i].idServicio == 20002)
        {
            contEncerado++;
        }
        else if(lista[i].idServicio == 20003)
        {
            contCompleto++;
        }
    }

    if(contLavado > contPulido && contLavado > contEncerado && contLavado > contCompleto)
    {
        printf("El servicio mas pedido es el Lavado.");
    }
    else if(contLavado < contPulido && contPulido > contEncerado && contPulido > contCompleto)
    {
        printf("El servicio mas pedido es el Pulido.");
    }
    else if(contLavado < contEncerado && contLavado < contEncerado && contEncerado > contCompleto)
    {
        printf("El servicio mas pedido es el Encerado.");
    }
    else if(contLavado < contCompleto && contCompleto > contEncerado && contEncerado < contCompleto)
    {
        printf("El servicio mas pedido es el Completo.");
    }
    else if(contLavado == contPulido && contPulido == contEncerado && contEncerado > contCompleto)
    {
        printf("Los servicios mas pedidos son Lavado, Pulido y Encerado.");
    }
    else if(contLavado == contPulido && contPulido == contCompleto && contEncerado < contCompleto)
    {
        printf("Los servicios mas pedidos son Lavado, Pulido y Completo.");
    }
    else if(contLavado == contEncerado && contEncerado == contCompleto && contEncerado > contPulido)
    {
        printf("Los servicios mas pedidos son Lavado, Encerado y Completo.");
    }
    else if(contPulido == contEncerado && contEncerado == contCompleto && contLavado < contPulido)
    {
        printf("Los servicios mas pedidos son Pulido, Encerado y Completo.");
    }
    else if(contLavado == contPulido && contEncerado < contPulido && contCompleto < contPulido)
    {
        printf("Los servicios mas pedidos son Lavado y Pulido.");
    }
    else if(contLavado == contEncerado && contEncerado > contPulido && contCompleto < contEncerado)
    {
        printf("Los servicios mas pedidos son Lavado y Encerado.");
    }
    else if(contLavado == contCompleto && contEncerado > contCompleto && contCompleto < contPulido)
    {
        printf("Los servicios mas pedidos son Lavado y Completo.");
    }
    else if(contEncerado == contPulido && contEncerado > contLavado && contCompleto < contPulido)
    {
        printf("Los servicios mas pedidos son Pulido y Encerado.");
    }
    else if(contCompleto == contPulido && contEncerado < contPulido && contCompleto > contLavado)
    {
        printf("Los servicios mas pedidos son Pulido y Completo.");
    }
    else if(contCompleto == contEncerado && contEncerado > contPulido && contCompleto > contLavado)
    {
        printf("Los servicios mas pedidos son Encerado y Completo.");
    }
    printf("\n\n");
    system("pause");
}

void recaudacionXFecha(eTrabajo lista[], int tamT, eServicio servicios[], int tamS)
{
    float recaudacion = 0;
    eFecha fechaBuscada;
    system("cls");

    printf("Ingrese fecha del trabajo (dd/mm/aaaa): ");
    scanf("%d/%d/%d", &fechaBuscada.dia, &fechaBuscada.mes, &fechaBuscada.anio);
    validarFecha(fechaBuscada.dia, fechaBuscada.mes, fechaBuscada.anio);

    for(int i=0; i<tamT; i++)
    {
        for(int j=0; j<tamS; j++)
        {
            if(fechaBuscada.dia == lista[i].fecha.dia && fechaBuscada.mes == lista[i].fecha.mes
               && fechaBuscada.anio == lista[i].fecha.anio && lista[i].idServicio == servicios[j].id)
            {
                recaudacion = (float) recaudacion + servicios[j].precio;
            }
        }
    }
    printf("\n");
    printf("La recaudacion del dia %d/%d/%d fue $%2f", fechaBuscada.dia, fechaBuscada.mes, fechaBuscada.anio, recaudacion);
    printf("\n\n");
    system("pause");
}
/*
void mostrarEncerados(eTrabajo lista[], int tamT, eServicio servicios[], int tamS, eAuto vec[], int tam)
{
    system("cls");



    system("pause");
}

void mostrarAutoYFechaEncerado(eAuto x, eColor colores[], int tamC, eMarca marcas[], int tamM, eTrabajo lista[], int tamT)
{
    char descripcionColor[21];
    char descripcionMarca[21];
    eFecha fechaEncerado;

    for(int i=0; i < tamC; i++)
    {
        if( colores[i].id == x.idColor && colores[i].isEmpty == 0)
        {
            strcpy(descripcionColor, colores[i].nombreColor);
            break;
        }
    }

    for(int j=0; j < tamM; j++)
    {
        if( marcas[j].id == x.idMarca && marcas[j].isEmpty == 0)
        {
            strcpy(descripcionMarca, marcas[j].descripcion);
            break;
        }
    }

    for(int k=0; k < tamT; k++)
    {
        if( lista[k].patente == x.patente && lista[k].idServicio == 20002 )
        {
            fechaEncerado.dia = lista[k].fecha.dia;
            fechaEncerado.mes = lista[k].fecha.mes;
            fechaEncerado.anio = lista[k].fecha.anio;
            break;
        }
    }

    printf(" %2d  %8d   %10s    %10s    %4d   %d/%d/%d  \n",
           x.id,
           x.patente,
           descripcionMarca,
           descripcionColor,
           x.modelo,
           fechaEncerado.dia,
           fechaEncerado.mes,
           fechaEncerado.anio);
}

void mostrarAutosYFechaEncerados(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM, eTrabajo lista[], int tamT)
{
    int flag = 0;
    system("cls");

    printf(" ID    Patente      Marca          Color   Modelo    Fecha \n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0 )
        {
            mostrarAutoYFechaEncerado(vec[i], colores, tamC, marcas, tamM, lista, tamT);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay autos que mostrar\n\n");
    }

    system("pause");
    printf("\n\n\n");
}
*/



