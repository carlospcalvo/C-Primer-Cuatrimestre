#ifndef cachorro_H_INCLUDED
#define cachorro_H_INCLUDED
typedef struct
{
    int id_Cachorro;
    char nombre[51];
    int dias;
    char raza[51];
    char reservado[3];
    char genero[3];
}Cachorro;

Cachorro* cachorro_new();
Cachorro* cachorro_newParametros(char* idStr, char* nombreStr, char* diasStr, char* razaStr, char* reservadoStr, char* generoStr);
//id
int cachorro_setId(Cachorro* this, int id);
int cachorro_getId(Cachorro* this, int* id);

//nombre
int cachorro_setNombre(Cachorro* this, char* nombre);
int cachorro_getNombre(Cachorro* this, char* nombre);

//dias
int cachorro_setDias(Cachorro* this, int dias);
int cachorro_getDias(Cachorro* this, int* dias);

//raza
int cachorro_setRaza(Cachorro* this, char* raza);
int cachorro_getRaza(Cachorro* this, char* raza);

//reservado
int cachorro_setReservado(Cachorro* this, char* reservado);
int cachorro_getReservado(Cachorro* this, char* reservado);

//genero
int cachorro_setGenero(Cachorro* this, char* genero);
int cachorro_getGenero(Cachorro* this, char* genero);
//int cachorro_sortSueldo(void* e1, void* e2);

int menu(int* option);
int cachorro_print(Cachorro* this);
int cachorro_compEdad(void* c1);
int cachorro_compGen(void* c1);

#endif // cachorro_H_INCLUDED
