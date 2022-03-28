#ifndef FUNCOES_H
#define FUNCOES_H

#include <iostream>
#include "ConjNaoOrdenado.hpp"
#include "ConjOrdenado.hpp"

using namespace std;

template <class T, typename U>
U count(T& estrutura, U& valor){
    int tam = estrutura.size();
    int cont = 0;
    for(int i = 0; i < tam; i++){
        if(estrutura[i] == valor){
            cont++;
        }
    }
    return cont;
}


template <class T, typename U>
U sum(T& estrutura, U& valor){
    int tam = estrutura.size();
    U soma = 0;
    for(int i = 0; i < tam; i++){
        if(estrutura[i] == valor){
            soma = estrutura[i] + soma;
        }
    }
    return soma;
}

template <class T>
average(T& estrutura){
    int qntd = estrutura.size();
    double soma = 0.0;

    for(int i = 0; i < qntd; i++){
        soma = estrutura[i] + soma;    
    }

    return soma/qntd;
}
#endif