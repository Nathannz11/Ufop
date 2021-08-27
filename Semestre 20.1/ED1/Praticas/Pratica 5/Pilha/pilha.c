#include "pilha.h"

struct pilha
{
    PilhaNo* last;
    int tamanho;
};

struct pilhano{
    PilhaNo* prox;
    Item item;
}


void Pilha_Inicia(Pilha *pPilha){
    *pPilha = malloc(sizeof(Pilha));
    (*pPilha)->last = NULL;
    (*pPilha)-> item = 0;
}

int Pilha_EhVazia(Pilha *pPilha){
    return (pPilha->last == NULL);
}

void Pilha_Push(Pilha *pPilha, Item x){
    PilhaNo* aux = malloc (sizeof(PilhaNo));
    aux->item = x;
    aux->prox = NULL;
    if(Pilha_EhVazia(pPilha)){
        pPilha->last = aux;
    }else{
        aux->prox = pPilha->last;
        pPilha->last = aux;
    }
    pPilha->tamanho += 1;
}

int Pilha_Pop(Pilha *pPilha, Item *pX){
    if(Pilha_EhVazia(pPilha)){
        return 0
    }else{
        PilhaNo* aux = pPilha->last;
        *pX = aux->item;
        pPilha->last = aux->prox;
        free(aux);
    }
    pPilha->tamanho -= 1;
    return 1;

}

int Pilha_Tamanho(Pilha *pPilha){
    return pPilha->tamanho;
}