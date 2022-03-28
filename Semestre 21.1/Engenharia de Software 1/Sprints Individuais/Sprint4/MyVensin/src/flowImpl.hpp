//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

class System;
#include "flow.hpp"

using namespace std;
//! Class FlowImpl
/**
* Essa classe representa um flow de um "modelo" de sistema do código.
*/
class FlowImpl : public Flow{

    string nome; /*!< Esse atributo contem um nome para o flow.*/
    System *origem; /*!< Esse atributo contem um ponteiro o sistema origem do flow.*/
    System *destino; /*!< Esse atributo contem um ponteiro o sistema destino do flow.*/
    
    public:
    /*!
        Construtor mais elaborado para a classe FlowImpl.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do Flow.
        \param destino a pointer to the target system of the Flow.
        \return Flow - Um objeto da classe Flow.
    */

    FlowImpl(string nome = "", System* origem = NULL, System* destino = NULL );

    virtual ~FlowImpl();

    /*!< Um metodo virtual puro que será herdado pelas subclasses criadas pelo usuario, e irar conter a equacao
    *    que será executada pelo model
    */
    virtual double run() = 0;


    /*!
        Retorna o atributo nome do objeto da classe FlowImpl.
        \return string - o conteúdo de atributo nome.
    */
    string getNome() const;

    /*!
        Seta o atributo nome do objeto da classe FlowImpl.
        \param nome que será setado ao flow atual.
    */
    void setNome(string nome);

    /*!
        Retorna o atributo *origem do objeto da classe FlowImpl.
        \return System* - o ponteiro do sistema de origem.
    */
    System* getOrigem() const;

    /*!
        Seta o atributo *origem do objeto da classe FlowImpl.
        \param origem que será setado ao flow atual.
    */
    void setOrigem(System* origem);

    /*!
        Retorna o atributo *destino do objeto da classe FlowImpl.
        \return System* - o ponteiro do sistema de saída.
    */
    System* getDestino() const;

    /*!
        Seta o atributo *destino do objeto da classe FlowImpl.
        \param destino que será setado ao flow atual.
    */
    void setDestino(System* destino);
     

    /*! Limpa o campo de sistema de origem do Flow atual*/
    void limparOrigem();

    /*! Limpa o campo de sistema de destino do Flow atual*/
    void limparDestino();

    /*! Construtor de copia*/
    FlowImpl(const Flow& flow);

    /*! Sobrecarga do operador = para a classe FlowImpl*/
    FlowImpl& operator=(const Flow& flow);

};



#endif
