//Nathann Zini Dos Reis 19.2.4007

#ifndef fila_h
#define fila_h

#include "lista.h"

typedef struct fila Fila;

typedef int Item;


void Fila_Inicia(Fila **pFila);

int Fila_EhVazia(Fila *pFila);

void Fila_Enfileira(Fila *pFila, Item x);

int Fila_Desenfileira(Fila *pFila, Item *pX);

int Fila_Tamanho(Fila *pFila);

void Fila_Imprimi(Fila* pFila);

void Fila_Libera(Fila** pFila);

#endif