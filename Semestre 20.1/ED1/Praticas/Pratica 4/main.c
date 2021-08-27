//Nathann Zini dos Reis 19.2.4007

#include "pratica4.h"

int main(){

    int escolha = menu();
    

    int n, i;

    //questao 1
    int qtdRepeticao = 0;
    int ultimoValor;

    //questao 2
    int *vet;

    //questao 3
    int grau = 0, tamanho = 0;
    int soma = 0;
    long long int n3;

    //questao 4
    *vet;
    int elemento, indice = -1, metade;

    switch (escolha)
    {
    case 1:
        qtdRepeticao = 0;
        ultimoValor, n;
        
        do{
            scanf("%d", &n);
            if(n == -1){
                qtdRepeticao = 0;
            }else{
                ultimoValor = sequenciaFibonacci(n, &qtdRepeticao);
                printf("%d %d\n", ultimoValor, qtdRepeticao);
            }
        } while (n != -2);
        break;
    case 2:
        scanf("%d", &n);
        vet = malloc(n * sizeof(int));
        for(i = 0; i < n; i++){
            scanf("%d", &vet[i]);
        }
        vetorInverso(n, vet);
        free(vet);
        break;
    
    case 3:
        do{
            scanf("%lld", &n3);
            if(n3 == -1){
                grau = 0, soma = 0, tamanho = 0;
            }else{
                grau9(n3, &grau, tamanho, &soma);
                printf("%d\n", grau);
            }
        } while (n3 != -2);
        break;
    case 4:
        do{
            scanf("%d", &n);
            vet = malloc(n * sizeof(int));
            for(i = 0; i < n; i++){
                scanf("%d", &vet[i]);
            }
            scanf("%d", &elemento);
            if(n == -1){
                
            }else{
                buscaBinaria(vet, n, &indice, elemento, metade);

            }
        } while (n != -2);
        free(vet);
        break;
    default:
        break;
    }
    
    
    



    return 0;
}