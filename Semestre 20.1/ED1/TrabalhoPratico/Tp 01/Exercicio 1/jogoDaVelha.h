//Nathann Zini dos Reis 19.2.4007
#include <stdlib.h>
#include <stdio.h>

typedef struct jogoDaVelha
{
    int tabuleiro[3][3];
    int scorePC;
    int scoreUser;
    int draw;
    int MatchCounter;
    int l;
    int c;
}Jogo;


int** criarTabuleiro();

void liberarTabuleiro(Jogo* jogo);

void iniciarTabuleiro(Jogo* jogo);

void mostrarJogo(Jogo* jogo);

char menu();

void jogadaUser(Jogo* jogo);

void jogadaPc(Jogo* jogo);

int verificarVitoria(Jogo* jogo);

int partida(Jogo* jogo);