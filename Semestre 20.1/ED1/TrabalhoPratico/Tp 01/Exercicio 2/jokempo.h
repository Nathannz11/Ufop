//Nathann Zini dos Reis 19.2.4007
#ifndef jokempo_h
#define jokempo_h

#include "jogador.h"

typedef struct jokempo Jokempo;

void setRodadas(Jokempo* jokempo, int rodadas);
int getRodadas(Jokempo* jokempo);
void setEmpates(Jokempo* jokempo, int empate);
int getEmpates(Jokempo* jokempo, int empate);

int getEscolhaPessoa(Jokempo* jokempo);
void setEscolhaPessoa(Jokempo* jokempo, int escolha);
void setVitoriasPessoa(Jokempo* jokempo, int vitorias);
int getVitoriasPessoa(Jokempo* jokempo);

int getEscolhaComputador(Jokempo* jokempo);
void setEscolhaComputadorJok(Jokempo* jokempo);
void setVitoriasComputador(Jokempo* jokempo, int vitorias);
int getVitoriasComputador(Jokempo* jokempo);


void iniciarJogadores(Jokempo* jokempo);

Jokempo* alocarJokempo();

void liberarJokempo(Jokempo* jokempo);

void liberarJogadores(Jokempo* jokempo);



#endif