//Nathann Zini dos Reis 19.2.4007
#include "arvore.h"
#include "pilha.h"

//insere um item na árvore, sempre da esquerda pra direita
int TArvore_Insere(TNo** ppR, TItem x){
    
    if (*ppR == NULL) {
        *ppR = TNo_Cria(x);
        return 1;
    }
    
    if ((*ppR)->pEsq == NULL){
        return TArvore_Insere(&((*ppR)->pEsq), x);
    }
        
    else{
        return TArvore_Insere(&((*ppR)->pDir), x);
    }
        
    
} 

//cria um nó para a árvore
TNo *TNo_Cria(TItem x){
    TNo *pAux = (TNo*)malloc(sizeof(TNo));
    pAux->item = x;
    pAux->pEsq = NULL;
    pAux->pDir = NULL;
    return pAux;
}

void TArvore_Inicia(TNo **pRaiz) {
    
    *pRaiz = NULL;
}

//vai achar qual o último operador que será feito e retornar a posição dele para dividir a expressão em duas
//uma metade vai para o filho da esquerda, a outra pro filho da direita e o operador fica sendo o pai deles;
int acharRaiz(char* expressao, int l, int r){
  int temp = l;
  for(int i = l; i < r; i++){
      if (expressao[i] == '+' || expressao[i] == '-'){
          temp = i;
          /* code */
      }
  }
  if(temp == l){
    for(int i = l; i < r; i++){
      if (expressao[i] == '*' || expressao[i] == '/'){
        temp = i;
        /* code */
      }
    }
  }
  return temp;
}
//recebe o vetor com a expressao e o inicio e o final do range a ser avaliado e monta, a partir dai a arvore;
//sempre vai dividindo a expressão ao meio até restar apenas um valor que vai sendo as folhas e os operadores sempre os nós internos;
void montarArvore(char* expressao, int l, int r, TNo** pRaiz){
  if(l < r){
    int root = acharRaiz(expressao, l, r);
    //insere o nó interno
    TArvore_Insere(pRaiz, expressao[root]);
    //passa a metade esquerda da expressao
    montarArvore(expressao, l, root - 1 , pRaiz);
    //passa a metade direita da expressao
    montarArvore(expressao, root +1, r , pRaiz);
  }else if( l == r){
    //insere a folha
    int temp = TArvore_Insere(pRaiz, expressao[l]);
  }
        
}

//percorre a arvore em Pre Ordem e salva na pilha o item do nó (é a ordem que eu preciso para o meu código em especifico)
void arvoreEncaminhamentoPreOrdem(TNo* raiz, Pilha* pilha)
{
  if (raiz != NULL)
  {
    Pilha_Push(pilha, raiz->item);

    arvoreEncaminhamentoPreOrdem(raiz->pEsq, pilha);
    arvoreEncaminhamentoPreOrdem(raiz->pDir, pilha);
  }
}

//imprime a árvore em pré ordem
void arvorePreOrdem(TNo* raiz)
{
  if (raiz != NULL)
  {
    printf("%c ", raiz->item);
    arvorePreOrdem(raiz->pEsq);
    arvorePreOrdem(raiz->pDir);
  }
}

//imprime a árvore em pós ordem
void arvorePosOrdem(TNo* raiz)
{
  if (raiz != NULL)
  {
    arvorePosOrdem(raiz->pEsq);
    arvorePosOrdem(raiz->pDir);
    printf("%c ", raiz->item);   

  }
}

//imprime a árvore em ordem central
void arvoreOrdemCentral(TNo* raiz)
{
  if (raiz != NULL)
  {
    arvoreOrdemCentral(raiz->pEsq);
    printf("%c ", raiz->item);
    arvoreOrdemCentral(raiz->pDir);
  }
}

//libera a árvore no sentido das folhas para as raízes;
void liberarArvore(TNo **pRaiz){
    if (*pRaiz != NULL)
  {
    
    liberarArvore(&(*pRaiz)->pEsq);
    liberarArvore(&(*pRaiz)->pDir);
    free(*pRaiz);
    

  }
}
