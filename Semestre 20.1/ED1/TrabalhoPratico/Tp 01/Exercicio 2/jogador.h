//Nathann Zini dos Reis 19.2.4007
#ifndef jogador_h
#define jogador_h

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

typedef struct jogador Jogador;

int getEscolha(Jogador* jogador);

void setEscolha(Jogador* jogador, int escolha);

void setVitorias(Jogador* jogador, int vitoria);

int getVitorias(Jogador* jogador);

void setEscolhaComputador(Jogador* jogador);



Jogador* alocarJogador();

void liberarJogador(Jogador** jogador);

#endif 