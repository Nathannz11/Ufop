//Nathann Zini dos Reis 19.2.4007

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITENSPAGINA 8
#define MAXTABELA 200

typedef struct {
    int chave;
    long int preco;
    char titulo[15];
}tipoItem ;

typedef struct {
    int posicao;
    int chave;
}tipoIndice;

FILE* converterEmBinario(FILE* arqTxt){
    FILE* arqBin;
    if((arqBin = fopen("arqSequencial.bin", "w+b"))== NULL){
        printf("Erro na criação do arquivo binario\n");
        exit(1);
    }

    tipoItem item;
    while(!feof(arqTxt)){
       
        fscanf(arqTxt, "%d %ld %[A-Z a-z]", &item.chave, &item.preco, item.titulo); 
        fwrite(&item, sizeof(tipoItem), 1, arqBin);
    }
    fseek(arqBin,0 ,SEEK_SET);
    return arqBin;
}

int pesquisa (tipoIndice tab[], int tam, tipoItem* item, FILE* arq){
    tipoItem pagina[ITENSPAGINA];
    int i, qtditens;
    long desloc;

    i = 0;
    while (i < tam && tab[i].chave <= item->chave)
        i++;
    
    if(i == 0)
        return 0;
    else{
        // a ultima pagina pode nao estar completa
        if( i < tam)
            qtditens = ITENSPAGINA;
        else{
            fseek (arq, 0, SEEK_END);
            qtditens = (ftell(arq)/sizeof(tipoItem))% ITENSPAGINA;
        }

        //lê a pagina desejada do arquivo
        desloc = (tab[i - 1].posicao - 1)* ITENSPAGINA * sizeof(tipoItem);
        fseek(arq, desloc, SEEK_SET);
        fread(&pagina, sizeof(tipoItem), qtditens, arq);

        

        //pesquisa sequencial na pagina lida
        for (i = 0; i < qtditens; i++ ){
            if(pagina[i].chave == item->chave){
                *item = pagina[i];
                return 1;
            }
        }
        return 0;
    }
}


int main(int argc, char* argv[]){

    if(argc != 2){
        printf("favor informar o arquivo sequencial txt\n");
        return 0;
    }else{

        FILE* arqTxt;
        if((arqTxt = fopen(argv[1], "r")) == NULL){
            printf("Erro na abertura do arquivo\n");
            return 0;
        }
        FILE* arqBin = converterEmBinario(arqTxt);

                

        tipoItem x[ITENSPAGINA];
        tipoIndice tabela[MAXTABELA];
        int pos = 0;
       
        while (fread(&x, sizeof(tipoItem), ITENSPAGINA, arqBin)){
                tabela[pos].chave = x[0].chave;
                tabela[pos].posicao = pos+1;
                pos++;
        }

        tipoItem aux;
        fflush(stdout);
        printf("Informe a chave desejada: ");
        scanf("%d", &aux.chave);

        if(pesquisa(tabela, pos, &aux, arqBin))
            printf("Item %d foi localizado:\n preço: %ld \n título: %s\n", aux.chave, aux.preco, aux.titulo);
        else
            printf("Item %d não foi localizado!\n", aux.chave);

        fclose(arqTxt);
        fclose(arqBin);
    }
    return 0;

}