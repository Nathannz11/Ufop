//Nathann Zini dos Reis 19.2.4007


#include "pratica4.h"

int menu(){
    
    printf("Escolha qual questão: \n");
    printf("1 - Sequencia Fibonacci\n");
    printf("2 - Vetor inverso\n");
    printf("3 - Multiplo de 9\n");
    printf("4 - Busca Binária\n");

    int escolha;
    scanf("%d", &escolha);
    return escolha;
}

int sequenciaFibonacci(int n, int *qtdRepeticao){
    if(n == 0)
        return 0;
    else if(n ==1)
        return 1;
    else{
        *qtdRepeticao += 2;
        return sequenciaFibonacci(n - 1, qtdRepeticao) + sequenciaFibonacci(n - 2, qtdRepeticao);
    }
}

void vetorInverso(int n, int* vet){
    if (n == 0){
        printf("\n");
    }
    else{
        printf("%d ", vet[n - 1]);
        vetorInverso(n - 1, vet);
    } 
    
}

void grau9(long long int n, int *grau, int tamanho, int *soma){
    if(n != 0){
        if(n % 9 == 0){
           int aux;
           tamanho = (int) log10(n) + 1;
           if(tamanho == 1){
                n = *soma;
                *soma = 0;
                *grau = *grau + 1;
                if(n == 9){
                  //condiçao de parada;
                 }else{
                    grau9(n, grau, tamanho, soma);
                 }
            }else{

                aux = n % 10;
                *soma += aux;
                n = (int) (n / pow(10,1));
                if(tamanho == 2){
                   *soma+= n;
                   n = 9;
                }
                grau9(n, grau, tamanho, soma);
           }
        }
    }  
}

void buscaBinaria(int* vetor, int n, int *indice, int elemento, int metade){
    if(n <= 0 || elemento > vetor[n-1]){
        *indice =  -1;
    }else{
        if (elemento < vetor[metade]){
            metade = n/2;
            n = metade;
            metade = metade / 2;
            buscaBinaria(vetor, n, indice, elemento, metade);
        }
        else if(elemento > vetor[metade]){
            
            metade += (n - metade) / 2;
            buscaBinaria(vetor, n, indice, elemento, metade);
        }
        else *indice = 
        metade;
    }
        
}