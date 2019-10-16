#include "Auto.h"

/** \brief Inicializa el vector de autos
 *
 * \param eAuto -- vector
 * \param int -- tamanio
 * \return
 *
 */

void inicializarAutos(eAuto vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}

/** \brief Muestra un elemento del vector de autos
 *
 * \param eAuto -- elemento
 * \param eColor -- vector colores
 * \param int -- tamanio del vector colores
 * \param eMarca -- vector marcas
 * \param int -- tamanio del vector marcas
 * \return
 *
 */

void mostrarAuto(eAuto x, eColor colores[], int tamC, eMarca marcas[], int tamM)
{
    char descripcionColor[21];
    char descripcionMarca[21];

    for(int i=0; i < tamC; i++)
    {
        if( colores[i].id == x.idColor && x.isEmpty == 0)
        {
            strcpy(descripcionColor, colores[i].nombreColor);
            break;
        }
    }

    for(int j=0; j < tamM; j++)
    {
        if( marcas[j].id == x.idMarca && x.isEmpty == 0)
        {
            strcpy(descripcionMarca, marcas[j].descripcion);
            break;
        }
    }
    printf(" %2d  %8d   %10s    %10s    %4d\n",
           x.id,
           x.patente,
           descripcionMarca,
           descripcionColor,
           x.modelo);
}

/** \brief Muestra todos los elemntos del vector de autos
 *
 * \param eAuto -- vector de autos
 * \param int -- tamanio del vector de autos
 * \param eColor -- vector de colores
 * \param int -- tamanio del vector de colores
 * \param eMarca -- vector de marcas
 * \param int -- tamanio del vector de marcas
 * \return
 *
 */

