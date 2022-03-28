//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "functional_tests.hpp"
#include "../../src/modelImpl.hpp"
#include <assert.h>
#include <math.h>


void exponentialFuncionalTest(){
    cout << "TESTE 1 - modelo simples com equacao exponencial" << endl;

    
    System* pop1 = new SystemImpl("Populacao 1", 100.0);
    System* pop2 = new SystemImpl("Populacao 2", 0.0);
    FlowExponencial* flowExponencial = new FlowExponencial("Crescimento ilimitado", pop1, pop2);
    Model* modelExponencial = new ModelImpl("Modelo Exponencial");
    

    modelExponencial->add(pop1);
    modelExponencial->add(pop2);
    modelExponencial->add(flowExponencial);


    modelExponencial->run(0, 100);

    assert(abs((pop1->getValorInicial() - 36.6032)) < 0.0001);
    assert(abs((pop2->getValorInicial() - 63.3968)) < 0.0001);

    delete (&modelExponencial);
    std :: cout << "OK" << endl;
}

// Function for logistical functional test.
void logisticalFuncionalTest(){
    cout << "TESTE 2 - modelo simples com equacao logistica" << endl;
    
    System* p1 = new SystemImpl("Populacao 1", 100.0);
    System* p2 = new SystemImpl("Populacao 2", 10.0);
    FlowLogistico* flowLogistico = new FlowLogistico("Crescimento limitado", p1, p2);
    Model* modeloLogistico = new ModelImpl("Modelo Logistico");
    
    modeloLogistico->add(p1);
    modeloLogistico->add(p2);
    modeloLogistico->add(flowLogistico);

    modeloLogistico->run(0, 100);

    assert(abs((p1->getValorInicial() - 88.2167)) < 0.0001);
    assert(abs((p2->getValorInicial() - 21.7833)) < 0.0001);

    delete(modeloLogistico);
    cout << "OK" << endl;
}

void complexFuncionalTest(){
    cout << "TESTE 3 - modelo complexo com equacoes exponenciais e logistica" << endl;

    System* q1 = new SystemImpl("Populaçao 1", 100.0);
    System* q2 = new SystemImpl("Populaçao 2", 0.0);
    System* q3 = new SystemImpl("População 3", 100.0);
    System* q4 = new SystemImpl("População 4", 0.0);
    System* q5 = new SystemImpl("População 5", 0.0);

    FlowComplexo* f = new FlowComplexo("Flow FlowComplexo F", q1, q2);
    FlowComplexo* g = new FlowComplexo("Flow FlowComplexo g", q1, q3);
    FlowComplexo* r = new FlowComplexo("Flow FlowComplexo r", q2, q5);
    FlowComplexo* t = new FlowComplexo("Flow FlowComplexo t", q2, q3);
    FlowComplexo* u = new FlowComplexo("Flow FlowComplexo u", q3, q4);
    FlowComplexo* v = new FlowComplexo("Flow FlowComplexo v", q4, q1);

    Model* model = new ModelImpl("Modelo complexo");
    model->add(q1);
    model->add(q2);
    model->add(q3);
    model->add(q4);
    model->add(q5);

    model->add(f);
    model->add(g);
    model->add(r);
    model->add(t);
    model->add(u);
    model->add(v);

    model->run(0,100);


    assert(abs((q1->getValorInicial() - 31.8513)) < 0.0001);
    assert(abs((q2->getValorInicial() - 18.4003)) < 0.0001);
    assert(abs((q3->getValorInicial() - 77.1143)) < 0.0001);
    assert(abs((q4->getValorInicial() - 56.1728)) < 0.0001);
    assert(abs((q5->getValorInicial() - 16.4612)) < 0.0001);

    cout << "OK" << endl;

}