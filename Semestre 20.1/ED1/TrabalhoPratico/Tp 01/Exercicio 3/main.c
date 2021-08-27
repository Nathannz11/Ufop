//Nathann Zini dos Reis 19.2.4007
#include "biblioteca.h"

int main(){
    char** entrada;

    int n, tamanho, metade;

    scanf("%d", &n);

    entrada = alocarVetor( n);
    getchar();
    for(int i = 0; i < n; i++){
        
        fgets(entrada[i],103, stdin);
    
        primeiro(entrada, i, 0);

        tamanho = strlen(entrada[i]) - 1;
        metade = tamanho  / 2;
        segundo(entrada, i, 0, tamanho, metade);

        terceira(entrada, i, tamanho, metade);

        printf("%s\n", entrada[i]);
    
    }

    desalocarvetor(entrada, n);
    return 0;
}