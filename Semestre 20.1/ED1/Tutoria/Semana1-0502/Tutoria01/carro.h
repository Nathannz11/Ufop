#ifndef carro.h
#define carro.h



#include <stdlib.h>
#include <string.h>

typedef struct carro Carro;

void setModelo(Carro* carro, char* modelo);

char* getModelo(Carro carro);

void setCor(Carro* carro, char* cor);

char* getCor(Carro carro);

void setPreco(Carro* carro, float preco);

float getPreco(Carro carro);

void setKmRodado(Carro* carro, float KmRodado);

float getKmRodado(Carro carro);

#endif /* carro.h */ 