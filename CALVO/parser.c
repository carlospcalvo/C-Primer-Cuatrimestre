#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Cachorro.h"

/** \brief Parsea los datos los datos de los cachorros desde el archivo cachorros.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListCachorro LinkedList*
 * \return int 1 si se ejecutó correctamente, 0 si error
 *
 */
int parser_CachorroFromText(FILE* pFile , LinkedList* pArrayListCachorro)
{
    int todoOk = 0;
    char buffer[6][30];
    int cant;
    Cachorro* auxCachorro = NULL;

    if( pFile != NULL && pArrayListCachorro != NULL)
    {
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
        while( !feof(pFile))
        {
            cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
            if( cant == 6)
            {
                auxCachorro = cachorro_newParametros(buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], buffer[5]);
                if(auxCachorro != NULL)
                {
                    ll_add(pArrayListCachorro, auxCachorro);
                    todoOk = 1;
                }
            }
            else
            {
                break;
            }
        }
    }

    return todoOk;
}
