//Nathann Zini dos Reis 19.2.4007
#include "jogador.h"

struct jogador{
    int escolha;
    int vitorias;
};

int getEscolha(Jogador* jogador){
    return jogador->escolha;
}

void setEscolha(Jogador* jogador, int escolha){
    jogador->escolha = escolha;
}

void setVitorias(Jogador* jogador, int vitoria){
    jogador->vitorias += vitoria;
}

int getVitorias(Jogador* jogador){
    return jogador->vitorias;
}

void setEscolhaComputador(Jogador* jogador){
    int n = rand() % 3;
    setEscolha(jogador, n);
}

Jogador* alocarJogador(){
    Jogador* temp = malloc (sizeof(Jogador));
    return temp;
}

void liberarJogador(Jogador** jogador){
    free(*jogador);
}