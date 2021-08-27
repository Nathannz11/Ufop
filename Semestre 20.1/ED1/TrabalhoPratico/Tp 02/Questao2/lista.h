//Nathann Zini Dos Reis 19.2.4007
#ifndef lista_h
#define lista_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct lista Lista;

typedef struct listano ListaNo;

typedef int Item;

void Lista_Inicia(Lista **pLista);

int Lista_EhVazia(Lista *pLista);

void Lista_Insere(Lista *pLista, int p, Item x);

int Lista_Remove(Lista *pLista, int p, Item *pX);

int Lista_Tamanho(Lista *pLista);

void Lista_imprime(Lista *pLista);

void lista_libera(Lista **pLista);

#endif