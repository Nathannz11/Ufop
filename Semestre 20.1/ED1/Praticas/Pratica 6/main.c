/*Nathann Zini dos Reis 19.2.4007
* - A questão 1 e 2 estão nesse mesmo codigo
* - basta comentar ou a linha 20 ou a linha 23 (estão com o comentario a respeito da respectiva questão)
*/
#include <stdio.h>
#include <stdlib.h>


typedef struct{
    int matricula;
    double p1;
    double tp;
    double notaFinal;
}Aluno;

void alocarAlunos(Aluno** alunos, int n);
void desalocarAlunos(Aluno** alunos);
void lerDadosAlunos(Aluno* alunos, int n);
//Questão 1
void ordernarInsertion(Aluno* alunos, int n);

//questão 2;
//void ordernarMerge(Aluno* alunos, int primeiro,int ultimo);
void merge(Aluno* alunos, int primeiro, int meio, int ultimo);

void imprimirResultado(Aluno* alunos, int n);



int main(){
    Aluno* alunos;

    int casoTeste, qtdAluno;
    scanf("%d", &casoTeste);

    for(int i = 0; i < casoTeste; i++){
        getchar();

        scanf("%d", &qtdAluno);

        alocarAlunos(&alunos, qtdAluno);
        
        lerDadosAlunos(alunos, qtdAluno);
        
        //Questão 1
        //ordernarInsertion(alunos, qtdAluno);

        //Questão 2
        ordernarMerge(alunos, 0, qtdAluno);

        imprimirResultado(alunos, qtdAluno);

        desalocarAlunos(&alunos);
    }
    
}

void alocarAlunos(Aluno** alunos, int n){
    *alunos = malloc(n*sizeof(Aluno));
    (*alunos)->matricula = 0;
    (*alunos)->p1 = 0.0;
    (*alunos)->tp = 0.0;
    (*alunos)->notaFinal = 0.0;

}

void desalocarAlunos(Aluno** alunos){
    free(*alunos);
}

void lerDadosAlunos(Aluno* alunos, int n){
    for(int i = 0; i < n; i++){
        scanf("%d", &alunos[i].matricula);
        scanf("%lf", &alunos[i].p1);
        scanf("%lf", &alunos[i].tp);

        alunos[i].notaFinal = (alunos[i].p1 * 0.7)+(alunos[i].tp * 0.3);
    }
}

//Questão 1
void ordernarInsertion(Aluno* alunos, int n){
    Aluno aux;
    int j;
    for(int i = 1; i < n; i++){
        aux = alunos[i];
        j = i - 1;

        while(j >= 0 && aux.notaFinal > alunos[j].notaFinal){
            alunos[j + 1] = alunos[j];
            j--;
        }
        alunos[j + 1] = aux;
    }
}

//Questão 2
void ordernarMerge(Aluno* alunos, int primeiro, int ultimo){
    if(primeiro < ultimo){
        int meio = (primeiro + ultimo) / 2; 
        ordernarMerge(alunos, primeiro, meio);
        ordernarMerge(alunos, meio +1, ultimo);
        merge(alunos, primeiro, meio, ultimo);
    }
}

void merge(Aluno* alunos, int primeiro, int meio, int ultimo){
    int tamanhoEsquerdo = (meio - primeiro) + 1;
    int tamanhoDireito = ultimo - meio;

    Aluno* vetEsquerdo;
    Aluno* vetDireito;

    alocarAlunos(&vetEsquerdo, tamanhoEsquerdo);
    alocarAlunos(&vetDireito, tamanhoDireito);

    for(int i = 0; i < tamanhoEsquerdo; i++){
        vetEsquerdo[i] = alunos[i + primeiro];
    }

    for(int i = 0; i < tamanhoDireito; i++){
        vetDireito[i] = alunos[i + meio + 1];
    }

    int i =0;
    int j = 0;

    for(int k = primeiro; k <= ultimo; k++){
        if(i == tamanhoEsquerdo)
            alunos[k] = vetDireito[j++];
        else if(j == tamanhoDireito)
            alunos[k] = vetEsquerdo[i++];
        else if(vetEsquerdo[i].notaFinal >= vetDireito[j].notaFinal)
            alunos[k] = vetEsquerdo[i++];
        else
            alunos[k] = vetDireito[j++];
    }
    desalocarAlunos(&vetEsquerdo);
    desalocarAlunos(&vetDireito);
}


void imprimirResultado(Aluno* alunos, int n){
    printf("\n");
    for(int i = 0; i < n; i++){
        printf("%d %.2lf\n", alunos[i].matricula, alunos[i].notaFinal);
    }
    printf("\n");
}
    

