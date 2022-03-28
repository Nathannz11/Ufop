//Aluno: Nathann Zini Dos Reis
//Matricula: 19.2.4007

#ifndef UNIT_FLOW_HPP
#define UNIT_FLOW_HPP

#include "../../src/include/systemImpl.hpp"
#include "../../src/include/flowImpl.hpp"

class SystemImpl;

using namespace std;

//! Unit tests 
/**
* Criacao do unit tests para a classe Flow.
*/
class UnitFlow{

    public:
        UnitFlow(){}
        ~UnitFlow(){}
        
        /*!
          prototipo de funcao para a classe Flow' construtor de copia unit test.
        */
        void unit_flow_copy_constructor();
        /*!
          prototipo de funcao para a classe Flow' atrubuicao de operador unit test.
        */
        void unit_flow_assingmentOperator();

};

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

/*!
  prototipo de funcao para a classe Flow' construtor unit test.
*/
void unit_flow_constructor();

/*!
  prototipo de funcao para a classe Flow' destrutor unit test.
*/
void unit_flow_destructor();

/*!
  prototipo de funcao para a classe Flow' metodo getName() unit test.
*/
void unit_flow_getNome();

/*!
  prototipo de funcao para a classe Flow' metodo setName() unit test.
*/
void unit_flow_setNome();

/*!
  prototipo de funcao para a classe Flow' metodo getOrigem() unit test.
*/
void unit_flow_getOrigem();

/*!
  prototipo de funcao para a classe Flow' metodo setOrigem() unit test.
*/
void unit_flow_setOrigem();

/*!
  prototipo de funcao para a classe Flow' metodo limparOrigem() unit test.
*/
void unit_flow_limparOrigem();

/*!
  prototipo de funcao para a classe Flow' metodo getDestino() unit test.
*/
void unit_flow_getDestino();

/*!
  prototipo de funcao para a classe Flow' metodo setDestino() unit test.
*/
void unit_flow_setDestino();

/*!
  prototipo de funcao para a classe Flow' metodo limparDestino() unit test.
*/
void unit_flow_limparDestino();

/*!
  prototipo de funcao para a classe Flow' metodo run() unit test.
*/
void unit_flow_run();

/*!
  Prototipo de funcao que executa todos os teste unitario da classe flow.
*/
void run_unit_tests_flow();

#endif