//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "../include/systemImpl.hpp"

SystemBody :: SystemBody(string name, double valorIni) : nome(name), valorInicial(valorIni){};

SystemBody :: ~SystemBody(){};

string SystemBody :: getNome() const{
    return this->nome;
}
void SystemBody :: setNome(string nome){
    this->nome = nome;
}

double SystemBody :: getValorInicial() const{
    return this->valorInicial;
}
void SystemBody :: setValorInicial(double valorInicial){
    this->valorInicial = valorInicial;
}

double SystemBody::operator+(const System& sistema){
    return getValorInicial() + sistema.getValorInicial();
}

double SystemBody::operator+(const double& valueSys){
    return valueSys + getValorInicial();
}


double operator+(const double& valueSys, const System& sys){
    return sys.getValorInicial() + valueSys;
}

double  SystemBody::operator-(const System& sys){
    return getValorInicial() - sys.getValorInicial();
}

double SystemBody::operator-(const double& valueSys){
    return getValorInicial() - valueSys;
}

double operator-(const double& valueSys, const System& sys){
    return valueSys - sys.getValorInicial();
}

double SystemBody::operator*(const System& sys){
    return getValorInicial() * sys.getValorInicial();
}

double SystemBody::operator*(const double& valueSys){
    return getValorInicial() * valueSys;
}

double operator*(const double& valueSys, const System& sys){
    return valueSys * sys.getValorInicial();
}

double SystemBody::operator/(const System& sys){
    return getValorInicial() / sys.getValorInicial();
}

double SystemBody::operator/(const double& valueSys){
    return getValorInicial() / valueSys;
}

double operator/(const double& valueSys, const System& sys){
    return valueSys / sys.getValorInicial();
}
/*
SystemBody::SystemBody(const SystemBody& sistema){
    if (this == &sistema){
        return;
    }
            
    nome = sistema.getNome();
    valorInicial = sistema.getValorInicial();
}

SystemBody& SystemBody :: operator=(const SystemBody& sistema){
    if (this == &sistema){
        return *this;
    }

    this->nome = sistema.getNome();
    this->valorInicial = sistema.getValorInicial();  

    return *this;
}
*/