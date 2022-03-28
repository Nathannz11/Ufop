//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "system.hpp"

System :: System(string name, double valorIni) : nome(name), valorInicial(valorIni){};

System :: ~System(){};

string System :: getNome() const{
    return this->nome;
}
void System :: setNome(string nome){
    this->nome = nome;
}

double System :: getValorInicial() const{
    return this->valorInicial;
}
void System :: setValorInicial(double valorInicial){
    this->valorInicial = valorInicial;
}


System::System(const System& sys){
    if (this == &sys){
        return;
    }
            
    nome = sys.getNome();
    valorInicial = sys.getValorInicial();
}


System& System :: operator=(const System& sistema){
    if (this == &sistema){
        return *this;
    }

    this->nome = sistema.getNome();
    this->valorInicial = sistema.getValorInicial();  

    return *this;
}