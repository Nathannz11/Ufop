#include "diretorio.h"
#include "arquivo.h"

struct diretorio{
    char nome[20];
    float tamanho_total;
    int qtd_arquivo;
    Arquivo** arquivo;
    int qtd_max_arquivo;
};

char* getNomeD(Diretorio* diretorio){
    return diretorio->nome;
}

void setNomeD(Diretorio* diretorio, char* nome){
    strcpy(diretorio->nome, nome);
}

char* getNomeAdir(Diretorio* diretorio, int n){
    return getNomeA(diretorio->arquivo[n]);
}

void setNomeAdir(Diretorio* diretorio, char* nome, int n){
    setNomeA(diretorio->arquivo[n], nome);
}

float GetTamanho_total(Diretorio* diretorio){
    return diretorio->tamanho_total;
}

void setTamanho_total(Diretorio* diretorio, float tamanho_total){
    diretorio->tamanho_total = tamanho_total;
}

int getQtd_arquivo(Diretorio* diretorio){
    return diretorio->qtd_arquivo;
}

void setQtd_aqruivo(Diretorio* diretorio, int qtd_arquivo){
    diretorio->qtd_arquivo += qtd_arquivo;
}

Arquivo** getArquivo(Diretorio* diretorio, int n){
    return &diretorio->arquivo[n];
}

void setArquivo(Diretorio* diretorio, int n){
    diretorio->arquivo[n] = diretorio->arquivo[getQtd_arquivo(diretorio) - 1];
    diretorio->arquivo[getQtd_arquivo(diretorio) - 1] = NULL; 
}

int getQtd_max_arquivo(Diretorio* diretorio){
    return diretorio->qtd_max_arquivo;
}

void setQtd_max_arquivo(Diretorio* diretorio, int qtd_max_arquivo){
    diretorio->qtd_max_arquivo = qtd_max_arquivo;
}

Diretorio* alocarDiretorio(char* nome, int qtd_max_arquivo){
    Diretorio* aux = malloc (1 * sizeof(Diretorio));
    strcpy(aux->nome, nome);
    aux->tamanho_total = 0;
    aux->qtd_arquivo = 0;
    aux->arquivo = alocarArrayArquivo(qtd_max_arquivo);
    aux->qtd_max_arquivo = qtd_max_arquivo;
    return aux;
}

void alocarArquivoDir(Diretorio* diretorio, char* nomeArq, char* extensao, float tamanho){
    for(int i = 0; i < diretorio->qtd_max_arquivo; i++){
        if(diretorio->arquivo[i] == NULL){
            diretorio->arquivo[i] = alocarArquivo(nomeArq, extensao, tamanho);
            break;
        }
            
    }
    
}

void liberarDiretorio(Diretorio** diretorio){
    liberarArquivo(&(**diretorio).arquivo);
    free(*diretorio);
    *diretorio = NULL;
}