//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "../include/flowImpl.hpp"


FlowBody :: FlowBody(string nome, System* origem , System* destino) : nome(nome), origem(origem), destino(destino){}

FlowBody :: ~FlowBody(){};

string FlowBody :: getNome() const{
        return this->nome;
}
void FlowBody :: setNome(string nome){
    this->nome = nome;
}
System* FlowBody :: getOrigem() const{
    return this->origem;   
}
void FlowBody :: setOrigem(System* origem){
    this->origem = origem;
}
System* FlowBody :: getDestino() const{
    return this->destino;
}
void FlowBody :: setDestino(System* destino){
    this->destino = destino;
}

     

    //Limpar Origem e Destino

void FlowBody :: limparOrigem(){
    this->origem = NULL;
}
void FlowBody :: limparDestino(){
   this->destino = NULL;
}

/*! Construtor de copia
FlowBody::FlowBody(const FlowBody& flow){
    if (this == &flow){
        return;
    }
            
    nome = flow.getNome();
    origem = flow.getOrigem();
    destino = flow.getDestino();
}

FlowBody& FlowBody :: operator=(const FlowBody& flow){
    if (this == &flow){
        return *this;
    }

    nome = flow.getNome();
    origem = flow.getOrigem();
    destino = flow.getDestino();
            
    return *this;
}*/