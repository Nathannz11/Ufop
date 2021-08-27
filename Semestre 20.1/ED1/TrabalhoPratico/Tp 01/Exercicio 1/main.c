//Nathann Zini dos Reis 19.2.4007
#include "jogoDaVelha.h"

int main(){

    Jogo jogo;
    jogo.scorePC = 0;
    jogo.scoreUser = 0;
    jogo.draw = 0;
    jogo.MatchCounter = 3;
    int flag = 1;

    printf("teste1\n");
    iniciarTabuleiro(&jogo);
    do{
        flag = partida(&jogo);
    }while(flag);
    
    printf("%d %d\n", jogo.scoreUser, jogo.scorePC);

    return 0;
}