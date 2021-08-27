//Nathann Zini dos Reis 19.2.4007
#include "pilha.h"

typedef char TItem;



typedef struct No{
    TItem item;
    struct No *pEsq, *pDir;
}TNo;


int TArvore_Insere(TNo** ppR, TItem x);

int ehNulo(TNo *ppR);

TNo *TNo_Cria(TItem x);

void TArvore_Inicia(TNo **pRaiz);

int acharRaiz(char* expressao, int l, int r);

void montarArvore(char* expressao, int l, int r, TNo** pRaiz);

void arvoreEncaminhamentoPreOrdem(TNo* raiz, Pilha* pilha);

void arvorePreOrdem(TNo *raiz);

void arvoreOrdemCentral(TNo *raiz);

void arvorePosOrdem(TNo *raiz);

void liberarArvore(TNo **pRaiz);
