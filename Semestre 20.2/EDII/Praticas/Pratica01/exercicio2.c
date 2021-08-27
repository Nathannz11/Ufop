#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int matricula;
    char nome[31];
    float nota1;
    float nota2;
    float nota3;
    int faltas;
}Aluno;


int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Formato: executável arquivo\n");
        exit(1);
    }
    FILE* arquivoE;
    if((arquivoE = fopen(argv[1], "r")) == NULL){
        printf("Impossível abrir o arquivo\n");
        exit(1);
    }
    FILE* arquivoS;
    if((arquivoS = fopen("alunos.bin", "wb")) == NULL){
        printf("Impossível abrir o arquivo\n");
        exit(1);
    }

    Aluno alunoTemp;
    char conceito;
    float media;
    while(!feof(arquivoE)){
        
        fscanf(arquivoE, "%d", &alunoTemp.matricula);
        fgetc(arquivoE);
        fgets(alunoTemp.nome, 30, arquivoE);
        fgetc(arquivoE);
        fscanf(arquivoE, "%f", &alunoTemp.nota1);
        fgetc(arquivoE);
        fscanf(arquivoE, "%f", &alunoTemp.nota2);
        fgetc(arquivoE);
        fscanf(arquivoE, "%f", &alunoTemp.nota3);
        fgetc(arquivoE);
        fscanf(arquivoE, "%d", &alunoTemp.faltas);

      
        fwrite(&alunoTemp, sizeof(Aluno), 1, arquivoS);
    }



    fclose(arquivoE);
    fclose(arquivoS);
    return 0;
}