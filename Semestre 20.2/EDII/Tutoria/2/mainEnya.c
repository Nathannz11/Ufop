#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define True 1;
#define False 0;

#define M 2
#define MM (2 * M)

typedef long TipoChave;

typedef struct TipoRegistro
{
  TipoChave Chave;
  /* outros componentes */
} TipoRegistro;

typedef struct TipoPagina *TipoApontador;

typedef struct TipoPagina
{
  short n;
  TipoRegistro r[MM];      //Chaves
  TipoApontador p[MM + 1]; //Filhos
} TipoPagina;

void Inicializa(TipoApontador *Arv);

void Imprime(TipoApontador Arv);

int Pesquisa(TipoRegistro *x, TipoApontador Ap);

int Maximo(TipoRegistro *x, TipoApontador Ap);

void Insere(TipoRegistro Reg, TipoApontador *Ap);

void Ins(TipoRegistro Reg, TipoApontador Ap, short *Cresceu, TipoRegistro *RegRetorno, TipoApontador *ApRetorno);

void InsereNaPagina(TipoApontador Ap, TipoRegistro Reg, TipoApontador ApDir);

void Reconstruir(TipoApontador ApPag, TipoApontador ApPai, int PosPai, short *Diminuiu);

void Antecessor(TipoApontador Ap, int Ind, TipoApontador ApPai, short *Diminuiu);

void Ret(TipoChave Ch, TipoApontador *Ap, short *Diminuiu);

void Retira(TipoChave Ch, TipoApontador *Ap);

int main()
{
  TipoApontador arv = NULL;
  int op = -1;
  TipoRegistro novoReg;

  Inicializa(&arv);

  printf("1 - Adicionar novo registro\n");
  printf("2 - Pesquisar por registro\n");
  printf("3 - Imprimir arvore\n");
  printf("4 - Encontrar a maior chave de um registro\n");
  printf("5 - Remover registro\n");
  printf("0 - Encerrar programa\n");

  while (op != 0)
  {
    scanf("%d", &op);
    if (op == 1)
    {
      scanf("%ld", &novoReg.Chave);
      Insere(novoReg, &arv);
    }
    else if (op == 2)
    {
      scanf("%ld", &novoReg.Chave);
      if (Pesquisa(&novoReg, arv))
      {
        printf("Registro [%ld] encontrado\n", novoReg.Chave);
      }
      else
      {
        printf("Registro [%ld] não foi encontrado\n", novoReg.Chave);
      }
    }
    else if (op == 3)
    {
      Imprime(arv);
      printf("\n");
    }
    else if (op == 4)
    {
      if (Maximo(&novoReg, arv))
        printf("A maior chave é a chave %ld\n", novoReg.Chave);
      else
        printf("Arvore vazia\n");
    }
    else if (op == 5)
    {
      scanf("%ld", &novoReg.Chave);
      Retira(novoReg.Chave, &arv);
    }
    else
    {
      op = 0;
    }
  }

  return 0;
}

void Inicializa(TipoApontador *Arv)
{
  *Arv = NULL;
}

void Imprime(TipoApontador Arv)
{
  int i = 0;
  if (Arv == NULL)
    return;

  while (i <= Arv->n)
  {
    Imprime(Arv->p[i]);

    if (i != Arv->n)
      printf("%ld ", Arv->r[i].Chave);
    i++;
  }
}

int Pesquisa(TipoRegistro *x, TipoApontador Ap)
{
  long i = 1;
  if (Ap == NULL)
  {
    printf("TipoRegistro nao esta presente na arvore\n");
    return 0;
  }

  while (i < Ap->n && x->Chave > Ap->r[i - 1].Chave)
    i++;

  if (x->Chave == Ap->r[i - 1].Chave)
  {
    *x = Ap->r[i - 1];
    return 1;
  }

  if (x->Chave < Ap->r[i - 1].Chave)
    return Pesquisa(x, Ap->p[i - 1]);
  else
    return Pesquisa(x, Ap->p[i]);
}

int Maximo(TipoRegistro *x, TipoApontador Ap)
{
  if (Ap == NULL)
    return False;

  TipoApontador aux = Ap->p[Ap->n];
  TipoApontador prev = NULL;

  while (aux != NULL)
  {
    prev = aux;
    aux = aux->p[aux->n];
  }

  *x = prev->r[prev->n - 1];

  return True;
}

void Insere(TipoRegistro Reg, TipoApontador *Ap)
{
  short Cresceu;
  TipoRegistro RegRetorno;
  TipoPagina *ApRetorno, *ApTemp;
  Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);
  if (Cresceu)
  {
    ApTemp = (TipoPagina *)malloc(sizeof(TipoPagina));
    ApTemp->n = 1;
    ApTemp->r[0] = RegRetorno;
    ApTemp->p[1] = ApRetorno;
    ApTemp->p[0] = *Ap;
    *Ap = ApTemp;
  }
}

void InsereNaPagina(TipoApontador Ap, TipoRegistro Reg, TipoApontador ApDir)
{
  int k;
  int NaoAchouPosicao;

  k = Ap->n;
  NaoAchouPosicao = k > 0;
  while (NaoAchouPosicao)
  {
    if (Reg.Chave >= Ap->r[k - 1].Chave)
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

/*
  Reg -> Item a ser registrado
  Ap -> 
  *Cresceu -> Ponteiro para atualizar se a árvore cresceu
  *RegRetorno -> Ponteiro para a arvore atual
  *ApRetorno ->
*/
void Ins(TipoRegistro Reg, TipoApontador Ap, short *Cresceu, TipoRegistro *RegRetorno, TipoApontador *ApRetorno)
{
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

  while (i < Ap->n && Reg.Chave > Ap->r[i - 1].Chave)
    i++;

  if (Reg.Chave == Ap->r[i - 1].Chave)
  {
    printf("Erro: Registro ja esta presente.\n");
    *Cresceu = False;
    return;
  }

  //Verificação para saber qual dos filhos da página deve ser analisado, esq ou dir.
  if (Reg.Chave < Ap->r[i - 1].Chave)
    i--;
  Ins(Reg, Ap->p[i], Cresceu, RegRetorno, ApRetorno);

  if (!*Cresceu)
    return;

  if (Ap->n < MM)
  {
    InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
    *Cresceu = False;
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

void Retira(TipoChave Ch, TipoApontador *Ap)
{
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

void Ret(TipoChave Ch, TipoApontador *Ap, short *Diminuiu)
{
  long j, Ind = 1;
  TipoApontador Pag;
  if (*Ap == NULL)
  {
    printf("Erro: registro nao esta na arvore\n");
    *Diminuiu = False;
    return;
  }
  Pag = *Ap;
  while (Ind < Pag->n && Ch > Pag->r[Ind - 1].Chave)
    Ind++;

  if (Ch == Pag->r[Ind - 1].Chave)
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

  if (Ch > Pag->r[Ind - 1].Chave)
    Ind++;
  Ret(Ch, &Pag->p[Ind - 1], Diminuiu);
  if (*Diminuiu)
    Reconstruir(Pag->p[Ind - 1], *Ap, Ind - 1, Diminuiu);
}

void Reconstruir(TipoApontador ApPag, TipoApontador ApPai, int PosPai, short *Diminuiu)
{
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

void Antecessor(TipoApontador Ap, int Ind, TipoApontador ApPai, short *Diminuiu)
{
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
