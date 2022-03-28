//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "functional_tests.hpp"
#include "../../src/include/model.hpp"
#include "../../src/include/system.hpp"
#include "../../src/include/flowImpl.hpp"
#include <assert.h>
#include <math.h>

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


void exponentialFuncionalTest(){
    cout << "TESTE 1 - modelo simples com equacao exponencial" << endl;

    Model* modelExponencial = Model::createModel("Modelo Exponencial");
    
    System* pop1 = modelExponencial->createSystem("Populacao 1", 100.0);
    System* pop2 = modelExponencial->createSystem("Populacao 2", 0.0);

    Flow* flowExponencial = modelExponencial->createFlow<FlowExponencial>("Crescimento ilimitado", pop1, pop2);
    

    assert(flowExponencial->getNome() == "Crescimento ilimitado");



    modelExponencial->run(0, 100);

    //asserts para verificar o se está funcionando corretamente;
    assert(abs((pop1->getValorInicial() - 36.6032)) < 0.0001);
    assert(abs((pop2->getValorInicial() - 63.3968)) < 0.0001);

    delete (&modelExponencial);
    std :: cout << "OK" << endl;
}

// Function for logistical functional test.
void logisticalFuncionalTest(){
    cout << "TESTE 2 - modelo simples com equacao logistica" << endl;
    
    Model* modeloLogistico = Model::createModel("Modelo Logistico");

    System* p1 = modeloLogistico->createSystem("Populacao 1", 100.0);
    System* p2 = modeloLogistico->createSystem("Populacao 2", 10.0);

    Flow* flowLogistico = modeloLogistico->createFlow<FlowLogistico>("Crescimento limitado", p1, p2);
    
    assert(flowLogistico->getNome() == "Crescimento limitado");

    modeloLogistico->run(0, 100);

    //asserts para verificar o se está funcionando corretamente;
    assert(abs((p1->getValorInicial() - 88.2167)) < 0.0001);
    assert(abs((p2->getValorInicial() - 21.7833)) < 0.0001);

    delete(modeloLogistico);
    cout << "OK" << endl;
}

void complexFuncionalTest(){
    cout << "TESTE 3 - modelo complexo com equacoes exponenciais e logistica" << endl;

    Model* model = Model::createModel("Modelo complexo");

    System* q1 = model->createSystem("Populaçao 1", 100.0);
    System* q2 = model->createSystem("Populaçao 2", 0.0);
    System* q3 = model->createSystem("População 3", 100.0);
    System* q4 = model->createSystem("População 4", 0.0);
    System* q5 = model->createSystem("População 5", 0.0);

    Flow* f = model->createFlow<FlowComplexo>("Flow FlowComplexo f", q1, q2);
    Flow* g = model->createFlow<FlowComplexo>("Flow FlowComplexo g", q1, q3);
    Flow* r = model->createFlow<FlowComplexo>("Flow FlowComplexo r", q2, q5);
    Flow* t = model->createFlow<FlowComplexo>("Flow FlowComplexo t", q2, q3);
    Flow* u = model->createFlow<FlowComplexo>("Flow FlowComplexo u", q3, q4);
    Flow* v = model->createFlow<FlowComplexo>("Flow FlowComplexo v", q4, q1);

    assert(f->getNome() == "Flow FlowComplexo f");
    assert(g->getNome() == "Flow FlowComplexo g");
    assert(r->getNome() == "Flow FlowComplexo r");
    assert(t->getNome() == "Flow FlowComplexo t");
    assert(u->getNome() == "Flow FlowComplexo u");
    assert(v->getNome() == "Flow FlowComplexo v");


    model->run(0,100);

    //asserts para verificar o se está funcionando corretamente;
    assert(abs((q1->getValorInicial() - 31.8513)) < 0.0001);
    assert(abs((q2->getValorInicial() - 18.4003)) < 0.0001);
    assert(abs((q3->getValorInicial() - 77.1143)) < 0.0001);
    assert(abs((q4->getValorInicial() - 56.1728)) < 0.0001);
    assert(abs((q5->getValorInicial() - 16.4612)) < 0.0001);

    cout << "OK" << endl;

}