#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int* vetor;
    int comparacoes;
    int movimentacoes;
    int tam;
}Vetores;

void alocarVetores(Vetores** vetores, int n);
void desalocarVetores(Vetores** vetores, int n);
void lerDadosVetor(Vetores* vetores, int n);
void imprimirDados(Vetores* vetores);

//HeapSort
void heapRefaz(Vetores* vetores, int esq, int dir);
void heapConstroi(Vetores* vetores, int n);
void heapSort(Vetores* vetores, int n);