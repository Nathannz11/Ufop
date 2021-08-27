//Nathann Zini dos Reis 19.2.4007
#include "biblioteca.h"

int main(int argc, char const *argv[]){
    
    //iniciar o struct Vetor
    Vetores vetores;
    int qtdVetor, tamVetor;

    //verifica se há arqruivo de entrada
    if(argc == 2){
        
        //abre o arquivo para leitura
        FILE *arq = fopen(argv[1], "r");
        iniciarVetores(arq, &vetores);
        //fecha o arquivo
        fclose(arq);
        

        for(int i = 0; i < vetores.qtdVetor; i++){
            //chama a função para ordenar os vetores para cada um vetor por vez;
            quickSort(vetores.vetor[i], 0, vetores.tamVetor - 1, &vetores.comparacoes[i], &vetores.movimentacoes[i]);
        }
        
        imprimirVetores(&vetores);
        

    }else{
        printf("Favor informar o arquivo de entrada!\n");

    }


    desalocarVetores(&vetores);
    return 0;
}
