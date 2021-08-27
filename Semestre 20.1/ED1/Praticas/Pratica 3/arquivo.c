#include "arquivo.h"

struct arquivo{
    char nome[20];
    float tamanho;
    char extensao[5];
};

char* getNomeA(Arquivo* arquivo){
    return arquivo->nome;
}

void setNomeA(Arquivo* arquivo, char* nome){
    strcpy(arquivo->nome, nome);
}

float GetTamanho(Arquivo* arquivo){
    return arquivo->tamanho;
}

void setTamanho(Arquivo* arquivo, float tamanho){
    arquivo->tamanho = tamanho;
}

char* getExtensao(Arquivo* arquivo){
    return arquivo->extensao;
}

void setExtensao(Arquivo* arquivo, char* extensao){
    strcpy(arquivo->extensao, extensao);
}

Arquivo** alocarArrayArquivo(int n){
    Arquivo** aux = malloc(n * sizeof(Arquivo));
    return aux;
}

Arquivo* alocarArquivo(char* nomeArq, char* extensao, float tamanho){
    Arquivo* aux = malloc(sizeof(Arquivo));
    strcpy(aux->nome, nomeArq);
    strcpy(aux->extensao, extensao);
    aux->tamanho = tamanho;
    return aux;
}

void liberarArquivo(Arquivo*** arquivo){
    free(**arquivo);
    **arquivo = NULL;
}