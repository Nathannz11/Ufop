#ifndef pilha_h
#define pilha_h

#include "lista.h"

typedef struct pilha Pilha;

typedef struct pilhano PilhaNo;

typedef int Item;

void Pilha_Inicia(Pilha *pPilha);

int Pilha_EhVazia(Pilha *pPilha);

void Pilha_Push(Pilha *pPilha, Item x);

int Pilha_Pop(Pilha *pPilha, Item *pX);

int Pilha_Tamanho(Pilha *pPilha);

#endif