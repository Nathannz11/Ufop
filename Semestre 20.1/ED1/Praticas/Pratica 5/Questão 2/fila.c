//Nathann Zini Dos Reis 19.2.4007

#include "fila.h"

struct fila{
    Lista* lista;
    int primeiro;
    int ultimo;
};

void Fila_Inicia(Fila **pFila){
    *pFila = malloc(sizeof(Fila));
    Lista_Inicia(&(*pFila)->lista);
    (*pFila)->primeiro = 0;
    (*pFila)->ultimo = 0;
}

int Fila_EhVazia(Fila *pFila){
    return Lista_EhVazia(pFila->lista);
}

void Fila_Enfileira(Fila *pFila, Item x){
    Lista_Insere(pFila->lista, pFila->ultimo, x);
    pFila->ultimo = Lista_Tamanho(pFila->lista);
}

int Fila_Desenfileira(Fila *pFila, Item *pX){
    int aux = Lista_Remove(pFila->lista, pFila->primeiro, pX);
    if(aux)
        pFila->ultimo = Lista_Tamanho(pFila->lista);
    return aux;
}

int Fila_Tamanho(Fila *pFila){
    return Lista_Tamanho(pFila->lista);
}

void Fila_Imprimi(Fila* pFila){
    Lista_imprime(pFila->lista);
}

void Fila_Libera(Fila** pFila){
    lista_libera(&(*pFila)->lista);
    free(pFila);
    *pFila = NULL;
}