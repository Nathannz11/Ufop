#ifndef CONJNAOORDENADO_HPP
#define CONJNAOORDENADO_HPP

#include <iostream>
#include <vector>

#include "Estudante.hpp"
#include "Disciplina.hpp"

using namespace std;

template <class T>
class ConjNaoOrdenado{

        vector<T> itens;

    public:
        typedef typename vector<T>::iterator iterator;

        ConjNaoOrdenado(void){}

        ConjNaoOrdenado(vector<T> t){
            this->itens = t;
        }

        void inserir(T t){
            this->itens.push_back(t);
        }

        iterator inicio() {
            return itens.begin();
        }
        iterator fim() {
            return itens.end();
        }
        T& operator [] ( int i ){
            return this->itens[i];
        }
        int size() {
            return this->itens.size();
        }
        
        void print(){
            for(int i = 0; i < this->itens.size(); i++ ){
                cout << "i = " << i << "\n" << this->itens[i] << "\n";
            }
        }
};

#endif