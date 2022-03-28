#ifndef CONJNAOORDENADO_HPP
#define CONJNAOORDENADO_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


template <class T>
class ConjOrdenado
{
	 multimap<int, T> itens;

    public:
        typedef typename multimap<int, T>::iterator iterator;

        //Construtores e destrutores
        ConjOrdenado(){}
        ConjOrdenado(multimap<int, T> t){
            this->itens = t;
        }

        // Metodo para insercao de forma ordenada
        void inserir(int chave, T t){
            this->itens.insert(pair <int, T> (chave, t));            
        }

        iterator inicio( void ) const {
            auto itr = itens.begin();
            return itr->second;
        }
        iterator fim( void ) const {
            auto itr = itens.end();
            return itr->second;
        }

        T& operator [] ( int i ){
            int qntd = this->itens.size();
            auto itr = this->itens.begin();
            for (int j = 0; j < qntd; j++){
                if (i == j){
                    return itr->second;
                }
                itr++;
            }

            return itr->second; //
        }

        int size() {
            return this->itens.size();
        }

        void print(){
            int i = 0;
            for (auto itr = this->itens.begin(); itr != this->itens.end(); ++itr){
                cout << "i = " << i++ << "\n" << itr->second << "\n";
            }
        }
};


#endif