#ifndef DFS_HPP
#define DFS_HPP

#include <stdlib.h>
#include <iostream>
#include <vector>

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
    int n;

}Dfs;

void inicioBuscaProfundidade();
void buscaProfundidade(Dfs *grafoDFS, int **adj, int vInicial);

#endif
