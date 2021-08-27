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
    if((arquivoS = fopen("conceitos.txt", "w")) == NULL){
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

        if(alunoTemp.faltas > 18){
            conceito = 'F';
        }else{
            media = (alunoTemp.nota1 + alunoTemp.nota2 + alunoTemp.nota3)/3;
            if(media < 6.0)
                conceito = 'R';
            else if(media < 7.5)
                conceito = 'C';
            else if(media < 9.0)
                conceito = 'B';
            else conceito = 'A';
        }

        fprintf(arquivoS, "%-4d ", alunoTemp.matricula);
        fprintf(arquivoS, "%-30s ", alunoTemp.nome);
        fprintf(arquivoS, "%-1c", conceito);
        fputc('\n', arquivoS);

    }



    fclose(arquivoE);
    fclose(arquivoS);
    return 0;
}