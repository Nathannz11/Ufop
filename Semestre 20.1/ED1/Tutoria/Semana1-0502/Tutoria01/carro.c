#include "carro.h"

struct carro{
    char modelo[50];
    char cor [15];
    int ano;
    float preco;
    float KmRodado;
};

void setModelo(Carro* carro, char* modelo){
    strcpy(carro->modelo, modelo);
}

char* getModelo(Carro carro){
    return carro.modelo;
}

void setCor(Carro* carro, char* cor){
    strcpy(carro->cor,cor);
}

char* getCor(Carro carro){
    return carro.cor;
}

void setAno(Carro* carro, int ano){
    carro->ano = ano;
}

int getAno(Carro carro){
    return carro.ano;
}

void setPreco(Carro* carro, float preco){
    carro->preco = preco;
}

float getPreco(Carro carro){
    return carro.preco;
}

void setKmRodado(Carro* carro, float KmRodado){
    carro->KmRodado = KmRodado;
}

float getKmRodado(Carro carro){
    return carro.KmRodado;
}