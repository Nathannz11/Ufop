//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef SYSTEMIMPL_HPP
#define SYSTEMIMPL_HPP

#include "system.hpp"

using namespace std;

//! Class SystemImpl
/**
* Essa classe representa um sistema de um "modelo" de sistema do código.
*/
class SystemImpl : public System{
    protected:
     
    string nome; /*!< Esse atributo contem um nome para o sistemaImpl.*/
    double valorInicial; /*!< Esse atributo contem um valor inicial para o sistemaImpl.*/

    public:
    
    /*!
        Construtor mais elaborado para a classe SystemImpl.
        \param nome nome para o sistema
        \param valorIni valor inicial para o sistema.
        \return SystemImpl - Um objeto da classe SystemImpl.
    */
    SystemImpl(string nome = "", double valorIni = 0.0) ;

    /*!
        Esse é o destrutor padrão da classe SystemImpl;
    */
    virtual ~SystemImpl();

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
    

    /*! Sobrecarga do contrutor para a classe Sistema */
    SystemImpl(const SystemImpl& sys);

    /*! Sobrecarga do operador = para a classe Sistema */
    SystemImpl& operator=(const SystemImpl& sistema);

    /*!
        Essa é a sobrecarga do operador "+" para a classe System.
    */
    double operator+(const SystemImpl& sys);
        
    /*!
        Essa é a sobrecarga do operador "+" para a classe SystemImpl.
    */
    double operator+(const double& valueSys);

    /*!
        Essa é a sobrecarga do operador "-" para a classe SystemImpl.
    */
    double operator-(const SystemImpl& sys);
        
    /*!
        Essa é a sobrecarga do operador "-" para a classe SystemImpl.
    */
    double operator-(const double& valueSys);

    /*!
        Essa é a sobrecarga do operador "*" para a classe SystemImpl.
    */
    double operator*(const SystemImpl& sys);
        
    /*!
        Essa é a sobrecarga do operador "*" para a classe SystemImpl.
    */
    double operator*(const double& valueSys);

    /*!
        Essa é a sobrecarga do operador "/" para a classe SystemImpl.
    */
    double operator/(const SystemImpl& sys);
        
    /*!
        Essa é a sobrecarga do operador "/" para a classe SystemImpl.
    */
    double operator/(const double& valueSys); 
     
};

double operator+(const double& valueSys, const SystemImpl& sys);
double operator-(const double& valueSys, const SystemImpl& sys);
double operator*(const double& valueSys, const SystemImpl& sys);
double operator/(const double& valueSys, const SystemImpl& sys);

#endif
