//Nathann Zini dos Reis 19.2.4007
#include "matricula.h"



int main(){

    int n;
    printf("Informe a quantidade de alunos: \n");
    scanf("%d", &n);

    Aluno* alunos = CriarAlunos(n);
    setAlunos(alunos, n);
    setConceito(alunos, n);
    for(int i = 0; i < n; i++){ 
        printf("Nome: %s, Conceito: %c\n\n", alunos[i].nome, alunos[i].conceito);
    }
    liberar(alunos, n);

    
    return 0;
}