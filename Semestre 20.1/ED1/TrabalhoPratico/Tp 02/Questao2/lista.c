//Nathann Zini Dos Reis 19.2.4007
#include "lista.h"

struct lista{
    ListaNo* prim;
    int tamanho;
};

struct listano {
    Item item;
    ListaNo* prox;
};

void Lista_Inicia(Lista **pLista){
    *pLista = (Lista*) malloc(sizeof(Lista));
    (*pLista)->prim = NULL;    
    (*pLista)->tamanho = 0;
}

int Lista_EhVazia(Lista *pLista){
    return (pLista->prim == NULL);
}

void Lista_Insere(Lista *pLista, int p, Item x){
    ListaNo* anterior = NULL;
    ListaNo* novo = malloc(sizeof(ListaNo));
    novo->prox= NULL;
    novo->item = x;

    if(!Lista_EhVazia(pLista)){
        anterior = pLista->prim;
        for(int i = 0; i < p; i++){
            anterior = anterior->prox;
        }
        novo->prox = anterior->prox;
        anterior->prox = novo;
        pLista->tamanho += 1;
    }else{
        pLista->tamanho += 1;
        pLista->prim = novo;
    }    
}

int Lista_Remove(Lista *pLista, int p, Item *pX){

    if(!Lista_EhVazia(pLista)){

        ListaNo* anterior = NULL;
        ListaNo* aux = pLista->prim;

        for(int i = 0; i < p - 1; i++){
            if(aux != NULL){
                anterior = aux;
                aux = aux->prox;
            }
            
        }
        if(aux != NULL){
            if(anterior == NULL){
                pLista->prim = aux->prox;
            }else{
                anterior->prox = aux->prox;
            }
            *pX = aux->item;
            aux->prox = NULL;
            
            free(aux);
        }
        pLista->tamanho -= 1;
        return 1;
        }
    return 0;
}

int Lista_Tamanho(Lista *pLista){
    
    return pLista->tamanho;
    
}



void Lista_imprime(Lista *pLista)
{   
    if (!Lista_EhVazia(pLista)){     
        ListaNo* aux = pLista->prim;
        while (aux != NULL){
            printf("%d ", aux->item);
            aux = aux->prox;
        }
        printf("\n");
    }
}

void lista_libera(Lista **pLista)
{
  ListaNo* aux = (*pLista)->prim;

  while (aux != NULL)
  {
    ListaNo *prox = aux->prox;
    free(aux);
    aux = prox;
  }

  free(*pLista);
  *pLista = NULL;
}