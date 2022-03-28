//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef SYSTEMIMPL_HPP
#define SYSTEMIMPL_HPP

#include "system.hpp"
#include "handleBodySemDebug.h"

using namespace std;

//! Class SystemBody
/**
* Essa classe representa um sistema de um "modelo" de sistema do código.
*/
class SystemBody : public Body{
    protected:
     
    string nome; /*!< Esse atributo contem um nome para o SystemBody.*/
    double valorInicial; /*!< Esse atributo contem um valor inicial para o SystemBody.*/
    
    private:
    /*! Sobrecarga do contrutor para a classe Sistema */
    SystemBody(const SystemBody& sys);

    /*! Sobrecarga do operador = para a classe Sistema */
    SystemBody& operator=(const SystemBody& sistema);
    
    public:
    
    /*!
        Construtor mais elaborado para a classe SystemBody.
        \param nome nome para o sistema
        \param valorIni valor inicial para o sistema.
        \return SystemBody - Um objeto da classe SystemBody.
    */
    SystemBody(string nome = "", double valorIni = 0.0) ;

    /*!
        Esse é o destrutor padrão da classe SystemBody;
    */
    virtual ~SystemBody();

    /*!
        Retorna o atributo nome do objeto da classe System.
        \return string - o conteúdo de atributo nome.
    */
    string getNome() const;

    /*!
        Seta o atributo nome do objeto da classe System.
        \param nome que será setado ao Sistema atual.
    */
    void setNome(string nome);

    /*!
        Retorna o atributo valorInicial do objeto da classe Sistema.
        \return double - o conteúdo de atributo valorInicial.
    */
    double getValorInicial() const;

    /*!
        Seta o atributo valorInicial do objeto da classe Sistema.
        \param valorIni que será setado ao Sistema atual.
    */
    void setValorInicial(double valorInicial);
    
    /*!
        Essa é a sobrecarga do operador "+" para a classe System.
    */
    double operator+(const System& sys);
        
    /*!
        Essa é a sobrecarga do operador "+" para a classe SystemBody.
    */
    double operator+(const double& valueSys);

    /*!
        Essa é a sobrecarga do operador "-" para a classe SystemBody.
    */
    double operator-(const System& sys);
        
    /*!
        Essa é a sobrecarga do operador "-" para a classe SystemBody.
    */
    double operator-(const double& valueSys);

    /*!
        Essa é a sobrecarga do operador "*" para a classe SystemBody.
    */
    double operator*(const System& sys);
        
    /*!
        Essa é a sobrecarga do operador "*" para a classe SystemBody.
    */
    double operator*(const double& valueSys);

    /*!
        Essa é a sobrecarga do operador "/" para a classe SystemBody.
    */
    double operator/(const System& sys);
        
    /*!
        Essa é a sobrecarga do operador "/" para a classe SystemBody.
    */
    double operator/(const double& valueSys); 


};

class SystemHandle : public Handle<SystemBody>, public System{
    public:

    SystemHandle(string nome = "", double valorInicial = 0.0){
        pImpl_->setNome(nome);
        pImpl_->setValorInicial(valorInicial);
    }

    virtual ~SystemHandle(){};

    void setNome(string nome){
        pImpl_->setNome(nome);
    }

    string getNome() const{
        return pImpl_->getNome();
    }

    void setValorInicial(double valorInicial){
        pImpl_->setValorInicial(valorInicial);
    }

    double getValorInicial() const{
        return pImpl_->getValorInicial();
    }

    /*!
        Essa é a sobrecarga do operador "+" para a classe System.
    */
    double operator+(const System& sys){
        if(this == &sys)
            return 2.0 * pImpl_->getValorInicial();
        return pImpl_->operator+(sys);
    }
        
    /*!
        Essa é a sobrecarga do operador "+" para a classe SystemBody.
    */
    double operator+(const double& valueSys){
        return pImpl_->operator+(valueSys);
    }

    /*!
        Essa é a sobrecarga do operador "-" para a classe SystemBody.
    */
    double operator-(const System& sys){
        if(this == &sys)
            return 0.0;
        return pImpl_->operator-(sys);
    }
        
    /*!
        Essa é a sobrecarga do operador "-" para a classe SystemBody.
    */
    double operator-(const double& valueSys){
        return pImpl_->operator-(valueSys);
    }

    /*!
        Essa é a sobrecarga do operador "*" para a classe SystemBody.
    */
    double operator*(const System& sys){
        if(this == &sys)
            return pImpl_->getValorInicial() * pImpl_->getValorInicial();
        return pImpl_->operator*(sys);
    }
        
    /*!
        Essa é a sobrecarga do operador "*" para a classe SystemBody.
    */
    double operator*(const double& valueSys){
        return pImpl_->operator*(valueSys);
    }

    /*!
        Essa é a sobrecarga do operador "/" para a classe SystemBody.
    */
    double operator/(const System& sys){
        if(this == &sys)
            return 1.0;
        return pImpl_->operator/(sys);
    }
        
    /*!
        Essa é a sobrecarga do operador "/" para a classe SystemBody.
    */
    double operator/(const double& valueSys){
        return pImpl_->operator/(valueSys);
    }

   
};



double operator+(const double& valueSys, const System& sys);
double operator-(const double& valueSys, const System& sys);
double operator*(const double& valueSys, const System& sys);
double operator/(const double& valueSys, const System& sys);

#endif
