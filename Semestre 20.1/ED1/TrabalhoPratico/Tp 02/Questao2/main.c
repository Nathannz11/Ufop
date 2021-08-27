//Nathann Zini dos Reis 19.2.4007
#include "arvore.h"


int main(){
    //Questão 2.1 - Lendo uma expressão e criando uma árvore binária a partir dela;

    //Leitura da Expressão
    char expressao[50];
    scanf("%s", expressao);
    //tamanho da expressão
    int tamExpr = strlen(expressao);
    
    //Iniciando a raiz da áarvore
    TNo* pRaiz;
    TArvore_Inicia(&pRaiz);

    //Montando a árvore a partir da expressão lida
    montarArvore(expressao, 0, tamExpr, &pRaiz);

    //imprimindo a árvore
    printf("Impressão Pré Ordem: ");
    arvorePreOrdem(pRaiz);
    printf("\n");
    printf("Impressão Ordem Central: ");
    arvoreOrdemCentral(pRaiz);
    printf("\n");
    printf("Impressão Pós Ordem: ");
    arvorePosOrdem(pRaiz);
    printf("\n");


    /* Questão 2.2 - Recebendo uma árvore e calculando o resultado;
     * Usarei a árvore criada anteriormente a partir da expressão apresentada; 
    */

    //Iniciando uma pilha para armazenar a expressão matemática
    Pilha* pilhaExpressao;
    Pilha_Inicia(&pilhaExpressao);
    //condição de parada para o cálculo
    Pilha_Push(pilhaExpressao, '=');

    //Salva a expressão na pilha na ordem correta para fazer o cálculo
    arvoreEncaminhamentoPreOrdem(pRaiz, pilhaExpressao);


    //Pilha que será usada para armazenar os dados do cálculo
    Pilha* pilhaCalculo;
    Pilha_Inicia(&pilhaCalculo);

    char entrada;
    int i = 0, x;
    int operando;


    do{
        //Pega o primeiro dado da pilha com a expressão e transforma para char para a comparação
        Pilha_Pop(pilhaExpressao, &x);
        entrada = (char) x;
        //Verifica se é um número. Se for, salva o numero na pilha do calculo. Caso contrário, se for um operador,
        //verifica se há digitos suficientes para o cálculo
        if(entrada >= '0' && entrada <= '9'){
            operando = (int) entrada - 48;
            Pilha_Push(pilhaCalculo, operando);
        }else if(entrada == '-' || entrada == '+' || entrada == '*' || entrada == '/' && Pilha_Tamanho(pilhaCalculo) >= 2){            
            Pilha_Push(pilhaCalculo, calculadora(entrada, pilhaCalculo));           
        }
    }while (entrada != '=');

    //verifica se a expressão é correta;
    if(Pilha_Tamanho(pilhaCalculo) > 1){
        printf("entrada inconsistente\n");
        return 0;
    }
    printf("Resultado da expressão: ");
    pilha_imprime(pilhaCalculo);


    pilha_libera(&pilhaExpressao);
    pilha_libera(&pilhaCalculo);
    liberarArvore(&pRaiz);
    
    return 0;
}

