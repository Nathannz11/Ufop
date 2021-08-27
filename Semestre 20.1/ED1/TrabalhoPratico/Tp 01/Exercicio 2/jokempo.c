//Nathann Zini dos Reis 19.2.4007
#include "jokempo.h"

struct jokempo{
    Jogador* pessoa;
    Jogador* computador;
    int rodadas;
    int empate;
};

void setRodadas(Jokempo* jokempo, int rodadas){
    jokempo->rodadas = rodadas;
}

int getRodadas(Jokempo* jokempo){
    return jokempo->rodadas;
}

void setEmpates(Jokempo* jokempo, int empate){
    jokempo->empate += empate;
}

int getEmpates(Jokempo* jokempo, int empate){
    return jokempo->empate;
}

int getEscolhaPessoa(Jokempo* jokempo){
    return getEscolha(jokempo->pessoa);
}

void setEscolhaPessoa(Jokempo* jokempo, int escolha){
    setEscolha(jokempo->pessoa, escolha);
}

void setVitoriasPessoa(Jokempo* jokempo, int vitoria){
    setVitorias(jokempo->pessoa, vitoria);
}

int getVitoriasPessoa(Jokempo* jokempo){
   return getVitorias(jokempo->pessoa); 
}

int getEscolhaComputador(Jokempo* jokempo){
    return getEscolha(jokempo->computador);
}

void setEscolhaComputadorJok(Jokempo* jokempo){
    setEscolhaComputador(jokempo->computador);
}

void setVitoriasComputador(Jokempo* jokempo, int vitoria){
    setVitorias(jokempo->computador, vitoria);
}

int getVitoriasComputador(Jokempo* jokempo){
    return getVitorias(jokempo->computador);
}






void iniciarJogadores(Jokempo* jokempo){
    jokempo->pessoa = alocarJogador();
    jokempo->computador = alocarJogador();  
}

Jokempo* alocarJokempo(){
    Jokempo* aux = malloc(sizeof(Jokempo));
    iniciarJogadores(aux);
    setRodadas(aux, 5);
    setEmpates(aux, 0);
    return aux;
}

void liberarJokempo(Jokempo* jokempo){
    liberarJogadores(jokempo);
    free(jokempo);
}

void liberarJogadores(Jokempo* jokempo){
    liberarJogador(&(*jokempo).pessoa);
    liberarJogador(&(*jokempo).pessoa);
}
