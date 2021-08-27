//Nathann Zini Dos Reis 19.2.4007
#include "pilha.h"

int calculadora(char operador, Pilha* pilha);

int main(){
    int operando;
    char entrada;

    Pilha* pilha;

    Pilha_Inicia(&pilha);

    while (entrada != '='){
        entrada = getchar();
        if(entrada >= '0' && entrada <= '9'){
            operando = (int) entrada - 48;
            Pilha_Push(pilha, operando);
        }else if(entrada == '-' || entrada == '+' || entrada == '*' || entrada == '/' && Pilha_Tamanho(pilha) >= 2){    
            Pilha_Push(pilha, calculadora(entrada, pilha));            
        }  
    }
        if(Pilha_Tamanho(pilha) > 1){
        printf("entrada inconsistente\n");
        return 0;
        }
    pilha_imprime(pilha);
    pilha_libera(&pilha);

    return 0;
}

int calculadora(char operador, Pilha* pilha){

    int v1, v2;
    Pilha_Pop(pilha, &v2);
    Pilha_Pop(pilha, &v1);

    switch (operador)
    {
    case '+':
        return v1 + v2;
        break;
    case '-':
        return v1 - v2;
        break;
    case '/':
        return v1 / v2;
        break;
    case '*':
        return v1 * v2;
        break;
    default:
        break;
    }
    return 0;

}
