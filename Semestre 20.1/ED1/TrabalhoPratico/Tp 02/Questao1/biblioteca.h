//Nathann Zini dos Reis 19.2.4007
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define k 20

typedef struct{
    int qtdVetor;
    int tamVetor;
    int *comparacoes;
    int *movimentacoes;
    int **vetor;
}Vetores;


void iniciarVetores(FILE* arq, Vetores *vetores);

void desalocarVetores(Vetores *vetores);

void quickSort(int* vetor, int l, int r, int *movimentacoes, int *comparacoes);

int partitionAleatorio(int* vetor, int l, int r, int *movimentacoes, int *comparacoes);

int partitionMediana(int* vetor, int l, int r, int *movimentacoes, int *comparacoes);

void insertionSort(int* vetor, int l, int r, int *movimentacoes, int *comparacoes);

void imprimirVetores(Vetores *vetores);