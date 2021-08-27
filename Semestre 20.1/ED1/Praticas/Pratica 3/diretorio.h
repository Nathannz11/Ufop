#ifndef diretorio_h
#define diretorio_h

#include "arquivo.h"

typedef struct diretorio Diretorio;

char* getNomeD(Diretorio* diretorio);

void setNomeD(Diretorio* diretorio, char* nome);

char* getNomeAdir(Diretorio* diretorio, int n);

void setNomeAdir(Diretorio* diretorio, char* nome, int n);

float GetTamanho_total(Diretorio* diretorio);

void setTamanho_total(Diretorio* diretorio, float tamanho_total);

int getQtd_arquivo(Diretorio* diretorio);

void setQtd_aqruivo(Diretorio* diretorio, int qtd_arquivo);

Arquivo** getArquivo(Diretorio* diretorio, int n);

void setArquivo(Diretorio* diretorio, int n);

int getQtd_max_arquivo(Diretorio* diretorio);

void setQtd_max_arquivo(Diretorio* diretorio, int qtd_max_arquivo);

Diretorio* alocarDiretorio(char* nome, int qtd_max_arquivo);

void alocarArquivoDir(Diretorio* diretorio, char* nomeArq, char* extensao, float tamanho);

void liberarDiretorio(Diretorio** diretorio);

#endif 