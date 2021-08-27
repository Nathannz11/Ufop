#include "ordExterna.h"

int main (){

    FILE** arqLEs;
    FILE** arqLi;
    FILE** arqEi;

    TipoItem r;

    arqLi = fopen("teste.dat", "wb");
    if(arqLi == NULL){
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    r.chave = 5; fwrite(&r, sizeof(TipoRegistro), 1, arqLi);
    r.chave = 3; fwrite(&r, sizeof(TipoRegistro), 1, arqLi);
    r.chave = 10; fwrite(&r, sizeof(TipoRegistro), 1, arqLi);
    r.chave = 6; fwrite(&r, sizeof(TipoRegistro), 1, arqLi);
    r.chave = 1; fwrite(&r, sizeof(TipoRegistro), 1, arqLi);
    r.chave = 7; fwrite(&r, sizeof(TipoRegistro), 1, arqLi);
    r.chave = 4; fwrite(&r, sizeof(TipoRegistro), 1, arqLi);
    fclose(arqLi);

    arqLi = fopen("teste.dat", "r+b");
    if(arqLi == NULL){
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    arqEi = fopen("teste.dat", "r+b");
    if(arqEi == NULL){
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }
    arqLEs = fopen("teste.dat", "r+b");
    if(arqLEs == NULL){
        printf("Arquivo não pode ser aberto\n");
        exit(1);
    }

    quicksortExterno(&arqLi, &arqEi, &arqLEs, 1, 7);
    fflush(arqLi);
    
    fclose(arqEi);
    fclose(arqLEs);
    fclose(arqEi);

    while(fread(&r, sizeof(TipoRegistro), 1, arqLi)){
        printf("Registro = %d\n", r.chave);
    }
    fclose(arqLi);
    return 0;



    return 0;
}

void converterArquivo(){
    TipoDado dado;
    FILE *in = fopen("PROVAO.TXT", "r");
    FILE *out = fopen("PROVAO.DAT", "w+b");
    while (fscanf(in, "%ld %lf %2[A-Z a-z] %49[A-Z a-z  Ã ã Õ õ Ç ç ' -] %29[A-Z a-z Ã ã Õ õ Ç ç ' -]", &dado.inscricao, &dado.nota, dado.estado, dado.cidade, dado.curso) != EOF){
        fwrite(&dado, sizeof(TipoDado), 1, out);
    }
}

void quicksortExterno(FILE **arqLi, FILE **arqEi, FILE **arqLEs, int esq, int dir){
    int i, j;
    TipoArea area;
    if(dir - esq < 1)
        return;
    faVazia(&area);
    particao(arqLi, arqEi, arqLEs, area, esq, dir, &i, &j);
    if(i - esq < dir - j){
        quicksortExterno(arqLi, arqEi, arqLEs, esq, i);
        quicksortExterno(arqLi, arqEi, arqLEs, j, dir);
    }
    else{
        quicksortExterno(arqLi, arqEi, arqLEs, j, dir);
        quicksortExterno(arqLi, arqEi, arqLEs, esq, i);
    }
}

void leSup(FILE **arqLEs, TipoRegistro *ultLido, int *ls, short *ondeLer){
    fseek(*arqLEs, (*ls -1) * sizeof(TipoRegistro), SEEK_SET);
    fread(ultLido, sizeof(TipoRegistro), 1, *arqLEs);
    (*ls)--;
    *ondeLer = FALSE;
}

void leInf(FILE **arqLi, TipoRegistro *ultLido, int *li, short *ondeLer){
    fread(ultLido, sizeof(TipoRegistro), 1, *arqLi);
    (*Li)++;
    *ondeLer = TRUE;
}

void inserirArea(TipoArea *area, TipoRegistro *ultLido, int *nrArea){
    insereItem(*ultLido, area);
    *nrArea = obterNumCelOcupadas(area);
}

void escreverMax(FILE **arqLEs, TipoRegistro r, int *es){
    fseek(*arqLEs, (*es - 1) * sizeof(TipoRegistro), SEEK_SET);
    fwrite(&r, sizeof(TipoRegistro), 1, *arqLEs);
    (*es)--;
}

void escreverMin(FILE **arqEi, TipoRegistro r, int *ei){
    fwrite(&r, sizeof(TipoRegistro), 1, *arqEi0;
    (*ei)++;
}

void retiraMax(TipoArea *area, TipoRegistro *r, int *nrArea){
    retiraUltimo(Area, r);
    *nrArea = obterNumCelOcupadas(area);
}

void retiraMin(TipoArea *area, TipoRegistro *r, int *nrArea){
    retiraPrimeiro(Area, r);
    *nrArea = obterNumCelOcupadas(area);
}

void particao(FILE **arqLi, FILE **arqEi, FILE **arqLEs, TipoArea area, int esq, int dir, int *i, int *j){
    int ls = dir, es = dir, li = esq, ei = esq, nrArea = 0, lInf = INT_MIN, lSup = INT_MAX;
    short ondeLer = TRUE;
    TipoRegistro ultLido, r;
    fseek(*arqLi, (li-1) * sizeof(TipoRegistro), SEEK_SET);
    fseek(*arqEi, (ei-1) * sizeof(TipoRegistro), SEEK_SET);
    *i = esq - 1;
    *j = dir + 1;
    while(ls >= li){
        if(nrArea < N - 1){
            if(ondeLer)
                leSup(arqLEs, &ultLido, &li, &ondeLer);
            else
                leInf(arqLi, &ultLido, &li, &ondeLer);
            inserirArea(&area, &ultLido, &nrArea);
            continue;
        }
        if(ls == es)
            leSup(arqLEs, &ultLido, &ls, &ondeLer);
        else if(li == ei)
            leInf(arqLi, &ultLido, &li, *ondeLer);
        else if(ondeLer)
            leSup(arqLEs, &ultLido, &ls, &ondeLer);
        else
            leInf(arqLi, &ultLido, &li, &ondeLer);
        if(ultLido.chave > lSup){
            *j = es;
            escreverMax(arqLEs, ultLido, &es);
            continue;
        }
        if(ultLido.chave < lInf){
            *i = ei;
            escreverMin(arqEi, ultLido, &ei);
            continue;
        }
        inserirArea(&area, &ultLido, &nrArea);
        if(ei - esq < dir - es){
            retiraMin(arqEi, r, &nrArea);
            escreverMin(arqEi, r, &ei);
            lInf = r.chave;
        }else{
            retiraMax(&area, &r, &nrArea);
            escreverMax(arqLEs, r, &es);
            lSup = r.chave;
        }
    }
    while(ei >= es){
        retiraMin(&area, &r, &nrArea);
        escreverMin(arqEi, r, &ei);
    }
}

void faVazia(TipoArea *area){
    for(int i = 0; i < TAMAREA; i++)
        area->vetorPivo[i] = NULL;
}

int obterNumCelOcupadas(TipoArea *area){
    int cont = 0;
    for(int i = 0; i < TAMAREA; i++)
        if((area->vetorPivo[i] != NULL)
            cont++
    return cont;
}

void retiraUltimo(TipoArea *area, TipoRegistro *r){
    *r = area->vetorPivo[N-1];
    area->vetorPivo[N-1] = NULL;

}

void retiraPrimeiro(TipoArea *area, TipoRegistro *r){
    *r = area->vetorPivo[0];
    area->vetorPivo[0] = NULL
}

void inserirArea(TipoArea *area, TipoRegistro *ultLido, int *nmArea){
    for(int i = 0; i < N; i++){
        if(area->vetorPivo[i] != NULL){
            area->vetorPivo[i] = *ultLido;
            *(nmArea)++;
            break;
        }
    }
}

