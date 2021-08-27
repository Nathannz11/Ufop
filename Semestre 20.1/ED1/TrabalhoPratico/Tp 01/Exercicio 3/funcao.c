//Nathann Zini dos Reis 19.2.4007
#include "biblioteca.h"

char** alocarVetor(int n){

    char** vetor = malloc(n * sizeof(char*));
    
    for(int i = 0; i < n; i++){
        vetor[i] = malloc(103*sizeof(char));
    }
    return vetor;
}

void desalocarvetor(char** vetor, int n){
    for (int i = 0; i < n; i++)
    {
        free(vetor[i]);
    }
    free(vetor);
}


//A complexidade dessa recursividade é O(n)
void primeiro(char** vetor, int i, int n){
    if(vetor[i][n] != '\n'){
        primeiro(vetor, i, n + 1);
    }
    if((vetor[i][n] >= 'A' && vetor[i][n] <= 'Z') || (vetor[i][n] >= 'a' && vetor[i][n] <= 'z')){
        vetor[i][n] += 3;
    }
}

//A complexidade dessa recursividade é O(n)
void segundo(char** vetor, int i, int n, int tamanho, int metade){
    char temp;

    if(metade % 2 == 0){
        if(n < metade - 1){
            segundo(vetor, i, n + 1, tamanho, metade);
        }
        temp = vetor[i][n];
        vetor[i][n] = vetor[i][(tamanho - n) - 1];
        vetor[i][(tamanho - n) - 1] = temp;
    }else{
        if(n < metade - 1){
            segundo(vetor, i, n + 1, tamanho, metade);
        }
        temp = vetor[i][n];
        vetor[i][n] = vetor[i][(tamanho - n) - 1];
        vetor[i][(tamanho - n) - 1] = temp;
    }

}

//A complexidade dessa recursividade é O(n) 
void terceira(char** vetor, int i, int tamanho, int n){
    if(n <= tamanho - 1){
        terceira(vetor, i, tamanho, n + 1);
        vetor[i][n] -= 1;
    }
}