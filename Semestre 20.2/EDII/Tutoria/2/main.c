//Nathann Zini dos Reis 19.2.4007

#include <stdio.h>
#include <stdlib.h>
#define MM 16
#define M 8

typedef long int TipoChave;
typedef struct TipoRegistro {
    TipoChave chave;
    /* outros componentes */
} TipoRegistro;

typedef struct TipoPagina* TipoApontador;
typedef struct TipoPagina {
    short n;
    TipoRegistro r[MM];
    TipoApontador p[MM + 1];
} TipoPagina;


void inicializa (TipoApontador arvore){
    arvore = NULL;
}

int pesquisa(TipoRegistro *x, TipoApontador ap){
    long i = 1;
    if(ap == NULL){
        return 0;
    }
    while(i < ap->n && x->chave > ap->r[i-1].chave)
        i++;
    if(x->chave == ap->r[i-1].chave){
        *x = ap->r[i-1];
        return 1;
    }
    if(x->chave < ap->r[i-1].chave)
        pesquisa(x, ap->p[i-1]);
    else 
        pesquisa(x, ap->p[i]);
    
}

void maximo(TipoRegistro *x, TipoApontador ap){
    
    if (ap == NULL)
    return;

  TipoApontador aux = ap->p[ap->n];
  TipoApontador prev = NULL;

  while (aux != NULL)
  {
    prev = aux;
    aux = aux->p[aux->n];
  }

  *x = prev->r[prev->n - 1];

  return;

}

void InsereNaPagina(TipoApontador Ap, TipoRegistro Reg, TipoApontador ApDir){
  int k;
  int NaoAchouPosicao;

  k = Ap->n;
  NaoAchouPosicao = k > 0;
  while (NaoAchouPosicao)
  {
    if (Reg.chave >= Ap->r[k - 1].chave)
    {
      NaoAchouPosicao = 0;
      break;
    }

    Ap->r[k] = Ap->r[k - 1];

    Ap->p[k + 1] = Ap->p[k];

    k--;
    if (k < 1)
      NaoAchouPosicao = 0;
  }
  Ap->r[k] = Reg;
  Ap->p[k + 1] = ApDir;
  Ap->n++;
}

void Ins(TipoRegistro Reg, TipoApontador Ap, short *Cresceu, TipoRegistro *RegRetorno, TipoApontador *ApRetorno){
  long i = 1;
  long j;
  TipoApontador ApTemp;

  if (Ap == NULL)
  {
    *Cresceu = 1;
    *RegRetorno = Reg;
    *ApRetorno = NULL;
    return;
  }

  while (i < Ap->n && Reg.chave > Ap->r[i - 1].chave)
    i++;

  if (Reg.chave == Ap->r[i - 1].chave)
  {
    printf("Erro: Registro ja esta presente.\n");
    *Cresceu = 0;
    return;
  }

  //Verificação para saber qual dos filhos da página deve ser analisado, esq ou dir.
  if (Reg.chave < Ap->r[i - 1].chave)
    i--;
  Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);

  if (!*Cresceu)
    return;

  if (Ap->n < MM)
  {
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    *Cresceu = 0;
    return;
  }

  /*Overflow - pagina precisa ser dividida*/
  ApTemp = (TipoApontador)malloc(sizeof(TipoPagina));
  ApTemp->n = 0;
  ApTemp->p[0] = NULL;

  if (i < M + 1)
  {
    InsereNaPagina(ApTemp, Ap->r[MM - 1], Ap->p[MM]);
    Ap->n--;
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
  }
  else
    InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);

  for (j = M + 2; j <= MM; j++)
    InsereNaPagina(ApTemp, Ap->r[j - 1], Ap->p[j]);

  Ap->n = M;
  ApTemp->p[0] = Ap->p[M + 1];
  *RegRetorno = Ap->r[M];
  *ApRetorno = ApTemp;
}

