//Aluno: Nathann Zini Dos Reis
//Matricula: 19.2.4007

#include <assert.h>
#include "unit_system.hpp" 

using namespace std;

void unit_system_constructor(){
    cout << "TEST 1 - Construtor padrao da classe System sem passar parametros" << endl;
    
    System* system1 = new SystemImpl();
    //Assert para verificar se o System foi contruido com os valores padrão.
    assert(system1->getNome() == "");
    assert(system1->getValorInicial() == 0.0);

    cout << "OK!"<< endl;

    cout << "TEST 2 - Construtor padrao da classe System passando parametros" << endl; 
    
    System* system2 = new SystemImpl("Test System", 10.0);
    //Assert para verificar se o System foi contruido com os valores especificados.
    assert(system2->getNome() == "Test System");
    assert(system2->getValorInicial() == 10.0);

    cout << "OK!"<< endl;
}

void UnitSystem::unit_system_copy_constructor(){
    cout << "TEST 3 - Copia do construtor da Classe System" << endl;
    
    SystemImpl* system1 = new SystemImpl("Test System", 10.0);
    System* system2 = new SystemImpl(*system1);
    system1->setNome("Original Test System");
    system1->setValorInicial(20.0);

    //Assert para verificar se o contrutor de copia funcionou corretamente.
    assert(system2->getNome() == "Test System");
    assert(system2->getValorInicial() == 10.0);
    assert(system1 != system2);

    cout << "OK!"<< endl;
}

void unit_system_destructor(){}

void unit_system_getNome(){
    cout << "TEST 4 - metodo getNome() da classe System" << endl;
    
    System* system = new SystemImpl("Test System", 10.0);

    //Assert para verificar se a funcao getNome() funcinou corretamente.
    assert(system->getNome() == "Test System");

    cout << "OK!"<< endl;
}

void unit_system_setNome(){
    cout << "TEST 5 - metodo setNome() da classe System" << endl;
    
    System* system = new SystemImpl("Test System", 10.0);
    system->setNome("Altered Name");
    
    //Assert para verificar se a funcao setNome() funcinou corretamente.
    assert(system->getNome() == "Altered Name");

    cout << "OK!"<< endl;
}

void unit_system_getValorInicial(){
    cout << "TEST 6 - metodo getValorInicial() da classe System" << endl;

    System* system = new SystemImpl("Test System", 10.0);
    //Assert para verificar se a funcao getValorInicial() está funcionando corretamente.
    assert(system->getValorInicial() == 10.0);

    cout << "OK!"<< endl;
}

void unit_system_setValorInicial(){
    cout << "TEST 7 -  metodo setValorInicial() da classe System" << endl;

    System* system = new SystemImpl("Test System", 10.0);
    system->setValorInicial(20.0);
    
    //Assert para verificar se a funcao setValorInicial() está funcionando corretamente.
    assert(system->getValorInicial() == 20.0);

    cout << "OK!"<< endl;
}

void UnitSystem::unit_system_assingmentOperator(){
    cout << "TEST 8 - System class assignment operator" << endl;
    
    SystemImpl* system1 = new SystemImpl("Test System", 10.0);
    SystemImpl* system2 = new SystemImpl();
    *system2 = *system1;

    system1->setNome("Original Test System");
    system1->setValorInicial(100.0);

    //Assert para verificar se a atribuicao está funcionando corretamente
    assert(system2->getNome() == "Test System");
    assert(system2->getValorInicial() == 10.0);

    cout << "OK!"<< endl;
}

void unit_system_sumOperator(){
    SystemImpl* sys1 = new SystemImpl("Populacao 1", 100.0);
    SystemImpl* sys2 = new SystemImpl("Populacao 2", 10.0);

    cout << "TEST 9 - operador de soma da classe System" << endl;
    assert(((*sys1) + (*sys2)) == 110);
    assert(((*sys1) + 20.0) == 120);

    cout << "OK!"<< endl;
}

void unit_system_minusOperator(){
    SystemImpl* sys1 = new SystemImpl("Populacao 1", 100.0);
    SystemImpl* sys2 = new SystemImpl("Populacao 2", 10.0);

    cout << "TEST 10 - operador de subtracao da classe System" << endl;
    assert(((*sys1) - (*sys2)) == 90);
    assert(((*sys1) - 20.0) == 80);

    cout << "OK!"<< endl;
}


void unit_system_timesOperator(){
    SystemImpl* sys1 = new SystemImpl("Populacao 1", 100.0);
    SystemImpl* sys2 = new SystemImpl("Populacao 2", 10.0);

    cout << "TEST 11 - operador de multiplicacao da classe System" << endl;
    assert(((*sys1) * (*sys2)) == 1000);
    assert(((*sys1) * 20.0) == 2000);

    cout << "OK!"<< endl;
}

void unit_system_divisionOperator(){
    SystemImpl* sys1 = new SystemImpl("Populacao 1", 100.0);
    SystemImpl* sys2 = new SystemImpl("Populacao 2", 10.0);

    cout << "TEST 12 - operador de divisao da classe System" << endl;
    assert(((*sys1) / (*sys2)) == 10);
    assert(((*sys1) / 20.0) == 5);

    cout << "OK!"<< endl;
}

void run_unit_tests_system(){

    UnitSystem* unit_sys = new UnitSystem();

    unit_system_constructor();
    unit_sys->unit_system_copy_constructor();
    unit_system_destructor();
    unit_system_getNome();
    unit_system_setNome();
    unit_system_getValorInicial();
    unit_system_setValorInicial();
    unit_sys->unit_system_assingmentOperator();
    unit_system_sumOperator();
    unit_system_minusOperator();
    unit_system_timesOperator();
    unit_system_divisionOperator();

    delete(unit_sys);
}