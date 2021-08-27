//Nathann Zini Dos Reis 19.2.4007
#include "pilha.h"

struct pilha
{
    Lista* lista;
    int tamanho;
};


void Pilha_Inicia(Pilha **pPilha){
    *pPilha = malloc(sizeof(Pilha));
    Lista_Inicia(&(*pPilha)->lista);
    (*pPilha)->tamanho = 0;
}

int Pilha_EhVazia(Pilha *pPilha){
    return Lista_EhVazia(pPilha->lista);
}

void Pilha_Push(Pilha *pPilha, Item x){
    Lista_Insere(pPilha->lista,pPilha->tamanho - 1, x);
    pPilha->tamanho = Lista_Tamanho(pPilha->lista);
}

int Pilha_Pop(Pilha *pPilha, Item *pX){
    int aux = Lista_Remove(pPilha->lista, pPilha->tamanho, pX);
    if(aux)
        pPilha->tamanho = Lista_Tamanho(pPilha->lista);
    return aux;

}

int Pilha_Tamanho(Pilha *pPilha){
    return pPilha->tamanho;
}

void pilha_imprime(Pilha* pilha){
    Lista_imprime(pilha->lista);
}

void pilha_libera(Pilha** pilha){
    lista_libera(&(*pilha)->lista);
    free(*pilha);
}


//Expressão que puxa os dois ultimos dados da pilha e resolve a operação de acordo com o operador em questão
int calculadora(char operador, Pilha* pilha){

    int v1, v2;
    Pilha_Pop(pilha, &v1);
    Pilha_Pop(pilha, &v2);

    switch (operador)
    {
    case '+':
        return v1 + v2;
        break;
    case '-':
        return v1 - v2;
        break;
    case '/':
        return v1 / v2;
        break;
    case '*':
        return v1 * v2;
        break;
    default:
        break;
    }
    return 0;

}

