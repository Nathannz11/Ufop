//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "systemImpl.hpp"

SystemImpl :: SystemImpl(string name, double valorIni) : nome(name), valorInicial(valorIni){};

SystemImpl :: ~SystemImpl(){};

string SystemImpl :: getNome() const{
    return this->nome;
}
void SystemImpl :: setNome(string nome){
    this->nome = nome;
}

double SystemImpl :: getValorInicial() const{
    return this->valorInicial;
}
void SystemImpl :: setValorInicial(double valorInicial){
    this->valorInicial = valorInicial;
}


SystemImpl::SystemImpl(const SystemImpl& sistema){
    if (this == &sistema){
        return;
    }
            
    nome = sistema.getNome();
    valorInicial = sistema.getValorInicial();
}

double SystemImpl::operator+(const SystemImpl& sistema){
    if (this == &sistema){
        return 2.0 * getValorInicial();
    }

    return getValorInicial() + sistema.getValorInicial();
}

double SystemImpl::operator+(const double& valueSys){
    return valueSys + getValorInicial();
}


double operator+(const double& valueSys, const SystemImpl& sys){
    return sys.getValorInicial() + valueSys;
}

double  SystemImpl::operator-(const SystemImpl& sys){
    if (this == &sys){
        return 0.0;
    }

    return getValorInicial() - sys.getValorInicial();
}

double SystemImpl::operator-(const double& valueSys){
    return getValorInicial() - valueSys;
}

double operator-(const double& valueSys, const SystemImpl& sys){
    return valueSys - sys.getValorInicial();
}

double SystemImpl::operator*(const SystemImpl& sys){
    if (this == &sys){
        return getValorInicial() * sys.getValorInicial();
    }

    return getValorInicial() * sys.getValorInicial();
}

double SystemImpl::operator*(const double& valueSys){
    return getValorInicial() * valueSys;
}

double operator*(const double& valueSys, const SystemImpl& sys){
    return valueSys * sys.getValorInicial();
}

double SystemImpl::operator/(const SystemImpl& sys){
    if (this == &sys){
        return 1.0;
    }

    return getValorInicial() / sys.getValorInicial();
}

double SystemImpl::operator/(const double& valueSys){
    return getValorInicial() / valueSys;
}

double operator/(const double& valueSys, const SystemImpl& sys){
    return valueSys / sys.getValorInicial();
}


SystemImpl& SystemImpl :: operator=(const SystemImpl& sistema){
    if (this == &sistema){
        return *this;
    }

    this->nome = sistema.getNome();
    this->valorInicial = sistema.getValorInicial();  

    return *this;
}