void Reconstruir(TipoApontador ApPag, TipoApontador ApPai, int PosPai, short *Diminuiu){
  TipoApontador Aux;
  int DispAux, j;

  if (PosPai < ApPai->n)
  { /* Aux = Pagina a direita de ApPag */
    Aux = ApPai->p[PosPai + 1];
    DispAux = (Aux->n - M + 1) / 2;
    ApPag->r[ApPag->n] = ApPai->r[PosPai];
    ApPag->p[ApPag->n + 1] = Aux->p[0];
    ApPag->n++;
    if (DispAux > 0)
    { /* Existe folga: transfere de Aux para ApPag */
      for (j = 1; j < DispAux; j++)
        InsereNaPagina(ApPag, Aux->r[j - 1], Aux->p[j]);
      ApPai->r[PosPai] = Aux->r[DispAux - 1];
      Aux->n -= DispAux;
      for (j = 0; j < Aux->n; j++)
        Aux->r[j] = Aux->r[j + DispAux];
      for (j = 0; j <= Aux->n; j++)
        Aux->p[j] = Aux->p[j + DispAux];
      *Diminuiu = 0;
    }
    else
    { /* Fusao: intercala Aux em ApPag e libera Aux */
      for (j = 1; j <= M; j++)
        InsereNaPagina(ApPag, Aux->r[j - 1], Aux->p[j]);
      free(Aux);
      for (j = PosPai + 1; j < ApPai->n; j++)
      { /* Preenche vazio em ApPai */
        ApPai->r[j - 1] = ApPai->r[j];
        ApPai->p[j] = ApPai->p[j + 1];
      }
      ApPai->n--;
      if (ApPai->n >= M)
        *Diminuiu = 0;
    }
  }
  else
  { /* Aux = Pagina a esquerda de ApPag */
    Aux = ApPai->p[PosPai - 1];
    DispAux = (Aux->n - M + 1) / 2;
    for (j = ApPag->n; j >= 1; j--)
      ApPag->r[j] = ApPag->r[j - 1];
    ApPag->r[0] = ApPai->r[PosPai - 1];
    for (j = ApPag->n; j >= 0; j--)
      ApPag->p[j + 1] = ApPag->p[j];
    ApPag->n++;
    if (DispAux > 0)
    { /* Existe folga: transfere de Aux para ApPag */
      for (j = 1; j < DispAux; j++)
        InsereNaPagina(ApPag, Aux->r[Aux->n - j], Aux->p[Aux->n - j + 1]);
      ApPag->p[0] = Aux->p[Aux->n - DispAux + 1];
      ApPai->r[PosPai - 1] = Aux->r[Aux->n - DispAux];
      Aux->n -= DispAux;
      *Diminuiu = 0;
    }
    else
    { /* Fusao: intercala ApPag em Aux e libera ApPag */
      for (j = 1; j <= M; j++)
        InsereNaPagina(Aux, ApPag->r[j - 1], ApPag->p[j]);
      free(ApPag);
      ApPai->n--;
      if (ApPai->n >= M)
        *Diminuiu = 0;
    }
  }
}

void Antecessor(TipoApontador Ap, int Ind, TipoApontador ApPai, short *Diminuiu){
  if (ApPai->p[ApPai->n] != NULL)
  {
    Antecessor(Ap, Ind, ApPai->p[ApPai->n], Diminuiu);
    if (*Diminuiu)
      Reconstruir(ApPai->p[ApPai->n], ApPai, (long)ApPai->n, Diminuiu);
    return;
  }

  Ap->r[Ind - 1] = ApPai->r[ApPai->n - 1];
  ApPai->n--;
  *Diminuiu = (ApPai->n < M);
}

void Ret(TipoChave Ch, TipoApontador *Ap, short *Diminuiu){
  long j, Ind = 1;
  TipoApontador Pag;
  if (*Ap == NULL)
  {
    printf("Erro: registro nao esta na arvore\n");
    *Diminuiu = 0;
    return;
  }
  Pag = *Ap;
  while (Ind < Pag->n && Ch > Pag->r[Ind - 1].chave)
    Ind++;

  if (Ch == Pag->r[Ind - 1].chave)
  {
    if (Pag->p[Ind - 1] == NULL) /* TipoPagina eh folha */
    {
      Pag->n--;
      *Diminuiu = (Pag->n < M);
      for (j = Ind; j <= Pag->n; j++)
      {
        Pag->r[j - 1] = Pag->r[j];
        Pag->p[j] = Pag->p[j + 1];
      }
      return;
    }
    /*TipoPagina nao eh folha: trocar com antecessor */
    Antecessor(*Ap, Ind, Pag->p[Ind - 1], Diminuiu);
    if (*Diminuiu)
      Reconstruir(Pag->p[Ind - 1], *Ap, Ind - 1, Diminuiu);
    return;
  }

  if (Ch > Pag->r[Ind - 1].chave)
    Ind++;
  Ret(Ch, &Pag->p[Ind - 1], Diminuiu);
  if (*Diminuiu)
    Reconstruir(Pag->p[Ind - 1], *Ap, Ind - 1, Diminuiu);
}

void Retira(TipoChave Ch, TipoApontador *Ap){
  short Diminuiu;
  TipoApontador Aux;
  Ret(Ch, Ap, &Diminuiu);
  if (Diminuiu && (*Ap)->n == 0)
  {
    Aux = *Ap;
    *Ap = Aux->p[0];
    free(Aux);
  }
}

int main(){
    TipoApontador arvoreB;
    inicializa(arvoreB);

    TipoRegistro item;

    scanf("Item para pesquisar: %ld", &item.chave);

    if(pesquisa(&item, arvoreB))
        printf("Registro encontrado.\n");
    else
        printf("Registro não encontrado na árvore.\n");




    return 0;
}