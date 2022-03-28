//Aluno: Nathann Zini Dos Reis
//Matricula: 19.2.4007

#include "unit_model.hpp"

#include "../../src/include/model.hpp"
#include "./unit_flow.hpp"

#include <assert.h>

#define DEBUGING
#ifdef DEBUGING
extern int numHandleCreated;
extern int numHandleDeleted;
extern int numBodyCreated;
extern int numBodyDeleted;
#endif

using namespace std;

// Function for Model class's constructor unit test.
void unit_model_constructor(){
    cout << "TEST 1 - contrutor padrao da classe MOdel sem passar parametros" << endl;

    Model* model1 =  Model::createModel();

    //Assert para verificar se o Model foi criado com os valores padrao.
    assert(model1->getNome() == "");

    cout << "OK!" << endl;

    cout << "TEST 2 - contrutor padrao da classe Model passando parametros" << endl;
    
    Model* model2 = Model::createModel("Test Model");
    
    //Assert para verificar se o Model foi criado com os valores informados.
    assert(model2->getNome() == "Test Model");
    
    cout << "OK!" << endl;
}

void unit_model_destructor(){}

void unit_model_getNome(){
    cout << "TEST 4 - metodo getNome() da classe Model" << endl;
    
    Model* model = Model::createModel("Test Model");
    
    //Assert para verificar se a funcao getNome() funciona.
    assert(model->getNome() == "Test Model");

    cout << "OK!" << endl;
}

void unit_model_setNome(){
    cout << "TEST 5 - metodo setNome() da classe Model" << endl;

    Model* model = Model::createModel();
    model->setNome("Test Model");
    
    //Assert para verificar se a funcao setNome() está funcionando corretamente.
    assert(model->getNome() == "Test Model");

    cout << "OK!" << endl;
}


void unit_model_addSystem(){
    cout << "TEST 9 - metodo addSystem() da classe Model" << endl;
    
    Model* model = Model::createModel("Test Model");

    System* system = new SystemHandle("System 1");

    model->add(system);
    //Assert para verificar se o Systema foi devidamente adicionado.
    assert((*(model->beginSystems()))->getNome() == system->getNome());

    cout << "OK!" << endl;
}

void unit_model_removeSystem(){
    cout << "TEST 10 -metodo removeSystem() da classe Model" << endl;

    Model* model = Model::createModel("Test Model");
    System* system = model->createSystem("System 1");

    model->remove(system);
    
    //Assert para verificar se o Systema foi devidamente removido.
    assert(model->beginSystems() == model->endSystems());

    cout << "OK!" << endl;
}

void unit_model_addFlow(){
    cout << "TEST 11 - metodo addFlow() da classe Model" << endl;

    Flow* flow = new FlowHandle<FlowExponencial>("Flow 1");
    Model* model = Model::createModel("Test Model");
    model->add(flow);
    
    //Assert para verificar se o Flow foi devidamente adicionado.
    assert((*(model->beginFlows()))->getNome() == flow->getNome());

    cout << "OK!" << endl;
}

void unit_model_removeFlow(){
    cout << "TEST 12 - metodo removeFlow() da classe Model" << endl;

    Model* model = Model::createModel("Test Model");
    Flow* flow = model->createFlow<FlowExponencial>("Flow 1");
    model->remove(flow);

    //Assert para verificar se o Flow foi devidamente removido.
    assert(model->beginFlows() == model->endFlows());

    cout << "OK!" << endl;
}

void unit_model_run(){
    cout << "TEST 13 - metodo run() da classe Model" << endl;
    
    Model* expModel = Model::createModel("Model exponencial");
    System* pop1 = expModel -> createSystem("Populacao 1", 100.0);
    System* pop2 = expModel -> createSystem("Populacao 2", 0.0);
    

    Flow* expFlow = expModel->createFlow<FlowExponencial>("Crescimento ilimitado", pop1, pop2);
    
    //Assert para verificar os unit testes antes da execucao
    assert(pop1->getNome() == "Populacao 1");
    assert(pop2->getNome() == "Populacao 2");
    assert(expFlow->getNome() == "Crescimento ilimitado");
    assert(expModel->getNome() == "Model exponencial");

    assert(abs(pop1->getValorInicial() - 100.0 < 0.0001));
    assert(abs(pop2->getValorInicial() - 0.0 < 0.0001));

    expModel->run(0, 100);

    //Assert para verificar os unit testes depois da execucao
    assert(abs(pop1->getValorInicial() - 36.6032 < 0.0001));
    assert(abs(pop2->getValorInicial() - 63.3968 < 0.0001));

    cout << "OK!" << endl;
}

void run_unit_tests_model(){
    
    // chamada de todos os unit tests da classe Model.
    unit_model_constructor();
    unit_model_destructor();
    unit_model_getNome();
    unit_model_setNome();
    unit_model_addSystem();
    unit_model_removeSystem();
    unit_model_addFlow();
    unit_model_removeFlow();
    unit_model_run();

}