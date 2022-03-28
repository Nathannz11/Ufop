//Aluno: Nathann Zini dos Reis
//Matricula: 19.2.4007

#include "flow.hpp"


Flow :: Flow(string nome, System* origem , System* destino) : nome(nome), origem(origem), destino(destino){}

Flow :: ~Flow(){};

string Flow :: getNome() const{
        return this->nome;
}
void Flow :: setNome(string nome){
    this->nome = nome;
}
System* Flow :: getOrigem() const{
    return this->origem;   
}
void Flow :: setOrigem(System* origem){
    this->origem = origem;
}
System* Flow :: getDestino() const{
    return this->destino;
}
void Flow :: setDestino(System* destino){
    this->destino = destino;
}

     

    //Limpar Origem e Destino

void Flow :: limparOrigem(){
    this->origem = NULL;
}
void Flow :: limparDestino(){
   this->destino = NULL;
}


Flow::Flow(const Flow& flow){
    if (this == &flow){
                return;
            }

            if(getOrigem() != NULL ){
                delete (getOrigem());
            }

            if(getDestino() != NULL ){
                delete (getDestino());
            }
            
            System* origemCopia = new System(flow.getOrigem()->getNome(), flow.getOrigem()->getValorInicial());
            System* destinoCopia = new System(flow.getDestino()->getNome(), flow.getDestino()->getValorInicial());
            
            nome = flow.getNome();           
            origem = origemCopia;
            destino = destinoCopia;
}

Flow& Flow :: operator=(const Flow& flow){
    if (this == &flow){
        return *this;
    }

    if(getOrigem() != NULL){
        delete (getOrigem());
    }

    if(getDestino() != NULL ){
        delete (getOrigem());
    }

    System* origemCopy = new System(flow.getOrigem()->getNome(), flow.getOrigem()->getValorInicial());
    System* destinoCopy = new System(flow.getDestino()->getNome(), flow.getDestino()->getValorInicial());

    nome = flow.getNome();
    origem = origemCopy;
    destino = destinoCopy;
            

    return *this;
}