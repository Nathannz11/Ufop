//Nathann Zini dos Reis 19.2.4007
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int matricula;
    char nome[30];
    float nota1;
    float nota2;
    float nota3;
    int faltas;
    char conceito;
}Aluno;

Aluno* CriarAlunos(int);
void setAlunos(Aluno* , int);
Aluno getAluno(Aluno* , int);
void setConceito(Aluno* , int);
void liberar(Aluno*, int);