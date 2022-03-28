//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "../include/modelImpl.hpp"
#include "../include/flow.hpp"
#include "../include/systemImpl.hpp"

ModelImpl :: ModelImpl(string nomeModel) : nome(nomeModel){}

ModelImpl :: ~ModelImpl(){
    //deletar flows
    for(Flow* item : flows){
        delete(item);
    }
    flows.clear();

    //deletar systems
    for(System* item : sistemas){
        delete(item);
    }
    sistemas.clear();

};

//Getters & Setters
string ModelImpl :: getNome() const{
    return this->nome;
}
void ModelImpl :: setNome(string nome){
    this->nome = nome;
}

//Adicionando Sistema ou Flow ao model
void ModelImpl :: add(System* system){
    sistemas.push_back(system);
}
void ModelImpl :: add(Flow* flow){
    flows.push_back(flow);
}

void ModelImpl :: run(double inicio, double fim){
    vector<double> resultados;
    int count = 0;

    for(double i = inicio; i < fim; i++){

        for(Flow* item : this->flows){
            double resultado = item->run();
            resultados.push_back(resultado);
        }

        count = 0;

        for(Flow* item : this->flows){
            System* entrada = item->getOrigem();
            entrada->setValorInicial(entrada->getValorInicial() - resultados[count]);

            System* destino = item->getDestino();
            destino->setValorInicial(destino->getValorInicial() + resultados[count]);

            count++;
        }

        for(auto j = flows.begin(); j != flows.end(); j++){
            resultados.pop_back();
        }
    }
}


void ModelImpl :: remove(System* sistema){
    auto i = sistemas.begin();
    for (System* item : sistemas){
        if (sistema == item){
            sistemas.erase(i);
            break;
        }
        i++;
    }
}
void ModelImpl :: remove(Flow* flow){
    auto i = flows.begin();
    for (Flow* item : flows){
        if (flow == item){
            flows.erase(i);
            break;
        }
        i++;
    }
}

ModelImpl::systemIterator ModelImpl::beginSystems( void ){return sistemas.begin();}
ModelImpl::systemIterator ModelImpl::endSystems( void ){return sistemas.end();}
ModelImpl::flowIterator ModelImpl::beginFlows( void ){return flows.begin();} 
ModelImpl::flowIterator ModelImpl::endFlows( void ){return flows.end();} 


Model* Model::createModel(string nome){   
    return ModelImpl::createModel(nome);
}

Model* ModelImpl::createModel(string nome){
    Model* model = new ModelImpl(nome);
    //models.push_back(model);
    return model;
}

System* ModelImpl::createSystem(string nome, double valorInicial){
    System* system = new SystemImpl(nome, valorInicial);
    add(system);
    return system;
}

//private
ModelImpl::ModelImpl (const ModelImpl& model){}
void ModelImpl :: operator=(const ModelImpl& model){}