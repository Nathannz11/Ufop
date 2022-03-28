//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef FLOW_HPP
#define FLOW_HPP

#include "system.hpp"
#include <string>

using namespace std;
//! Class Flow
/**
* Essa classe representa um flow de um "modelo" de sistema do código.
*/
class Flow{

    string nome; /*!< Esse atributo contem um nome para o flow.*/
    System *origem; /*!< Esse atributo contem um ponteiro o sistema origem do flow.*/
    System *destino; /*!< Esse atributo contem um ponteiro o sistema destino do flow.*/
    
    public:
    /*!
        Construtor mais elaborado para a classe Flow.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do Flow.
        \param destino a pointer to the target system of the Flow.
        \return Flow - Um objeto da classe Flow.
    */

    Flow(string nome = "", System* origem = NULL, System* destino = NULL  );

    virtual ~Flow();

    /*!< Um metodo virtual puro que será herdado pelas subclasses criadas pelo usuario, e irar conter a equacao
    *    que será executada pelo model
    */
    virtual double run() = 0;


    /*!
        Retorna o atributo nome do objeto da classe Flow.
        \return string - o conteúdo de atributo nome.
    */
    string getNome() const;

    /*!
        Seta o atributo nome do objeto da classe Flow.
        \param nome que será setado ao flow atual.
    */
    void setNome(string nome);

    /*!
        Retorna o atributo *origem do objeto da classe Flow.
        \return System* - o ponteiro do sistema de origem.
    */
    System* getOrigem() const;

    /*!
        Seta o atributo *origem do objeto da classe Flow.
        \param origem que será setado ao flow atual.
    */
    void setOrigem(System* origem);

    /*!
        Retorna o atributo *destino do objeto da classe Flow.
        \return System* - o ponteiro do sistema de saída.
    */
    System* getDestino() const;

    /*!
        Seta o atributo *destino do objeto da classe Flow.
        \param destino que será setado ao flow atual.
    */
    void setDestino(System* destino);
     

    /*! Limpa o campo de sistema de origem do Flow atual*/
    void limparOrigem();

    /*! Limpa o campo de sistema de destino do Flow atual*/
    void limparDestino();

    /*! Construtor de copia*/
    Flow(const Flow& flow);

    /*! Sobrecarga do operador = para a classe Flow*/
    Flow& operator=(const Flow& flow);

};

//! Class FlowExponencial
/**
* Essa classe representa um flow exponencial com crescimento ilimitado de um "modelo" de sistema do código.
*/
class FlowExponencial : public Flow{
    public:
        /*!
        Construtor mais elaborado para a classe Flow.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do Flow.
        \param destino a pointer to the target system of the Flow.
        */
        FlowExponencial(string nome = "", System* origem = NULL, System* destino = NULL): Flow(nome, origem, destino){}

        //! Class FlowExponencial
        /**
         Um metodo criado pelo usuaria que contem uma equacao que sera executada pelo modelo exponencial
        */
        double run(){
            return 0.01 * getOrigem()->getValorInicial();
        }
};

//! Class FlowLogico
/**
* Essa classe representa um flow Logico com crescimento limitado de um "modelo" de sistema do código.
*/
class FlowLogistico : public Flow{
    public:
        /*!
        Construtor mais elaborado para a classe Flow.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do Flow.
        \param destino a pointer to the target system of the Flow.
        */
        FlowLogistico(string nome, System* origem, System* destino): Flow(nome, origem, destino){}
        /**
         Um metodo criado pelo usuaria que contem uma equacao que sera executada pelo modelo Logico
        */
        double run(){
            return 0.01 * getDestino()->getValorInicial() * (1 - getDestino()->getValorInicial() / 70);
        }
};

class FlowComplexo : public Flow{
    public:
        /*!
        Construtor mais elaborado para a classe Flow.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do Flow.
        \param destino a pointer to the target system of the Flow.
        */
        FlowComplexo(string nome = "", System* origem = NULL, System* destino = NULL): Flow(nome, origem, destino){}

        //! Class FlowComplexo
        /**
         Um metodo criado pelo usuaria que contem uma equacao que sera executada pelo modelo Complexo
        */
        double run(){
            return 0.01 * getOrigem()->getValorInicial();
        }
};

#endif
