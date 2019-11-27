#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"
#include "Cachorro.h"
#include "parser.h"
#include "Controller.h"

int main()
{
    int option;
    char salir;
    char path[51];
    LinkedList* listaCachorros = ll_newLinkedList();
    LinkedList* listaMayores = ll_newLinkedList();
    LinkedList* listaHembras = ll_newLinkedList();

   do
   {
       switch(menu(&option))
        {
            case 1:
                printf("Ingrese el nombre del archivo: ");
                fflush(stdin);
                scanf("%s", path);
                strcpy(path, strcat(path, ".csv"));
                controller_loadFromText(path, listaCachorros);
                break;
            case 2:
                controller_ListCachorro(listaCachorros);
                break;
            case 3:
                listaMayores = ll_filter(listaCachorros, cachorro_compEdad);
                controller_ListCachorro(listaMayores);
                printf("\nIngrese el nombre del archivo donde se guardaran los datos: ");
                fflush(stdin);
                scanf("%s", path);
                strcpy(path, strcat(path, ".csv"));
                controller_saveAsText(path, listaMayores);
                break;
            case 4:
                listaHembras = ll_filter(listaCachorros, cachorro_compGen);
                controller_ListCachorro(listaHembras);
                printf("\nIngrese el nombre del archivo donde se guardaran los datos: ");
                fflush(stdin);
                scanf("%s", path);
                strcpy(path, strcat(path, ".csv"));
                controller_saveAsText(path, listaHembras);
                break;
            case 5:
                printf("Generar lista Callejeros\n");
                break;
            case 6:
                printf("Confirma salida? (y/n)");
                fflush(stdin);
                salir = getche();
        }
   }while(salir != 'y');


    return 0;
}
