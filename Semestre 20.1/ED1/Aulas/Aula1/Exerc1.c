#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gerarAleatorio();
void menuInicial();
int menuJogada();

int main(){
    int pessoaCont = 0, compCont = 0, resultado;
    srand(time(NULL));
    menuInicial();
    do{
        resultado = menuJogada();
        if(resultado == 0)
            compCont++;
        else if(resultado == 1)
            pessoaCont++;
    } while (compCont < 3 && pessoaCont < 3);
    if(pessoaCont == 3){
        printf("\nVitoria!!!\n");
        printf("Placar: Usuário: %d vs %d Computador\n",pessoaCont, compCont);   
    }       
    else{
      printf("\nDerrota!!!\n");
      printf("Placar: Usuário: %d vs %d Computador\n",pessoaCont, compCont);  
    } 
    
    
    return 0;
}


int gerarAleatorio(){
    int temp;
    temp = rand() % 3;
    return temp;
}

void menuInicial(){
    printf("|  DISPUTA DE PEDRA, PAPEL OU TESOURA       |\n");
    printf("|___________________________________________|\n");
    printf("|escolha entre as opções abaixo:            |\n");
    printf("|___________________________________________|\n");
    printf("|0 - Pedra                                  |\n");
    printf("|1 - Papel                                  |\n");
    printf("|2 - Tesoura                                |\n");
    printf("|___________________________________________|\n");
}

int menuJogada(){
    // resultado 0 = pc, 1 = pessoa, 2 = draw;
    int pessoa, comp, resultado;
    printf("Digite uma opção: ");
    scanf("%d", &pessoa);
    comp = gerarAleatorio();
    printf("sua escolha %d vs %d escolha do computador\n", pessoa, comp);
    switch (pessoa){
    case 0:
        if(comp == 1){
            resultado = 0;
        }else if(comp == 2){
            resultado = 1;
        }else resultado = 2;
        break;
    case 1:
        if(comp == 0){
            resultado = 1;
        }else if(comp == 2){
            resultado = 0;
        }else resultado = 2;
        break;
    case 2:
        if(comp == 0){
            resultado = 0;
        }else if(comp == 1){
            resultado = 1;
        }else resultado = 2;
        break;
    default:
        printf("Opção inválida\n");
        resultado = 2;
        break;
    }
    return resultado;

}