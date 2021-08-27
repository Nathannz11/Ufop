#include "biblioteca.h"

void alocarVetores(Vetores** vetores, int n){
    *vetores = malloc(n * sizeof(Vetores));

    
}

void desalocarVetores(Vetores** vetores, int n){
    for( int i = 0; i < n; i ++){
        free((*vetores)[i].vetor);
    } 
    free(*vetores);
}

void lerDadosVetor(Vetores* vetores, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &vetores[i].tam);
        vetores[i].vetor = malloc (vetores[i].tam * sizeof(int));
        for(int j = 0; j < vetores[i].tam; j++){
            scanf("%d", &vetores[i].vetor[j]);
        }
        vetores[i].comparacoes = 0;
        vetores[i].movimentacoes = 0;   
        
    }
    
}

void imprimirDados(Vetores* vetores){
    for(int i = 0; i < vetores->tam; i++){
        printf("%d ", vetores->vetor[i]);
    }
    printf(" | %d \t\t| %d\n", vetores->comparacoes, vetores->movimentacoes);
}

//HeapSort

void heapRefaz(Vetores* vetores, int esq, int dir) {
    int i = esq;
    int j = i*2 + 1; // j = primeiro filho de i

    int aux = vetores->vetor[i]; // aux = no i (pai de j)

    while (j <= dir) {
        vetores->comparacoes++;
        if (j < dir && vetores->vetor[j] < vetores->vetor[j+1])
            j++; // j recebe o outro filho de i
        vetores->comparacoes++;
        if (aux >= vetores->vetor[j])
            break; // heap foi refeito corretamente
        vetores->movimentacoes++;
        vetores->vetor[i] = vetores->vetor[j];
        i = j;
        j = i*2 + 1; // j = primeiro filho de i
    }
    vetores->vetor[i] = aux;
}

void heapConstroi(Vetores* vetores, int n) {
    int esq;
    esq = (n / 2) - 1; // esq = primeiro nó antes do primeiro nó folha do heap
    while (esq >= 0) {
        heapRefaz(vetores, esq, n-1);
    esq--;
    }
}

void heapSort(Vetores* vetores, int n) {
    int aux;
    heapConstroi(vetores, n);
    while (n > 1) {
        aux = vetores->vetor[n-1];
        vetores->vetor[n-1] = vetores->vetor[0];
        vetores->vetor[0] = aux;
        n--;
        vetores->movimentacoes ++;
        heapRefaz(vetores, 0, n-1); // refaz o heap
    }
}
