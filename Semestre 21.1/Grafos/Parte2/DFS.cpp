#include "DFS.hpp"

void inicioBuscaProfundidade(){
    Dfs grafoDFS;

    int n, m, dir, vInicial;

    cin >> n; //nmro vertices
    cin >> m; //nmro arestas
    cin >> dir; //se direcionado
    cin >> vInicial; //vertice inicial

    //adiciona vertices
    for(int i = 1; i <=n; i++){
        Vertice aux;
        aux.numero = i;
        aux.visitado = false;
        grafoDFS.vertices.push_back(aux);
    }

    grafoDFS.direcionado = dir;
    grafoDFS.n = n;


    //Criando e iniciando com 0 a matriz de adjacencia    
    int** adj = (int**) malloc(n * sizeof(int*));
    for(int i = 0; i < n; i ++){
        adj[i] = (int* )malloc(n * sizeof(int));
    }
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            adj[i][j] = 0;
        }
    }
  
    //adiciona arestas
    for(int i = 0; i < m; i++){
        Aresta aux;

        int nmrOrigem;
        cin >> nmrOrigem;
        aux.origem = &grafoDFS.vertices[nmrOrigem - 1];

        int nmrDestino;
        cin >> nmrDestino;
        aux.destino = &grafoDFS.vertices[nmrDestino - 1];

        cin >> aux.peso;
        aux.visitado = false;

        grafoDFS.arestas.push_back(aux);

        //adicionando adjacencia
        adj[nmrOrigem - 1][nmrDestino - 1] = 1;

        if(!grafoDFS.direcionado)
            adj[nmrDestino - 1][nmrOrigem - 1] = 1;
    }


    buscaProfundidade(&grafoDFS, adj, vInicial);
    for(int i = 0; i < n; i ++){
        free(adj[i]);
    }
    free(adj);
}


void buscaProfundidade(Dfs *grafoDFS, int **adj, int vInicial){

    grafoDFS->vertices[vInicial-1].visitado = true;
    cout << vInicial << endl; 
    
    for(int j = 0; j < grafoDFS->n; j ++){
        if(adj[vInicial-1][j] == 1 && !grafoDFS->vertices[j].visitado){
            buscaProfundidade(grafoDFS, adj, j+1);
        }
    }
       
    

}

