//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "../include/flowImpl.hpp"
#include "../include/systemImpl.hpp"


FlowImpl :: FlowImpl(string nome, System* origem , System* destino) : nome(nome), origem(origem), destino(destino){}

FlowImpl :: ~FlowImpl(){};

string FlowImpl :: getNome() const{
        return this->nome;
}
void FlowImpl :: setNome(string nome){
    this->nome = nome;
}
System* FlowImpl :: getOrigem() const{
    return this->origem;   
}
void FlowImpl :: setOrigem(System* origem){
    this->origem = origem;
}
System* FlowImpl :: getDestino() const{
    return this->destino;
}
void FlowImpl :: setDestino(System* destino){
    this->destino = destino;
}

     

    //Limpar Origem e Destino

void FlowImpl :: limparOrigem(){
    this->origem = NULL;
}
void FlowImpl :: limparDestino(){
   this->destino = NULL;
}


FlowImpl::FlowImpl(const Flow& flowImpl){
    if (this == &flowImpl){
        return;
    }
            
    nome = flowImpl.getNome();
    origem = flowImpl.getOrigem();
    destino = flowImpl.getDestino();
}

FlowImpl& FlowImpl :: operator=(const Flow& flowImpl){
    if (this == &flowImpl){
        return *this;
    }

    nome = flowImpl.getNome();
    origem = flowImpl.getOrigem();
    destino = flowImpl.getDestino();
            
    return *this;
}