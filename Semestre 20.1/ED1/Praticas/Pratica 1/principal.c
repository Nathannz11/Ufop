#include <stdio.h>
#include <stdlib.h>
#include "vetor_util.h"

int main(){
    //Exercicios 1 e 2

    int *vetor;
    int n, elemento;
    printf("informe o tamanho do vetor: ");
    scanf("%d", &n);
    vetor = malloc(n * sizeof(int));
    printf("Informe o vetor: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    printf("Informe o elemento a ser procurado: ");
    scanf("%d", &elemento);

    //printf("%d\n", buscaSequencial(vetor, n, elemento));
    printf("%d\n", buscaBinaria(vetor, n, elemento));
    free(vetor);
    
    
/*
   //Exercicio 3
    int *vetor1, *vetor2;
    int n1, n2;
    printf("informe o tamanho do vetor: ");
    scanf("%d", &n1);
    vetor1 = malloc(n1 * sizeof(int));
    printf("Informe o vetor: ");
    for(int i = 0; i < n1; i++){
        scanf("%d", &vetor1[i]);
    }

    printf("informe o tamanho do vetor: ");
    scanf("%d", &n2);
    vetor2 = malloc(n2 * sizeof(int));
    printf("Informe o vetor: ");
    for(int i = 0; i < n2; i++){
        scanf("%d", &vetor2[i]);
    }

    //exercicio 4
    //printf("%d\n", comparaVetores(vetor1, vetor2, n1, n2));
    
    
    int *vetorTemp = malloc((n1 + n2) *(sizeof(int)));
    vetorTemp = intercalaVetoresOrdenados(vetor1, n1, vetor2, n2);
    printf("Vetor intercalado: ");
    for(int i = 0; i < n1 + n2; i++){
        printf("%d ", vetorTemp[i]);
    }
    printf("\n");

    free(vetor1);
    free(vetor2);
    free(vetorTemp);*/
    return 0;
}