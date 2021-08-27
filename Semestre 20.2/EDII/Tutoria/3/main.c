//Nathann Zini dos Reis 19.2.4007

#include <stdio.h>
#include <stdlib.h>

#define M 2
#define MM 4 
#define MM2 8 
typedef long TipoChave;
typedef struct TipoRegistro{
    TipoChave Chave;
/* outros componentes */
} TipoRegistro;

typedef enum {Interna, Externa} TipoIntExt;
typedef struct TipoPagina* TipoApontador;

typedef struct TipoPagina {
    TipoIntExt Pt;
    union {
        struct {
            int ni;
            TipoChave ri[MM];
            TipoApontador pi[MM + 1];
        } U0;
        struct {
            int ne;
            TipoRegistro re[MM2];
        } U1;
    } UU;
} TipoPagina;

void inicializa (TipoApontador arvore);
int pesquisa(TipoRegistro *x, TipoApontador *ap);
void maximo(TipoRegistro *x, TipoApontador ap);
void Insere(TipoRegistro Reg, TipoApontador *Ap);
void InsereNaPagina(TipoApontador Ap, TipoRegistro Reg, TipoApontador ApDir);
void Ins(TipoRegistro Reg, TipoApontador Ap, short *Cresceu, TipoRegistro *RegRetorno, TipoApontador *ApRetorno);
void Reconstruir(TipoApontador ApPag, TipoApontador ApPai, int PosPai, short *Diminuiu);
void Antecessor(TipoApontador Ap, int Ind, TipoApontador ApPai, short *Diminuiu);
void Ret(TipoChave Ch, TipoApontador *Ap, short *Diminuiu);
void Retira(TipoChave Ch, TipoApontador *Ap);

int main(){
    TipoApontador arvoreB;
    inicializa(arvoreB);

    TipoRegistro item;

    int escolha = 1;

    while(escolha){
        printf("Inserir: ");
        scanf("%ld", &item.Chave);
        Insere(item, &arvoreB);

        printf("continuar? 1 - sim | 2 - não \n");
        scanf("%d", &escolha);
    }

    escolha = 1;
    while(escolha){
        printf("Item para pesquisar: ");
        scanf("%ld", &item.Chave);

        if(pesquisa(&item, &arvoreB))
            printf("Registro encontrado.\n");
        else
            printf("Registro não encontrado na árvore.\n");


        printf("continuar? 1 - sim | 2 - não \n ");
        scanf("%d", &escolha);
    }


    return 0;
}



void inicializa (TipoApontador arvore){
    arvore = NULL;
}

int pesquisa(TipoRegistro *x, TipoApontador *Ap){
    long i;
    TipoApontador pag;
    pag = *Ap;
    if((*Ap)->Pt == Interna){
        i = 1;
        while(i < pag->UU.U0.ni && x->Chave > pag->UU.U0.ri[i - 1])
            i++;
        if(x->Chave < pag->UU.U0.ri[i - 1])
            pesquisa(x, &pag->UU.U0.pi[i - 1]);
        else
            pesquisa(x, &pag->UU.U0.pi[i]);
        return 0;
    
    }
    i = 1;
    while(i < pag->UU.U1.ne && x->Chave > pag->UU.U1.re[i-1].Chave)
        i++;
    if(x->Chave == pag->UU.U1.re[i-1].Chave){
        *x = pag->UU.U1.re[i-1];
        return 1;
    }
    
}

void maximo(TipoRegistro *x, TipoApontador ap){
    
    if (ap == NULL)
    return;

    while(ap->Pt == Interna){
        ap = ap->UU.U0.pi[ap->UU.U0.ni];
    }
    *x = ap->UU.U1.re[ap->UU.U1.ne - 1];

  return;

}

void Insere(TipoRegistro Reg, TipoApontador *Ap){
  short Cresceu;
  TipoRegistro RegRetorno;
  TipoPagina *ApRetorno, *ApTemp;
  Ins(Reg, *Ap, &Cresceu, &RegRetorno, &ApRetorno);

  if (Cresceu){
    ApTemp = (TipoPagina *)malloc(sizeof(TipoPagina));
    if(*Ap == NULL){
        ApTemp->Pt = Externa;
        ApTemp->UU.U1.ne = 1;
        ApTemp->UU.U1.re[0] = RegRetorno;        
        *Ap = ApTemp;
    }else{
        ApTemp->Pt = Interna;
        ApTemp->UU.U0.ni = 1;
        ApTemp->UU.U0.ri[0] = RegRetorno.Chave;
        ApTemp->UU.U0.pi[1] = ApRetorno;
        ApTemp->UU.U0.pi[0] = *Ap;
        *Ap = ApTemp;
    }
  }
}

