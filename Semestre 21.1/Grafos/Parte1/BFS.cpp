#include "BFS.hpp"

void inicioBuscaLargura(){
    Bfs grafoBFS;

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
        grafoBFS.vertices.push_back(aux);
    }

    grafoBFS.direcionado = dir;

    //iniciando lista de adjacencia;
    //list<list <Vertice>> adj[n];
    list<Vertice> *adj = new list<Vertice>[n];
  
    //adiciona arestas
    for(int i = 0; i < m; i++){
        Aresta aux;

        int nmrOrigem;
        cin >> nmrOrigem;
        aux.origem = &grafoBFS.vertices[nmrOrigem - 1];

        int nmrDestino;
        cin >> nmrDestino;
        aux.destino = &grafoBFS.vertices[nmrDestino - 1];

        cin >> aux.peso;
        aux.visitado = false;

        grafoBFS.arestas.push_back(aux);

        //adicionando adjacencia
        adj[aux.origem->numero - 1].push_back(*aux.destino);

        if(!grafoBFS.direcionado)
            adj[aux.destino->numero - 1].push_back(*aux.origem);
    }


    buscaLargura(&grafoBFS, adj, vInicial);

}


void buscaLargura(Bfs *grafoBFS, list<Vertice> *adj, int vInicial){
    //procurar a partir do inicial
    queue<int> listaDeEspera;
    vector<int> descobertos;
    
    listaDeEspera.push(vInicial);
    grafoBFS->vertices[vInicial-1].visitado = true;
    descobertos.push_back(vInicial);

    while(!listaDeEspera.empty()){
        int u = listaDeEspera.front();
        listaDeEspera.pop();
        for(Vertice &vertice : adj[u-1]){
            if(grafoBFS->vertices[vertice.numero - 1].visitado == false){
                listaDeEspera.push(vertice.numero);
                descobertos.push_back(vertice.numero);
                grafoBFS->vertices[vertice.numero - 1].visitado = true;
            }
        }
    }

    imprimirResultado(descobertos);
}



void imprimirResultado(vector<int> descobertos){
    for(auto &item : descobertos){
        cout << item << endl;
    }
}