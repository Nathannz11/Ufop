//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#ifndef FUNCTIONAL_TEST
#define FUNCTIONAL_TEST

#include "../../src/systemImpl.hpp"
#include "../../src/flowImpl.hpp"
class Model;



using namespace std;
//! Functional tests
/**
* Impelemtacao do teste funcional para as classes Flow, System e Model.
*/

/*!
  Prototipo de funcao para teste funcional de flow exponencial.
*/
void exponentialFuncionalTest();

/*!
  Prototipo de funcao para teste funcional de flow Logico.
*/
void logisticalFuncionalTest();

/*!
  Prototipo de funcao para teste funcional de flow Complexo.
*/
void complexFuncionalTest();

//! Class FlowExponencial
/**
* Essa classe representa um flow exponencial com crescimento ilimitado de um "modelo" de sistema do código.
*/
class FlowExponencial : public FlowImpl{
    public:
        /*!
        Construtor mais elaborado para a classe FlowExponencial.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do FlowExponencial.
        \param destino a pointer to the target system of the FlowExponencial.
        */
        FlowExponencial(string nome = "", System* origem = NULL, System* destino = NULL): FlowImpl(nome, origem, destino){}

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
class FlowLogistico : public FlowImpl{
    public:
        /*!
        Construtor mais elaborado para a classe FlowLogistico.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do FlowLogistico.
        \param destino a pointer to the target system of the FlowLogistico.
        */
        FlowLogistico(string nome, System* origem, System* destino): FlowImpl(nome, origem, destino){}
        /**
         Um metodo criado pelo usuaria que contem uma equacao que sera executada pelo modelo Logico
        */
        double run(){
            return 0.01 * getDestino()->getValorInicial() * (1 - getDestino()->getValorInicial() / 70);
        }
};

class FlowComplexo : public FlowImpl{
    public:
        /*!
        Construtor mais elaborado para a classe FlowComplexo.
        \param nome nome para o flow
        \param origem ponteiro para o sistema origem do FlowComplexo.
        \param destino a pointer to the target system of the FlowComplexo.
        */
        FlowComplexo(string nome = "", System* origem = NULL, System* destino = NULL): FlowImpl(nome, origem, destino){}

        //! Class FlowComplexo
        /**
         Um metodo criado pelo usuaria que contem uma equacao que sera executada pelo modelo Complexo
        */
        double run(){
            return 0.01 * getOrigem()->getValorInicial();
        }
};


#endif