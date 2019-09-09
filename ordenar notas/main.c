#include <stdio.h>
#include <stdlib.h>

#define TAM 2

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam);
void mostrarAlumno(int leg, int age, char sex, int n1, int n2, float prom);

int main()
{
    char sexos[TAM];
    int legajos[TAM];
    int edades[TAM];
    int nota1[TAM];
    int nota2[TAM];
    float promedio[TAM];

    for(int i = 0; i< TAM; i++)
    {

        printf("Ingrese legajo: ");
        fflush(stdin);
        scanf("%d", &legajos[i]);

        printf("Ingrese edad: ");
        fflush(stdin);
        scanf("%d", &edades[i]);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexos[i]);

        printf("Ingrese nota primer parcial: ");
        fflush(stdin);
        scanf("%d", &nota1[i]);

        printf("Ingrese nota segundo parcial: ");
        fflush(stdin);
        scanf("%d", &nota2[i]);

        promedio[i] = (float) (nota1[i] + nota2[i]) / 2;
    }

    mostrarAlumnos(legajos, edades, sexos, nota1, nota2, promedio, TAM);

    return 0;
}

void mostrarAlumnos(int leg[], int age[], char sex[], int n1[], int n2[], float prom[], int tam)
{
    printf("\nLegajo  Edad  Sexo  Nota1  Nota2  Promedio\n");
    for(int i = 0; i< tam; i++)
    {
        mostrarAlumno(leg[i], age[i], sex[i], n1[i], n2[i], prom[i]);
    }
    printf("\n\n");
}

void mostrarAlumno(int leg, int age, char sex, int n1, int n2, float prom){
    printf("  %d     %d    %c    %d      %d      %.2f\n", leg, age, sex, n1, n2, prom);
}
