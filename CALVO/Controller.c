#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "LinkedList.h"
#include "Cachorro.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListCachorro)
{
    int todoOk = 0;
    FILE* f = NULL;

    system("cls");

    if(path != NULL && pArrayListCachorro != NULL && ll_isEmpty(pArrayListCachorro))
    {
        f = fopen(path, "r");
        if(parser_CachorroFromText(f, pArrayListCachorro))
        {
            todoOk = 1;
        }
    }

    if(todoOk == 1)
    {
        printf("Datos cargados exitosamente.\n");
    }
    else
    {
        printf("No se pudo cargar los datos.\n");
    }

    system("pause");

    return todoOk;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error
 *
 */
int controller_ListCachorro(LinkedList* pArrayListCachorro)
{
    int todoOk = 0;
    Cachorro* auxCachorro = NULL;

    system("cls");

    if(pArrayListCachorro != NULL && ll_len(pArrayListCachorro) > 0)
    {
        printf("Id                  Nombre      Dias                        Raza      Reservado  Genero\n\n");
        for(int i=0; i < ll_len(pArrayListCachorro); i++)
        {
            auxCachorro = (Cachorro*) ll_get(pArrayListCachorro, i);
            cachorro_print(auxCachorro);
        }
        todoOk = 1;
    }
    else
    {
        printf("No hay cachorros que mostrar. \n");
    }

    system("pause");

    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int  1 si se ejecutó correctamente, 0 si error
 *
 */

int controller_saveAsText(char* path, LinkedList* pArrayListCachorro)
{
    int todoOk = 0;
    int cant;
    int tam = ll_len(pArrayListCachorro);
    FILE* f;
    Cachorro* cachorroAux;
    int idAux;
    char nombreAux[51];
    int diasAux;
    char razaAux[51];
    char resAux[3];
    char genAux[2];

    if(pArrayListCachorro != NULL && path != NULL && tam > 0)
    {
        f = fopen(path, "w");
        if(f == NULL)
        {
            return todoOk;
        }

        fprintf(f, "ID,Nombre,Dias,Raza,Reservado,Genero\n");

        for(int i=0; i<tam; i++)
        {
            cachorroAux = (Cachorro*) ll_get(pArrayListCachorro, i);
            cachorro_getId(cachorroAux, &idAux);
            cachorro_getNombre(cachorroAux, nombreAux);
            cachorro_getDias(cachorroAux, &diasAux);
            cachorro_getRaza(cachorroAux, razaAux);
            cachorro_getReservado(cachorroAux, resAux);
            cachorro_getGenero(cachorroAux, genAux);
            cant = fprintf(f, "%d, %s, %d, %s, %s, &s\n",
                           idAux,
                           nombreAux,
                           diasAux,
                           razaAux,
                           resAux,
                           genAux);

            if (cant < 1)
            {
                return todoOk;
            }
        }
        todoOk = 1;
    }
    fclose(f);

    if(todoOk == 1)
    {
        printf("Datos guardados en archivo .csv exitosamente.\n");
    }
    else
    {
        printf("No se pudo guardar los datos.\n");
    }

    system("pause");

    return todoOk;
}