void mostrarAutos(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM)
{

    int flag = 0;
    system("cls");

    printf(" ID    Patente      Marca          Color   Modelo\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarAuto(vec[i],colores,tamC,marcas,tamM);
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

/** \brief Busca un indice libre (isEmpty == 1) en el vector de autos
 *
 * \param eAuto -- vector
 * \param int -- tamanio del vector
 * \return int -- != -1 si hay un indice libre
 *                -1 si Error
 */

int buscarLibre(eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Permite dar de alta un auto
 *
 * \param eAuto -- vector de autos
 * \param int -- tamanio del vector de autos
 * \param int -- id del auto
 * \param eMarca -- vector de marcas
 * \param int -- tamanio del vector de marcas
 * \param eColor -- vector de colores
 * \param int -- tamanio del vector de colores
 * \return int -- 1 si se dio de alta con exito
 *                0 si el sistema esta completo
 */

int altaAuto(eAuto vec[], int tam, int id, eMarca marcas[], int tamM, eColor color[], int tamC)
{
    int todoOk = 0;
    int indice;
    int patente;
    int idMarca;
    int idColor;
    int modelo;

    system("cls");

    printf("*****Alta Auto*****\n\n");

    indice = buscarLibre(vec, tam);

    if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese patente: ");
        fflush(stdin);
        scanf("%d", &patente);

        mostrarMarcas(marcas, tamM);
        printf("Ingrese id de marca: ");
        fflush(stdin);
        scanf("%d", &idMarca);
        validarIdMarca(idMarca);

        mostrarColores(color, tamC);
        printf("Ingrese color: ");
        fflush(stdin);
        scanf("%d", &idColor);
        validarIdColor(idColor);

        printf("Ingrese modelo (anio): ");
        fflush(stdin);
        scanf("%d", &modelo);
        validarModelo(modelo);

        vec[indice] = newAuto(id, patente, idMarca, idColor, modelo);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

    return todoOk;


}

/** \brief Busca un auto cuya patente coincida con la patente ingresada por el usuario
 *
 * \param int -- patente del auto
 * \param eAuto -- vector de autos
 * \param int -- tamanio del vector
 * \return int -- -1 si no se encontro el auto
 *                != -1 el indice del auto
 */

int buscarAuto(int patente, eAuto vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].patente == patente && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief Permite modificar datos de un auto existente.
 *
 * \param eAuto -- vector de autos
 * \param int -- tamanio del vector de autos
 * \param eColor -- vector de colores
 * \param int -- tamanio del vector de colores
 * \param eMarca -- vector de marcas
 * \param int -- tamanio del vector de marcas
 * \return in -- 0 si no hay errores
 *
 */

int modificarAuto(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM)
{
    int todoOk = 0;
    int patente;
    int indice;
    system("cls");
    printf("***** Modificar Auto *****\n\n");
    printf("Ingrese patente: ");
    scanf("%d", &patente);
    int opcion;

    indice = buscarAuto(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe un auto con esa patente\n\n");

    }
    else
    {

        mostrarAuto(vec[indice], colores, tamC, marcas, tamM);

        printf("1- Modificar color\n");
        printf("2- Modificar modelo\n");
        printf("3- Salir\n\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            mostrarColores(colores, tamC);
            printf("Ingrese nuevo color: ");
            scanf("%d", &vec[indice].idColor);
            validarIdColor(vec[indice].idColor);
            break;

        case 2:
            printf("Ingrese nuevo modelo: ");
            scanf("%d", &vec[indice].modelo);
            validarModelo(vec[indice].modelo);
            break;
        case 3:
            printf("Se ha cancelado la modificacion.\n\n");
            break;

        }
    }
    return todoOk;
}

/** \brief Permite dar de baja un auto.
 *
 * \param eAuto -- vector de autos
 * \param int -- tamanio del vector de autos
 * \param eColor -- vector de colores
 * \param int -- tamanio del vector de colores
 * \param eMarca -- vector de marcas
 * \param int -- tamanio del vector de marcas
 * \return int -- 1 si se dio de baja un auto
 *                0 si se cancelo la operacion
 *                != 1 && 0 si hubo algun error
 */

int bajaAuto(eAuto vec[], int tam, eColor colores[], int tamC, eMarca marcas[], int tamM)
{
    int todoOk = 0;
    int patente;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja Auto *****\n\n");
    printf("Ingrese patente: ");
    scanf("%d", &patente);

    indice = buscarAuto(patente, vec, tam);

    if( indice == -1)
    {
        printf("No existe un auto con esa patente\n\n");

    }
    else
    {
        mostrarAuto(vec[indice], colores, tamC, marcas, tamM);

        printf("\nConfirma baja? (s/n)");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa.\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion.\n\n");
        }
    }

    return todoOk;
}

/** \brief Hardcodea 5 autos
 *
 * \param eAuto -- vector
 * \param int -- tamanio del vector
 * \param int -- cantidad de elemntos del vector a hardcodear
* \return int -- 0 si Error
          *                !=0 si Ok
 */

int hardcodearAutos( eAuto vec[], int tam, int cantidad)
{
    int cont = 0;

    eAuto suplentes[]=
    {
        { 1, 123456, 1001, 5000, 2006, 0},
        { 2, 123789, 1000, 5000, 1998, 0},
        { 3, 456789, 1004, 5002, 1928, 0},
        { 4, 123123, 1002, 5001, 2011, 0},
        { 5, 100001, 1003, 5003, 2019, 0},
        { 6, 101010, 1001, 5002, 2006, 0},
        { 7, 600111, 1003, 5000, 1988, 0},
        { 8, 110011, 1001, 5004, 1979, 0},
        { 9, 222222, 1004, 5001, 2007, 0},
        { 10, 999999, 1003, 5003, 2016, 0}
    };

    if( cantidad <= 10 && tam >= cantidad)
    {
        for(int i=0; i < cantidad; i++)
        {

            vec[i] = suplentes[i];
            cont++;
        }
    }

    return cont;
}

/** \brief Crea un elemento eAuto
 *
 * \param int -- id del auto
 * \param int -- patente del auto
 * \param int -- id de la marca del auto
 * \param int -- id del color del auto
 * \param int -- modelo del auto
 * \return eAuto -- nuevo auto
 *
 */

eAuto newAuto(int id, int patente, int idMarca, int idColor, int modelo)
{
    eAuto carro;
    carro.id = id;
    carro.patente = patente;
    carro.idMarca = idMarca;
    carro.idColor = idColor;
    carro.modelo = modelo;
    carro.isEmpty = 0;

    return carro;
}

