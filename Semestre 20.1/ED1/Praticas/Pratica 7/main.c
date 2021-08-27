#include "biblioteca.h"

int main(){
    int n;
    Vetores* vetores;
    scanf("%d", &n);

    alocarVetores(&vetores, n);
    lerDadosVetor(vetores, n);

    for(int i = 0; i < n; i++){
        heapSort(&vetores[i], vetores[i].tam);
    }
    printf("Vetor\t\t\t| Comparacoes | Moviementacoes\n");
    for(int i = 0; i < n; i++){
        imprimirDados(&vetores[i]);
    }

    desalocarVetores(&vetores, n);

    return 0;
}
