#ifndef arquivo_h
#define arquivo_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arquivo Arquivo;

char* getNomeA(Arquivo* arquivo);

void setNomeA(Arquivo* arquivo, char* nome);

float GetTamanho(Arquivo* arquivo);

void setTamanho(Arquivo* arquivo, float tamanho);

char* getExtensao(Arquivo* arquivo);

void setExtensao(Arquivo* arquivo, char* extensao);

Arquivo** alocarArrayArquivo(int n);

Arquivo* alocarArquivo(char* nomeArq, char* extensao, float tamanho);

void liberarArquivo(Arquivo*** arquivo);


#endif