//Nathann Zini dos Reis 19.2.4007
#include "matricula.h"


Aluno* CriarAlunos(int n){
    Aluno* alunos = malloc(n * sizeof(Aluno));
    return alunos;
}

void setAlunos(Aluno* alunos, int n){
    printf("Digite as informaçoes dos alunos \n");
    for(int i = 0; i < n; i++){
        printf("---- ALUNO %d ----\n", i+1);
        printf("matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("nome: ");
        scanf("%s", alunos[i].nome);
        printf("nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("nota 2: ");
        scanf("%f", &alunos[i].nota2);
        printf("nota 3: ");
        scanf("%f", &alunos[i].nota3);
        printf("faltas: ");
        scanf("%d", &alunos[i].faltas);
    }
}

void setConceito(Aluno* alunos, int n){
    float media;
    for(int i = 0; i < n; i++){
        if(alunos[i].faltas > 18){
            alunos[i].conceito = 'F';
        }else{
            media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;
            if(media < 6.0)
                alunos[i].conceito = 'R';
            else if(media < 7.5)
                alunos[i].conceito = 'C';
            else if(media < 9.0)
                alunos[i].conceito = 'B';
            else
                alunos[i].conceito = 'A';
        }        
    }
}

void liberar(Aluno* alunos, int n){
    free(alunos);   
}