void InsereNaPagina(TipoApontador Ap, TipoRegistro Reg, TipoApontador ApDir){
  int k;
  int NaoAchouPosicao;

  if(Ap->Pt = Externa){
    k = Ap->UU.U1.ne;
    NaoAchouPosicao = k > 0;
    while (NaoAchouPosicao){
        if (Reg.Chave >= Ap->UU.U1.re[k - 1].Chave){
            NaoAchouPosicao = 0;
            break;
        }

        Ap->UU.U1.re[k] = Ap->UU.U1.re[k - 1];

        k--;
        if (k < 1)
            NaoAchouPosicao = 0;
    }
    Ap->UU.U1.re[k] = Reg;
    Ap->UU.U1.ne++;
    
  }else{
    k = Ap->UU.U0.ni;
    NaoAchouPosicao = k > 0;
    while (NaoAchouPosicao){
        if (Reg.Chave >= Ap->UU.U0.ri[k - 1]){
            NaoAchouPosicao = 0;
            break;
        }

        Ap->UU.U0.ri[k] = Ap->UU.U0.ri[k - 1];

        Ap->UU.U0.pi[k + 1] = Ap->UU.U0.pi[k];

        k--;
        if (k < 1)
            NaoAchouPosicao = 0;
    }
    Ap->UU.U0.ri[k] = Reg.Chave;
    Ap->UU.U0.pi[k + 1] = ApDir;
    Ap->UU.U0.ni++;
    } 
}

void Ins(TipoRegistro Reg, TipoApontador Ap, short *Cresceu, TipoRegistro *RegRetorno, TipoApontador *ApRetorno){
    long i = 1;
    long j;
    TipoApontador ApTemp;

    if (Ap == NULL){
        *Cresceu = 1;
        *RegRetorno = Reg;
        *ApRetorno = NULL;
        return;
    }
    if(Ap->Pt == Interna){
        while (i < Ap->UU.U0.ni && Reg.Chave > Ap->UU.U0.ri[i - 1])
            i++;

        if (Reg.Chave == Ap->UU.U0.ri[i - 1]){
            printf("Erro: Registro ja esta presente.\n");
            *Cresceu = 0;
            return;
        }

        //Verificação para saber qual dos filhos da página deve ser analisado, esq ou dir.
        if (Reg.Chave < Ap->UU.U0.ri[i - 1])
            i--;
        Ins(Reg, Ap->UU.U0.pi[i], Cresceu, RegRetorno, ApRetorno);
    
        if (!*Cresceu)
            return;

        if (Ap->UU.U0.ni < MM){
            InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
            *Cresceu = 0;
            return;
        }

        /*Overflow - pagina precisa ser dividida*/
        ApTemp = (TipoApontador)malloc(sizeof(TipoPagina));
        ApTemp = Interna;
        ApTemp->UU.U0.ni = 0;
        ApTemp->UU.U0.pi[0] = NULL;

        TipoRegistro regTemp;
        if (i < M + 1){
            regTemp.Chave = Ap->UU.U0.ri[MM - 1];
            InsereNaPagina(ApTemp, regTemp, Ap->UU.U0.pi[MM]);
            Ap->UU.U0.ni--;
            InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
        }
        else
            InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);

        for (j = M + 1; j <= MM; j++){
            regTemp.Chave= Ap->UU.U0.ri[j - 1];
            InsereNaPagina(ApTemp, regTemp, Ap->UU.U0.pi[j]);
        }

        Ap->UU.U0.ni = M;
        ApTemp->UU.U0.pi[0] = Ap->UU.U0.pi[M + 1];
        regTemp.Chave = Ap->UU.U0.ri[M];
        *RegRetorno = regTemp;
        *ApRetorno = ApTemp;
    }else{
        while (i < Ap->UU.U1.ne && Reg.Chave > Ap->UU.U1.re[i - 1].Chave)
            i++;

        if (Reg.Chave == Ap->UU.U1.re[i - 1].Chave){
            printf("Erro: Registro ja esta presente.\n");
            *Cresceu = 0;
            return;
        }

        //Verificação para saber qual dos filhos da página deve ser analisado, esq ou dir.
        if (Reg.Chave < Ap->UU.U1.re[i - 1].Chave)
            i--;
        Ins(Reg, NULL, Cresceu, RegRetorno, ApRetorno);
    
        if (!*Cresceu)
            return;

        if (Ap->UU.U1.ne < MM){
            InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
            *Cresceu = 0;
            return;
        }

        /*Overflow - pagina precisa ser dividida*/
        ApTemp = (TipoApontador)malloc(sizeof(TipoPagina));
        ApTemp->Pt = Interna;
        ApTemp->UU.U1.ne = 0;

        if (i < M + 1){
            InsereNaPagina(ApTemp, (*Ap).UU.U1.re[MM - 1], NULL);
            Ap->UU.U1.ne--;
            InsereNaPagina(Ap, *RegRetorno, *ApRetorno);
        }
        else
            InsereNaPagina(ApTemp, *RegRetorno, *ApRetorno);

        for (j = M + 1; j <= MM; j++)
            InsereNaPagina(ApTemp, (*Ap).UU.U1.re[j - 1], NULL);

        Ap->UU.U1.ne = M;
        *RegRetorno = Ap->UU.U1.re[M];
        *ApRetorno = ApTemp;
    }

    
}
