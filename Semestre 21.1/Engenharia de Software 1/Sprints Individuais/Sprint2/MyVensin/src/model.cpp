//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "model.hpp"


Model :: Model(string nomeModel) : nome(nomeModel){}

Model :: ~Model(){};

//Getters & Setters
string Model :: getNome() const{
    return this->nome;
}
void Model :: setNome(string nome){
    this->nome = nome;
}

//Adicionando Sistema ou Flow ao model
void Model :: add(System* system){
    sistemas.push_back(system);
}
void Model :: add(Flow* flow){
    flows.push_back(flow);
}

void Model :: run(double inicio, double fim){
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


void Model :: remove(System* sistema){
    auto i = sistemas.begin();
    for (System* item : sistemas){
        if (sistema == item){
            sistemas.erase(i);
            break;
        }
        i++;
    }
}
void Model :: remove(Flow* flow){
    auto i = flows.begin();
    for (Flow* item : flows){
        if (flow == item){
            flows.erase(i);
            break;
        }
        i++;
    }
}
//private
Model::Model (const Model& model){
    if (this == &model){
        return;
    }

    nome = model.getNome();
    
            
    for (System* item : sistemas){
        System* copy(item);
        sistemas.insert(sistemas.end(), copy);
    }         

    for (Flow* item : flows){
        Flow* copy(item);
        flows.insert(flows.end(), copy);
    }
}


Model& Model :: operator=(const Model& model){
    if (this == &model){
        return *this;
    }

    nome = model.getNome();

    for (System* item : sistemas){
        System* copy(item);
        sistemas.insert(sistemas.end(), copy);
    }

    for (Flow* item : flows){
        Flow* copy(item);
        flows.insert(flows.end(), copy);
    }

    return *this;
}