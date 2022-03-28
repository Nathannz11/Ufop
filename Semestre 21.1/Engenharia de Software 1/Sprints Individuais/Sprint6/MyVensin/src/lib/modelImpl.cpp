//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "../include/modelImpl.hpp"
#include "../include/systemImpl.hpp"

ModelBody :: ModelBody(string nomeModel) : nome(nomeModel){}

ModelBody :: ~ModelBody(){
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
string ModelBody :: getNome() const{
    return this->nome;
}
void ModelBody :: setNome(string nome){
    this->nome = nome;
}

//Adicionando Sistema ou Flow ao model
void ModelBody :: add(System* system){
    sistemas.push_back(system);
}
void ModelBody :: add(Flow* flow){
    flows.push_back(flow);
}

void ModelBody :: run(double inicio, double fim){
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


void ModelBody :: remove(System* sistema){
    auto i = sistemas.begin();
    for (System* item : sistemas){
        if (sistema == item){
            sistemas.erase(i);
            break;
        }
        i++;
    }
}
void ModelBody :: remove(Flow* flow){
    auto i = flows.begin();
    for (Flow* item : flows){
        if (flow == item){
            flows.erase(i);
            break;
        }
        i++;
    }
}

ModelBody::systemIterator ModelBody::beginSystems( void ){return sistemas.begin();}
ModelBody::systemIterator ModelBody::endSystems( void ){return sistemas.end();}
ModelBody::flowIterator ModelBody::beginFlows( void ){return flows.begin();} 
ModelBody::flowIterator ModelBody::endFlows( void ){return flows.end();} 


Model* Model::createModel(string nome){   
    return ModelHandle::createModel(nome);
}

Model* ModelBody::createModel(string nome){
    Model* model = new ModelHandle(nome);
    //models.push_back(model);
    return model;
}

System* ModelBody::createSystem(string nome, double valorInicial){
    System* system = new SystemHandle(nome, valorInicial);
    add(system);
    return system;
}

//private
/*
ModelBody::ModelBody (const ModelBody& model){}
void ModelBody :: operator=(const ModelBody& model){}*/