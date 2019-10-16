#ifndef COLOR_H_INCLUDED
#define COLOR_H_INCLUDED

typedef struct
{
    int id;
    char nombreColor[21];
    int isEmpty;
} eColor;

#endif // COLOR_H_INCLUDED

void inicializarColores(eColor vec[], int tam);
void mostrarColor(eColor x);
void mostrarColores(eColor vec[], int tam);
int hardcodearColores( eColor vec[], int tam, int cantidad);

