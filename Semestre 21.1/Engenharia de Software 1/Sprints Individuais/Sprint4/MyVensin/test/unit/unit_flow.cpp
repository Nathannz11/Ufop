//Aluno: Nathann Zini Dos Reis
//Matricula: 19.2.4007

#include "unit_flow.hpp"
#include <assert.h>


void unit_flow_constructor() {
    cout << "TEST 1 - Construtor padrao da classe flow sem parametros" << endl;

    FlowExponencial* flow1 = new FlowExponencial();
    
    //Assert para verificar se os parametros foram inicializado com os valores padrão
    assert(flow1->getNome() == "");
    assert(flow1->getOrigem() == NULL);
    assert(flow1->getDestino() == NULL);

    cout << "OK!" <<  endl;

    cout << "TEST 2 - Construtor padrao da classe flow com parametros" << endl;

    System* origem = new SystemImpl("Test System 1", 5.0);
    System* destino = new SystemImpl("Test System 2", 10.0);

    FlowExponencial* flow2 = new FlowExponencial("Flow 2", origem, destino);
    
    //Assert para verificar se os parametros foram inicializados com os valores especificados
    assert(flow2->getNome() == "Flow 2");
    assert(flow2->getOrigem() == origem);
    assert(flow2->getDestino() == destino);

    cout << "OK!" << endl;
}

void UnitFlow::unit_flow_copy_constructor() { 
    cout << "TEST 3 - Contrutor de copia da classe Flow" << endl;

    System* sys1 = new SystemImpl("Sys 1", 5.0);
    System* sys2 = new SystemImpl("Sys 2", 6.0);

    FlowExponencial* flow1 = new FlowExponencial("Flow 1");
    Flow* flow2 = new FlowExponencial(*flow1); 

    flow1->setNome("Original Flow 1");
    flow1->setOrigem(sys1);
    flow1->setDestino(sys2);
    
    //Assert para verificar se o construtor de cópia estar funcionando corretamente
    assert(flow2->getNome() == "Flow 1");
    assert(flow2->getOrigem() == NULL); 
    assert(flow2->getDestino() == NULL);

    cout << "OK!" << endl;
} 

void unit_flow_destructor(){}

void unit_flow_getNome() {
    cout << "TEST 5 - metodo GetNome() da classe Flow" << endl;
    
    FlowExponencial* flow = new FlowExponencial("Flow 1");

    //Assert para verificar se o getNome funciona corretamente
    assert(flow->getNome() == "Flow 1");
    
    cout << "OK!" << endl;
}

void unit_flow_setNome() {
    cout << "TEST 6 - metodo setNome() da classe Flow" << endl;

    FlowExponencial* flow = new FlowExponencial();
    flow->setNome("Test Flow");

    //Assert para verificar se o metodo setNome() corretamente atribuiu o nome informado ao flow
    assert(flow->getNome() == "Test Flow");

    cout << "OK!" << endl;
}

void unit_flow_getOrigem(){
    cout << "TEST 7 - metodo getOrigem() da classe Flow" << endl;
    
    System* system = new SystemImpl("Test System");
    FlowExponencial* flow = new FlowExponencial("Flow 1", system);

    //Assert para verificar se o metodo getOrigem esta funcionando corretamente
    assert(flow->getOrigem()->getNome() == "Test System");
    
    cout << "OK!" << endl;  
}

void unit_flow_setOrigem(){
    cout << "TEST 8 - metodo setOrigem() da classe Flow" << endl;
    
    System* system = new SystemImpl("Test System");
    FlowExponencial* flow1 = new FlowExponencial("Flow 1");
    flow1->setOrigem(system);

    //Assert para verificar se a funcao setOrigem() atribuiu corretamente o sistema informado ao flow
    assert(flow1->getOrigem()->getNome() == "Test System");
    
    cout << "OK!" << endl;  
}

void unit_flow_limparOrigem(){
    cout << "TEST 9 - metodo limparOrigem() da classe Flow" << endl;
    
    System* system = new SystemImpl("Test System");
    FlowExponencial* flow1 = new FlowExponencial("Flow 1",system);
    flow1->limparOrigem();

    //Assert para verificar se o Origem foi corretamente "limpado".
    assert(flow1->getOrigem() == NULL);
    
    cout << "OK!" << endl;  
}

void unit_flow_getDestino(){
    cout << "TEST 10 - metodo getDestino() da classe Flow" << endl;
    
    System* system = new SystemImpl("Test System"); 
    FlowExponencial* flow = new FlowExponencial("Flow 1",NULL,system);    

    //Assert para verificar se a funcao getDestino está funcionando corretamente. 
    assert(flow->getDestino()->getNome() == "Test System");
    
    cout << "OK!" << endl;
}

void unit_flow_setDestino(){
    cout << "TEST 11 - metodo setDestino() da classe Flow" << endl;
    
    System* system = new SystemImpl("Test System");
    FlowExponencial* flow = new FlowExponencial("Flow 1");
    flow->setDestino(system);

    //Assert para verificar se o destino está sendo setado corretamente
    assert(flow->getDestino()->getNome() == "Test System");
    
    cout << "OK!" <<  endl;
}

void unit_flow_limparDestino(){
    cout << "TEST 12 - metodo limparDestino() da classe Flow" << endl;
    
    System* system = new SystemImpl("Test System");
    FlowExponencial* flow = new FlowExponencial("Flow", NULL, system); 
    flow->limparDestino();

    //Assert para verificar se o destino está sendo corretamente "limpado".
    assert(flow->getDestino() == NULL);
    
    cout << "OK!" << endl;  
}

void UnitFlow::unit_flow_assingmentOperator(){
    cout << "TEST 13 - Atribuicao de operador da classe Flow" << endl;
    
    System* sys1 = new SystemImpl("Sys 1", 5.0);
    System* sys2 = new SystemImpl("Sys 2", 6.0);

    FlowExponencial* flow1 = new FlowExponencial("Flow 1");
    FlowExponencial* flow2 = new FlowExponencial();
    *flow2 = *flow1;
    
    flow1->setNome("Original Flow 1");
    flow1->setOrigem(sys1);
    flow1->setDestino(sys2);
        
    //Assert verificar se o flow esta sendo corretamente atribuido
    assert(flow2->getNome() == "Flow 1");
    assert(flow2->getOrigem() == NULL);
    assert(flow2->getDestino() == NULL);
    
    cout << "OK!" << endl;
}

void unit_flow_run(){
    cout << "TEST 14 - metodo run() da classe Flow" << endl;
    
    System* system1 = new SystemImpl("Test System 1", 10.0);
    System* system2 = new SystemImpl("Test System 2", 0.0);
    FlowExponencial* flow = new FlowExponencial("Flow", system1, system2);
    system2->setValorInicial(flow->run());
    
    //Assert para verificar se o flow foi executado corretamente.
    assert(flow->getDestino()->getValorInicial() - 0.1 < 0.01);
    
    cout << "OK!" << endl;
}

void run_unit_tests_flow() {

    UnitFlow* unit_flow = new UnitFlow();

    //Chamada de todos os unit tests da classe Flow.
    unit_flow_constructor();  
    unit_flow->unit_flow_copy_constructor();
    unit_flow_destructor(); 
    unit_flow_getNome();
    unit_flow_setNome();
    unit_flow_getOrigem();
    unit_flow_setOrigem();
    unit_flow_limparOrigem();
    unit_flow_getDestino();
    unit_flow_setDestino();
    unit_flow_limparDestino();
    unit_flow->unit_flow_assingmentOperator();
    unit_flow_run();

    delete(unit_flow);
}