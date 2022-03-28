//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef FLOW_HPP
#define FLOW_HPP

class System;
#include <string>

using namespace std;
//! Class Flow
/**
* Essa classe representa um flow de um "modelo" de sistema do código.
*/
class Flow{
    
    public:

    friend class Model; /*!< This Class represents a model in the General Systems Theory implemented in this code. */
    friend class ModelImpl; /*!< This Class represents a model in the General Systems Theory implemented in this code. */
    friend class UnitFlow;
    

    virtual ~Flow(){}

    /*!< Um metodo virtual puro que será herdado pelas subclasses criadas pelo usuario, e irar conter a equacao
    *    que será executada pelo model
    */
    virtual double run() = 0;


    /*!
        Retorna o atributo nome do objeto da classe Flow.
        \return string - o conteúdo de atributo nome.
    */
    virtual string getNome() const = 0;

    /*!
        Seta o atributo nome do objeto da classe Flow.
        \param nome que será setado ao flow atual.
    */
    virtual void setNome(string nome) = 0;

    /*!
        Retorna o atributo *origem do objeto da classe Flow.
        \return System* - o ponteiro do sistema de origem.
    */
    virtual System* getOrigem() const = 0;

    /*!
        Seta o atributo *origem do objeto da classe Flow.
        \param origem que será setado ao flow atual.
    */
    virtual void setOrigem(System* origem) = 0;

    /*!
        Retorna o atributo *destino do objeto da classe Flow.
        \return System* - o ponteiro do sistema de saída.
    */
    virtual System* getDestino() const = 0;

    /*!
        Seta o atributo *destino do objeto da classe Flow.
        \param destino que será setado ao flow atual.
    */
    virtual void setDestino(System* destino) = 0;
     

    /*! Limpa o campo de sistema de origem do Flow atual*/
    virtual void limparOrigem() = 0;

    /*! Limpa o campo de sistema de destino do Flow atual*/
    virtual void limparDestino() = 0;


};

#endif
