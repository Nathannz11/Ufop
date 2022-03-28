//Aluno: Nathann Zini Dos Reis
//Matricula: 19.2.4007

#ifndef UNIT_SYSTEM_HPP
#define UNIT_SYSTEM_HPP

#include "../../src/include/systemImpl.hpp"

//! Unit tests 
/**
* Criacao dos unit tests para a classe System.
*/
class UnitSystem{
    public:
        UnitSystem(){}
        ~UnitSystem(){}
        
        /*!
        Prototipo de funcao para a classe System' Copia do contrutor unit test.
        */
        void unit_system_copy_constructor();
        /*!
        Prototipo de funcao para a classe System' atribuicao do operador unit test.
        */
        void unit_system_assingmentOperator();
};

/*!
  Prototipo de funcao para a classe System' construtor unit test.
*/
void unit_system_constructor();

/*!
  Prototipo de funcao para a classe System' destrutor unit test.
*/
void unit_system_destructor();

/*!
  Prototipo de funcao para a classe System' metodo getNome() unit test.
*/
void unit_system_getNome();

/*!
  Prototipo de funcao para a classe System' metodo setNome() unit test.
*/
void unit_system_setNome();

/*!
  Prototipo de funcao para a classe System' metodo getValorinicial() unit test.
*/
void unit_system_getValorInicial();

/*!
  Prototipo de funcao para a classe System' metodo setValorInicial() unit test.
*/
void unit_system_setValorInicial();

/*!
  Prototipo de funcao para a classe System' "+" operador unit test.
*/
void unit_system_sumOperator();

/*!
  Prototipo de funcao para a classe System' "-" operador unit test.
*/
void unit_system_minusOperator();

/*!
  Prototipo de funcao para a classe System' "*" operador unit test.
*/
void unit_system_timesOperator();

/*!
  Prototipo de funcao para a classe System' "/" operador unit test.
*/
void unit_system_divisionOperator();

/*!
    Prototipo de funcao que executa todos os unit tests da classe System.
*/
void run_unit_tests_system();

#endif