#ifndef BFS_HPP
#define BFS_HPP

#include <iostream>
#include <list>
#include <vector>
#include <queue>

using namespace std;

typedef struct  vertice{
    int numero;
    bool visitado;
}Vertice;

typedef struct aresta{
    Vertice *origem;
    Vertice *destino;
    int peso;
    bool visitado;
}Aresta;

typedef struct bfs{
    vector<Vertice> vertices;
    vector<Aresta> arestas;
    int direcionado;

}Bfs;

void inicioBuscaLargura();
void preencherGrafo(Bfs *grafoBFS, int n, int m);
void buscaLargura(Bfs *grafoBFS, list<Vertice> *adj, int vInicial);
void imprimirResultado(vector<int> descobertos);

#endif
