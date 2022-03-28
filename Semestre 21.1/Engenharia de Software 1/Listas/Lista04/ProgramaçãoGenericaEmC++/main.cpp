#include "Estudante.hpp"
#include "Disciplina.hpp"
#include "ConjNaoOrdenado.hpp"
#include "ConjOrdenado.hpp"
#include "Funcoes.hpp"

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <assert.h>
#include <typeinfo>
#include <algorithm>

using namespace std;

#define TEST

#ifdef TEST

int main(){

    //Criando instancias da classe Estudante
    Estudante e("Joao", "19.2.0001", 8.5);
    Estudante e2("Maria", "19.2.0002", 6.5);
    Estudante e3("Pedro", "19.2.0003", 7.5);
    
    assert(e.getMatricula() != "");
    assert(e.getNome() != "");
    assert(e.getNota() == 8.5);
    cout << "Classe Estudante funcionando corretamente\n";

    //Criando instancias da classe Disciplina
    Disciplina d("Programacao I",40);
    Disciplina d2("Algoritmos",60);
    Disciplina d3("Banco de Dados",30);
    
    assert(d.getNome() != "");
    assert(d.getCargaHoraria() == 0);
    cout << "Classe Disciplina funcionando corretamente\n";

    //Testando template Desordenada com classe Estudante
    ConjNaoOrdenado<Estudante> listaEstudantesDesord;
    listaEstudantesDesord.inserir(e);
    listaEstudantesDesord.inserir(e2);
    listaEstudantesDesord.inserir(e3);
    assert(listaEstudantesDesord[0].getNota() == 8.5);
    assert(listaEstudantesDesord[0].getNome() == "Joao");
    assert(listaEstudantesDesord[0].getMatricula() == "19.1.0001");
    cout << "Template Desordenada funcionando corretamente\n";

    //Testando template Desordenada com classe Estudante
    ConjOrdenado<Estudante> listaEstudantesOrd;
    listaEstudantesOrd.inserir(2, e);
    listaEstudantesOrd.inserir(3, e2);
    listaEstudantesOrd.inserir(1, e3);
    assert(listaEstudantesOrd[0].getNota() == 7.5);
    assert(listaEstudantesOrd[0].getNome() == "Pedro");
    assert(listaEstudantesOrd[0].getMatricula() == "19.1.0003");
    cout << "Template Desordenada funcionando corretamente\n";


    //Testando template Ordenada com a classe Disciplina
    ConjOrdenado<Disciplina> listaDisciplinaOrd;
    listaDisciplinaOrd.inserir(2, d);
    listaDisciplinaOrd.inserir(3, d2);
    listaDisciplinaOrd.inserir(1, d3);
    assert(listaDisciplinaOrd[0].getCargaHoraria() == 30);
    assert(listaDisciplinaOrd[0].getNome() == "Banco de Dados");
    cout << "Template Ordenada funcionando corretamente\n";

    //Testando template Desordenada com a classe Disciplina
    ConjNaoOrdenado<Disciplina> listaDisciplinaDesord;
    listaDisciplinaDesord.inserir(d);
    listaDisciplinaDesord.inserir(d2);
    listaDisciplinaDesord.inserir(d3);
    assert(listaDisciplinaDesord[0].getCargaHoraria() == 40);
    assert(listaDisciplinaDesord[0].getNome() == "Programacao I");
    cout << "Template Ordenada funcionando corretamente\n\n";

    assert(count(listaDisciplinaDesord, (float)9) == 2);
    assert(sum(listaDisciplinaDesord) == (float)34);
    assert(average(listaDisciplinaDesord) == (float)6.8);
    return 0;
}

#else
int main(){

    //Criando instancias da classe Estudante
    Estudante e("Joao", "19.2.0001", 8.5);
    Estudante e2("Maria", "19.2.0002", 6.5);
    Estudante e3("Pedro", "19.2.0003", 7.5);

    //Criando instancias da classe Disciplina
    Disciplina d("Programacao I",40);
    Disciplina d2("Algoritmos",60);
    Disciplina d3("Banco de Dados",30);

    //Testando template Desordenada com classe Estudante
    ConjNaoOrdenado<Estudante> listaEstudantesDesord;
    listaEstudantesDesord.inserir(e);
    listaEstudantesDesord.inserir(e2);
    listaEstudantesDesord.inserir(e3);

    //Testando template Desordenada com classe Estudante
    ConjNaoOrdenado<Estudante> listaEstudantesOrd;
    listaEstudantesOrd.inserir(2, e);
    listaEstudantesOrd.inserir(3, e2);
    listaEstudantesOrd.inserir(1, e3);


    //Testando template Ordenada com a classe Disciplina
    ConjNaoOrdenado<Disciplina> listaDisciplinaOrd;
    listaDisciplinaOrd.inserir(2, d);
    listaDisciplinaOrd.inserir(3, d2);
    listaDisciplinaOrd.inserir(1, d3);

    //Testando template Desordenada com a classe Disciplina
    ConjNaoOrdenado<Disciplina> listaDisciplinaDesord;
    listaDisciplinaDesord.inserir(d);
    listaDisciplinaDesord.inserir(d2);
    listaDisciplinaDesord.inserir(d3);

   
    return 0;
}

#endif