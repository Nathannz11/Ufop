//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef FLOWIMPL_HPP
#define FLOWIMPL_HPP

class System;
#include "flow.hpp"
#include "handleBodySemDebug.h"

using namespace std;
//! Class FlowBody
/**
* Essa classe representa um flow de um "modelo" de sistema do código.
*/
class FlowBody : public Body{

    string nome; /*!< Esse atributo contem um nome para o flow.*/
    System *origem; /*!< Esse atributo contem um ponteiro o sistema origem do flow.*/
    System *destino; /*!< Esse atributo contem um ponteiro o sistema destino do flow.*/
    
    private:

    /*! Construtor de copia*/
    FlowBody(const Flow& flow);

    /*! Sobrecarga do operador = para a classe FlowBody*/
    FlowBody& operator=(const Flow& flow);

    public:
    /*!
        Construtor mais elaborado para a classe FlowBody.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do Flow.
        \param destino a pointer to the target system of the Flow.
        \return Flow - Um objeto da classe Flow.
    */

    FlowBody(string nome = "", System* origem = NULL, System* destino = NULL );

    virtual ~FlowBody();

    /*!< Um metodo virtual puro que será herdado pelas subclasses criadas pelo usuario, e irar conter a equacao
    *    que será executada pelo model
    */
    virtual double run() = 0;


    /*!
        Retorna o atributo nome do objeto da classe FlowBody.
        \return string - o conteúdo de atributo nome.
    */
    string getNome() const;

    /*!
        Seta o atributo nome do objeto da classe FlowBody.
        \param nome que será setado ao flow atual.
    */
    void setNome(string nome);

    /*!
        Retorna o atributo *origem do objeto da classe FlowBody.
        \return System* - o ponteiro do sistema de origem.
    */
    System* getOrigem() const;

    /*!
        Seta o atributo *origem do objeto da classe FlowBody.
        \param origem que será setado ao flow atual.
    */
    void setOrigem(System* origem);

    /*!
        Retorna o atributo *destino do objeto da classe FlowBody.
        \return System* - o ponteiro do sistema de saída.
    */
    System* getDestino() const;

    /*!
        Seta o atributo *destino do objeto da classe FlowBody.
        \param destino que será setado ao flow atual.
    */
    void setDestino(System* destino);
     

    /*! Limpa o campo de sistema de origem do Flow atual*/
    void limparOrigem();

    /*! Limpa o campo de sistema de destino do Flow atual*/
    void limparDestino();

    

};

//! Class FlowHandle
/**
* Essa classe representa o handle do Handle/Body do Flow.
*/
template <typename F_IMPL>
class FlowHandle : public Handle<F_IMPL>, public Flow{


    public:
    /*!
        Construtor mais elaborado para a classe FlowHandle.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do Flow.
        \param destino a pointer to the target system of the Flow.
        \return Flow - Um objeto da classe Flow.
    */

    FlowHandle<F_IMPL>(string nome = "", System* origem = NULL, System* destino = NULL ){
        this->pImpl_->setNome(nome);
        this->pImpl_->setOrigem(origem);
        this->pImpl_->setDestino(destino);
    }

    virtual ~FlowHandle(){};

    /*!< Um metodo virtual puro que será herdado pelas subclasses criadas pelo usuario, e irar conter a equacao
    *    que será executada pelo model
    */
    double run(){
        return this->pImpl_->run();
    }


    /*!
        Retorna o atributo nome do objeto da classe FlowHandle.
        \return string - o conteúdo de atributo nome.
    */
    string getNome() const{
        return this->pImpl_->getNome();
    }

    /*!
        Seta o atributo nome do objeto da classe FlowHandle.
        \param nome que será setado ao flow atual.
    */
    void setNome(string nome){
        this->pImpl_->setNome(nome);
    }

    /*!
        Retorna o atributo *origem do objeto da classe FlowHandle.
        \return System* - o ponteiro do sistema de origem.
    */
    System* getOrigem() const{
        return this->pImpl_->getOrigem();
    }

    /*!
        Seta o atributo *origem do objeto da classe FlowHandle.
        \param origem que será setado ao flow atual.
    */
    void setOrigem(System* origem){
        this->pImpl_->setOrigem(origem);
    }

    /*!
        Retorna o atributo *destino do objeto da classe FlowHandle.
        \return System* - o ponteiro do sistema de saída.
    */
    System* getDestino() const{
        return this->pImpl_->getDestino();
    }

    /*!
        Seta o atributo *destino do objeto da classe FlowHandle.
        \param destino que será setado ao flow atual.
    */
    void setDestino(System* destino){
        this->pImpl_->setDestino(destino);
    }
     

    /*! Limpa o campo de sistema de origem do Flow atual*/
    void limparOrigem(){
        this->pImpl_->limparOrigem();
    }

    /*! Limpa o campo de sistema de destino do Flow atual*/
    void limparDestino(){
        this->pImpl_->limparDestino();
    }


};


#endif
