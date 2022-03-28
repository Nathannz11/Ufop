//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <iostream>

using namespace std;

//! Class System
/**
* Essa classe representa um sistema de um "modelo" de sistema do código.
*/
class System{
    

    public: 
    
    virtual ~System(){}

    /*!
        Retorna o atributo nome do objeto da classe System.
        \return string - o conteúdo de atributo nome.
    */
    virtual string getNome() const = 0;

    /*!
        Seta o atributo nome do objeto da classe System.
        \param nome que será setado ao Sistema atual.
    */
    virtual void setNome(string nome) = 0;

    /*!
        Retorna o atributo valorInicial do objeto da classe Sistema.
        \return double - o conteúdo de atributo valorInicial.
    */
    virtual double getValorInicial() const = 0;

    /*!
        Seta o atributo valorInicial do objeto da classe Sistema.
        \param valorIni que será setado ao Sistema atual.
    */
    virtual void setValorInicial(double valorInicial) = 0;
    
    /*!
        Essa é a sobrecarga do operador "+" para a classe System.
    */
    virtual double operator+(const System& sys) = 0;
        
    /*!
        Essa é a sobrecarga do operador "+" para a classe System.
    */
    virtual double operator+(const double& valueSys) = 0;

    /*!
        Essa é a sobrecarga do operador "-" para a classe System.
    */
    virtual double operator-(const System& sys) = 0;
        
    /*!
        Essa é a sobrecarga do operador "-" para a classe System.
    */
    virtual double operator-(const double& valueSys) = 0;

    /*!
        Essa é a sobrecarga do operador "*" para a classe System.
    */
    virtual double operator*(const System& sys) = 0;
        
    /*!
        Essa é a sobrecarga do operador "*" para a classe System.
    */
    virtual double operator*(const double& valueSys) = 0;

    /*!
        Essa é a sobrecarga do operador "/" para a classe System.
    */
    virtual double operator/(const System& sys) = 0;
        
    /*!
        Essa é a sobrecarga do operador "/" para a classe System.
    */
    virtual double operator/(const double& valueSys) = 0; 


};

double operator+(const double& valueSys, const System& sys);
double operator-(const double& valueSys, const System& sys);
double operator*(const double& valueSys, const System& sys);
double operator/(const double& valueSys, const System& sys);


#endif
