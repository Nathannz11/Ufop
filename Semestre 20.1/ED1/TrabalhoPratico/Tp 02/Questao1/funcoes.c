//Nathann Zini dos Reis 19.2.4007
#include "biblioteca.h"

//Aloca e iniciar os valores dos vetores;
void iniciarVetores(FILE* arq, Vetores *vetores){
    fscanf(arq, "%d %d", &vetores->qtdVetor, &vetores->tamVetor);

    vetores->vetor = malloc(vetores->qtdVetor * sizeof(int*));

    for(int i = 0; i < vetores->qtdVetor; i ++){
        vetores->vetor[i] = malloc(vetores->tamVetor * sizeof(int));
    }

    //preenche os vetores com os valores do arquivo
    for(int i = 0; i < vetores->qtdVetor; i ++){
        for(int j = 0; j < vetores->tamVetor; j ++){
            fscanf(arq, "%d", &vetores->vetor[i][j]);
        }   
    }

    vetores->comparacoes = malloc(vetores->qtdVetor * sizeof(int));
    vetores->movimentacoes = malloc(vetores->qtdVetor * sizeof(int));

    for(int i = 0; i < vetores->qtdVetor; i ++){
        vetores->comparacoes[i] = 0;
        vetores->movimentacoes[i] = 0;
    }
    

}

//desaloca os vetores
void desalocarVetores(Vetores *vetores){
    for(int i = 0; i < vetores->qtdVetor; i ++){
        free(vetores->vetor[i]);
    }
    free(vetores->vetor);
    free(vetores->comparacoes);
    free(vetores->movimentacoes);
}

//Função para ordernar o vetor; Usa o quickSort sorte até o vetor ser do tamanho K. A partir daí, ordena com o insertionSort
void quickSort(int* vetor, int l, int r, int *movimentacoes, int *comparacoes){
    if( l < r){
        //para o pivô aleatorio, eu pego qualquer valor que esteja na ultima posicao; Para pivô não aleatorio, eu pego o mediano 
        //do primeiro, do ultimo e do valor do meio do vetor não ordenado; 


        //-----FAVOR COMENTAR UMA DAS LINHAS 49 ou 50 E DESCOMENTAR A OUTRA para que a outra rode;
        //int q = partitionAleatorio(vetor, l, r, movimentacoes, comparacoes);
        int q = partitionMediana(vetor, l, r, movimentacoes, comparacoes);
        if(l + q - 1 <= k)
            insertionSort(vetor, l, q, movimentacoes, comparacoes);
        else
            quickSort(vetor, l, q - 1, movimentacoes, comparacoes);
        
        if( r - q - 1 <= k)
            insertionSort(vetor, q, r + 1, movimentacoes, comparacoes);
        else
            quickSort(vetor, q + 1, r, movimentacoes, comparacoes);
    }
}

//coloca os valores menores que o pivô para a esquerda dele e os maiores para a direita e retorna a posição do pivô
int partitionAleatorio(int* vetor, int l, int r, int *movimentacoes, int *comparacoes){
    int x = vetor[r];
    int i = l - 1;
    int aux;
    for(int j = l; j < r; j++){
        *comparacoes += 1;
        if(vetor[j] <= x){
            *movimentacoes += 1;
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    *movimentacoes += 1;
    aux = vetor[i + 1];
    vetor[i + 1] = vetor[r];
    vetor[r] = aux;

    return (i + 1);
}

//coloca os valores menores que o pivô para a esquerda dele e os maiores para a direita e retorna a posição do pivô
//o pivô é selecionado a partir do mediano dos valores inicio, meio e fim do vetor;
int partitionMediana(int* vetor, int l, int r, int* movimentacoes, int* comparacoes){
    int x;
    if(vetor[l] <= vetor[r - l] && vetor[r - l] <= vetor[r]){
        x = vetor[r - l];
    }else{
        if(vetor[r - l] <= vetor[l] && vetor[l] <= vetor[r]){
            x = vetor[l];
        }else{
            x = vetor[r];
        }
    }
    
    int i = l - 1;
    int aux;
    for(int j = l; j < r; j++){
        *comparacoes += 1;
        if(vetor[j] <= x){
            *movimentacoes += 1;
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    *movimentacoes += 1;
    aux = vetor[i + 1];
    vetor[i + 1] = vetor[r];
    vetor[r] = aux;

    return (i + 1);
}

//coloca o menor valor na frente e "arrasta" os demais uma casa para direita
void insertionSort(int* vetor, int l, int r, int *movimentacoes, int *comparacoes){
    int j, aux;
    for(int i = l + 1; i < r; i++){
        aux = vetor[i];
        j = i - 1;
        *comparacoes += 1;
        while(j >= 0 && aux < vetor[j]){
            *movimentacoes += 1;
            vetor[j + 1] = vetor[j];
            j--;
            *comparacoes += 1;
        }
        *movimentacoes += 1;

        vetor[j + 1] = aux;
    }
}

//função para imprimir os vetores
void imprimirVetores(Vetores *vetores){
    for(int i = 0; i < vetores->qtdVetor; i++){
        printf("Vetor %d: ", i);
        for(int j = 0; j < vetores->tamVetor; j++){
            printf("%d ", vetores->vetor[i][j]);
        }
        printf("\nMovimentacoes: %d || Comparacoes: %d\n", vetores->movimentacoes[i], vetores->comparacoes[i]);
        printf("----------------\n");
    }
}