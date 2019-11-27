#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Cachorro.h"
#include "LinkedList.h"

/** \brief Muestra el menu de opciones
 *
 * \param int* option
 * \param
 * \return int 1-10 segun opcion elegida.
 *
 */


int menu(int* option)
{
    system("cls");
    printf("****Menu de opciones****\n\n");
    printf("1-Cargar archivo\n");
    printf("2-Imprimir lista\n");
    printf("3-Filtrar menores de 45 dias\n");
    printf("4-Filtrar machos\n");
    printf("5-Generar listado de callejeros\n");
    printf("6-Salir\n\n");

    scanf("%d", option);

    return *option;
}

/** \brief Guarda una estructura Cachorro inicializada y devuelve un puntero a dicha estructura
 *
 * \param
 * \param
 * \return Cachorro* puntero a la estructura inicialiada
 *
 */

Cachorro* cachorro_new()
{
    Cachorro* nuevo = (Cachorro*) malloc(sizeof(Cachorro));
    if(nuevo != NULL)
    {
        nuevo->id_Cachorro = 0;
        strcpy(nuevo->nombre, " ");
        nuevo->dias = 0;
        strcpy(nuevo->raza, " ");
        strcpy(nuevo->reservado, " ");
        strcpy(nuevo->genero, " ");
    }
    return nuevo;
}

/** \brief Recibe como string el id, el nombre, las horas trabajadas y el sueldo de un empleado para crearlo.
 *
 * \param char* idStr
 * \param char* nombreStr
 * \param char* diasStr
 * \param char* sueldoStr
 * \return Cachorro* nuevo cachorro
 *
 */

Cachorro* cachorro_newParametros(char* idStr, char* nombreStr, char* diasStr, char* razaStr, char* reservadoStr, char* generoStr)
{
    Cachorro* nuevo = cachorro_new();
    if(nuevo != NULL)
    {
        if(!(cachorro_setId(nuevo, atoi(idStr))
        && cachorro_setNombre(nuevo, nombreStr)
        && cachorro_setDias(nuevo, atoi(diasStr))
        && cachorro_setRaza(nuevo, razaStr)
        && cachorro_setReservado(nuevo, reservadoStr)
        && cachorro_setGenero(nuevo, generoStr)))
        {
            nuevo = NULL;
        }
    }

    return nuevo;
}

/** \brief Muestra los datos de un empleado
 *
 * \param Cachorro*
 * \param
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_print(Cachorro* this)
{
    int todoOk = 0;
    int idAux;
    char nombreAux[51];
    int diasAux;
    char razaAux[51];
    char resAux[3];
    char genAux[2];

    cachorro_getId(this, &idAux);
    cachorro_getNombre(this, nombreAux);
    cachorro_getDias(this, &diasAux);
    cachorro_getRaza(this, razaAux);
    cachorro_getReservado(this, resAux);
    cachorro_getGenero(this, genAux);

    if(this != NULL)
    {
        printf("%03d  %20s          %02d           %20s      %2s     %s\n", idAux, nombreAux, diasAux, razaAux, resAux, genAux);
        todoOk = 1;
    }

    return todoOk;

}

/** \brief Asigna el id al empleado
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_setId(Cachorro* this, int id)
{
    int todoOk = 0;

    if(this != NULL && id > 0)
    {
        this->id_Cachorro = id;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Asigna el nombre al empleado
 *
 * \param Cachorro*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_setNombre(Cachorro* this, char* nombre)
{
    int todoOk = 0;
    if(this != NULL && nombre != NULL && strlen(nombre) < 51)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Asigna las horas trabajadas al empleado
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_setDias(Cachorro* this, int dias)
{
    int todoOk = 0;

    if( this != NULL && dias > 0)
    {
        this->dias = dias;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Asigna la raza al cachorro
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_setRaza(Cachorro* this, char* raza)
{
    int todoOk = 0;

    if(this != NULL && raza != NULL && strlen(raza) < 51)
    {
        strcpy(this->raza, raza);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Asigna la raza al cachorro
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_setReservado(Cachorro* this, char* reservado)
{
    int todoOk = 0;

    if(this != NULL && reservado != NULL && strlen(reservado) < 3)
    {
        strcpy(this->reservado, reservado);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Asigna la raza al cachorro
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_setGenero(Cachorro* this, char* genero)
{
    int todoOk = 0;
    if(this != NULL && genero != NULL )
    {
        strcpy(this->genero, genero);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Obtiene el id del empleado
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_getId(Cachorro* this, int* id)
{
    int todoOk = 0;

    if( this != NULL && id != NULL)
    {
        *id = this->id_Cachorro;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Obtiene el nombre del empleado
 *
 * \param Cachorro*
 * \param char*
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_getNombre(Cachorro* this, char* nombre)
{
    int todoOk = 0;

    if( this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}

/** \brief Obtiene las horas trabajadas del empleado
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_getDias(Cachorro* this, int* dias)
{
    int todoOk = 0;

    if(this != NULL && dias != NULL)
    {
        *dias = this->dias;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Obtiene el sueldo del empleado
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_getRaza(Cachorro* this, char* raza)
{
    int todoOk = 0;

    if( this != NULL && raza != NULL)
    {
        strcpy(raza, this->raza);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Obtiene el sueldo del empleado
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_getReservado(Cachorro* this, char* reservado)
{
    int todoOk = 0;

    if( this != NULL && reservado != NULL)
    {
        strcpy(reservado, this->reservado);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief Obtiene el sueldo del empleado
 *
 * \param Cachorro*
 * \param int
 * \return int 1 si se ejecutó correctamente, 0 si error.
 *
 */

int cachorro_getGenero(Cachorro* this, char* genero)
{
    int todoOk = 0;

    if( this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        todoOk = 1;
    }

    return todoOk;
}

int cachorro_compEdad(void* c1)
{
    Cachorro* aux = (Cachorro*) c1;
    int todoOk = -1;
    int edad;

    if(aux != NULL)
    {
        cachorro_getDias(aux, &edad);
        if(edad >= 45)
        {
            todoOk = 1;
        }
        else
        {
            todoOk = 0;
        }
    }

    return todoOk;
}

int cachorro_compGen(void* c1)
{
    Cachorro* aux = (Cachorro*) c1;
    int todoOk = -1;
    char auxGen[2];

    if(aux != NULL)
    {
        cachorro_getGenero(aux, auxGen);
        if(auxGen == "M")
        {
            todoOk = 0;
        }
        else
        {
            todoOk = 1;
        }
    }

    return todoOk;
}
