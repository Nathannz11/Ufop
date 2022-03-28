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
    protected:
     
    string nome; /*!< Esse atributo contem um nome para o sistema.*/
    double valorInicial; /*!< Esse atributo contem um valor inicial para o sistema.*/

    public:
    
    /*!
        Construtor mais elaborado para a classe System.
        \param nome nome para o sistema
        \param valorIni valor inicial para o sistema.
        \return System - Um objeto da classe System.
    */
    System(string nome = "", double valorIni = 0.0) ;

    virtual ~System();

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
    

    System(const System& sys);
    /*! Sobrecarga do operador = para a classe Sistema */
    System& operator=(const System& sistema);
     
};

#endif
